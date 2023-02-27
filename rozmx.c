#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
void rozmx(int **obraz, int *struktura, int kolor)
{
    /* PRE: obraz nie może być NULL */
    assert(obraz && "brak obrazu");
    assert(struktura[1] > 0 && struktura[2] > 0 && struktura[3] > 0 && "podane wartosci niepoprawne");
    if (struktura[0] == 2)
    {
        for (int i = 0; i < struktura[2]; i++)
        {
            for (int j = 0; j < struktura[1]; j++)
            {
                if (j != (struktura[1] - 1) && j != 0)
                    obraz[i][j] = ((obraz[i][j - 1] + obraz[i][j] + obraz[i][j + 1]) / 3);
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
                    if (j != (struktura[1] - 3) && j != 0)
                        obraz[i][j] = ((obraz[i][j - 3] + obraz[i][j] + obraz[i][j + 3]) / 3);
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
                    if (j != (struktura[1] - 1) && j != 2)
                        obraz[i][j] =((obraz[i][j - 3] + obraz[i][j] + obraz[i][j + 3]) / 3);
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
                    if (j != (struktura[1] - 2) && j != 1)
                        obraz[i][j] = ((obraz[i][j - 3] + obraz[i][j] + obraz[i][j + 3]) / 3);
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