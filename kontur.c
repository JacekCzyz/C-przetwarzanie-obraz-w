#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
int bezwzgledna(int z);

void kontur(int **obraz, int *struktura, int kolor)
{
    /* PRE: wszystkie parametry musza byc wieksze od 0, obraz nie może być NULL */
    assert(obraz && "brak obrazu");
    assert(struktura[1] > 0 && struktura[2] > 0 && struktura[3] > 0 && "podane wartosci niepoprawne");
    if (struktura[0] == 2)
    {
        for (int i = 0; i < struktura[2]; i++)
        {
            for (int j = 0; j < struktura[1]; j++)
            {
                if (i < (struktura[2]-1) && j < (struktura[1]-1)) /*konturowanie piskeli "w srodku" tablicy - porownanie z pikselem po prawej i ponizej*/
                {
                    if (obraz[i + 1][j] != obraz[i][j] || obraz[i][j + 1] != obraz[i][j])
                        obraz[i][j] = bezwzgledna(obraz[i + 1][j] - obraz[i][j]) + bezwzgledna(obraz[i][j + 1] - obraz[i][j]);
                    else
                        obraz[i][j] = 0;
                }
                else if (i == (struktura[2]-1) && j < (struktura[1]-1)) /*konturowanie w ostatnim rzedzie - porownanie z pikselem po prawej*/
                {
                    if (obraz[i][j + 1] != obraz[i][j])
                        obraz[i][j] = bezwzgledna(obraz[i][j + 1] - obraz[i][j]);
                    else
                        obraz[i][j] = 0;
                }
                else if (i < (struktura[2]-1) && j == (struktura[1]-1)) /*konturowanie w ostatniej kolumnie - porownanie z pikselem ponizej*/
                {
                    if (obraz[i + 1][j] != obraz[i][j])
                        obraz[i][j] = bezwzgledna(obraz[i + 1][j] - obraz[i][j]);
                    else
                        obraz[i][j] = 0;
                }
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
                    if (i < (struktura[2]-1) && j < (struktura[1]-3)) /*konturowanie piskeli "w srodku" tablicy - porownanie z pikselem po prawej i ponizej*/
                    {
                        if (obraz[i + 1][j] != obraz[i][j] || obraz[i][j + 3] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i + 1][j] - obraz[i][j]) + bezwzgledna(obraz[i][j + 1] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
                    else if (i == (struktura[2]-1) && j < (struktura[1]-3)) /*konturowanie w ostatnim rzedzie - porownanie z pikselem po prawej*/
                    {
                        if (obraz[i][j + 3] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i][j + 1] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
                    else if (i < (struktura[2]-1) && j == (struktura[1] - 5)) /*konturowanie w ostatniej kolumnie - porownanie z pikselem ponizej*/
                    {
                        if (obraz[i + 1][j] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i + 1][j] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
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
                    if (i < (struktura[2]-1) && j < (struktura[1]-3)) /*konturowanie piskeli "w srodku" tablicy - porownanie z pikselem po prawej i ponizej*/
                    {
                        if (obraz[i + 1][j] != obraz[i][j] || obraz[i][j + 3] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i + 1][j] - obraz[i][j]) + bezwzgledna(obraz[i][j + 1] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
                    else if (i == (struktura[2]-1) && j < (struktura[1]-3)) /*konturowanie w ostatnim rzedzie - porownanie z pikselem po prawej*/
                    {
                        if (obraz[i][j + 3] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i][j + 1] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
                    else if (i < struktura[2] && j == (struktura[1] - 1)) /*konturowanie w ostatniej kolumnie - porownanie z pikselem ponizej*/
                    {
                        if (obraz[i + 1][j] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i + 1][j] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
                }
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < struktura[2]; i++)
            {
                for (int j = 3; j < struktura[1]; j = j + 3)
                {
                    if (i < (struktura[2]-1) && j < (struktura[1]-3)) /*konturowanie piskeli "w srodku" tablicy - porownanie z pikselem po prawej i ponizej*/
                    {
                        if (obraz[i + 1][j] != obraz[i][j] || obraz[i][j + 3] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i + 1][j] - obraz[i][j]) + bezwzgledna(obraz[i][j + 1] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
                    else if (i == (struktura[2]-1) && j < (struktura[1]-3)) /*konturowanie w ostatnim rzedzie - porownanie z pikselem po prawej*/
                    {
                        if (obraz[i][j + 3] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i][j + 1] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
                    else if (i < (struktura[2]-1) && j == (struktura[1]-5)) /*konturowanie w ostatniej kolumnie - porownanie z pikselem ponizej*/
                    {
                        if (obraz[i + 1][j] != obraz[i][j])
                            obraz[i][j] = bezwzgledna(obraz[i + 1][j] - obraz[i][j]);
                        else
                            obraz[i][j] = 0;
                    }
                }
            }
            break;
        }
        default:
        {
            printf("Niepoprawny wybór koloru");
            break;
        }
        }
    }
}

int bezwzgledna(int z) /*funkcja obliczajaca wartosc bezwzgledna*/
{
    return sqrt(z * z);
}