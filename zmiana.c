#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
void zmiana(int **obraz, int *struktura, int biel, int czern, int kolor)
{
    /* PRE: wszystkie parametry musza byc wieksze od 0, obraz nie może być NULL */
    assert(obraz && "brak obrazu");
    assert(struktura[1] > 0 && struktura[2] > 0 && struktura[3] > 0 && "podane wartosci niepoprawne");
    assert(czern > 0 && biel > 0 && biel > czern && "niepoprawne wartosci bieli i czerni");
    if (struktura[0] == 2)
    {
        for (int i = 0; i < struktura[2]; i++)
        {
            for (int j = 0; j < struktura[1]; j++)
            {
                if (obraz[i][j] <= czern) /*przypisywanie nowych wartosci pikselom wg wzoru*/
                    obraz[i][j] = 0;
                else if (obraz[i][j] > czern && obraz[i][j] < biel)
                    obraz[i][j] = (obraz[i][j] - czern) * struktura[3] / (biel - czern);
                else
                    obraz[i][j] = struktura[3];
            }
        }
    }
    else
    {
        switch (kolor)
        {
        case 1:
        {
            for (int i = 0; i < struktura[2]; i++)
            {
                for (int j = 0; j < struktura[1]; j = j + 3)
                {
                    if (obraz[i][j] <= czern) /*przypisywanie nowych wartosci pikselom wg wzoru*/
                        obraz[i][j] = 0;
                    else if (obraz[i][j] > czern && obraz[i][j] < biel)
                        obraz[i][j] = (obraz[i][j] - czern) * struktura[3] / (biel - czern);
                    else
                        obraz[i][j] = struktura[3];
                }
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < struktura[2]; i++)
            {
                for (int j = 1; j < struktura[1]; j = j + 3)
                {
                    if (obraz[i][j] <= czern) /*przypisywanie nowych wartosci pikselom wg wzoru*/
                        obraz[i][j] = 0;
                    else if (obraz[i][j] > czern && obraz[i][j] < biel)
                        obraz[i][j] = (obraz[i][j] - czern) * struktura[3] / (biel - czern);
                    else
                        obraz[i][j] = struktura[3];
                }
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < struktura[2]; i++)
            {
                for (int j = 2; j < struktura[1]; j = j + 3)
                {
                    if (obraz[i][j] <= czern) /*przypisywanie nowych wartosci pikselom wg wzoru*/
                        obraz[i][j] = 0;
                    else if (obraz[i][j] > czern && obraz[i][j] < biel)
                        obraz[i][j] = (obraz[i][j] - czern) * struktura[3] / (biel - czern);
                    else
                        obraz[i][j] = struktura[3];
                }
            }
            break;
        }
        default:
        {
            printf("Blad: niepoprawny wybor koloru");
            break;
        }
        }
    }
}