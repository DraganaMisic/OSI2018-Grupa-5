#include "pomocne_funkcije.h"
int ucitajBodove()
{
    FILE *fp;
    fp=fopen("bodovi.txt","r");
    char s[20];
    int x;
    if(fp)
    {
        fscanf(fp,"%s",s);
        fclose(fp);
        x=atoi(s);
        return x;
    }
    else
    {
        printf("Datoteka nije uspjesno otvorena !\n");
        return 0;
    }


}

int ispravnostBroja2(char *n)
{
    {
        if (n[1]!='\0')
        {
            printf("Pogresan unos, unesite ponovo !\n");
            return 0;
        }
        if(n[0]>='1' && n[0]<='2')
            return 1;
        else
        {
            printf("Pogresan unos, unesite ponovo !\n");
            return 0;
        }
    }
}
int ispravnostBroja100(char *n)
{
    if(n[3]!='\n')
    {
        printf("Pogresan unos, unesite ponovo !\n");
        return 0;
    }
    if(n[0]<'0')
    {
        printf("Pogresan unos, unesite ponovo !\n");
        return 0;
    }
    if(n[0]=='1' && n[1]=='0' && n[2]!='0')
    {
        printf("Pogresan unos,unesite ponovo !\n");
        return 0;
    }
    if((n[0]>'1' && n[0]<'9') && (n[1]>'0' && n[1]<'9') && n[2]!='\n')
    {
        printf("Pogresan unos, unesite ponovo !\n");
        return 0;
    }
    else
        return 1;
}
int ispravnostBroja(char *n)
{
    if (n[1]!='\0')
    {
        printf("Pogresan unos, unesite ponovo !");
        return 0;
    }
    if(n[0]>='0' && n[0]<='4')
        return 1;
    else
    {
        printf("Pogresan unos, unesite ponovo !");
        return 0;
    }
}
void ispisi()
{
    printf("=======================================================================================================================\n");
}

void ispis_bodova(int br_bodova)
{
    printf("\n\n");
    printf("U ovoj igri ste osvojili %d bodova. \n", br_bodova);

}

