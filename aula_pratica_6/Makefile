# Variáveis
CXX = g++
CXXFLAGS = -Wall -Iinclude
OBJDIR = obj
BINDIR = bin
SRCDIR = src
INCLUDEDIR = include

# Arquivos
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/heap.cpp
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/heap.o
EXECUTABLE = $(BINDIR)/pa2.out

# Regras de compilação
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
