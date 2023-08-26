CC=gcc

BIN=main

OBJ=main.o

${BIN}: ${OBJ}

clean:
	${RM} ${OBJ} ${BIN}
