/* kompilacja poprzez plik makefile */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"

int main(int argc, char *argv[])
{
    int **obraz;
    int *struktura[4];
    int kolor;
    FILE *plik1, *plik2;
    char *nazwa;
    float progproc, wspolczynnik;

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-i"))
        {
            nazwa = argv[i + 1];
            plik1 = fopen(nazwa, "r");
            if (plik1 == NULL)
            {
                perror("Error");
            }

            if (plik1 != NULL)
            {
                odczyt(plik1, &obraz, struktura);
                fclose(plik1);
            }
        }
        else if (!strcmp(argv[i], "-o"))
        {
            nazwa = argv[i + 1];       /*zczytanie nazwy pliku*/
            plik2 = fopen(nazwa, "w"); /*otwarcie pliku do zapisu*/
            if (plik2 != NULL)
            {
                zapis(plik2, obraz, &struktura);
                fclose(plik2);
            }
        }
        else if (!strcmp(argv[i], "-d")) /* wyswietl obraz po przetworzeniu */
        {
            wyswietl(nazwa);
        }
        else if (!strcmp(argv[i], "-m"))
        {
            if (!strcmp(argv[i + 1], "r")) /*przetwarzanie czerwieni*/
            {
                kolor = 1;
            }
            else if (!strcmp(argv[i + 1], "b")) /*przetwarzanie niebieskiego*/
            {
                kolor = 2;
            }
            else if (!strcmp(argv[i + 1], "g")) /*przetwarzanie zielonego*/
            {
                kolor = 3;
            }
            else if (!strcmp(argv[i + 1], "s")) /*konwersja do szarosci*/
            {
                konwersja(obraz, &struktura);
            }
            else
            {
                printf("nieodpowieni znak"); /*zakonczenie dzialania i wypisanie komunikatu w przypadku podania blednego kolou do przetworzenia*/
                break;
            }
        }
        else if (!strcmp(argv[i], "-n")) /*funkcja negatyw*/
        {
            negatyw(obraz, &struktura, kolor);
        }
        else if (!strcmp(argv[i], "-p")) /*funkcja progowanie*/
        {
            progproc = atof(argv[i + 1]); /*zczytanie wartosci progu z konsoli i zapisanie jako float*/
            progowanie(obraz, &struktura, progproc, kolor);
        }
        else if (!strcmp(argv[i], "-pc")) /*polprogowanie czerni*/
        {
            progproc = atof(argv[i + 1]); /*zczytanie wartosci progu z konsoli i zapisanie jako float*/
            polprogcz(obraz, &struktura, progproc, kolor);
        }
        else if (!strcmp(argv[i], "-pb")) /*polprogowanie bieli*/
        {
            progproc = atof(argv[i + 1]); /*zczytanie wartosci progu i zapisanie jako float*/
            polprogb(obraz, &struktura, progproc, kolor);
        }
        else if (!strcmp(argv[i], "-g")) /*korekcja gamma*/
        {
            wspolczynnik = atof(argv[i + 1]);
            korekcja(obraz, &struktura, wspolczynnik, kolor);
        }
        else if (!strcmp(argv[i], "-z")) /*zmiana poziomow*/
        {
            int czern = atoi(argv[i + 1]);
            int biel = atoi(argv[i + 2]);
            zmiana(obraz, &struktura, biel, czern, kolor);
        }
        else if (!strcmp(argv[i], "-k")) /*konturowanie*/
        {
            kontur(obraz, &struktura, kolor);
        }
        else if (!strcmp(argv[i], "-rx")) /*rozmycie w poziomie*/
        {
            rozmx(obraz, &struktura, kolor);
        }
        else if (!strcmp(argv[i], "-ry")) /*rozmycie w pionie*/
        {
            rozmy(obraz, &struktura, kolor);
        }
    }
    free(obraz);
    return 0;
}