#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "header.h"
#define DL_LINII 1024 /* Dlugosc buforow pomocniczych */

/************************************************************************************
 * Funkcja wczytuje obraz PGM z pliku do tablicy       	       	       	       	    *
 *										    *
 * \param[in] plik_we uchwyt do pliku z obrazem w formacie PGM			    *
 * \param[out] obraz tablica, do ktorej zostanie odczytany obraz		    *
 * \param[out] struktura tablica, zawiera informacje o obrazi				    *
 * \return liczba wczytanych pikseli						    *
 ************************************************************************************/
int odczyt(FILE *plik_we, int ***obraz, int *struktura)
{
  char buf[DL_LINII]; /* bufor pomocniczy do czytania naglowka i komentarzy */
  int znak;           /* zmienna pomocnicza do czytania komentarzy */
  int koniec = 0;     /* czy napotkano koniec danych w pliku */
  int i, j, k;

  /*Sprawdzenie czy podano prawid�owy uchwyt pliku */
  if (plik_we == NULL)
  {
    fprintf(stderr, "Blad: Nie podano uchwytu do pliku\n");
    return (0);
  }

  /* Sprawdzenie "numeru magicznego" - powinien by� P2 lub P3*/
  if (fgets(buf, DL_LINII, plik_we) == NULL) /* Wczytanie pierwszej linii pliku do bufora */
    koniec = 1;                              /* Nie udalo sie? Koniec danych! */

  if ((buf[0] != 'P') || ((buf[1] != '2' && buf[1] != '3')) || koniec)
  { /* Czy jest magiczne "P2" lub "P3"? */
    fprintf(stderr, "Blad: To nie jest plik PGM ani PPM\n");
    return (0);
  }
  // struktura[0] = 1;
  struktura[0] = buf[1] - '0'; /* wpisanie typu obrazu (2 = PGM, 3 = PPM) do pierwszej komorki tablicy (wg. tablicy znakow ASCII)*/

  /* Pominiecie komentarzy */
  do
  {
    if ((znak = fgetc(plik_we)) == '#')
    {                                            /* Czy linia rozpoczyna sie od znaku '#'? */
      if (fgets(buf, DL_LINII, plik_we) == NULL) /* Przeczytaj ja do bufora                */
        koniec = 1;                              /* Zapamietaj ewentualny koniec danych */
    }
    else
    {
      ungetc(znak, plik_we);        /* Gdy przeczytany znak z poczatku linii */
    }                               /* nie jest '#' zwroc go                 */
  } while (znak == '#' && !koniec); /* Powtarzaj dopoki sa linie komentarza */
                                    /* i nie nastapil koniec danych         */
  /* Pobranie wymiarow obrazu i liczby odcieni szarosci , wczytanie do tablicy ze struktura*/
  if (fscanf(plik_we, "%d %d %d", &struktura[1], &struktura[2], &struktura[3]) != 3)
  {
    fprintf(stderr, "Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
    return (0);
  }

  /* Pobranie obrazu i odczytanie w tablicy obraz*/
  if (struktura[0] == 3)
    struktura[1] = 3 * struktura[1];                     /* dopasowanie rozmiaru w przypadku obrazu PPM */
  *obraz = (int **)malloc(struktura[2] * sizeof(int *)); /* przydzielenie pamieci dla wierszy - wymy*/
  for (k = 0; k < struktura[2]; k++)
  {
    (*obraz)[k] = (int *)malloc(struktura[1] * sizeof(int)); /* przydzielenie pamieci dla kolumn - wymx */
  }
  for (i = 0; i < struktura[2]; i++) /* wpisanie wartosci do pol tablicy */
  {
    for (j = 0; j < struktura[1]; j++)
    {
      int temp;
      if (fscanf(plik_we, "%d", &temp) != 1)
      {
        fprintf(stderr, "Blad: Niewlasciwe wymiary obrazu\n");
        return (0);
      }
      (*obraz)[i][j] = temp;
    }
  }
}

/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(char *n_pliku)
{
  char polecenie[DL_LINII]; /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie, "display "); /* konstrukcja polecenia postaci */
  strcat(polecenie, n_pliku);    /* display "nazwa_pliku" &       */
  strcat(polecenie, " &");
  printf("%s\n", polecenie); /* wydruk kontrolny polecenia */
  system(polecenie);         /* wykonanie polecenia        */
}