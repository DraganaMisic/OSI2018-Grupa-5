#include "loto.h"

int *unos()     //funkcija za unos 7 brojeva
{

    okvir();
    int n=0,k,m=0;
    int *niz=(int *)calloc(7, sizeof(int));  //alociranje niza za smjestanje unesenih brojeva
    printf(" UNESITE 7 ZELJENIH BROJEVA U OPSEGU OD 1 DO 45:\n\n");
    do
    {
        int i,l=1,slovo=0;
        char c[100];
        printf(" %d. broj:",n+1);
        scanf("%s",&c);
        if(strlen(c)>=2)//provjera da li je upisan broj pa slovo
        {
            if(strlen(c)==2)
            if(isdigit(c[1]))
                slovo=1;
            else{
            if(isdigit(c[2])){
                printf("test\n");
                slovo=1;}
            else slovo=0;}
        }
        if(strlen(c)==1)//u slucaju da je unesen jednocifren broj, slovo se postavlja na 1 kako bi se omogucio sljedeci uslov, inace program javlja da je bilo koji jednocifren broj van opsega
        {
            slovo=1;
        }
        k=atoi(c);
        if((k>0 && k<=45)&&(slovo==1))    //provjera da li je broj u opsegu
        {
            for( i=0; i<n; i++)
                if(niz[i]==k)   //provjera da li broj vec postoji
                {
                    printf("Taj broj ste vec unijeli.\n");
                    Sleep(1000);
                    m=1;
                }
            if(m==0)
                niz[n++]=k;   //dodavanje elementa u niz
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
        sortiranje(niz,n);  //sortiranje unesenih brojeve
        ispis_niza(niz,n);  //ispisuje brojeve koji su uneseni
    }
    while(n<=6);
    return niz;
}
void okvir()    //funkcija koja crta okvir
{
    printf("========================================================================================================================");
    printf("                                                       LOTO\n");
    printf("========================================================================================================================\n");
    printf("\n");
}
void ispis_niza(int *niz,int n)     //funkcija koja ispisuje niz
{
    int i;
    for( i=0; i<n; i++)
    {
        printf(" |%2d| ",niz[i]);

    }
    printf("\n\n");

}
int *generisanje_brojeva()      //funkcija koja generise 20 brojeva
{
    int i;
    srand(time(NULL));
    int *niz=(int*)calloc(20,sizeof(int));
    int n=0,br,k=0;
    do
    {
        br=rand()%44+1;    //izvlacenje nasumicnih brojeva
        for( i=0; i<n; i++)
            if(br==niz[i])   //provjera da li broj vec postoji
                k=1;
        if(k==0)
        {
            niz[n++]=br;     //smjestanje broja u niz
        }
        k=0;
    }
    while(n<20);
    return niz;
}
int izvlacenje(int *niz1,int *niz2)     //funkcija koja ispisuje na standardni izlaz i izracunava bodove
{
    int i,j;
    int br=0,k=10,bodovi=0,brojac=0;
    for( i=0; i<20; i++)
    {
        brojac++;
        ispis1(niz1,niz2,brojac-1,niz2[i],bodovi);      //ispis unesenih brojeva, izvucenih brojeva i ostvarenih bodova
        Sleep(2000);
        for( j=0; j<7; j++)
            if(niz2[i]==niz1[j])
            {
                br++;
                bodovi+=br*k;             //racunanje bodova
                ispis2(niz1,niz2,brojac-1,niz2[i],br*k,bodovi);     //ispis kada se pogodi broj
                Sleep(2000);
            }
    }
    ispis3(niz1,niz2,brojac,niz2[i],bodovi);    //zavrsni ispis
    free(niz1);
    free(niz2);
    return bodovi;
}
void ispis2(int*niz1,int*niz2,int brojac,int broj,int bodovi,int ukupno_bodova)     //funkcija za ispis kada je broj pogodjen
{
    int a=7;
    system("cls");
    okvir();
    printf("Uneseni brojevi: ");
    ispis_niza(niz1,a);     //ispis unesenih brojeva
    printf("\n\n\n\n");
    printf("Izvuceni broj je: |%2d| ",broj);
    printf("POGODAK!!!\n");
    printf("Broj dobijenih bodova je %d !!!",bodovi);
    printf("\n\n\n\n");
    printf("Izvuceni brojevi: \n");
    ispis_niza(niz2,brojac);    //ispis izvucenih brojeva
    printf("\n\n\n");
    printf("U ovoj igri imate trenutno %d bodova\n",ukupno_bodova);
}
void ispis1(int *niz1,int *niz2,int brojac,int broj,int bodovi)     //funkcija za standardni ispis dok se brojevi izvlace
{
    int a=7;
    system("cls");
    okvir();
    printf("Uneseni brojevi: ");
    ispis_niza(niz1,a);     //ispis unesenih brojeva
    printf("\n\n\n\n");
    printf("Izvuceni broj je: |%2d| ",broj);
    printf("\n\n\n\n\n");
    printf("Izvuceni brojevi: \n");
    ispis_niza(niz2,brojac);    //ispis izvucenih brojeva
    printf("\n\n\n");
    printf("U ovoj igri imate trenutno %d bodova !\n",bodovi);
}
void ispis3(int *niz1,int *niz2,int brojac,int broj,int bodovi)     //funkcija koja ispisuje sve na kraju
{
    int a=7;
    system("cls");
    okvir();
    printf("Uneseni brojevi: ");
    ispis_niza(niz1,a);     //ispis unesenih brojeva
    printf("\n\n\n\n");
    printf("Izvuceni brojevi: \n");
    ispis_niza(niz2,brojac);     //ispis izvucenih brojeva
    printf("\n\n\n\n");
    printf("Pogodjeni brojevi: ");
    ispis_pogodjenih_brojeva(niz1,niz2);
    printf("\n\n\n\n");
    printf("U ovoj igri ste osvojili %d bodova !\n",bodovi);
}

void ispis_pogodjenih_brojeva(int *niz1,int*niz2)      //funkcija koja ispisuje pogodjene brojeve
{
    for(int i=0; niz1[i]; i++)
        for(int j=0; niz2[j]; j++)
            if(niz1[i]==niz2[j])
                printf("|%2d|  ",niz1[i]);
}
void sortiranje(int*niz,int n)      //funkcija za sortiranje niza
{
  int i, j;
  for (i=0; i<n-1; i++)
  {
    for (j=0; j<n-i-1; j++)
      if (niz[j]>niz[j+1])
      {
         int pom=niz[j];
         niz[j]=niz[j+1];
         niz[j+1]=pom;
      }
  }

}
