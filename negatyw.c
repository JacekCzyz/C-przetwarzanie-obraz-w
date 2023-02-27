#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
void negatyw(int **obraz, int *struktura, int kolor)
{
    /* PRE: wszystkie parametry musza byc wieksze od 0, obraz_pgm nie może być NULL */
    /* POST nowa wartosc musi byc wieksza od 0 */
    assert(obraz), "brak obrazu";
    assert(struktura[1] > 0 && struktura[2] > 0 && struktura[3] > 0), "podane wartosci niepoprawne";
    if (struktura[0] == 2)
    {
        for (int i = 0; i < struktura[2]; i++)
        {
            for (int j = 0; j < struktura[1]; j++)
            {
                obraz[i][j] = struktura[3] - obraz[i][j]; /*przyporzadkowywanie nowych wartosci wg wzoru*/
                assert(obraz[i][j] > 0), "niepoprawne wartosci po wykonaniu operacji";
            }
        }
    }
    if (struktura[0] == 3)
    {
        switch (kolor)
        {
        case 1:
        {
            for (int i = 0; i < struktura[2]; i++)
            {
                for (int j = 0; j < struktura[1]; j = j + 3)
                {
                    obraz[i][j] = struktura[3] - obraz[i][j]; /*przyporzadkowywanie nowych wartosci wg wzoru*/
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
                    obraz[i][j] = struktura[3] - obraz[i][j]; /*przyporzadkowywanie nowych wartosci wg wzoru*/
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
                    obraz[i][j] = struktura[3] - obraz[i][j]; /*przyporzadkowywanie nowych wartosci wg wzoru*/
                }
            }
            break;
        }
        }
    }
}