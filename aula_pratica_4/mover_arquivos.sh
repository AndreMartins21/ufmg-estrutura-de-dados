#!/bin/bash

# Loop para criar as pastas c1 até c19, mover os arquivos .c e criar os arquivos solicitado
for i in {1..19}
do
  
  # Criar os arquivos c$i.c, c$irelatorio.txt dentro da pasta c$i
  touch "c$i/c${i}correto.c"
  touch "c$i/c${i}relatorio.txt"
 
done
