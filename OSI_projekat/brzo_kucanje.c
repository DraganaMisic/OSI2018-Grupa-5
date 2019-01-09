#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "pomocne_funkcije.h"
#include "brzo_kucanje.h"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void naslovBrzoKucanje()//ispisuje naslov igrice
{
    ispisi();
    printf(ANSI_COLOR_CYAN"                                                     BRZO KUCANJE\n"ANSI_COLOR_RESET);
    ispisi();
    printf("\n");
}

void brisiString(char* s1, char* s2)//funkcija sluzi za oslobadjanje zadatog i unesenog niza
{
    free(s1);
    free(s2);
}

void unosNetacan(int* bodovi, int k, int end, int start)//ispisuje se u slucaju da je unos netacan
{
    if((end - start)/1000 > (10+k))
    {
        printf("\n");
        printf("Niste uspjeli ukucati za %d sekundi, trebalo vam je %d sekundi.\n",10+k, (end - start)/1000);
    }
    else
    {
        printf("\n");
        printf("Unos netacan, izgubili ste 10 bodova!\n");
    }
    printf("Trenutno imate %d bodova!\n", *bodovi);
    Sleep(4000);
    system("cls");
}

void unosTacan(int* bodovi, int k) //ispisuje se u slucaju da je unos tacan
{
    printf("\n");
    printf("Osvojili ste %d bodova!\n",k*10);
    printf("Trenutno imate %d bodova!\n", *bodovi);
    Sleep(4000);
    system("cls");
}

char* unosStringa(long int *start, long int *end, char *zadati_str, int k)//ispisuje nasumicno generisani string koji korisnik treba da otkuca
{
    char* uneseni_str = calloc(100, sizeof(char));
    system("cls");
    *start = clock();//pamti vrijeme kada se korisnik dobije mogucnost da ukuca string
    naslovBrzoKucanje();
    printf("%d. NIVO:\n", k);
    printf("Zadati niz je: \n");
    int lengthStr = strlen(zadati_str);
    for(int i=0; i<lengthStr; i++)//ispis karaktera zadatog niza
    {
        printf("%c ", zadati_str[i]);
    }
    printf("\n");
    scanf("%s", uneseni_str);//string koji korisnik unosi
    *end = clock();
    return uneseni_str;
}

void ispisNivoa(int k, int j)//prije svakog nivoa ispisuje koji je nivo
{
    naslovBrzoKucanje();
    printf("%d. NIVO:\n", k);
    printf("Imate %d sekundi da unesete niz !\n",k+10);
    printf("Kucanje pocinje za %d sekundi! (unesite niz bez razmaka)\n", j);//ispisuje za koliko sekundi korisnik moze poceti kucati string
    Beep(750, 300);
    Sleep(1000);
    system("cls");
}

char generatorStringa()//funkcija automatski generise jedno slovo
{
    char randomletter;
    randomletter = 'A' + (rand() % 26);
    return randomletter;
}
int cetvrtaIgra()
{
    time_t start, end;
    int bodoviCetvrtaIgra = 0;
    jump6:;
    int br_karaktera = 12;
    char* zadati_str = calloc(100, sizeof(char));
    char* uneseni_str;
    srand(time(0));
    for(int k = 1; k<=5; k++)
    {
        for(int i=0; i<br_karaktera; i++)
        {
            zadati_str[i] = generatorStringa();//generisana slova se smjestaju u zadati niz
        }
        for(int j=3; j>0; j--)
        {
            ispisNivoa(k, j);
        }
        uneseni_str = unosStringa(&start, &end, zadati_str, k);//korisnik unosi string
        if(strcmp(uneseni_str, zadati_str) == 0 && (end - start)/1000 <= (10+k))//provjera da li je uneseni string tacan ili netacan i da li je upisan prije zadatog vremena
        {
            bodoviCetvrtaIgra += 10*k;
            unosTacan(&bodoviCetvrtaIgra, k);
        }
        else
        {
            bodoviCetvrtaIgra -= 10;
            unosNetacan(&bodoviCetvrtaIgra, k, end, start);
        }
        br_karaktera = br_karaktera+12;
    }
    brisiString(zadati_str, uneseni_str);//oslobadjaju se zadati i uneseni string
    dodajStatistika("4", bodoviCetvrtaIgra);//osvojeni rezulat se upisuje u statistiku
    char c3[20];
    int p3;
    naslovBrzoKucanje();
    do//provjera da li korisnik zeli da ponovo igra igricu
    {
        printf("Da li zelite ponovo da igrate ovu igru ? (1/0)\n");
        scanf("%s",c3);
        p3=ispravnostBroja(c3);
    }
    while(p3==0);
    p3=atoi(c3);
    if(p3==1)
    {
        system("cls");
        naslovBrzoKucanje();
        goto jump6;

    }
    else
    return bodoviCetvrtaIgra;
}

