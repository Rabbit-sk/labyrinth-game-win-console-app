#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dirent.h>

const int Dlzka_Retazca_Suboru = 25;

FILE *Otvor_Subor(char *Nazov_Suboru, char *Rezim);
int Zatvor_Subor(FILE *pf);
int Prehliadac();
int Nastav_Rozmery(int *Riadky_y, int *Stlpce_x);
int Menu();
int Hrat(char *Nazov_Suboru);
int Nova_Mapa();
void Ulozit_Mapu(char **Pole, int Riadky_y, int Stlpce_x);
void Pravidla();
void Info();
void Uvolni_2D_char_Pole(char **Pole, int Pocet_Riadkov);
char **Vytvor_2D_char_Pole(int Riadky_y, int Stlpce_x);
int Zobraz_Mapu(char *Nazov_Suboru);
int Editor(char **Mapa, int Riadky_y, int Stlpce_x);

int main()
{
    Menu();

    return 0;
}

int Menu()
{
    int Polozka=1, Pokracuj1, Pokracuj2, Pokracuj3;

    Pokracuj1=1;
    do
    {
        Pokracuj2=1;
        do
        {
            switch(Polozka)
            {
                case 1:
                    system("cls");
                    printf("X     X   XX  X XX   X X   X XXX\n");
                    printf("X    X X  X X X X X  X XX  X  X\n");
                    printf("X   XXXXX XX  X XX   X X X X  X\n");
                    printf("X   X   X X X X X X  X X  XX  X\n");
                    printf("XXX X   X XX  X X  X X X   X  X\n\n");
                    printf("XXXXXXXXXXXX\n");
                    printf("XX     XXX C    * LABIRINTY *\n");
                    printf("XX XXX X   X    NOVY LABIRINT\n");
                    printf("XX*XXX X XXX       PRAVIDLA\n");
                    printf("XX XXX   XXX         INFO\n");
                    printf("XX XXXXXXXXX       ZATVORIT\n");
                    printf("XXSXXXXXXXXX\n");
                    break;
                case 2:
                    system("cls");
                    printf("X     X   XX  X XX   X X   X XXX\n");
                    printf("X    X X  X X X X X  X XX  X  X\n");
                    printf("X   XXXXX XX  X XX   X X X X  X\n");
                    printf("X   X   X X X X X X  X X  XX  X\n");
                    printf("XXX X   X XX  X X  X X X   X  X\n\n");
                    printf("XXXXXXXXXXXX\n");
                    printf("XX     XXX C      LABIRINTY\n");
                    printf("XX XXX X   X  * NOVY LABIRINT *\n");
                    printf("XX*XXX X XXX       PRAVIDLA\n");
                    printf("XX XXX   XXX         INFO\n");
                    printf("XX XXXXXXXXX       ZATVORIT\n");
                    printf("XXSXXXXXXXXX\n");
                    break;
                case 3:
                    system("cls");
                    printf("X     X   XX  X XX   X X   X XXX\n");
                    printf("X    X X  X X X X X  X XX  X  X\n");
                    printf("X   XXXXX XX  X XX   X X X X  X\n");
                    printf("X   X   X X X X X X  X X  XX  X\n");
                    printf("XXX X   X XX  X X  X X X   X  X\n\n");
                    printf("XXXXXXXXXXXX\n");
                    printf("XX     XXX C      LABIRINTY\n");
                    printf("XX XXX X   X    NOVY LABIRINT\n");
                    printf("XX*XXX X XXX     * PRAVIDLA *\n");
                    printf("XX XXX   XXX         INFO\n");
                    printf("XX XXXXXXXXX       ZATVORIT\n");
                    printf("XXSXXXXXXXXX\n");
                    break;
                case 4:
                    system("cls");
                    printf("X     X   XX  X XX   X X   X XXX\n");
                    printf("X    X X  X X X X X  X XX  X  X\n");
                    printf("X   XXXXX XX  X XX   X X X X  X\n");
                    printf("X   X   X X X X X X  X X  XX  X\n");
                    printf("XXX X   X XX  X X  X X X   X  X\n\n");
                    printf("XXXXXXXXXXXX\n");
                    printf("XX     XXX C      LABIRINTY\n");
                    printf("XX XXX X   X    NOVY LABIRINT\n");
                    printf("XX*XXX X XXX       PRAVIDLA\n");
                    printf("XX XXX   XXX       * INFO *\n");
                    printf("XX XXXXXXXXX       ZATVORIT\n");
                    printf("XXSXXXXXXXXX\n");
                    break;
                case 5:
                    system("cls");
                    printf("X     X   XX  X XX   X X   X XXX\n");
                    printf("X    X X  X X X X X  X XX  X  X\n");
                    printf("X   XXXXX XX  X XX   X X X X  X\n");
                    printf("X   X   X X X X X X  X X  XX  X\n");
                    printf("XXX X   X XX  X X  X X X   X  X\n\n");
                    printf("XXXXXXXXXXXX\n");
                    printf("XX     XXX C      LABIRINTY\n");
                    printf("XX XXX X   X    NOVY LABIRINT\n");
                    printf("XX*XXX X XXX       PRAVIDLA\n");
                    printf("XX XXX   XXX         INFO\n");
                    printf("XX XXXXXXXXX     * ZATVORIT *\n");
                    printf("XXSXXXXXXXXX\n");
                    break;
                default :
                    printf("\nChyba 1!\n");
                    break;
            }
            Pokracuj3=1;
            do
            {
                switch(getch())
                {
                    case '8':
                        if(Polozka>1)
                        {
                            Polozka--;
                            Pokracuj3=0;
                        }
                        else
                        {
                            Pokracuj3=1;
                        }
                        break;
                    case 13:
                        Pokracuj2=0;
                        Pokracuj3=0;
                        break;
                    case '2':
                        if(Polozka<5)
                        {
                            Polozka++;
                            Pokracuj3=0;
                        }
                        else
                        {
                            Pokracuj3=1;
                        }
                        break;
                }
            }while(Pokracuj3!=0);
        }while(Pokracuj2!=0);
        switch(Polozka)
        {
            case 1:
                Prehliadac();
                break;
            case 2:
                Nova_Mapa();
                break;
            case 3:
                Pravidla();
                break;
            case 4:
                Info();
                break;
            case 5:
                Pokracuj1=0;
                break;
            default : //k chybe moze dojst zo stranz programatora
                printf("\nChyba 3!\n");
                break;
        }
    }while(Pokracuj1!=0);

    return 0;
}

