# Define os caminhos para as pastas e arquivos
SRC_DIR = src
INCLUDE_DIR = include
FILES_DIR = files

# Arquivos de origem
MAIN_SRC = $(SRC_DIR)/main.c
ORD_IND_SRC = $(SRC_DIR)/ord_indireta.c
ALG_ORDER_SRC = $(SRC_DIR)/alg_ordenacao.c

# Arquivos de cabeçalho
ORD_IND_H = $(INCLUDE_DIR)/ord_indireta.h
ALG_ORDER_H = $(INCLUDE_DIR)/alg_ordenacao.h

all: bin/tp3.out

# Alvo para o executável final
bin/tp3.out: $(MAIN_SRC) $(ORD_IND_SRC) $(ALG_ORDER_SRC) $(ORD_IND_H) $(ALG_ORDER_H)
	gcc -o bin/tp3.out $(MAIN_SRC) $(ORD_IND_SRC) $(ALG_ORDER_SRC) -I$(INCLUDE_DIR)

# Alvos para os arquivos objeto
obj/ord_indireta.o: $(ORD_IND_SRC) $(ORD_IND_H)
	gcc -c $(ORD_IND_SRC) -o obj/ord_indireta.o -I$(INCLUDE_DIR)

obj/alg_ordenacao.o: $(ALG_ORDER_SRC) $(ALG_ORDER_H)
	gcc -c $(ALG_ORDER_SRC) -o obj/alg_ordenacao.o -I$(INCLUDE_DIR)

obj/main.o: $(MAIN_SRC) $(ORD_IND_H) $(ALG_ORDER_H)
	gcc -c $(MAIN_SRC) -o obj/main.o -I$(INCLUDE_DIR)

# Limpar arquivos temporários
clean:
	rm -f obj/*.o bin/tp3.out
