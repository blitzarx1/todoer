BINFOLDER = bin
CFLAGS = -Wall -Wextra -pedantic -std=c99

build:
	cc -o ${BINFOLDER}/main ${CFLAGS} main.c