int Hrat(char *Nazov_Suboru)
{
    FILE *fr;
    int Riadky_y, Stlpce_x, r_y, s_x, Pom, K_y, K_x, K_y_Max, K_x_Max, Podmenu;
    int Pokracuj1, Pokracuj2, Pokracuj3;
    char **Mapa = NULL, *Text_Menu, Kurzor, Pom1;

    if((fr=Otvor_Subor(Nazov_Suboru, "r"))==NULL)
        return 1;
    fscanf(fr, "%d %d", &Riadky_y, &Stlpce_x);
    Mapa = Vytvor_2D_char_Pole(Riadky_y, Stlpce_x);
    for(r_y=0; r_y<Riadky_y; r_y++)
    {
        for(s_x=0; s_x<Stlpce_x; s_x++)
        {
            fscanf(fr, "%d", &Pom);
            Mapa[r_y][s_x] = Pom;
            if(Mapa[r_y][s_x]=='S')
            {
                K_y=r_y;
                K_x=s_x;
            }
        }
    }

    K_x_Max=Stlpce_x-1;
    K_y_Max=Riadky_y-1;


    Podmenu=0;
    Kurzor='*';
    Pokracuj1=1;
    do
    {
        switch(Podmenu)
        {
            case 0:
                Text_Menu="Ukoncit hru U \xB3\n";
                break;
            case 1:
                Text_Menu="Naozaj chces ukoncit hru? \xB3 Ano A \xB3 Spat S\n";
                break;
            case 2:
                Text_Menu="Si v cieli!\n";
                break;
            default :
                printf("\nChybne zvolene cislo pre podmenu.\n");    //Mozna chyba zo strany programatora
                break;
        }

        Pom1=Mapa[K_y][K_x];
        Mapa[K_y][K_x]=Kurzor;

        system("cls");
        printf("%s",Text_Menu);

        for(r_y=0; r_y<Riadky_y; r_y++)
        {
            for(s_x=0; s_x<Stlpce_x; s_x++)
            {
                printf("%c", Mapa[r_y][s_x]);
            }
            printf("\n");
        }

        Mapa[K_y][K_x]=Pom1;

        switch(Podmenu)
        {
            case 0:
                Pokracuj2=1;
                do
                {
                    switch(getch())
                    {
                        case '2':
                            if(K_y<K_y_Max&&(Mapa[K_y+1][K_x]==' '||Mapa[K_y+1][K_x]=='C'))
                            {
                                K_y++;
                                Pokracuj2=0;
                            }
                            else
                            {
                                Pokracuj2=1;
                            }
                            break;
                        case '4':
                            if(K_x>0&&(Mapa[K_y][K_x-1]==' '||Mapa[K_y][K_x-1]=='C'))
                            {
                                K_x--;
                                Pokracuj2=0;
                            }
                            else
                            {
                                Pokracuj2=1;
                            }
                            break;
                        case '6':
                            if(K_x<K_x_Max&&(Mapa[K_y][K_x+1]==' '||Mapa[K_y][K_x+1]=='C'))
                            {
                                K_x++;
                                Pokracuj2=0;
                            }
                            else
                            {
                                Pokracuj2=1;
                            }
                            break;
                        case '8':
                            if(K_y>0&&(Mapa[K_y-1][K_x]==' '||Mapa[K_y-1][K_x]=='C'))
                            {
                                K_y--;
                                Pokracuj2=0;
                            }
                            else
                            {
                                Pokracuj2=1;
                            }
                            break;
                        case 'U':
                        case 'u':
                            Podmenu=1;
                            Pokracuj2=0;
                            break;
                    }
                    if(Mapa[K_y][K_x]=='C')
                        Podmenu=2;
                }while(Pokracuj2!=0);
                break;
            case 1:
                Pokracuj3=1;
                do
                {
                    switch(getch())
                    {
                        case 'A':
                        case 'a':
                            Pokracuj3=0;
                            Pokracuj1=0;
                            break;
                        case 'S':
                        case 's':
                            Pokracuj3=0;
                            Pokracuj2=0;
                            break;
                    }
                }while(Pokracuj3!=0);
                Podmenu=0;
                break;
            case 2:
                getch();
                Podmenu=0;
                break;
            default :
                printf("\nChybne zvolene cislo pre podmenu.\n");    //Mozna chyba zo strany programatora
                getch();
                Podmenu=0;
                break;
        }
    }while(Pokracuj1!=0);

    return 0;
}

