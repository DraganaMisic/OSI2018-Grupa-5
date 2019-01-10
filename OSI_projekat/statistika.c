#include "statistika.h"
void bubbleSort(DATUM niz[],int bod[],int n)  //sortiranje bodova i odgovarajucih datuma u opadajucem poretku
{
    int i,j;
    for (i=0;i<n-1;i++)
        for (j=0;j<n-i-1;j++)
        if (bod[j]<bod[j+1])
    {
        DATUM temp; //pomocna promjenljiva
        temp=niz[j];
        niz[j]=niz[j+1];
        niz[j+1]=temp;

        int p; //pomocna
        p=bod[j];
        bod[j]=bod[j+1];
        bod[j+1]=p;
    }
}
void dodajStatistika(char *brIgre, int bodovi) //dodavanje igranja u statistiku
{
    char naziv[100]="statistika";
    strcat(naziv,brIgre);
    strcat(naziv,".txt"); //kreiranje odgovarajuceg naziva datoteke, zavisno od igre
    DATUM niz[100];
        int bod[100],br=0; //br-trenutni broj igranja u datoteci
    FILE *fp;
     time_t t = time(NULL);
    struct tm tm = *localtime(&t); //trenutni datum i vrijeme (vrijeme nije potrebno)
    fp=fopen(naziv,"a"); //"a" - append, dodavanje na kraj datoteke
    if (fp)
    {
        int i=1;
        fprintf(fp,"\n%d.%d  %d.%d.%d.",i,bodovi,tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900 ); //dodavanje novog igranja
        fclose(fp); //zatvaranje datototeke

    } else printf("Greska pri otvaranju datoteke za dodavanje na kraj!");
    fp=fopen(naziv,"r"); //otvaranje datoteke za citanje
    if (fp)
    {
        int m,d,g,b,rb; //mjesec,dan,godina,bodovi,rb-redni broj
        while(fscanf(fp,"%d.%d %d.%d.%d.",&rb,&b,&d,&m,&g)!=EOF) //formatirano ucitavanje iz datoteke
        {
            //dodavanje igranja u datoteku:
            bod[br]=b;
            niz[br].dan=d;
            niz[br].mjesec=m;
            niz[br].godina=g;
            br++;
        }
        fclose(fp); //zatvaranje datoteke
    }else printf("Greska pri otvaranju datoteke za citanje!");
        bubbleSort(niz,bod,br); //poziv funkcije za sortiranje bodova i datuma koji im odgovaraju
   fp=fopen(naziv,"w"); //otvaranje tekstualne datoteke za pisanje
    if (fp)
    {
        int i;
        if (br>10) br=10; //regulisanje maksimalnog broja igranja u datoteci
        //formatirani upis u datoteku:
        for (i=0;i<br;i++)
         fprintf(fp,"%2d.%10d      %d.%d.%d.\n",i+1,bod[i],niz[i].dan,niz[i].mjesec, niz[i].godina);
         fclose(fp); //zatvaranje datoteke
    }
    else printf("Greska pri otvaranju datoteke za pisanje!");

    //dodavanje u csv fajl:
    //kreiranje odgovarajuceg naziva fajla zavisno od igre
    char nazivCsv[100]="csv";
    strcat(nazivCsv,brIgre);
    strcat(nazivCsv,".csv");
    fp=fopen(nazivCsv,"w"); //otvaranje datoteke za pisanje
    if (fp)
    {
       int i;
       fprintf(fp,"%10s,%10s,%10s\n","Redni broj","Bodovi","Datum"); //naslov
        for (i=0;i<br;i++)
         fprintf(fp,"%d.,       %d,      %d.%d.%d.\n",i+1,bod[i],niz[i].dan,niz[i].mjesec, niz[i].godina);//formatirani upis u csv fajl
        fclose(fp); //zatvaranje datoteke
    }
    else printf("Greska pri otvaranju datoteke za pisanje!");


}
void prikazStatistike(char *brIgre) //prikaz statistike zavisno od broja igre
{
    char naziv[100]="statistika",datum[100];
    int bodovi,br=0,rb=1,x; //br -broj znakova, rb-redni broj
    strcat(naziv,brIgre); //izbor odgovarajuce datoteke za datu igru
    strcat(naziv,".txt");
    FILE *fp=fopen(naziv,"r");
    if (fp)
    {
        //formatirano citanje iz datoteke, EOF-end of file
        while(fscanf(fp,"%d.%d%s\n",&x,&bodovi,datum)!=EOF) br++; //racunanje broja igranja u datoteci
        if (br==0) printf("Statistika je prazna!"); //odgovarajuci ispis
          else
        {
        fseek(fp,0,0); //povratak na pocetak datoteke, jer je prethodno procitan sav sadrzaj datoteke(pokazivac pokazuje na kraj)
        //ispis tabele:
        printf("    -----------------------------------\n");
        printf("    RB      BODOVI          DATUM        \n" );
        printf("    -----------------------------------\n");
            while(fscanf(fp,"%d.%d%s\n",&x,&bodovi,datum)!=EOF)
        {
            printf("  %3d.%10d%20s\n",rb++,bodovi,datum);
            printf("    -----------------------------------\n");

            br++;
        }
        }
       fclose(fp); //zatvaranje datoteke
    }
    else printf("Nemate zabiljezenih rezultata!");
}

