TARGET=tp

# compiler
CC=gcc
CCO=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= gcc main.c indiceInvertido/LIndice_invertido.c patricia/Pat.c tst/tst.c leitura.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clear:
	rm $(TARGET)