int Edituj_Ulozenu_Mapu(char *Nazov_Suboru)
{
    FILE *fr;
    int Riadky_y, Stlpce_x, r_y, s_x, Pom;
    char **Mapa = NULL;

    if((fr=Otvor_Subor(Nazov_Suboru, "r"))==NULL)
        return 1;
    fscanf(fr, "%d %d", &Riadky_y, &Stlpce_x);
    Mapa = Vytvor_2D_char_Pole(Riadky_y, Stlpce_x);
    for(r_y=0; r_y<Riadky_y; r_y++)
    {
        for(s_x=0; s_x<Stlpce_x; s_x++)
        {
            fscanf(fr, "%d", &Pom);
            Mapa[r_y][s_x] = Pom;
        }
    }
    Editor(Mapa, Riadky_y, Stlpce_x);

    return 0;
}

int Nova_Mapa()
{
    int Riadky_y, Stlpce_x, r_y, s_x;
    char **Mapa = NULL;

    Nastav_Rozmery(&Riadky_y, &Stlpce_x);
    Mapa = Vytvor_2D_char_Pole(Riadky_y, Stlpce_x);
    for(r_y=0; r_y<Riadky_y; r_y++)
    {
        for(s_x=0; s_x<Stlpce_x; s_x++)
        {
            Mapa[r_y][s_x]= 219;
        }
    }
    Editor(Mapa, Riadky_y, Stlpce_x);

    return 0;
}

int Nastav_Rozmery(int *Riadky_y, int *Stlpce_x)
{
    int r_y, s_x, Pokracuj1, Pokracuj2, Pokracuj3;

    *Stlpce_x=1;
    *Riadky_y=1;
    Pokracuj1=1;
    do
    {
        if(*Stlpce_x<1)
        {
            *Stlpce_x=1;
        }
        if(*Riadky_y<1)
        {
            *Riadky_y=1;
        }
        system("cls");
        printf("Potvrdit rozmer ENTER \xB3 Spat S \xB3 %d x %d\n",*Stlpce_x,*Riadky_y);
        for(r_y=0; r_y<*Riadky_y; r_y++)
        {
            for(s_x=0; s_x<*Stlpce_x; s_x++)
            {
                printf("\xdb");
            }
            printf("\n");
        }
        Pokracuj2=1;
        do
        {
            switch(getch())
            {
                case '1':
                    *Stlpce_x-=1;
                    *Riadky_y+=1;
                    Pokracuj2=0;
                    break;
                case '2':
                    *Riadky_y+=1;
                    Pokracuj2=0;
                    break;
                case '3':
                    *Stlpce_x+=1;
                    *Riadky_y+=1;
                    Pokracuj2=0;
                    break;
                case '4':
                    *Stlpce_x-=1;
                    Pokracuj2=0;
                    break;
                case '6':
                    *Stlpce_x+=1;
                    Pokracuj2=0;
                    break;
                case '7':
                    *Stlpce_x-=1;
                    *Riadky_y-=1;
                    Pokracuj2=0;
                    break;
                case '8':
                    *Riadky_y-=1;
                    Pokracuj2=0;
                    break;
                case '9':
                    *Stlpce_x+=1;
                    *Riadky_y-=1;
                    Pokracuj2=0;
                    break;
                case 13:
                    system("cls");
                    printf("Pokracovat? \xB3 Ano A \xB3 Nie N\n");
                    for(r_y=0; r_y<*Riadky_y; r_y++)
                    {
                        for(s_x=0; s_x<*Stlpce_x; s_x++)
                        {
                            printf("\xdb");
                        }
                        printf("\n");
                    }
                    Pokracuj3=1;
                    do
                    {
                        switch(getch())
                        {
                            case 'A':
                            case 'a':
                                Pokracuj3=0;
                                Pokracuj2=0;
                                Pokracuj1=0;
                                break;
                            case 'N':
                            case 'n':
                                Pokracuj3=0;
                                Pokracuj2=0;
                                break;
                        }
                    }while(Pokracuj3!=0);
                    break;
                case 'S':
                case 's':
                    return 0;
            }
        }while(Pokracuj2!=0);
    }while(Pokracuj1!=0);

    return 0;
}

