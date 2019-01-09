#include "playground.h"
#include "meni.h"
#include "pomocne_funkcije.h"


void PlayGround()
{
    FILE *kljucevi, *otkazivanje;
    system("COLOR 71");
    char n[20],p[20];
    FILE *fp;
    int prva=0,druga=0,treca=0,cetvrta=0;
    registracija();
    int bodoviPrvaIgra=0,bodoviDrugaIgra,bodoviTrecaIgra,bodoviCetvrtaIgra,ukupnoBodovi=10,n1,p1;
    FILE *kljuc1,*kljuc2,*kljuc3,*kljuc4;
    generisanje_kljuceva(kljuc1, kljuc2, kljuc3, kljuc4); //smjestanje kljuceva u datoteke
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
    if(p1==1)  //opcije u slucaju izbora prve igre
    {
        if(otkazivanje=fopen("otkazana1.txt", "r"))  //provjera da li je igra otkazana
        {
            system("cls");
            fclose(otkazivanje);
            prviIspis(ukupnoBodovi);    //odgovrajuci ispis
            printf("Unesite redni broj igre koju zelite da igrate: \n\n");
            printf("Otkazali ste ovo igru. Ne mozete joj vise pristupiti!\n");
            Sleep(2500);
            system("cls");
            goto jump;  //prelazak na meni za izbor igre
        }
        if(kljucevi=fopen("trajanje_kljuca1.txt","r")) //provjera da li je igra otkljucana
        {
            fclose(kljucevi);
            goto skok1;   //prekazak u Igra meni
        }


        else
        {
            //prelazak u meni sa opcijom Unesi kljuc
            int k1;
            naslov();
            k1=meni1(p1);
            if(k1==0)
                goto jump;

            else
            {

skok1:

                naslov();
                int o=meni2(p1,"trajanje_kljuca1.txt");
                if(o==0)
                    goto skok1;
                if(o==1)
                    goto jump;
                if(o==2)
                {
                    system("cls");
                    naslov();
                    bodoviPrvaIgra=igranje();
                    ispis_bodova(bodoviPrvaIgra);
                    ukupnoBodovi+=bodoviPrvaIgra;
                }
            }
        }
    }
    if(p1==2)   //opcije u slucaju izbora druge igre
    {
        if(otkazivanje=fopen("otkazana2.txt", "r")) //provjera da li je igra otkazana
        {
            system("cls");
            fclose(otkazivanje);
            prviIspis(ukupnoBodovi);
            printf("Unesite redni broj igre koju zelite da igrate: \n\n");
            printf("Otkazali ste ovo igru. Ne mozete joj vise pristupiti!\n");
            Sleep(2500);
            system("cls");
            goto jump;
        }
        if(kljucevi=fopen("trajanje_kljuca2.txt", "r")) //provjera da li je igra otkljucana
        {
            fclose(kljucevi);
            goto skok2;
        }

        else
        {

            int k2;
            naslovKviz();
            k2=meni1(p1);
            if(k2==0)
                goto jump;
            else
            {
skok2:

                naslovKviz();
                int o1=meni2(p1,"trajanje_kljuca2.txt");
                if(o1==0)
                    goto skok2;
                else if(o1==1)
                    goto jump;
                else if(o1==2)
                {
                    bodoviDrugaIgra=drugaIgra();
                    ukupnoBodovi+=bodoviDrugaIgra;
                }
            }
        }

    }
    if(p1==3) //opcije u slucaju izbora trece igre
    {
        if(otkazivanje=fopen("otkazana3.txt", "r")) //provjera da li je igra otkazana
        {
            system("cls");
            fclose(otkazivanje);
            prviIspis(ukupnoBodovi);
            printf("Unesite redni broj igre koju zelite da igrate: \n\n");
            printf("Otkazali ste ovo igru. Ne mozete joj vise pristupiti!\n");
            Sleep(2500);
            system("cls");
            goto jump;  //prelazak na glavni meni
        }
        if(kljucevi=fopen("trajanje_kljuca3.txt", "r")) //provjera da li je igra otkljucana
        {
            fclose(kljucevi);
            goto skok3;
        }

        else
        {

            int k3;
            okvir();
            k3=meni1(p1);
            if(k3==0)
                goto jump;
            else
            {
skok3:
                okvir();
                int o2=meni2(p1,"trajanje_kljuca3.txt");
                if(o2==0)
                    goto skok3;
                else if(o2==1)
                    goto jump;
                else if(o2==2)
                {
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
                        system("cls");
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
                        {
                            system("cls");
                            goto jump6;
                        }
                    }
                }
            }
        }
    }
    if(p1==4)  //opcije u slucaju izbora cetvrte igre
    {
        if(otkazivanje=fopen("otkazana4.txt", "r"))  //provjera da li je igra otkazana
        {
            system("cls");
            fclose(otkazivanje);
            prviIspis(ukupnoBodovi);
            printf("Unesite redni broj igre koju zelite da igrate: \n\n");
            printf("Otkazali ste ovo igru. Ne mozete joj vise pristupiti!\n");
            Sleep(2500);
            system("cls");
            goto jump;
        }
        if(kljucevi=fopen("trajanje_kljuca4.txt", "r")) //provjera da li je igra otkazana
        {
            fclose(kljucevi);
            goto skok4;
        }

        else
        {

            int k4;
            naslovBrzoKucanje();
            k4=meni1(p1);
            if(k4==0)
                goto jump;
            else
            {
skok4:
                naslovBrzoKucanje();
                int o4=meni2(p1,"trajanje_kljuca4.txt");
                if(o4==0)
                    goto skok4;
                else if(o4==1)
                    goto jump;
                else if(o4==2)
                {
                    bodoviCetvrtaIgra=cetvrtaIgra();
                    ukupnoBodovi+=bodoviCetvrtaIgra;
                }
            }
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
    {
        pamtiBodove(ukupnoBodovi);
        goto jump;
    }
    else
    {
        pamtiBodove(ukupnoBodovi);
        naslovPlayGround();
        zadnjiIspis(ukupnoBodovi);
    }
}

