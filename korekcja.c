#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
void korekcja(int **obraz, int *struktura, float wspolczynnik, int kolor)
{
    /* PRE: wszystkie parametry musza byc wieksze od 0, obraz nie może być NULL */
    assert(obraz && "brak obrazu");
    assert(struktura[1] > 0 && struktura[2] > 0 && struktura[3] > 0 && "podane wartosci niepoprawne");
    assert(wspolczynnik>0 && "niepoprawny wspolczynnik");
    float wykladnik;
    wykladnik = 1 / wspolczynnik;
    if (struktura[0] == 2)
    {
        for (int i = 0; i < struktura[2]; i++)
        {
            for (int j = 0; j < struktura[1]; j++)
            {
                obraz[i][j] = (pow(obraz[i][j], wykladnik) / pow(struktura[3], wykladnik)) * struktura[3];
            }
        }
    }
    else if (struktura[0] == 3)
    {
        switch (kolor)
        {
        case 1:
        {
            for (int i = 0; i < struktura[2]; i++)
            {
                for (int j = 0; j < struktura[1]; j = j + 3)
                {
                    obraz[i][j] = (pow(obraz[i][j], wykladnik) / pow(struktura[3], wykladnik)) * struktura[3];
                }
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < struktura[2]; i++)
            {
                for (int j = 2; j < struktura[1]; j = j + 3)
                {
                    obraz[i][j] = (pow(obraz[i][j], wykladnik) / pow(struktura[3], wykladnik)) * struktura[3];
                }
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < struktura[2]; i++)
            {
                for (int j = 1; j < struktura[1]; j = j + 3)
                {
                    obraz[i][j] = (pow(obraz[i][j], wykladnik) / pow(struktura[3], wykladnik)) * struktura[3];
                }
            }
            break;
        }
        default:
        {
            printf("niepoprawny wybor koloru");
            break;
        }
        }
    }
}