int Editor(char **Mapa, int Riadky_y, int Stlpce_x)
{
    int r_y, s_x, K_y, K_x, K_y_Max, K_x_Max, Kurzor_Mod, Orto;
    int Podmenu, Pocet_Startov=0, Pocet_Cielov=0;
    int Pokracuj1, Pokracuj2, Pokracuj3, Pokracuj4, Pokracuj5;
    char *Text_Menu, Kurzor, Pom1, Pom2;

    K_x_Max=Stlpce_x-1;
    K_y_Max=Riadky_y-1;
    K_x=Stlpce_x/2;
    K_y=Riadky_y/2;

    Podmenu=0;
    Kurzor_Mod=1;
    Kurzor=250;
    Orto=0;
    do
    {
        switch(Podmenu)
        {
            case 0:
                Text_Menu="Ulozit U \xB3 Zrusit Z \xB3 \xFA Q \xB3 \xB0 W \xB3 \xDB E \xB3 Start R \xB3 Ciel T\n";
                break;
            case 1:
                Text_Menu="Ulozit mapu? \xB3 Ano A \xB3 Spat S\n";
                Pom2=Kurzor;
                switch(Kurzor)
                {
                    case '\xFA':
                        Kurzor=Pom1;
                        break;
                    case '\xB0':
                        Kurzor=32;
                        break;
                    case '\xB2':
                        Kurzor=219;
                        break;
                }
                break;
            case 2:
                Text_Menu="Mapa sa neulozi. Zrusit mapu? \xB3 Ano A \xB3 Spat S\n";
                Pom2=Kurzor;
                switch(Kurzor)
                {
                    case '\xFA':
                        Kurzor=Pom1;
                        break;
                    case '\xB0':
                        Kurzor=32;
                        break;
                    case '\xB2':
                        Kurzor=219;
                        break;
                }
                break;
            case 5:
                for(r_y=0; r_y<Riadky_y; r_y++)
                {
                    for(s_x=0; s_x<Stlpce_x; s_x++)
                    {
                        if(Mapa[r_y][s_x]=='S')
                            Pocet_Startov++;
                    }
                }
                if(Pocet_Startov>=1)
                {
                    Text_Menu="Start moze byt len jeden. \xB3 Spat S\n";
                }
                else
                {
                    Text_Menu="Potvrdit polohu startu ENTER \xB3 Spat S\n";
                }
                break;
            case 6:
                for(r_y=0; r_y<Riadky_y; r_y++)
                {
                    for(s_x=0; s_x<Stlpce_x; s_x++)
                    {
                        if(Mapa[r_y][s_x]=='C')
                            Pocet_Cielov++;
                    }
                }
                if(Pocet_Cielov>=1)
                {
                    Text_Menu="Ciel moze byt len jeden. \xB3 Spat S\n";
                }
                else
                {
                    Text_Menu="Potvrdit polohu ciela ENTER \xB3 Spat S\n";
                }
                break;
            default :
                printf("\nChybne zvolene cislo pre podmenu.\n");    //Mozna chyba zo strany programatora
                break;
        }

        switch(Kurzor_Mod)
        {
            case 1: //Kurzor nenechava stopu
                Pom1=Mapa[K_y][K_x];
                Mapa[K_y][K_x]=Kurzor;
                break;
            case 2: //Kurzor zanechava stopu
                Mapa[K_y][K_x]=Kurzor;
                break;
        }

        system("cls");
        printf("%s",Text_Menu);

        for(r_y=0; r_y<Riadky_y; r_y++)
        {
            for(s_x=0; s_x<Stlpce_x; s_x++)
            {
                printf("%c", Mapa[r_y][s_x]);
            }
            printf("\n");
        }

        switch(Kurzor_Mod)
        {
            case 1: //Kurzor nenechava stopu
                Mapa[K_y][K_x]=Pom1;
                break;
            case 2: //Kurzor zanechava stopu
                switch(Kurzor)
                {
                    case '\xB2':
                        Mapa[K_y][K_x]=219;
                        break;
                    case '\xB0':
                        Mapa[K_y][K_x]=32;
                        break;
                }
                break;
        }

        switch(Podmenu)
        {
            case 0:
                Pokracuj1=1;
                do
                {
                    switch(getch())
                    {
                        case '1':
                            if(Orto==0&&K_x>0&&K_y<K_y_Max)
                            {
                                K_x--;
                                K_y++;
                                Pokracuj1=0;
                            }
                            else
                            {
                                Pokracuj1=1;
                            }
                            break;
                        case '2':
                            if(K_y<K_y_Max)
                            {
                                K_y++;
                                Pokracuj1=0;
                            }
                            else
                            {
                                Pokracuj1=1;
                            }
                            break;
                        case '3':
                            if(Orto==0&&K_x<K_x_Max&&K_y<K_y_Max)
                            {
                                K_x++;
                                K_y++;
                                Pokracuj1=0;
                            }
                            else
                            {
                                Pokracuj1=1;
                            }
                            break;
                        case '4':
                            if(K_x>0)
                            {
                                K_x--;
                                Pokracuj1=0;
                            }
                            else
                            {
                                Pokracuj1=1;
                            }
                            break;
                        case '6':
                            if(K_x<K_x_Max)
                            {
                                K_x++;
                                Pokracuj1=0;
                            }
                            else
                            {
                                Pokracuj1=1;
                            }
                            break;
                        case '7':
                            if(Orto==0&&K_x>0&&K_y>0)
                            {
                                K_x--;
                                K_y--;
                                Pokracuj1=0;
                            }
                            else
                            {
                                Pokracuj1=1;
                            }
                            break;
                        case '8':
                            if(K_y>0)
                            {
                                K_y--;
                                Pokracuj1=0;
                            }
                            else
                            {
                                Pokracuj1=1;
                            }
                            break;
                        case '9':
                            if(Orto==0&&K_x<K_x_Max&&K_y>0)
                            {
                                K_x++;
                                K_y--;
                                Pokracuj1=0;
                            }
                            else
                            {
                                Pokracuj1=1;
                            }
                            break;
                        case 'U':
                        case 'u':
                            Podmenu=1;
                            Pokracuj1=0;
                            break;
                        case 'Z':
                        case 'z':
                            Podmenu=2;
                            Pokracuj1=0;
                            break;
                        case 'Q':
                        case 'q':
                            Kurzor=250;
                            Orto=0;
                            Kurzor_Mod=1;
                            Pokracuj1=0;
                            break;
                        case 'W':
                        case 'w':
                            Kurzor=176;
                            Orto=1;
                            Kurzor_Mod=2;
                            Pokracuj1=0;
                            break;
                        case 'E':
                        case 'e':
                            Kurzor=178;
                            Orto=1;
                            Kurzor_Mod=2;
                            Pokracuj1=0;
                            break;
                        case 'R':
                        case 'r':
                            Podmenu=5;
                            Kurzor='S';
                            Orto=0;
                            Kurzor_Mod=1;
                            Pokracuj1=0;
                            break;
                        case 'T':
                        case 't':
                            Podmenu=6;
                            Kurzor='C';
                            Orto=0;
                            Kurzor_Mod=1;
                            Pokracuj1=0;
                            break;
                    }
                }while(Pokracuj1!=0);
                break;
            case 1:
                Pokracuj2=1;
                do
                {
                    switch(getch())
                    {
                        case 'A':
                        case 'a':
                            Ulozit_Mapu(Mapa, Riadky_y, Stlpce_x);
                            Uvolni_2D_char_Pole(Mapa, Riadky_y);
                            return 0;
                            break;
                        case 'S':
                        case 's':
                            Pokracuj2=0;
                            break;
                    }
                }while(Pokracuj2!=0);
                Podmenu=0;
                Kurzor=Pom2;
                break;
            case 2:
                Pokracuj3=1;
                do
                {
                    switch(getch())
                    {
                        case 'A':
                        case 'a':
                            Uvolni_2D_char_Pole(Mapa, Riadky_y);
                            return 0;
                            break;
                        case 'S':
                        case 's':
                            Pokracuj3=0;
                            break;
                    }
                }while(Pokracuj3!=0);
                Kurzor=Pom2;
                Podmenu=0;
                break;
            case 5:
            case 6:
                if(Pocet_Startov>=1||Pocet_Cielov>=1)
                {
                    Pokracuj4=1;
                    do
                    {
                        switch(getch())
                        {
                            case 'S':
                            case 's':
                                Pokracuj4=0;
                                break;
                        }
                    }while(Pokracuj4!=0);
                    Pocet_Startov=0;
                    Pocet_Cielov=0;
                }
                else
                {
                    Pokracuj5=1;
                    do
                    {
                        switch(getch())
                        {
                            case 13:
                                Mapa[K_y][K_x]=Kurzor;
                                Pokracuj5=0;
                                break;
                            case 'S':
                            case 's':
                                Pokracuj5=0;
                                break;
                        }
                    }while(Pokracuj5!=0);
                }
                Podmenu=0;
                Kurzor=250;
                Orto=0;
                Kurzor_Mod=1;
                break;
            default :
                printf("\nChybne zvolene cislo pre podmenu.\n");    //Mozna chyba zo strany programatora
                getch();
                Podmenu=0;
                break;
        }

    }while(1);

    return 0;
}

