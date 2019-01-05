#include "meni.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void meni2(int x)
{

    int p;
    char n[20];
    printf("Izaberite opciju koju zelite ! (1/2/3/4)\n");
    printf("1. Igranje igre\n");
    printf("2. Otkazivanje igre\n");
    printf("3. Pregled statistike\n");
    printf("4. Cuvanje rezultata u CSV fajl\n");
    do
    {
        scanf("%s",n);
        p=ispravnostBroja(n);
    }
    while(p==0);
    p=atoi(n);
    if(p==1)
        printf("Igranje igre\n");
    else if(p==2)
        printf("Otkazali ste igru, vas kljuc je ponisten\n");
    else if(p==3)
    {
        if(x==1)
        {system("cls");naslov();prikazStatistike("1");Sleep(7000);}
        else if(x==2)
            {system("cls");naslovKviz();prikazStatistike("2");Sleep(7000);}
        else if(x==3)
            {system("cls");okvir();prikazStatistike("3");Sleep(7000);}
        else if(x==4)
            {system("cls");naslovBrzoKucanje();prikazStatistike("4");Sleep(7000);}
    }
    else if(p==4)
    {

        if(x==1)
        {
            system("cls");naslov();printf("Uspjesno ste sacuvali statistiku u CSV fajl !");Sleep(3000);
        }
        else if(x==2)
        {
            system("cls");naslovKviz();printf("Uspjesno ste sacuvali statistiku u CSV fajl !");Sleep(3000);
        }
        else if(x==3)
        {
           system("cls");okvir();printf("Uspjesno ste sacuvali statistiku u CSV fajl !");Sleep(3000);
        }
        else if(x==4)
        {
            system("cls");naslovBrzoKucanje();printf("Uspjesno ste sacuvali statistiku u CSV fajl !");Sleep(3000);
        }
    }
    system("cls");

}
int meni1(int x)
{
    int p;
    char n[20];
    printf("Izaberite opciju koju zelite ! (1/2/3/4)\n");
    printf("1. Unos kljuca\n");
    printf("2. Otkazivanje igre\n");
    printf("3. Pregled statistike\n");
    printf("4. Cuvanje rezultata u CSV fajl\n");
    do
    {
        scanf("%s",n);
        p=ispravnostBroja(n);
    }
    while(p==0);
    p=atoi(n);
    if(p==1)
    {
        int k=otkljucavanje();
        if(k==0)
            return 0;
    }
    else if(p==2)
    {
        printf("Otkazali ste igru, vas kljuc je ponisten\n");
        Sleep(2500);
        system("cls");
        return 0;
    }
    else if(p==3)
       {
        printf("Ovu igru jos niste otkljucali, nemate zabiljezenih rezultata !\n");
        Sleep(3000);
        system("cls");
        return 0;
       }
    else if(p==4)
        {
            printf("Ovu igru jos nista otkljucali, ne mozete sacuvati rezultate u CSV fajl !\n");
            Sleep(3000);
            system("cls");
            return 0;
        }
    return 1;

}

void prviIspis(int ukupnoBodovi)
{
    naslovPlayGround();
    printf("\n");
    printf("Bodovi: %d\n\n",ukupnoBodovi);
    printf("          IGRE\n\n");
    printf("1. Pogodi zamisljeni broj\n");
    printf("2. Kviz\n");
    printf("3. Loto (ulog 100 bodova)\n");
    printf("4. Brzo kucanje\n\n");

}

void zadnjiIspis(int ukupnoBodovi)
{
    printf("KONACNI BROJ BODOVA: %d\n",ukupnoBodovi);
}
void naslovPlayGround()
{

    printf("=======================================================================================================================\n");
    printf(ANSI_COLOR_CYAN"                                            <<< P L A Y G R O U N D >>>\n"ANSI_COLOR_RESET);
    printf("=======================================================================================================================\n");
}
