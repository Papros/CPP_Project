#include "labirynt.h"
#include <stdlib.h>
#include <time.h>

labirynt::labirynt()
{
    //ctor
}

labirynt::~labirynt()
{
    //dtor
}

void labirynt::generuj(int SZEROKOSC, int WYSOKOSC)  // uzupelnia wszystkie scianki
{
    for(int a=0;a<SZEROKOSC+1;a++)
        for(int b=0;b<WYSOKOSC+1;b++)
            for(int c=0;c<4;c++)
            {
              cell[a][b][c] = true;
              cell_bool[a][b] = true;
            }

    for(int a=1;a<SZEROKOSC;a++)
        for(int b=1;b<WYSOKOSC;b++)
                cell_bool[a][b] = false;

                krok = 0;

     SZEROKOSC_lab = SZEROKOSC-1;
     WYSOKOSC_lab = WYSOKOSC-1;
}

void labirynt::losuj_start(int x, int y)
{
    srand(time(NULL));
    x_start = rand() % x;
    y_start = rand() % y;
    krok++;

}

bool labirynt::sprawdz_scianke(int a)
{
    switch(a)
    {
        case 1: return !cell_bool[x_akt][y_akt-1]; break;
        case 2: return !cell_bool[x_akt+1][y_akt]; break;
        case 3: return !cell_bool[x_akt][y_akt+1];  break;
        case 4: return !cell_bool[x_akt-1][y_akt]; break;
    }
}

void labirynt::losuj_scianke(int y)
{
    srand(time(NULL));
    bool zgoda = false;

    while(zgoda == false)
    {
        nr_scianki = rand() % 5;

        switch(nr_scianki)
            {
                case 1: zgoda = !cell_bool[x_akt][y_akt-1]; break;
                case 2: zgoda = !cell_bool[x_akt+1][y_akt]; break;
                case 3: zgoda = !cell_bool[x_akt][y_akt+1];  break;
                case 4: zgoda = !cell_bool[x_akt-1][y_akt]; break;
            }
    }
}

void labirynt::usun_scianke(int a)
{
    cell[x_akt][y_akt][nr_scianki] = false;

    switch(nr_scianki)
    {
        case 1: cell[x_akt][y_akt-1][3] = false; y_akt--; break;
        case 2: cell[x_akt+1][y_akt][4] = false; x_akt++; break;
        case 3: cell[x_akt][y_akt+1][1] = false; y_akt++; break;
        case 4: cell[x_akt-1][y_akt][2] = false; x_akt--; break;
    }
    krok++;
    kroki[krok][0] = x_akt;
    kroki[krok][1] = y_akt;
}

bool labirynt::koniec()
{
    bool koniec = true;
    for(int a=0;a<SZEROKOSC_lab+1;a++)
        for(int b=0;b<WYSOKOSC_lab+1;b++)
                if(cell_bool[a][b] == false)
                    koniec = false;

    return koniec;
}

bool labirynt::test()
{
    bool zgoda = false;
    if(cell_bool[x_akt - 1][y_akt] == false;) zgoda = true;
    if(cell_bool[x_akt + 1][y_akt] == false;) zgoda = true;
    if(cell_bool[x_akt][y_akt - 1] == false;) zgoda = true;
    if(cell_bool[x_akt][y_akt + 1] == false;) zgoda = true;

    return zgoda;
}