void Ulozit_Mapu(char **Pole, int Riadky_y, int Stlpce_x)
{
    FILE *fw_Nova_Mapa, *ftest;
    int r_y, s_x, Pokracuj1, Pokracuj2;
    char Nazov_Suboru[Dlzka_Retazca_Suboru];

    Pokracuj1=1;
    do
    {
        system("cls");
        printf("Zadaj nazov mapy (max 20 znakov): ");
        scanf("%20s",Nazov_Suboru);
        fflush(stdin);
        strcat(Nazov_Suboru, ".laf");

        if((ftest=fopen(Nazov_Suboru, "r"))!=NULL)
        {
            fclose(ftest);
            printf("\nSubor s tymto nazvom uz existuje. Chces ho prepisat?    A / N\n");
            Pokracuj2=1;
            do
            {
                switch(getch())
                {
                    case 'A':
                    case 'a':
                        Pokracuj2=0;
                        Pokracuj1=0;
                        break;
                    case 'N':
                    case 'n':
                        Pokracuj2=0;
                        break;
                }
            }while(Pokracuj2!=0);
        }
        else
            Pokracuj1=0;
    }while(Pokracuj1!=0);

    fw_Nova_Mapa = fopen(Nazov_Suboru, "w");

    fprintf(fw_Nova_Mapa, "%d %d\n", Riadky_y, Stlpce_x);
    for(r_y=0; r_y<Riadky_y; r_y++)
    {
        for(s_x=0; s_x<Stlpce_x; s_x++)
        {
            fprintf(fw_Nova_Mapa, "%d ",Pole[r_y][s_x]);
        }
        fprintf(fw_Nova_Mapa, "\n");
    }
    if(fclose(fw_Nova_Mapa)== EOF)
        printf("chyba\n");
    printf("Labirint je ulozeny.\nPre pokracovanie stlac lubovolnu klavesu.\n");
    getch();
}

