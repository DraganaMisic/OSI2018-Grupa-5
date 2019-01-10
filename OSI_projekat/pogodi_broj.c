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

int generator1() //Generise slucajan broj u intervalu od 0 do 5
{
    srand(time(0));
    int r = (rand() % 5)+1;
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
    int niz_pokusaja[6]= {150,150,150,150,150,150},i,k;
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

int rezim0()  // Rezim koji radi u slucaju da igrac ulazi prvi put u igru
{
    int suma_bodova = 0;
    int niz_pokusaja[6]= {150,150,150,150,150,150},i,k;
    printf("Pogodite zamisljeni broj u intervalu od 0 do 100: \n");
    int p = generator();
    int broj, broj_prethodni;
    int nizPomoc[3];
    int pogodjeno = 0;
    for( i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
            nizPomoc[j] = generator1();
        do
        {
            printf("%d. pokusaj: ", i+1);
            broj_prethodni = broj;
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
        if(broj == p || nizPomoc[0] == i || nizPomoc[1] == i || nizPomoc[2] == i)
        {
            if(broj_prethodni > p && broj > p)
            {
                if(i == 4)
                    goto here3;
                goto here1;
            }
            if(broj_prethodni < p && broj < p){
                    if(i == 4)
                    goto here3;
                goto here2;
            }
            suma_bodova += 100/(i+1);
            pogodjeno++;
            printf("Cestitamo, osvojili ste %d bodova!\n", 100/(i+1));
            goto jump;
        }
        if(pogodjeno < 3 && i >= 2)
        {
            if(broj_prethodni > p && broj > p)
            {
                if(i == 4)
                    goto here3;
                goto here1;
            }
            if(broj_prethodni < p && broj < p)
            {
                if(i == 4)
                    goto here3;
                goto here2;
            }
            suma_bodova += 100/(i+1);
            pogodjeno++;
            printf("Cestitamo, osvojili ste %d bodova!\n", 100/(i+1));
            goto jump;
        }
        if(i == 4){
                here3:
            printf("Zao nam je, pogrijesili ste, zamisljeni broj je %d! \n", p);
        }
        else
        {
            if(p > broj)
{
    here2:
                printf("Zamisljeni broj je veci od unesenog! \n");
}
            else
{
    here1:
                printf("Zamisljeni broj je manji od unesenog! \n");
}
        }
    }
jump:
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
int igranje()     // Glavna funkcija koja se poziva u PlayGround funkciji
{
    int rezim, p, br_igranja = 0,br_bodova=0,x=1,t;
    char enter,c,m1;
    FILE *fp,*fp1;
    char m[20]="1";
    p=atoi(m);

    scanf("%c",&c);
    while(p)
    {
        fp1=fopen("pamcenjerezima.txt","r");
        fscanf(fp1,"%d",&br_igranja);
        fclose(fp1);
        fp=fopen("rezim.txt","r");
        if(fp)
        {
            rezim=1;
            fclose(fp);
        }
        else
        {
            rezim=0;
        }
        if(rezim == 0)
        {
            br_bodova += rezim0();
            br_igranja++;
            fp1=fopen("pamcenjerezima.txt","w");
            fprintf(fp1,"%d",br_igranja);
            fclose(fp1);

        }
        else
        {
            br_bodova += rezim1();

        }
        do
        {

            printf("Da li zelite ponovo da igrate ovu igru? \n");
            printf("1 - Da\n");
            printf("2 - Ne\n");
            scanf("%s", m);
            p=atoi(m);
            if(p<1 || p>2)
                printf("Pogresan unos, mozete unijeti samo 1 ili 2 !\n");
        }
        while(p<1 || p>2);
        if(p==2)
            p=0;
        scanf("%c",&enter);

        if(br_igranja == 3)
        {
            fp=fopen("rezim.txt","w");
            if(fp)
                fclose(fp);
        }
        if(br_igranja>=3)
            rezim=1;
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
