#ifndef LABIRYNT_H
#define LABIRYNT_H


class labirynt
{
    public:
        labirynt();
        int SZEROKOSC_lab,WYSOKOSC_lab;
        virtual ~labirynt();
        void tworz();
        int cell[22][22][4];


    protected:

    private:
        int kroki[22*22][2];
        int krok;
        int x_start,y_start;
        int x_akt,y_akt;
        int nr_scianki;
        bool cell_bool[22][22];
        void generuj(int SZEROKOSC,int WYSOKOSC);
        void czysc();
        void usun_scianke(int a);
        void losuj_start(int x,int y);
        void losuj_scianke(int y);
        bool koniec();
        bool test();
        bool sprawdz_scianke(int a);
};




#endif // LABIRYNT_H
