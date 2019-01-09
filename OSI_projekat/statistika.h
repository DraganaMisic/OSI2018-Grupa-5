#ifndef STATISTIKA_H_INCLUDED
#define STATISTIKA_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#include <time.h>
typedef struct //korisnicki definisan tip, struktura DATUM
{
    int dan;
    int mjesec;
    int godina;
}DATUM;
void bubbleSort(DATUM *,int*,int);
void prikazStatistike(char*);
void dodajStatistika(char*,int);


#endif // STATISTIKA_H_INCLUDED
