#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
void progowanie(int **obraz, int *struktura, float progproc, int kolor)
{
    /* PRE: prog procentowy musi byc wiekszy/rowny od 0, obraz nie może być NULL */
    assert(obraz && "brak obrazu");
    assert(struktura[1] > 0 && struktura[2] > 0 && struktura[3] > 0 && "podane wartosci niepoprawne");
    assert(progproc > 0 && "niepoprawny prog procentowy");
    int prog;
    prog = struktura[3] * (progproc / 100); /*obliczanie progu szarosci wg ktorego progujemy*/
    printf("%d, %d", struktura[1], struktura[2]);
    if (struktura[0] == 2)
    {
        for (int i = 0; i < struktura[2]; i++)
        {
            for (int j = 0; j < struktura[1]; j++)
            {
                if (obraz[i][j] <= prog) /*czern jesli wartosc ponizej progu*/
                    obraz[i][j] = 0;
                else
                    obraz[i][j] = struktura[3]; /*odpowiednia wartosc jesli powyzej progu*/
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
                    if (obraz[i][j] <= prog) /*czern jesli wartosc ponizej progu*/
                        obraz[i][j] = 0;
                    else
                        obraz[i][j] = struktura[3]; /*odpowiednia wartosc jesli powyzej progu*/
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
                    if (obraz[i][j] <= prog) /*czern jesli wartosc ponizej progu*/
                        obraz[i][j] = 0;
                    else
                        obraz[i][j] = struktura[3]; /*odpowiednia wartosc jesli powyzej progu*/
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
                    if (obraz[i][j] <= prog) /*czern jesli wartosc ponizej progu*/
                        obraz[i][j] = 0;
                    else
                        obraz[i][j] = struktura[3]; /*odpowiednia wartosc jesli powyzej progu*/
                }
            }
            break;
        }
        }
    }
}