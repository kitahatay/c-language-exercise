CC = gcc
all:
	${CC} -c example3.c

x:
	${CC} example3.c -o example3.o

clean:
	rm -rf example3.o

#example2: example2.c
#	gcc example2.c -o example2


