# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -g

# Arquivos-fonte
SRC = main.c funcoes.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Nome do executável
EXEC = sistema

# Regra principal
all: $(EXEC)

# Gera o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Compila cada .c em .o
%.o: %.c funcoes.h
	$(CC) $(CFLAGS) -c $<

# Remove arquivos gerados
clean:
	rm -f $(OBJ) $(EXEC)

# Recompila tudo
rebuild: clean all