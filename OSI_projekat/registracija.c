#include "registracija.h"

int meniRegistracija1()
{

    printf("1. Registracija\n");
    printf("2. Izlaz\n");
    char c[20];
    int p;
    do
    {
        printf("Unesite vas izbor ! (1/2)\n");
        scanf("%s",c);
        p=ispravnostBroja2(c);
    }
    while(p==0);
    p=atoi(c);

    if(p==1)
    {
        return 1;
    }

    if(p==2)
    {
        printf("Izasli ste iz platforme, nadamo se da cete se uskoro vratiti :)");
        Sleep(2500);
        system("cls");
        exit(0);
        return 0;
    }
}

int meniRegistracija2()
{
    naslovPlayGround();
    printf("1. Igraj igre\n");
    printf("2. Izlaz\n");
    char c[20];
    int p;
    do
    {
        printf("Unesite vas izbor ! (1/2)\n");
        scanf("%s",c);
        p=ispravnostBroja2(c);
    }
    while(p==0);
    p=atoi(c);

    if(p==1)
    {
        return 1;

    }

    if(p==2)
    {
        printf("Izasli ste iz platforme, nadamo se da cete se uskoro vratiti :)");
        Sleep(2500);
        system("cls");
        exit(0);
        return 0;
    }
}
void registracija()
{
    naslovPlayGround();
    int brKaraktera=0;
    FILE *fp,*fp1;
    char x[100],imeKorisnika[100]= {};
    char s1[]="10";
    fp=fopen("korisnik.txt","r"); //otvaranje datoteke za citanje
    if (fp)
    {
        //prebrojavanje broja stringova u datoteci
        while (fscanf(fp,"%s",x)!=EOF) //formatirano ucitavanje stringa,tj. imena korisnika ukoliko postoji
            brKaraktera++;
        fclose(fp); //zatvaranje datoteke
    }
    else printf("Greska pri otvaranju datoteke za citanje!");
    if (brKaraktera==0) //registracija, prazna datoteka
    {
         brisi_datoteke();
        int t=meniRegistracija1();
        if(t==1)
        {
            printf("\nDOBRODOSLI ! UNESITE VASE IME: ");
            scanf(" %[^\t\n]s",imeKorisnika); //citanje imena korisnika(moguc unos vise rijeci)
            fp=fopen("korisnik.txt","w"); //otvaranje datoteke za pisanje
            fp1=fopen("bodovi.txt","w");
            if (fp && fp1)
            {
                fprintf(fp1,"%s",&s1);
                fprintf(fp, "%s\n", &imeKorisnika); //formatirano pisanje u datoteku
                fclose(fp); //zatvaranje datoteke
                fclose(fp1);
            }
            Sleep(1200);
            printf("\n");
            printf("Uspjesno ste se registrovali na nasu platformu !\n");
            Sleep(2500);
            system("cls"); //brisanje ekrana
        }
        else
        {
            printf("Izasli ste iz platforme !");
            Sleep(1000);
            system("cls");
        }

    }
    else
    {

        fp=fopen("korisnik.txt","r");
        while(fscanf(fp,"%s",x)!=EOF) //formatirano citanje stringa(do razmaka)
        {
            strcat(imeKorisnika,x);
            strcat(imeKorisnika," ");

        }
        printf("\n");
        printf("POZDRAV %s!",imeKorisnika);
        Sleep(1000);
        system("cls");
        int t=meniRegistracija2();
        if(t==1)
        {

            fclose(fp);
            //Sleep(1000);
            system("cls");
        }
        else
        {
            printf("Izasli ste iz platforme !");
            Sleep(1000);
            system("cls");
        }
        // return 1;

    }

}
