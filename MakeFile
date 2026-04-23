CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = src/main.c src/leitura_csv.c src/busca.c
OUT = programa.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)