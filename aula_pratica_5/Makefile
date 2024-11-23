# Variáveis
CC = gcc
CFLAGS = -Wall -Iinclude
OBJDIR = obj
BINDIR = bin
SRCDIR = src
INCDIR = include
TARGET = $(BINDIR)/matop

# Arquivos SRC (Código-fonte) e objetos (códigos gerados pelo Makefile)
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: $(TARGET)

# Compilação dos arquivos-objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criando o executável e jogando-o no dir bin/
$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

# Rodar o executável com os 3 testes:
run: $(TARGET)
	./$(TARGET) -s -x 5 -y 5
	./$(TARGET) -m -x 5 -y 5
	./$(TARGET) -t -x 5 -y 5

# Limpeza dos arquivos objeto e do executável
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

.PHONY: all run clean