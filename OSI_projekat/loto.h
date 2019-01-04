#ifndef LOTO_H_INCLUDED
#define LOTO_H_INCLUDED
//#define ANSI_COLOR_RED     "\x1b[31m"
//#define ANSI_COLOR_RESET   "\x1b[0m"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int *unos();
void okvir();
int *generisanje_brojeva();
int izvlacenje(int*,int*);
void ispis_niza(int*,int);
void ispis_svega2(int*,int*,int,int,int,int);
void ispis_svega1(int*,int*,int,int,int);
void ispis_pogodjenih_brojeva(int*,int*);
void sortiranje(int*,int);
#endif // LOTO_H_INCLUDED
