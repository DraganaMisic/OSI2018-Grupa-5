#include "kviz.h"

void naslovKviz()
{
    printf("=======================================================================================================================\n");
    printf("                                            <<<     K V I Z       >>>\n");
    printf("=======================================================================================================================\n");
}

int pretragaPitanja(int niz[],int kljuc)
{
    int i;
    for (i=0;i<5;i++)
        if (niz[i]==kljuc) return 1;
    return 0;
}
int kontrolaBodova()
{
    if (izgubljeniBodovi>osvojeniBodovi+0.4*osvojeniBodovi) return 1;
    else return 0;
}
void pitaj()
{
  FILE *fp;
  time_t t; //za random broj
  srand((unsigned) time(&t)); //za random broj
  int brPitanja,rezim,x;
  static int lagana[5]={0},teska[5]={0},brLaganih=0,brTeskih=0; //potrebno jer broj pitanja nije isti u obe datoteke
  if (kontrolaBodova())
  {
      fp=fopen("laganapitanja.txt","r");
      brPitanja=100;  //broj pitanja u ovoj datoteci
      rezim=1;
  }

    else
    {
        fp=fopen("teskapitanja.txt","r");
        rezim=0;
        brPitanja=90;                   //broj pitanja u ovoj datoteci
    }

    if (fp  != NULL)
    {
           if (rezim==1)
    {
        do
        {
           x=rand()%brPitanja+1;
        }while(pretragaPitanja(lagana,x));
        lagana[brLaganih++]=x;
    }
    else
    {
        do
        {
           x=rand()%brPitanja+1;
        }while(pretragaPitanja(teska,x));
        teska[brTeskih++]=x;

    }    //za random broj
        int broj;
        char s1[100],s2[100],s3[100],s4[100],odgovor[100],tacan[100];
      while (fscanf(fp,"%d.%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%s\n",&broj,s1,s2,s3,s4,tacan) != EOF) //formatirano citanje iz datoteke
        {
           if (broj==x) //provjera rednog broja pitanja, tj da li je broj pronadjen u datoteci jednak random broju
           {
               printf("%s\n",s1);
               printf(" 1. %s\n",s2);
               printf(" 2. %s\n",s3);
               printf(" 3. %s\n",s4);

                do //kontrola unosa
                {
                    printf("\nVas odgovor je: (unesite redni broj odgovora)\n");
                    Sleep(2000);
                    scanf("%s",odgovor);
                }while(atoi(odgovor)<1 || atoi(odgovor)>3);

               if (!strcmp(tacan,odgovor)) //poredjenje tacnog i odgovora koji je dao korisnik
               {
                   printf("Tacan odgovor! Osvojili ste 20 bodova!\n\n");
                   Sleep(2000);
                   tacniOdgovori++;
                   osvojeniBodovi+=20;
                   bodoviDrugaIgra+=20;
               }
               else
               {
                   printf("Netacan odgovor! Izgubili ste 30 bodova!\n\n");
                   Sleep(2000);
                   izgubljeniBodovi+=30;
                   bodoviDrugaIgra-=30;
               }

           }
        }
      fclose(fp);
    }else printf("Greska prilikom otvaranja datoteke!");
}

void drugaIgra()
{
    bodoviDrugaIgra=0;
    tacniOdgovori=0;
    system("cls");
    naslovKviz();
    printf("\n Broj bodova: %d",bodoviDrugaIgra); //treba promijeniti( trebaju ukupni bodovi)
    printf("\n\n");
    int i;
    for (i=0;i<5;i++)
    {
        system("cls");
        naslovKviz();
        printf("\n Broj bodova: %d",bodoviDrugaIgra);
        printf("\n\n");
        printf(" PITANJE BROJ %d:\n\n",i+1);
        pitaj();
    }
    system("cls");
    naslovKviz();
    if (tacniOdgovori==5)
    {
        printf("Cestitamo! Tacno ste odgovori na svih 5 pitanja! Osvojili se dodatnih 50 bodova!\n");
        osvojeniBodovi+=50;
        bodoviDrugaIgra+=50;
    }
    printf("\n Broj bodova: %d",bodoviDrugaIgra);
    if (bodoviDrugaIgra<0) printf("\nU ovoj igri ste izgubili %d bodova!",bodoviDrugaIgra);
    else printf("\nU ovoj igri ste dobili %d bodova!",bodoviDrugaIgra);
}



