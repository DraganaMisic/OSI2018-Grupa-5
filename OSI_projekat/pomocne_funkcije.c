#include "pomocne_funkcije.h"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
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
    if(n[0]>='1' && n[0]<='5')
        return 1;
    else
    {
        printf("Pogresan unos, unesite ponovo !");
        return 0;
    }
}
int ispravnostBroja4(char *n)
{
    if (n[1]!='\0')
    {
        printf("Pogresan unos, unesite ponovo !");
        return 0;
    }
    if(n[0]>='1' && n[0]<='4')
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
//funkcija za generisanje i smjestanje kljuceva u datoteke za sve 4 igre
void generisanje_kljuceva(FILE *kljuc1, FILE *kljuc2, FILE *kljuc3, FILE *kljuc4)
{

    char c[120],x[120];
    int t;
    char s1[120],s2[120],s3[120],s4[120],s5[120],s6[120],s7[120],s8[120];
    char s9[120],s10[120],s11[120],s12[120],s13[120],s14[120],s15[120],s16[120];
    int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16;
    srand(time(NULL));
    //generisanje 4 broja
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
    //pretvaranje brojeva u string
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
    //upisivanje kljuca u odgovarajucem formatu
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
//funkcija za upis vremena kada je otkljucana igra
void upisi_vrijeme(char *naziv_datoteke, int i)
{
    FILE *fp;
    fp=fopen(naziv_datoteke, "w"); //otvaranje datoteke za odgovarajucu igru
    //pretvaranje vremena u string
    time_t t = time(NULL);
    struct tm *ptm = localtime(&t);
    char buf[256];
    strftime(buf, sizeof(buf), "%d.%m.%Y  %H:%M:%S", ptm);
    fprintf(fp, "%s", buf); //upisivanje u datoteku
    fclose(fp);

}
//provjera da li je korisnik unio ispravan kljuc
int provjera_kljuca(char *naziv_datoteke)
{
    FILE *fp;
    fp=fopen(naziv_datoteke, "r"); //otvaranje datoteke u kojoj se nalazi kljuc
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
    while((strcmp(postojeci_kljuc, uneseni_kljuc))!=0); //ponavljanje unosa dok nije pravilan
    fclose(fp);
    return 1;
}
int otkljucavanje(int broj_igre)
{

    FILE *fp;
    if(broj_igre==1) //otkljucavanje prve igre
    {
        fp=fopen("kljucevi7d.txt", "r");
        if(provjera_kljuca("kljucevi7d.txt"))
            printf("Unijeli ste validan kljuc. Igra je otkljucana na 7 dana.\n");
        fclose(fp);
        Sleep(2000);
        system("cls");
        upisi_vrijeme("trajanje_kljuca1.txt",1);


    }
    else if(broj_igre==2) //otkljucavanje druge igre
    {

        fp=fopen("kljucevi1d.txt", "r");
        if(provjera_kljuca("kljucevi1d.txt"))
            printf("Unijeli ste validan kljuc. Igra je otkljucana na 1 dan.");
        fclose(fp);
        Sleep(2000);
        system("cls");
        upisi_vrijeme("trajanje_kljuca2.txt",2);

    }
    else if(broj_igre==3)  //otkljucavanje trece igre
    {
        fp=fopen("kljucevi1s.txt", "r");
        if(provjera_kljuca("kljucevi1s.txt"))
            printf("Unijeli ste validan kljuc. Igra je otkljucana na 1 sat.");
        fclose(fp);
        Sleep(2000);
        system("cls");
        upisi_vrijeme("trajanje_kljuca3.txt",3);

    }
    else  //otkljucavanje cetvrte igre
    {
        fp=fopen("kljucevineograniceno.txt", "r");
        if(provjera_kljuca("kljucevineograniceno.txt"))
            printf("Unijeli ste validan kljuc. Igra je otkljucana na neogranicen period.");
        fclose(fp);
        Sleep(2000);
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
long long razlika_vremena(char *buf1,char *buf2)    //funkcija koja izracunava razliku izmedju dva vremena u sekundama
{
    char prvo[6][5],drugo[6][5];
    int j=0,k=0;
    for(int i=0; i<20; i++) //u ovoj petlji se string dijeli na manje stringove koij predstavljaju dan, mjesec, godinu, sat, minut i sekund
    {

        if(buf1[i]=='.' || (buf1[i]==' ' && buf1[i+1]==' ') || buf1[i]==':')
        {
            prvo[j][k]=drugo[j][k]='\0';
            j++;
            k=0;
        }
        else if(buf1[i]==' ')
        {
            k=0;
        }
        else
        {
            prvo[j][k]=buf1[i];
            drugo[j][k++]=buf2[i];
        }
    }
    //dodjeljivanje stringova koji predstavljaju vrijeme sttrukturi tm
    struct tm prvo_vrijeme= {0},drugo_vrijeme= {0};
    prvo_vrijeme.tm_mday=atoi(prvo[0]);
    prvo_vrijeme.tm_mon=atoi(prvo[1]);
    prvo_vrijeme.tm_year=atoi(prvo[2])-1900;
    prvo_vrijeme.tm_hour=atoi(prvo[3]);
    prvo_vrijeme.tm_min=atoi(prvo[4]);
    prvo_vrijeme.tm_sec=atoi(prvo[5]);
    drugo_vrijeme.tm_mday=atoi(drugo[0]);
    drugo_vrijeme.tm_mon=atoi(drugo[1]);
    drugo_vrijeme.tm_year=atoi(drugo[2])-1900;
    drugo_vrijeme.tm_hour=atoi(drugo[3]);
    drugo_vrijeme.tm_min=atoi(drugo[4]);
    drugo_vrijeme.tm_sec=atoi(drugo[5]);
    long long c;
    c=difftime(mktime(&prvo_vrijeme),mktime(&drugo_vrijeme));   //racuna razliku izmedju dva vremena u sekundama
    return c;
}
//funkcija za brisanje datoteka prije registrovanja novog korisnika
void brisi_datoteke()
{
    remove("kljucevi1d.txt");
    remove("kljucevi1s.txt");
    remove("kljucevi7d.txt");
    remove("kljucevineograniceno.txt");
    remove("trajanje_kljuca1.txt");
    remove("trajanje_kljuca2.txt");
    remove("trajanje_kljuca3.txt");
    remove("trajanje_kljuca4.txt");
    remove("statistika1.txt");
    remove("statistika2.txt");
    remove("statistika3.txt");
    remove("statistika4.txt");
    remove("rezim.txt");
    remove("csv1.csv");
    remove("csv2.csv");
    remove("csv3.csv");
    remove("csv4.csv");
    remove("otkazana1.txt");
      remove("otkazana2.txt");
        remove("otkazana3.txt");
          remove("otkazana4.txt");
          remove("otkljucane_igre.txt");
          remove("pamcenjerezima.txt");
}
void ispis_za_istek_kljuca()
{
    printf("\nTrajanje kljuca za ovu igru je isteklo!");
    Sleep(2000);
    system("cls");
}
//ispis za otkazivanje
void otkazivanje_igre(char *naziv_datoteke)
{
    FILE *fp;
    fp=fopen(naziv_datoteke, "w");   //datoteka za pamcenje da je igra otkazana
    fclose(fp);
    printf("Otkazali ste igru, vas kljuc je ponisten\n");
    Sleep(2500);
    system("cls");
}
void prviIspis(int ukupnoBodovi)
{
    naslovPlayGround();
    printf("\n");
    printf("Bodovi: %d\n\n",ukupnoBodovi);
    printf("          IGRE\n\n");
    printf("1. Pogodi zamisljeni broj\n");
    printf("2. Kviz\n");
    printf("3. Loto (ulog 100 bodova)\n");
    printf("4. Brzo kucanje\n\n");

}

void zadnjiIspis(int ukupnoBodovi)
{
    printf("KONACNI BROJ BODOVA: %d\n",ukupnoBodovi);
}
void naslovPlayGround()
{

    printf("=======================================================================================================================\n");
    printf(ANSI_COLOR_CYAN"                                            <<< P L A Y G R O U N D >>>\n"ANSI_COLOR_RESET);
    printf("=======================================================================================================================\n");
}
