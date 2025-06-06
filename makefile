# Compilador
CC = gcc

# Nome do executável
TARGET = batalhaNaval

# Arquivos fonte
SRCS = batalhaNaval.c

# Comando padrão (digitar apenas 'make' compila o programa)
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRCS)
	$(CC) -o $@ $^

# Limpar arquivos gerados
clean:
	rm -f $(TARGET)