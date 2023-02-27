CC = gcc
all: przetwarzanie2.o polprogb.o polprogcz.o progowanie.o rozmy.o rozmx.o konwersja.o kontur.o korekcja.o negatyw.o odczyt.o zapis.o zmiana.o
	$(CC) przetwarzanie2.o polprogb.o polprogcz.o progowanie.o rozmy.o rozmx.o konwersja.o kontur.o korekcja.o negatyw.o odczyt.o zapis.o zmiana.o -o przetwarzanie2 -lm
przetwarzanie2.o: przetwarzanie2.c header.h 
	$(CC) przetwarzanie2.c -c -o przetwarzanie2.o
polprogb.o: polprogb.c header.h 
	$(CC) polprogb.c -c -o polprogb.o
polprogcz.o: polprogcz.c header.h 
	$(CC) polprogcz.c -c -o polprogcz.o
progowanie.o: progowanie.c header.h 
	$(CC) progowanie.c -c -o progowanie.o
rozmy.o: rozmy.c header.h 
	$(CC) rozmy.c -c -o rozmy.o
rozyx.o: rozmx.c header.h 
	$(CC) rozmx.c -c -o rozmx.o
konwersja.o: konwersja.c header.h 
	$(CC) konwersja.c -c -o konwersja.o
kontur.o: kontur.c header.h 
	$(CC) kontur.c -c -o kontur.o -lm
korekcja.o: korekcja.c header.h 
	$(CC) korekcja.c -c -o korekcja.o -lm
negatyw.o: negatyw.c header.h 
	$(CC) negatyw.c -c -o negatyw.o
odczyt.o: odczyt.c header.h 
	$(CC) odczyt.c -c -o odczyt.o
zapis.o: zapis.c header.h 
	$(CC) zapis.c -c -o zapis.o
zmiana.o: zmiana.c header.h 
	$(CC) zmiana.c -c -o zmiana.o