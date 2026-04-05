CC = gcc
CFLAGS = -Wall

all: projet_gps

projet_gps: main.o gps.o affichage.o
	$(CC) main.o gps.o affichage.o -o projet_gps $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

gps.o: gps.c
	$(CC) -c gps.c $(CFLAGS)

affichage.o: affichage.c
	$(CC) -c affichage.c $(CFLAGS)

clean:
	rm -f *.o projet_gps resultat.txt
