#ifndef KVIZ_H_INCLUDED
#define KVIZ_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#include <time.h>
int tacniOdgovori, osvojeniBodovi,izgubljeniBodovi,bodoviDrugaIgra;
void naslovKviz();
int kontrolaBodova();
int pretragaPitanja(int *,int );
void pitaj();
void drugaIgra();
#endif // KVIZ_H_INCLUDED
