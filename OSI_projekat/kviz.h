#ifndef KVIZ_H_INCLUDED
#define KVIZ_H_INCLUDED
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
int tacniOdgovori, osvojeniBodovi,izgubljeniBodovi,bodoviDrugaIgra;
int pretragaPitanja(int [],int);
void naslovKviz();
int kontrolaBodova();
int pitaj();
int drugaIgra();
void ispis(int );


#endif // KVIZ_H_INCLUDED
