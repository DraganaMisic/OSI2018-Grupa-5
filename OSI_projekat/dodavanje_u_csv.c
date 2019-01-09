/*#include "dodavanje_u_csv.h"
void CSV(char *brIgre,int br)
{
    FILE *fp;
    char nazivCsv[100]="csv";
    strcat(nazivCsv,brIgre);
    strcat(nazivCsv,".csv");
    fp=fopen(nazivCsv,"w");
    if (fp)
    {
       int i;
        for (i=0;i<br;i++)
         fprintf(fp,"%d.,       %d,      %d.%d.%d.\n",i+1,bod[i],niz[i].dan,niz[i].mjesec, niz[i].godina);
        fclose(fp);
    }
    else printf("Greska pri otvaranju datoteke za pisanje!");
}
*/
