#include "statistika.h"
void bubbleSort(DATUM niz[],int bod[],int n)
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
void dodajStatistika(char *brIgre, int bodovi)
{
    char naziv[100]="statistika";
    strcat(naziv,brIgre);
    strcat(naziv,".txt");
    DATUM niz[100];
        int bod[100],br=0; //br-broj igranja u datotec
    FILE *fp;
     time_t t = time(NULL);
    struct tm tm = *localtime(&t); //trenutni datum i vrijeme (vrijeme nije potrebno)
    fp=fopen(naziv,"a"); //"a" - append, dodavanje na kraj datoteke
    if (fp)
    {
        int i=1;
        fprintf(fp,"\n%d.%d  %d.%d.%d.",i,bodovi,tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900 ); //dodavanje novog igranja
        fclose(fp);

    } else printf("Greska pri otvaranju datoteke za dodavanje na kraj!");
    fp=fopen(naziv,"r");
    if (fp)
    {
        int m,d,g,b,rb; //mjesec,dan,godina,bodovi
        while(fscanf(fp,"%d.%d %d.%d.%d.",&rb,&b,&d,&m,&g)!=EOF)
        {
            bod[br]=b;
            niz[br].dan=d;
            niz[br].mjesec=m;
            niz[br].godina=g;
            br++;
        }
        fclose(fp);
    }else printf("Greska pri otvaranju datoteke za citanje!");
        bubbleSort(niz,bod,br);
   fp=fopen(naziv,"w");
    if (fp)
    {
        int i;
        if (br>10) br=10;
        for (i=0;i<br;i++)
         fprintf(fp,"%2d.%10d      %d.%d.%d.\n",i+1,bod[i],niz[i].dan,niz[i].mjesec, niz[i].godina);
         fclose(fp);
    }
    else printf("Greska pri otvaranju datoteke za pisanje!");

    //dodavanje u csv fajl
    char nazivCsv[100]="csv";
    strcat(nazivCsv,brIgre);
    strcat(nazivCsv,".csv");
    fp=fopen(nazivCsv,"w");
    if (fp)
    {
       int i;
        for (i=0;i<br;i++)
         fprintf(fp,"%d.,%d,%d.%d.%d.\n",i+1,bod[i],niz[i].dan,niz[i].mjesec, niz[i].godina);
        fclose(fp);
    }
    else printf("Greska pri otvaranju datoteke za pisanje!");


}
void prikazStatistike(char *brIgre)
{
    char naziv[100]="statistika",datum[100];
    int bodovi,br=0,rb=1,x; //br -broj znakova, rb-redni broj
    strcat(naziv,brIgre); //izbor odgovarajuce datoteke za datu igru
    strcat(naziv,".txt");
    FILE *fp=fopen(naziv,"r");
    if (fp)
    {

        while(fscanf(fp,"%d.%d%s\n",&x,&bodovi,datum)!=EOF) br++;
        if (br==0) printf("Statistika je prazna!");
          else
        {
        fseek(fp,0,0);
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
       fclose(fp);
    }
    else printf("Greska pri otvaranju datoteke za citanje!");
}
/*void prikazStatistike(char *brIgre) //brIgre - da bi se otvorila odgovarajuca datoteka;
{

    char naziv[100]="statistika",datum[100];
    int bodovi,br=0,rb=1,x; //br -broj znakova, rb-redni broj
    strcat(naziv,brIgre); //izbor odgovarajuce datoteke za datu igru
    strcat(naziv,".txt");
    FILE *fp;
    fp=fopen(naziv,"r");
    if (fp)
    {
        while(fscanf(fp,"%d.%d%s\n",&x,&bodovi,datum)!=EOF) br++;
            printf("%d",br);
        if (br==0)  printf("\nStatistika prazna!");
        else
        {
        fseek(fp,0,0);
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
       fclose(fp);
    }
    else printf("Greska pri otvaranju datoteke za citanje!");

}*/

