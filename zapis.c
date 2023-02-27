#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
int zapis(FILE *plik_wy, int **obraz, int *struktura)
{
  if (plik_wy == NULL)
  {
    fprintf(stderr, "Blad: Nie podano uchwytu do pliku\n");
    return 0;
  }
  if (struktura[0] == 3)
  {
    struktura[1] = struktura[1] / 3;
    fprintf(plik_wy, "P%d\n%d %d\n%d\n", struktura[0], struktura[1], struktura[2], struktura[3]);
    struktura[1] = struktura[1] * 3;
  }
  else
    fprintf(plik_wy, "P%d\n%d %d\n%d\n", struktura[0], struktura[1], struktura[2], struktura[3]);

  /* Pobranie obrazu i odczytanie w tablicy obraz*/
  for (int i = 0; i < struktura[2]; i++)
  {
    for (int j = 0; j < struktura[1]; j++)
    {
      fprintf(plik_wy, "%d ", obraz[i][j]);
    }
    fprintf(plik_wy, "\n");
  }
  return 0;
}