void Pravidla()
{
    system("cls");
    printf("Ulohou hraca je dostat sa do ciela pouzitim tlacidiel 2, 4, 6, 8.\n\nPre pokracovanie stlac lubovolnu klavesu.\n");
    getch();
}

void Info()
{
    system("cls");
    printf("    Zilinska univerzita v Ziline\n      Elektrotechnicka fakulta");
    printf("\n\n\n\n\n\n\n\n        ALGORITMIZACIA ULOH\n\n         Semestralna praca\n\n\n\n\n\n\n\n\nVYPRACOVAL:");
    printf(" Jan J.\nSK.ROK: 2013/2014\n\n\t\t      Pre pokracovanie stlac lubovolnu klavesu.\n");
    getch();
}

void Uvolni_2D_char_Pole(char **Pole, int Pocet_Riadkov)
{
    int r_y;

    for(r_y=0; r_y<Pocet_Riadkov; r_y++)
    {
        free(Pole[r_y]);
    }
    free(Pole);
    Pole = NULL;
}

char** Vytvor_2D_char_Pole(int Riadky_y, int Stlpce_x)
{
    char **Pole;
    int r_y;

    Pole=(char**)malloc(Riadky_y*sizeof(char*));
    if(Pole==NULL)
    {
        system("cls");
        printf("Chyba pri alokovani pola.\n");
        getch();
        return NULL;
    }
    else
    {
        for(r_y=0; r_y<Riadky_y; r_y++)
        {
            Pole[r_y]=(char*)malloc(Stlpce_x*sizeof(char));
            if(Pole[r_y]==NULL)
            {
                system("cls");
                printf("Chyba pri alokovani pola.\n");
                getch();
                return NULL;
            }
        }
    }
    return Pole;
}

