#!/bin/bash

# Diretório de resultados
OUTPUT_DIR="results"
mkdir -p $OUTPUT_DIR

# Intervalo de valores a serem testados
FACTORIAL_MAX=20
FIBONACCI_MAX=45

# Executável normal e com gprof
EXEC_NORMAL="./bin/main"
EXEC_GPROF="./bin/main_gprof"

# Função para executar e medir tempo
run_time_measurement() {
    local task=$1
    local method=$2
    local value=$3
    local exec_file=$4
    local label=$5

    # Medição com 'time'
    /usr/bin/time -o "$OUTPUT_DIR/${label}_time_${task}_${method}_${value}.txt" -v $exec_file $value $task $method > "$OUTPUT_DIR/output_${task}_${method}_${value}.txt" 2>&1
}

# Função para executar com gprof
run_gprof_measurement() {
    local task=$1
    local method=$2
    local value=$3

    # Executa e gera perfil com gprof
    $EXEC_GPROF $value $task $method
    gprof $EXEC_GPROF gmon.out > "$OUTPUT_DIR/gprof_${task}_${method}_${value}.txt"
    rm gmon.out # Limpa para próxima execução
}

# Rodar experimentos de fatorial (iterative e recursive)
for i in $(seq 1 $FACTORIAL_MAX); do
    run_time_measurement "fatorial" "iterative" $i $EXEC_NORMAL "normal"
    run_time_measurement "fatorial" "recursive" $i $EXEC_NORMAL "normal"
    run_time_measurement "fatorial" "iterative" $i $EXEC_GPROF "gprof"
    run_time_measurement "fatorial" "recursive" $i $EXEC_GPROF "gprof"
    run_gprof_measurement "fatorial" "recursive" $i
done

# Rodar experimentos de Fibonacci (iterative e recursive)
for i in $(seq 1 $FIBONACCI_MAX); do
    run_time_measurement "fibonacci" "iterative" $i $EXEC_NORMAL "normal"
    run_time_measurement "fibonacci" "recursive" $i $EXEC_NORMAL "normal"
    run_time_measurement "fibonacci" "iterative" $i $EXEC_GPROF "gprof"
    run_time_measurement "fibonacci" "recursive" $i $EXEC_GPROF "gprof"
    run_gprof_measurement "fibonacci" "recursive" $i
done

echo "Experimentos concluídos. Resultados armazenados em $OUTPUT_DIR"
