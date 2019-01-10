#include "meni.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
void ispis_opcija() //ispis opcija koje se prikazu nakon pregleda statistike ili cuvanja u csv
{

    printf("\n");
    printf("Unesite opciju koju zelite !\n");
    printf("1 - Povratak nazad\n");
    printf("2 - Povratak na meni za izbor igre\n");
}

int meni2(int broj_igre,char *naziv_datoteke)  // meni koji se prikazuje ukoliko je igra otkljucana

{

    int p;
    char n[20];
    printf("Izaberite opciju koju zelite ! \n");
    printf("1. Igranje igre\n");
    printf("2. Otkazivanje igre\n");
    printf("3. Pregled statistike\n");
    printf("4. Cuvanje rezultata u CSV fajl\n");
    printf("5. Povratak na meni za izbor igre\n");
    do
    {
        scanf("%s",n);
        p=ispravnostBroja(n); // provjerava da li smo unijeli nesto sto je van opsega ili neki drugi karakter
    }
    while(p==0);
    p=atoi(n);
    if(p==1)     //petlja u slucaju izbora Igranje igre iz menija
    {

        FILE *fp=fopen(naziv_datoteke,"r");    //otvaranje datoteke sa upisanim vremenom otkljucavanja igre
        char staro_vrijeme[256]= {0},novo_vrijeme[256]= {0};
        fgets(staro_vrijeme,256,fp);    //uzimanje vremena iz datoteke
        //dobijanje trenutnog vremena
        time_t t = time(NULL);
        struct tm *ptm = localtime(&t);
        strftime(novo_vrijeme, sizeof(novo_vrijeme), "%d.%m.%Y  %H:%M:%S", ptm);
        long long proteklo_vrijeme=razlika_vremena(novo_vrijeme,staro_vrijeme); //racunanje razlike sadasnjeg
        //i vremena otkljucavanja u sekundama
        if(broj_igre==1)
            if(proteklo_vrijeme>7*24*3600)   //provjera da li je kljuc istekao
            {
                ispis_za_istek_kljuca();    //ispis odgovarajuce poruke
                return 1;                       //radi na istom principu za ostale 3 igre
            }
            else
                return 2;
        else if(broj_igre==2)
            if(proteklo_vrijeme>24*3600)
            {
                ispis_za_istek_kljuca();
                return 1;
            }
            else
                return 2;
        else if(broj_igre==3)
            if(proteklo_vrijeme>3600)
            {
                ispis_za_istek_kljuca();
                return 1;
            }
            else
                return 2;
        else if(broj_igre==4)
            return 2;
        system("cls");
    }
    else if(p==2)    //opcija u slucaju izbora Otkazivanje igre iz menija
    {
        system("cls");
        //ispiivanje odgovarajucih naslova
        if(broj_igre==1)
            naslov();
        else if(broj_igre==2)
            naslovKviz();
        else if(broj_igre==3)
            okvir();
        else if(broj_igre==4)
            naslovBrzoKucanje();
        printf("Da li ste sigurni da zelite otkazati igru, vise joj necete moci pristupiti !\n"); //potvrdjivanje izbora
        printf("1 - Da\n");
        printf("2 - Ne\n");
        printf("Unesite vas izbor:");
        char izbor[20];
        int o;
        do
        {
            scanf("%s",izbor);
            o=ispravnostBroja2(izbor); //provjera da li je korektan unos
        }
        while(o==0);
        o=atoi(izbor);
        if(o==1)
        {
            FILE *fp;
            //otkazivanje za svaku igru pojedinacno
            if(broj_igre==1)
            {
                otkazivanje_igre("otkazana1.txt");
                return 1;
            }
            if(broj_igre==2)
            {
                otkazivanje_igre("otkazana2.txt");
                return 1;
            }
            if(broj_igre==3)
            {
                otkazivanje_igre("otkazana3.txt");
                return 1;
            }
            if(broj_igre==4)
            {
                otkazivanje_igre("otkazana4.txt");
                return 1;
            }
        }
        else
        {
            system("cls");
            return 1;
        }
    }

    else if(p==3)  //opcija u slucaju izbora Pregled Statistike
    {
        //petlje za svaku igru pojedinacno
        if(broj_igre==1)
        {
            system("cls");
            naslov();
            prikazStatistike("1");
            char c1[20];
            int p1;
            ispis_opcija();
            do
            {

                scanf("%s",c1);
                p1=ispravnostBroja2(c1);
            }
            while(p1==0);
            p1=atoi(c1);
            if(p1==1)
            {
                system("cls");
                return 0;
            }
            else if(p1==2)
            {
                system("cls");
                return 1;
            }
        }
        else if(broj_igre==2)
        {
            system("cls");
            naslovKviz();
            prikazStatistike("2");
            char c2[20];
            int p2;
            ispis_opcija();
            do
            {

                scanf("%s",c2);
                p2=ispravnostBroja2(c2);
            }
            while(p2==0);
            p2=atoi(c2);
            if(p2==1)
            {
                system("cls");
                return 0;
            }
            else if(p2==2)
            {
                system("cls");
                return 1;
            }
        }
        else if(broj_igre==3)
        {
            system("cls");
            okvir();
            prikazStatistike("3");
            char c3[20];
            int p3;
            ispis_opcija();
            do
            {

                scanf("%s",c3);
                p3=ispravnostBroja2(c3);
            }
            while(p3==0);
            p3=atoi(c3);
            if(p3==1)
            {
                system("cls");
                return 0;
            }
            else if(p3==2)
            {
                system("cls");
                return 1;
            }
        }
        else if(broj_igre==4)
        {
            system("cls");
            naslovBrzoKucanje();
            prikazStatistike("4");
            char c4[20];
            int p4;
            ispis_opcija();
            do
            {

                scanf("%s",c4);
                p4=ispravnostBroja2(c4);
            }
            while(p4==0);
            p4=atoi(c4);
            if(p4==1)
            {
                system("cls");
                return 0;
            }
            else if(p4==2)
            {
                system("cls");
                return 1;
            }

        }
    }
    else if(p==4) //opcije u slucaju izbora Cuvanje u CSV fajl
    {
        //petlje za svaku igru pojedinacno
        if(broj_igre==1)
        {
            FILE *fp;
            fp=fopen("statistika1.txt","r");
            fclose(fp);
            system("cls");
            naslov();
            if(fp)
                printf("Uspjesno ste sacuvali statistiku u CSV fajl !");
            else printf("Nemate zabiljezenih rezultata, ne mozete ih sacuvati u CSV fajl !");
            char c5[20];
            int p5;
            do
            {
                ispis_opcija();
                scanf("%s",c5);
                p5=ispravnostBroja2(c5);
            }
            while(p5==0);
            p5=atoi(c5);
            if(p5==1)
            {
                system("cls");
                return 0;
            }
            else if(p5==2)
            {
                system("cls");
                return 1;
            }

        }
        else if(broj_igre==2)
        {
            FILE *fp1;
            fp1=fopen("statistika2.txt","r");
            fclose(fp1);
            system("cls");
            naslovKviz();
            if(fp1)
                printf("Uspjesno ste sacuvali statistiku u CSV fajl !");
            else printf("Nemate zabiljezenih rezultata, ne mozete ih sacuvati u CSV fajl !");
            char c6[20];
            int p6;
            do
            {
                ispis_opcija();
                scanf("%s",c6);
                p6=ispravnostBroja2(c6);
            }
            while(p6==0);
            p6=atoi(c6);
            if(p6==1)
            {
                system("cls");
                return 0;
            }
            else if(p6==2)
            {
                system("cls");
                return 1;
            }
        }
        else if(broj_igre==3)
        {
            FILE *fpp;
            fpp=fopen("statistika3.txt","r");
            fclose(fpp);
            system("cls");
            okvir();
            if(fpp)
                printf("Uspjesno ste sacuvali statistiku u CSV fajl !");
            else printf("Nemate zabiljezenih rezultata, ne mozete ih sacuvati u CSV fajl !");
            char c7[20];
            int p7;
            do
            {
                ispis_opcija();
                scanf("%s",c7);
                p7=ispravnostBroja2(c7);
            }
            while(p7==0);
            p7=atoi(c7);
            if(p7==1)
            {
                system("cls");
                return 0;
            }
            else if(p7==2)
            {
                system("cls");
                return 1;
            }
        }
        else if(broj_igre==4)
        {
            FILE *fp3;
            fp3=fopen("statistika4.txt","r");
            fclose(fp3);
            system("cls");
            naslovBrzoKucanje();
            if(fp3)
                printf("Uspjesno ste sacuvali statistiku u CSV fajl !");
            else printf("Nemate zabiljezenih rezultata, ne mozete ih sacuvati u CSV fajl !");
            char c8[20];
            int p8;
            do
            {
                ispis_opcija();
                scanf("%s",c8);
                p8=ispravnostBroja2(c8);
            }
            while(p8==0);
            p8=atoi(c8);
            if(p8==1)
            {
                system("cls");
                return 0;
            }
            else if(p8==2)
            {
                system("cls");
                return 1;
            }
        }
    }
    else if(p==5)  //opcije ako ste izabrali Nazad
    {
        system("cls");
        return 1;
    }
    system("cls");

}
//meni koji se pojavljuje prije otkljucavanja igre
int meni1(int broj_igre)
{

    int p;
    char n[20];
    printf("Izaberite opciju koju zelite !\n");
    printf("1. Unos kljuca\n");
    printf("2. Otkazivanje igre\n");
    printf("3. Pregled statistike\n");
    printf("4. Cuvanje rezultata u CSV fajl\n");
    printf("5. Povratak na meni za izbor igre\n");
    do
    {
        scanf("%s",n);
        p=ispravnostBroja(n);
    }
    while(p==0);
    p=atoi(n);

    if(p==1)  //opcije ako ste izabrali Unos kljuca
    {
        otkljucavanje(broj_igre);

    }
    else if(p==2) //opcije ako ste izabrali Otkazivanje igre
    {
        //funkcionise na isti nacin kao u meni1
        system("cls");
        if(broj_igre==1)
            naslov();
        else if(broj_igre==2)
            naslovKviz();
        else if(broj_igre==3)
            okvir();
        else if(broj_igre==4)
            naslovBrzoKucanje();
        printf("Da li ste sigurni da zelite otkazati igru, vise joj necete moci pristupiti !\n");
        printf("1 - Da\n");
        printf("2 - Ne\n");
        printf("Unesite vas izbor:");
        char izbor[20];
        int o;
        do
        {
            scanf("%s",izbor);
            o=ispravnostBroja2(izbor);
        }
        while(o==0);
        o=atoi(izbor);
        if(o==1)
        {
            FILE *fp;
            if(broj_igre==1)
            {
                fp=fopen("otkazana1.txt", "w");
                fclose(fp);
            }
            if(broj_igre==2)
            {
                fp=fopen("otkazana2.txt", "w");
                fclose(fp);
            }
            if(broj_igre==3)
            {
                fp=fopen("otkazana3.txt", "w");
                fclose(fp);
            }
            if(broj_igre==4)
            {
                fp=fopen("otkazana4.txt", "w");
                fclose(fp);
            }
            printf("Otkazali ste igru, vas kljuc je ponisten\n");
            Sleep(2500);
            system("cls");
            return 0;
        }
        else
        {
            system("cls");
            return 0;
        }

    }
    else if(p==3)
    {
        printf("Igra nije otkljucana, ne mozete prikazati statistiku !\n");
        Sleep(3000);
        system("cls");
        return 0;
    }
    else if(p==4)
    {
        printf("Igra nije otkljucana, ne mozete sacuvati rezultate u CSV fajl !\n");
        Sleep(3000);
        system("cls");
        return 0;
    }
    else if(p==5)
    {
        system("cls");
        return 0;
    }
    return 1;

}

