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

int otkljucavanje()
{
    FILE *fp,*fp1,*fp2,*fp3;
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
    fp=fopen("kljucevineograniceno.txt","w");
    if(fp)
    {
        fprintf(fp,"%s-%s-%s-%s",&s1,&s2,&s3,&s4);
        fclose(fp);
    }
    fp1=fopen("kljucevi1h.txt","w");
    if(fp1)
    {
        fprintf(fp1,"%s-%s-%s-%s",&s5,&s6,&s7,&s8);
        fclose(fp1);
    }
    fp2=fopen("kljucevi1d.txt","w");
    if(fp2)
    {
        fprintf(fp2,"%s-%s-%s-%s",&s9,&s10,&s11,&s12);
        fclose(fp2);
    }
    fp3=fopen("kljucevi7d.txt","w");
    if(fp3)
    {
        fprintf(fp3,"%s-%s-%s-%s",&s13,&s14,&s15,&s16);
        fclose(fp3);
    }
    printf("Unesite kljuc u formatu XXXX-XXXX-XXXX-XXXX\n");
    scanf("%s",&c);
    fp=fopen("kljucevineograniceno.txt","r");
    fp1=fopen("kljucevi1h.txt","r");
    fp2=fopen("kljucevi1d.txt","r");
    fp3=fopen("kljucevi7d.txt","r");
    if(fp && fp1 && fp2 && fp3)
    {
        fscanf(fp,"%s",x);
        t=strcmp(c,x);
        fscanf(fp1,"%s",x);
        int t1=strcmp(c,x);
        fscanf(fp2,"%s",x);
        int t2=strcmp(c,x);
        fscanf(fp3,"%s",x);
        int t3=strcmp(c,x);
        if(t==0)
        {
            printf("Kljuc je validan, igra je otkljucana neograniceno ! Srecno !\n");
            Sleep(2500);
            system("cls");
            return 1;
        }
        else if(t1==0)
        {
            printf("Kljuc je validan, igra je otkljucana na 1 sat ! Srecno !\n");
            Sleep(2500);
            system("cls");
            return 1;
        }
        else if(t2==0)
        {
            printf("Kljuc je validan, igra je otkljucana na 1 dan ! Srecno !\n");
            Sleep(2500);
            system("cls");
            return 1;
        }
        else if(t3==0)
        {
            printf("Kljuc je validan, igra je otkljucana na 7 dana ! Srecno !\n");
            Sleep(2500);
            system("cls");
            return 1;
        }
        else
        {
            printf("Kljuc nije validan, novi kljuc je generisan, vraceni ste u glavni meni !\n");
            Sleep(3500);
            system("cls");
            fclose(fp);

            return 0;
        }
    }
    else
        printf("Greska prilikom otvaranja datoteke !");
    fclose(fp);
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


