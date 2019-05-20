#include "labirynt.h"
#include <stdlib.h>
#include <iostream>
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
    srand(time(NULL));
    for(int a=0;a<SZEROKOSC+2;a++)
        for(int b=0;b<WYSOKOSC+2;b++)
            for(int c=0;c<4;c++)
            {
              cell[a][b][c] = true;
              cell_bool[a][b] = true;
            }

    for(int a=1;a<SZEROKOSC+1;a++)
        for(int b=1;b<WYSOKOSC+1;b++)
                cell_bool[a][b] = false;

                krok = 0;

     SZEROKOSC_lab = SZEROKOSC;
     WYSOKOSC_lab = WYSOKOSC;
}

void labirynt::losuj_start(int x, int y)
{
    srand(time(NULL));
    x_start = rand() % x;
    y_start = rand() % y;
   // std::cout<<x_start<<" | "<<y_start<<std::endl;
    x_akt = x_start;
    y_akt = y_start;
    krok++;

}

/* bool labirynt::sprawdz_scianke(int a)
{
    switch(a)
    {
        case 1: return !cell_bool[x_akt][y_akt-1]; break;
        case 2: return !cell_bool[x_akt+1][y_akt]; break;
        case 3: return !cell_bool[x_akt][y_akt+1];  break;
       case 4: return !cell_bool[x_akt-1][y_akt]; break;
   }
} */

int labirynt::losuj_scianke()
{
    srand(rand()*rand());

    bool zgoda = false;

    while(!zgoda)
    {
        nr_scianki = rand() % 4;

        switch(nr_scianki)
            {
                case 0: zgoda = !cell_bool[x_akt][y_akt-1]; break;
                case 1: zgoda = !cell_bool[x_akt+1][y_akt]; break;
                case 2: zgoda = !cell_bool[x_akt][y_akt+1];  break;
                case 3: zgoda = !cell_bool[x_akt-1][y_akt]; break;
            }
    }

   //  std::cout<<" NR : "<<nr_scianki<<std::endl;
    return  nr_scianki;
}

void labirynt::usun_scianke(int a)
{
    cell[x_akt][y_akt][a] = false;

    switch(a)
    {
        case 0: cell[x_akt][y_akt-1][2] = false; y_akt--; break;
        case 1: cell[x_akt+1][y_akt][3] = false; x_akt++; break;
        case 2: cell[x_akt][y_akt+1][0] = false; y_akt++; break;
        case 3: cell[x_akt-1][y_akt][1] = false; x_akt--; break;
    }
    krok++;
    kroki[krok][0] = x_akt;
    kroki[krok][1] = y_akt;
    cell_bool[x_akt][y_akt] = true;
     // std::cout<<x_akt<<" | "<<y_akt<<std::endl;
}

bool labirynt::koniec()
{
    bool koniec = true;

    for(int a=1;a<SZEROKOSC_lab+2;a++)
        for(int b=1;b<WYSOKOSC_lab+2;b++)
                if(cell_bool[a][b] == false)
                    koniec = false;

    return koniec;
}

bool labirynt::test()
{
    bool zgoda = false;

    if(cell_bool[x_akt - 1][y_akt] == false) zgoda = true;
    if(cell_bool[x_akt + 1][y_akt] == false) zgoda = true;
    if(cell_bool[x_akt][y_akt - 1] == false) zgoda = true;
    if(cell_bool[x_akt][y_akt + 1] == false) zgoda = true;

    return zgoda;
}


void labirynt::ruch(bool zgoda)
{
    if(zgoda == false)
    {
        // std::cout<<"SCIANA!! "<<std::endl;
        if(krok!=0) krok--;

        x_akt = kroki[krok][0];
        y_akt = kroki[krok][1];
    }
    else
    {

    }

}





