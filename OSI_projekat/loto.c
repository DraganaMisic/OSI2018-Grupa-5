#include "loto.h"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int *unos()
{
    jump6:
    okvir();
    int n=0,k,m=0;
    int *niz=(int *)calloc(7, sizeof(int));
    printf(" UNESITE 7 ZELJENIH BROJEVA U OPSEGU OD 1 DO 45:\n\n");
    do
    {
        int i;
        printf(" %d. broj:",n+1);
        scanf("%d",&k);
        if(k>0 && k<=45)
        {
            for( i=0; i<n; i++)
                if(niz[i]==k)
                {
                    printf("Taj broj ste vec unijeli.\n");
                    Sleep(1000);
                    m=1;
                }
            if(m==0)
                niz[n++]=k;
        }
        else
        {
            printf("Broj mora biti u opsegu od 1 do 45!\n");
            Sleep(1000);
        }
        m=0;
        system("cls");
        okvir();
        printf("Uneseni brojevi: ");
        ispis_niza(niz,n);
        /* for(int i=0; i<n; i++)
         {
             printf(" |%2d| ",niz[i]);

         }
         printf("\n\n");*/
    }
    while(n<=6);
    return niz;
}
void okvir()
{
    printf("========================================================================================================================");
    printf(ANSI_COLOR_CYAN"                                                       LOTO\n"ANSI_COLOR_RESET);
    printf("========================================================================================================================\n");
    printf("\n");
}
void ispis_niza(int *niz,int n)
{
    int i;
    for( i=0; i<n; i++)
    {
        printf(" |%2d| ",niz[i]);

    }
    printf("\n\n");

}
int *generisanje_brojeva()
{
    int i;
    srand(time(NULL));
    int *niz=(int*)calloc(20,sizeof(int));
    int n=0,br,k=0;
    do
    {
        br=rand()%44+1;
        for( i=0; i<n; i++)
            if(br==niz[i])
                k=1;
        if(k==0)
        {
            niz[n++]=br;
        }
        k=0;
    }
    while(n<20);
    /*   for(int i=0; i<20; i++)
           printf("%d ",niz[i]);*/
    return niz;
}
int izvlacenje(int *niz1,int *niz2)
{
    int i,j;
    int br=0,k=10,bodovi=0,brojac=0;
    for( i=0; i<20; i++)
    {
        brojac++;
        ispis_svega1(niz1,niz2,brojac-1,niz2[i],bodovi);
        //printf("<<<IMATE %d BODOVA>>>",bodovi);
        Sleep(2000);
        for( j=0; j<7; j++)
            if(niz2[i]==niz1[j])
            {
                br++;
                bodovi+=br*k;
                ispis_svega2(niz1,niz2,brojac-1,niz2[i],br*k,bodovi);
                Sleep(2000);
            }
        // ispis_svega1(niz1,niz2,brojac,niz2[i],bodovi);
        // Sleep(1000);
    }
    dodajStatistika("3", bodovi);
    return bodovi;
}
void ispis_svega2(int*niz1,int*niz2,int brojac,int broj,int bodovi,int ukupno_bodova)
{
    int a=7;
    system("cls");
    okvir();
    printf("Uneseni brojevi: ");
    ispis_niza(niz1,a);
    printf("\n\n\n\n\n");
    printf("Izvuceni broj je: |%2d| \n\n",broj);
    printf("POGODAK!!!   \n");
    printf("Broj dobijenih bodova je %d !!!",bodovi);
    printf("\n\n\n\n\n");
    printf("Izvuceni brojevi: ");
    ispis_niza(niz2,brojac);
    printf("\n\n\n\n\n");
    printf("U ovoj igri ste osvojili %d bodova\n",ukupno_bodova);
}
void ispis_svega1(int *niz1,int *niz2,int brojac,int broj,int bodovi)
{
    int a=7;
    system("cls");
    okvir();
    printf("Uneseni brojevi: ");
    ispis_niza(niz1,a);
    printf("\n\n\n\n\n");
    printf("Izvuceni broj je: |%2d| ",broj);
    printf("\n\n\n\n\n");
    printf("Izvuceni brojevi: ");
    ispis_niza(niz2,brojac);
    printf("\n\n\n\n\n");
    printf("U ovoj igri imate trenutno %d bodova !\n",bodovi);
}
