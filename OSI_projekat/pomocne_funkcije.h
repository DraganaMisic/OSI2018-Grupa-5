#ifndef POMOCNE_FUNKCIJE_H_INCLUDED
#define POMOCNE_FUNKCIJE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>
#include <string.h>
int ucitajBodove();
int ispravnostBroja(char *);
void pamtiBodove(int);
int ispravnostBroja2(char *);
void ispis_bodova(int br_bodova);
int otkljucavanje(int);
int ucitajBodove();
void ispisi();
void generisanje_kljuceva(FILE *, FILE *, FILE *, FILE *);
void upisi_vrijeme(char *, int );
long long razlika_vremena(char *,char *);
void brisi_datoteke();
//void uporedi_vrijeme();
#endif // POMOCNE_FUNKCIJE_H_INCLUDED

