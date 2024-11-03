# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = bin/main

# Diretórios
SRCDIR = src
OBJDIR = obj
INCDIR = include

# Arquivos
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
DEPS = $(wildcard $(INCDIR)/*.h)

# Regra padrão
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar os arquivos .o a partir dos arquivos .c
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
