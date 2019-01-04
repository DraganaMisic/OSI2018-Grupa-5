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
    else return 1;
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