int Zobraz_Mapu(char *Nazov_Suboru)
{
    FILE *fr = NULL;
    int Riadky_y, Stlpce_x, r_y, s_x, Pom;

    if((fr=Otvor_Subor(Nazov_Suboru, "r"))==NULL)
        return 1;
    fscanf(fr, "%d %d", &Riadky_y, &Stlpce_x);
    char **Mapa = Vytvor_2D_char_Pole(Riadky_y, Stlpce_x);
    for(r_y=0; r_y<Riadky_y; r_y++)
    {
        for(s_x=0; s_x<Stlpce_x; s_x++)
        {
            fscanf(fr, "%d", &Pom);
            Mapa[r_y][s_x] = Pom;
        }
    }
    for(r_y=0; r_y<Riadky_y; r_y++)
        {
            for(s_x=0; s_x<Stlpce_x; s_x++)
            {
                printf("%c", Mapa[r_y][s_x]);
            }
            printf("\n");
        }
    Zatvor_Subor(fr);
    Uvolni_2D_char_Pole(Mapa, Riadky_y);

    return 0;
}

FILE *Otvor_Subor(char *Nazov_Suboru, char *Rezim)
{
    FILE *pf;
    int Pokracuj1, Pokracuj2;

    Pokracuj1=1;
    do
    {
        if((pf = fopen(Nazov_Suboru, Rezim)) == NULL)
        {
            system("cls");
            printf("Nepodarilo sa otvorit/vytvorit %s\nSkusit znovu?    a / n\n", Nazov_Suboru);
            Pokracuj2=1;
            do
            {
                switch(getch())
                {
                    case 'a':
                        Pokracuj2=0;
                        Pokracuj1=1;
                        break;
                    case 'n':
                        return NULL;
                        break;
                }
            }while(Pokracuj2!=0);
        }
        else
            Pokracuj1=0;
    }while(Pokracuj1!=0);

    return pf;
}

int Zatvor_Subor(FILE *pf)
{
    int Pokracuj1, Pokracuj2;

    Pokracuj1=1;
    do
    {
        if(fclose(pf) == EOF)
        {
            system("cls");
            printf("Nepodarilo sa zatvorit subor\nSkusit znovu?    a / n\n");
            Pokracuj2=1;
            do
            {
                switch(getch())
                {
                    case 'a':
                        Pokracuj2=0;
                        Pokracuj1=1;
                        break;
                    case 'n':
                        return 1;
                }
            }while(Pokracuj2!=0);
        }
        else
            Pokracuj1=0;
    }while(Pokracuj1!=0);

    return 0;
}