void generisanje_kljuceva(FILE *kljuc1, FILE *kljuc2, FILE *kljuc3, FILE *kljuc4)
{

    char c[120],x[120];
    int t;
    char s1[120],s2[120],s3[120],s4[120],s5[120],s6[120],s7[120],s8[120];
    char s9[120],s10[120],s11[120],s12[120],s13[120],s14[120],s15[120],s16[120];
    int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16;
    srand(time(NULL));
    do
    {
        c1=rand()%10000;
        c2=rand()%10000;
        c3=rand()%10000;
        c4=rand()%10000;
    }
    while(c1<1000 || c2<1000 || c3<1000 || c4<1000);
    do
    {
        c5=rand()%10000;
        c6=rand()%10000;
        c7=rand()%10000;
        c8=rand()%10000;

    }
    while(c5<1000 || c6<1000 || c7<1000 || c8<1000);
    do
    {
        c9=rand()%10000;
        c10=rand()%10000;
        c11=rand()%10000;
        c12=rand()%10000;

    }
    while(c9<1000 || c10<1000 || c11<1000 || c12<1000);
    do
    {
        c13=rand()%10000;
        c14=rand()%10000;
        c15=rand()%10000;
        c16=rand()%10000;
    }
    while(c13<1000 || c14<1000 || c15<1000 || c16<1000);
    itoa(c1,s1,10);
    itoa(c2,s2,10);
    itoa(c3,s3,10);
    itoa(c4,s4,10);
    itoa(c5,s5,10);
    itoa(c6,s6,10);
    itoa(c7,s7,10);
    itoa(c8,s8,10);
    itoa(c9,s9,10);
    itoa(c10,s10,10);
    itoa(c11,s11,10);
    itoa(c12,s12,10);
    itoa(c13,s13,10);
    itoa(c14,s14,10);
    itoa(c15,s15,10);
    itoa(c16,s16,10);
    kljuc1=fopen("kljucevi7d.txt","w");
    if(kljuc1)
    {
        fprintf(kljuc1,"%s-%s-%s-%s",&s1,&s2,&s3,&s4);
        fclose(kljuc1);
    }
    kljuc2=fopen("kljucevi1d.txt","w");
    if(kljuc2)
    {
        fprintf(kljuc2,"%s-%s-%s-%s",&s5,&s6,&s7,&s8);
        fclose(kljuc2);
    }
    kljuc3=fopen("kljucevi1s.txt","w");
    if(kljuc3)
    {
        fprintf(kljuc3,"%s-%s-%s-%s",&s9,&s10,&s11,&s12);
        fclose(kljuc3);
    }
    kljuc4=fopen("kljucevineograniceno.txt","w");
    if(kljuc4)
    {
        fprintf(kljuc4,"%s-%s-%s-%s",&s13,&s14,&s15,&s16);
        fclose(kljuc4);
    }
}
void upisi_vrijeme(char *naziv_datoteke, int i)
{
    FILE *fp;
    fp=fopen(naziv_datoteke, "w");
    time_t t = time(NULL);
    struct tm *ptm = localtime(&t);
    char buf[256];
    strftime(buf, sizeof(buf), "%d.%m.%Y  %H.%M.%S", ptm);
    fprintf(fp, "%s", buf);
    fclose(fp);
    //char redni_brojevi[4];
    //redni_brojevi[i-1]=i;
    fp=fopen("otkljucane_igre.txt", "a");
    {
       // for(int j=0; j<4; j++)
            fprintf(fp, "%d ",i);
    }
    fclose(fp);
}
int provjera_kljuca(char *naziv_datoteke)
{
    FILE *fp;
    fp=fopen(naziv_datoteke, "r");
    char postojeci_kljuc[20];
    char uneseni_kljuc[20];
    int i=1;
    fscanf(fp, "%s", postojeci_kljuc);
    printf("Unesite kljuc:(%s)\n", postojeci_kljuc);
    do
    {
        if(i!=1)
            printf("Unijeli ste pogresan kljuc. Molimo Vas da unesete ponovo.\n");
        scanf("%s",uneseni_kljuc);
        i++;
    }
    while((strcmp(postojeci_kljuc, uneseni_kljuc))!=0);
    fclose(fp);
    return 1;
}
int otkljucavanje(int broj_igre)
{

    FILE *fp;
    if(broj_igre==1)
    {
        fp=fopen("kljucevi7d.txt", "r");
        if(provjera_kljuca("kljucevi7d.txt"))
            printf("Unijeli ste validan kljuc.\n");
        fclose(fp);
        Sleep(1000);
        system("cls");
        upisi_vrijeme("trajanje_kljuca1.txt",1);


    }
    else if(broj_igre==2)
    {

        fp=fopen("kljucevi1d.txt", "r");
        if(provjera_kljuca("kljucevi1d.txt"))
            printf("Unijeli ste validan kljuc.");
        fclose(fp);
        Sleep(1000);
        system("cls");
        upisi_vrijeme("trajanje_kljuca2.txt",2);

    }
    else if(broj_igre==3)
    {
        fp=fopen("kljucevi1s.txt", "r");
        if(provjera_kljuca("kljucevi1s.txt"))
            printf("Unijeli ste validan kljuc.");
        fclose(fp);
        Sleep(1000);
        system("cls");
        upisi_vrijeme("trajanje_kljuca3.txt",3);

    }
    else
    {
        fp=fopen("kljucevi7d.txt", "r");
        if(provjera_kljuca("kljucevineograniceno.txt"))
            printf("Unijeli ste validan kljuc.");
        fclose(fp);
        Sleep(1000);
        system("cls");
        upisi_vrijeme("trajanje_kljuca4.txt",4);

    }
}
void pamtiBodove(int ukupnoBodovi)
{
    FILE *fp;
    fp=fopen("bodovi.txt","w");
    char s[20];
    itoa(ukupnoBodovi,s,10);
    if(fp)
    {
        fprintf(fp,"%s",s);
        fclose(fp);
        //return 1;
    }
    else
    {
        printf("Datoteka nije uspjesno otvorena !\n");
        //return 0;
    }
}
