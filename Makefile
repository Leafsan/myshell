# Makefile by CWK

CC = gcc
STRIP = strip

SRC1 = mybash
SRC2 = promptprint
SRC3 = reader
SRC4 = parser
SRC5 = execute

all: mybash

mybash: $(SRC1).o $(SRC2).o $(SRC3).o $(SRC4).o $(SRC5).o
	$(CC) -o mybash $(SRC1).o $(SRC2).o $(SRC3).o $(SRC4).o $(SRC5).o
	$(STRIP) mybash

$(SRC1).o: $(SRC1).c
	$(CC) -c $(SRC1).c

$(SRC2).o: $(SRC2).c
	$(CC) -c $(SRC2).c

$(SRC3).o: $(SRC3).c
	$(CC) -c $(SRC3).c

$(SRC4).o: $(SRC4).c
	$(CC) -c $(SRC4).c

$(SRC5).o: $(SRC5).c
	$(CC) -c $(SRC5).c

clean:
	rm -f *.o mybash
