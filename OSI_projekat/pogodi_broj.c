#include "pogodi_broj.h"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int pretrazivanje_pokusaja(int niz[], int kljuc)  // Pretrazuje da li smo 2x unijeli isti broj
{
    int i;
    for( i=0; i<5; i++)
    {
        if(niz[i] == kljuc)
            return 1;
    }
    return 0;
}

int generator()    // Generise slucajan broj u intervalu od 0 do 100
{
    srand(time(0));
    int r = (rand() % 100)+1;
    return r;
}

int brojac_pokusaja(int niz[])    // Broji koliko smo puta pokusali pogoditi zamisljeni broj
{
    int i;
    int p = 0;
    for( i=0; i<5; i++)
    {
        if(niz[i] == p)
            return i+1;
    }
    return 0;
}

int brojac_bodova(int pokusaj)     // Broji bodove
{
    return 100/pokusaj;
}

/*void ispisi()
{
    printf("=======================================================================================================================\n");
}*/

int rezim1()  // Rezim koji radi u slucaju da igrac ne ulazi prvi put u igru
{
    int suma_bodova = 0;
    int niz_pokusaja[6],i,k;
    printf("Pogodite zamisljeni broj u intervalu od 0 do 100: \n");
    int p = generator();
    int broj;
    for( i=0; i<5; i++)
    {
        do
        {
            printf("%d. pokusaj: ", i+1);
            broj=ucitaj_karakter();
            if(broj!=-1)
            {
                if(pretrazivanje_pokusaja(niz_pokusaja, broj))
                    printf("Broj je vec unesen, ponovite pokusaj. \n");
            }
            else
                printf("Pogresan unos, pokusajte ponovo! \n");

        }
        while(broj < 0 || broj > 100 || pretrazivanje_pokusaja(niz_pokusaja, broj));
        niz_pokusaja[i] = broj;
        if(broj == p)
        {
            suma_bodova += 100/(i+1);
            printf("Cestitamo, osvojili ste %d bodova!\n", 100/(i+1));
            goto jump;
        }
        if(i == 4)
            printf("Zao nam je, pogrijesili ste, zamisljeni broj je %d! \n", p);
        else
        {
            if(p > broj)
                printf("Zamisljeni broj je veci od unesenog! \n");
            else
                printf("Zamisljeni broj je manji od unesenog! \n");
        }
    }
jump:
    dodajStatistika("1", suma_bodova);
    return suma_bodova;
}

int rezim0()   // Rezim koji radi ako je igrac prvi put u igri i omogucava mu da osvoji 300 bodova za prva 3 pogadjanja broja
{
    int broj,n,k,t,k1;
    int suma_bodova = 0;
    char c[20];
    srand(time(NULL));
    printf("Pogodite zamisljeni broj u intervalu od 0 do 100: \n");
    do
    {
        n=rand()%2;
    }
    while(n==0);
    if(n==1)
    {
        do
        {
            printf("1. pokusaj: ");
            broj=ucitaj_karakter();
            if(broj==-1)
                printf("Pogresan unos, pokusajte ponovo! \n");
            else
            {
                printf("Cestitamo, osvojili ste 100 bodova !\n");
                suma_bodova+=100;
            }
        }
        while(broj < 0 || broj > 100);
    }
    else if(n==2)
    {
        do
        {
            printf("1. pokusaj: ");
            scanf("%s",c);
            k=ispravnostBroja100(c);
            t=atoi(c);
            if(t==100)
            {
                printf("Zamisljeni broj je manji od unesenog !\n");
                goto jump;
            }
            else if(t==0)
            {
                printf("Zamisljeni broj je veci od unesenog !\n");
                goto jump;
            }
            else if(t!=100 && t!=0)
            {
                printf("Zamisljeni broj je veci od unesenog! \n");
jump:
                printf("2. pokusaj: ");
                scanf("%s",c);
                k1=ispravnostBroja100(c);
                if(k1==1)
                {
                    printf("Cestitamo, osvojili ste 50 bodova !\n");
                    suma_bodova+=50;
                }
            }

        }
        while(k==0 && k1==0);
    }
    dodajStatistika("1", suma_bodova);
    return suma_bodova;
}

void naslov()
{
    ispisi();
    printf(ANSI_COLOR_CYAN "                                               POGODI ZAMISLJENI BROJ\n"ANSI_COLOR_RESET);
    ispisi();
    printf("\n");
}
int igranje()     // Glavna funkcija koja se poziva u mainu
{
    int rezim = 0, p = 1, br_igranja = 0,br_bodova=0;
    char enter,c;
    scanf("%c",&c);
    while(p)
    {
        if(rezim == 0)
        {
            br_bodova += rezim0();
            br_igranja++;

        }
        else
        {
            br_bodova += rezim1();

        }
        do
        {
            printf("Da li zelite ponovo da igrate? (1/0) \n");
            scanf("%d", &p);
            if(p<0 || p>1)
                printf("Pogresan unos, mozete unijeti samo 1 ili 0 !\n");
        }
        while(p<0 || p>1);
        scanf("%c",&enter);
        if(br_igranja >= 3)
            rezim = 1;
        else
            rezim = 0;
    }
    return br_bodova;
}
int ucitaj_karakter() // Provjerava da li je to sto se unosi broj (odnosno da nije neki karakter koji nije broj)
{
    int i,i1,i2,i3,j;
    char *c;
    c=(char *)calloc(512,sizeof(char));

    fgets(c,512,stdin);
    if (c[0]<48 || c[0]>57 || c[0]=='\n')
    {
        return -1;
    }
    else
    {
        i1=c[0]-48;
    }
    if(c[1]=='\n' || c[2]=='\0')
    {
        i=i1;
        return i;
    }
    else if (c[1]<48 || c[1]>57)
    {
        return -1;
    }

    else
    {
        i2=c[1]-48;
    }
    if(c[2]=='\n' || c[2]=='\0')
    {
        i=i1*10+i2;
        return i;
    }
    else if (c[2]<48 || c[2]>57)
    {
        return -1;
    }

    else
    {
        i3=c[2]-48;
    }
    for(j = 3; j<512; j++)
        if (c[j]!= '\n' && c[j] != '\0')
        {
            return -1;
        }
    i=100*i1+i2*10+i3;
    if(i>100)
    {
        return -1;
    }
    return i;
}
