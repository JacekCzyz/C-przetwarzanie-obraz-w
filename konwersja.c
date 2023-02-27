#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
void konwersja(int **obraz, int *struktura)
{
    assert(obraz && "brak obrazu");
    assert(struktura[1] > 0 && struktura[2] > 0 && struktura[3] > 0 && "podane wartosci niepoprawne");
    int **temp;
    temp = (int **)malloc(struktura[2] * sizeof(int *)); /*tworzenie tymczasowego obrazu pomocniczego*/
    for (int k = 0; k < struktura[2]; k++)
    {
        temp[k] = (int *)malloc(struktura[1] / 3 * sizeof(int));
    }
    for (int i = 0; i < struktura[2]; i++)
    {
        int kolumna_pgm = 0;
        for (int j = 1; j < (struktura[1] - 1); j = j + 3)
        {
            temp[i][kolumna_pgm] = (obraz[i][j - 1] + obraz[i][j] + obraz[i][j + 1]) / 3; /*obliczanie sredniej wartosci z 3 kolumn kodujacych piksel i przypisanie tymczasowemu obrazowi wartosci pojedynczych kolumn obrazu*/
            kolumna_pgm++;
        }
    }
    struktura[1] = struktura[1] / 3; /*dostosowanie rozmiaru*/

    for (int l = 0; l < struktura[2]; l++)
    {
        for (int m = 0; m < struktura[1]; m++)
        {
            obraz[l][m] = temp[l][m]; /*przypisuje obrazowi nowe wartosci pikseli z obrazu tymczasowego*/
        }
    }
    free(temp);
    struktura[0] = 2; /*zmiana slowa magicznego na P2 - dopasowanie do nowego formatu(PGM) i dostosowanie do nastepnych funkcji*/
}