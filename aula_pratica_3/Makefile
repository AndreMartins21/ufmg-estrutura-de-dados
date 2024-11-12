# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = bin/main
TARGET_GPROF = bin/main_gprof

# Diretórios
SRCDIR = src
OBJDIR = obj
INCDIR = include

# Arquivos
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
OBJS_GPROF = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%_gprof.o, $(SRCS))
DEPS = $(wildcard $(INCDIR)/*.h)

# Regra padrão: compila a versão normal e a versão com gprof
all: $(TARGET) $(TARGET_GPROF)

# Regra para gerar o executável normal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para gerar o executável com gprof
$(TARGET_GPROF): $(OBJS_GPROF)
	$(CC) -pg $(CFLAGS) -o $@ $^

# Regra para compilar os arquivos .o para a versão normal
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

# Regra para compilar os arquivos .o para a versão com gprof
$(OBJDIR)/%_gprof.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -pg $(CFLAGS) -c -o $@ $<

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/*_gprof.o $(TARGET) $(TARGET_GPROF)
