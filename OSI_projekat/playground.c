#include "playground.h"
#include "meni.h"
#include "pomocne_funkcije.h"


void PlayGround()
{
    system("COLOR 71");
    char n[20],p[20];
    registracija();
    int bodoviPrvaIgra=0,bodoviDrugaIgra,bodoviTrecaIgra,bodoviCetvrtaIgra,ukupnoBodovi=10,n1,p1;
    int t=ucitajBodove();
    if(t!=10)
        ukupnoBodovi=ucitajBodove();
jump:
    prviIspis(ukupnoBodovi);
    do
    {
        printf("Unesite redni broj igre koju zelite da igrate: ");
        scanf("%s",n);
        n1=ispravnostBroja(n);
    }
    while(n1==0);
    system("cls");
    p1=atoi(n);
    if(p1==1)
    {
        naslov();
        meni2(p1);
        naslov();
        bodoviPrvaIgra=igranje();
        ispis_bodova(bodoviPrvaIgra);
        ukupnoBodovi+=bodoviPrvaIgra;
    }
    if(p1==2)
    {
        int k2;
        naslovKviz();
        k2=meni1(p1);
        if(k2==0)
            goto jump;
        else
        {
            naslovKviz();
            meni2(p1);
            bodoviDrugaIgra=drugaIgra();
            ukupnoBodovi+=bodoviDrugaIgra;
        }

    }
    if(p1==3)
    {
        int k3;
        okvir();
        k3=meni1(p1);
        if(k3==0)
            goto jump;
        else
        {

            okvir();
            meni2(p1);
            jump6:
            if(ukupnoBodovi<100)
            {
                okvir();
                printf("Nemate dovoljno bodova da pocnete igru !");
                Sleep(2000);
                system("cls");
                goto jump;
            }
            else
            {
                ukupnoBodovi-=100;
                int *niz=unos();
                int *niz1=generisanje_brojeva();
                bodoviTrecaIgra=izvlacenje(niz,niz1);
                ukupnoBodovi+=bodoviTrecaIgra;
                char c3[20];
                int p3;
                do
                {
                    printf("Da li zelite ponovo da igrate ovu igru ? (1/0)\n");
                    scanf("%s",c3);
                    p3=ispravnostBroja(c3);
                }
                while(p3==0);
                p3=atoi(c3);
                if(p3==1)
                    {system("cls");goto jump6;}
            }
        }
    }
    if(p1==4)
    {
        int k4;
        naslovBrzoKucanje();
        k4=meni1(p1);
        if(k4==0)
            goto jump;
        else
        {
            naslovBrzoKucanje();
            meni2(p1);
            bodoviCetvrtaIgra=cetvrtaIgra();
            ukupnoBodovi+=bodoviCetvrtaIgra;
        }
    }
    do
    {
        printf("Da li zelite da igrate neku drugu igru: (1/0)");
        scanf("%s",p);
        n1=ispravnostBroja(p);

    }
    while(n1==0);
    system("cls");
    n1=atoi(p);
    if(n1==1)
        goto jump;
    else
    {
        pamtiBodove(ukupnoBodovi);
        naslovPlayGround();
        zadnjiIspis(ukupnoBodovi);
    }
}