int Prehliadac()
{
    DIR *pdir = NULL;
    struct dirent *pent = NULL;
    FILE *fwp = NULL;
    int Dlzka, Riadky_y=0,  r_y, Pokracuj1, Pokracuj2, Pokracuj3, Pokracuj4;
    char **Zoznam, *Kurzor, Nazov_Bez_Pripony[Dlzka_Retazca_Suboru-4], Nazov_Suboru[Dlzka_Retazca_Suboru];

    pdir = opendir (".");
    if (pdir == NULL)
    {
        printf ("\nChyba! pdir nemohol byt spravne inicializovany\n");
        return 1;
    }
    fwp = Otvor_Subor("zoznam.txt", "w+");
    while ((pent = readdir (pdir))!=0)
    {
        if (pent == NULL)
        {
            printf ("\nChyba! pent nemohol byt spravne inicializovany\n");
            Zatvor_Subor(fwp);
            return 1;
        }
        if(strlen(pent->d_name)<=Dlzka_Retazca_Suboru-1)
        {
            sscanf(pent->d_name, "%s", Nazov_Suboru);
            Dlzka=strlen(Nazov_Suboru);
            if((Nazov_Suboru[Dlzka-4]=='.')&&(Nazov_Suboru[Dlzka-3]=='l')&&(Nazov_Suboru[Dlzka-2]=='a')&&(Nazov_Suboru[Dlzka-1]=='f'))
            {
                fprintf(fwp, "%s\n", Nazov_Suboru);
                ++Riadky_y;
            }
        }
    }
    closedir (pdir);
    if(Riadky_y==0)
    {
        printf("Chyba! Nenaslo sa ziadne bludisko.\n\nPre pokracovanie stlac lubovolnu klavesu.\n");
        getch();
        return 1;
    }

    Zoznam = Vytvor_2D_char_Pole(Riadky_y, Dlzka_Retazca_Suboru);
    Kurzor=(char*)malloc(Riadky_y*sizeof(char));
    if(Kurzor==NULL)
    {
        system("cls");
        printf("Chyba pri alokovani pola.\n");
        getch();
    }
    for(r_y=0; r_y<Riadky_y; r_y++)
        Kurzor[r_y] = ' ';
    Kurzor[0]='*';
    rewind(fwp);
    for(r_y=0; r_y<Riadky_y; r_y++)
        fscanf(fwp, "%s", Zoznam[r_y]);
    Zatvor_Subor(fwp);
    remove("zoznam.txt");
    Pokracuj1=1;
    r_y=0;
    do
    {
        strncpy(Nazov_Bez_Pripony, Zoznam[r_y], strlen(Zoznam[r_y])-4);
        Nazov_Bez_Pripony[strlen(Zoznam[r_y])-4]='\0';
        system("cls");
        printf("Hrat H \xB3 Editovat E \xB3 Premenovat P \xB3 Vymazat V \xB3 Spat S \xB3 %s\n", Nazov_Bez_Pripony);
        if((Zobraz_Mapu(Zoznam[r_y]))==1)
        {
            printf("Stlac lubovolnu klavesu pre navrat do hlavneho menu.\n");
            getch();
            return 1;
        }

        Pokracuj2=1;
        do
        {
            switch(getch())
            {
                case '8':
                    if(r_y>0)
                    {
                        --r_y;
                        Pokracuj2=0;
                    }
                    else
                        Pokracuj2=1;
                    break;
                case '2':
                    if(r_y<Riadky_y-1)
                    {
                        ++r_y;
                        Pokracuj2=0;
                    }
                    else
                        Pokracuj2=1;
                    break;
                case 'H':
                case 'h':
                    Hrat(Zoznam[r_y]);
                    Pokracuj2=0;
                    Pokracuj1=0;
                    break;
                case 'E':
                case 'e':
                    if((Edituj_Ulozenu_Mapu(Zoznam[r_y]))!=0)
                    {
                        system("cls");
                        printf("Labirint sa nepodarilo otvorit.\nPre pokracovanie stlac lubovolnu klavesu.\n");
                        getch();
                        return 1;
                    }
                    Pokracuj2=0;
                    Pokracuj1=0;
                    break;
                case 'P':
                case 'p':
                    Pokracuj4=1;
                    do
                    {
                        system("cls");
                        printf("Akualny nazov: %s\nNovy nazov (max 20 znakov): ", Nazov_Bez_Pripony);
                        scanf("%20s",Nazov_Suboru);
                        fflush(stdin);
                        strcat(Nazov_Suboru, ".laf");
                        if(rename(Zoznam [r_y], Nazov_Suboru)!=0)
                        {
                            printf("Nepodarilo sa premenovat subor, zadaj iny nazov.\nPokracuj stlacenim lubovolnej klavesy.\n");
                            getch();
                        }
                        else
                        {
                            printf("Subor je premenovany.\nPokracuj stlacenim lubovolnej klavesy.\n");
                            getch();
                            Pokracuj4=0;
                            Pokracuj2=0;
                            Pokracuj1=0;
                        }
                    }while(Pokracuj4!=0);
                    break;
                case 'V':
                case 'v':
                    system("cls");
                    printf("Naozaj chces vymazat bludisko s nazvom %s ?    A / N\n", Nazov_Bez_Pripony);
                    Pokracuj3=1;
                    do
                    {
                        switch(getch())
                        {
                            case 'A':
                            case 'a':
                                if(remove(Zoznam[r_y])!=0)
                                {
                                    printf("Nepodarilo sa vymazat subor.\nPokracuj stlacenim lubovolnej klavesy.\n");
                                    getch();
                                }
                                else
                                {
                                    printf("Subor je vymazany.\nPokracuj stlacenim lubovolnej klavesy.\n");
                                    getch();
                                }
                                Uvolni_2D_char_Pole(Zoznam, Riadky_y);
                                return 0;
                            case 'N':
                            case 'n':
                                Pokracuj3=0;
                                Pokracuj2=0;
                                break;
                        }
                    }while(Pokracuj3!=0);
                    break;
                case 'S':
                case 's':
                    Uvolni_2D_char_Pole(Zoznam, Riadky_y);
                    return 0;
            }
        }while(Pokracuj2!=0);
    }while(Pokracuj1!=0);

    return 0;
}
