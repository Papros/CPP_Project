#ifndef LABIRYNT_H
#define LABIRYNT_H


class labirynt
{
    public:
        labirynt();
        int SZEROKOSC_lab,WYSOKOSC_lab;
        virtual ~labirynt();
        void tworz();
        bool cell[42][42][4];

        int kroki[42*42][2];
        int krok;
        int x_start,y_start;
        int x_akt,y_akt;
        int nr_scianki;
        bool cell_bool[42][42];
        void generuj(int SZEROKOSC,int WYSOKOSC);
        void czysc();
        void usun_scianke(int a);
        void losuj_start(int x,int y);
        int losuj_scianke();
        bool koniec();
        bool test();
        bool sprawdz_scianke(int a);
        void ruch(bool zgoda);

        protected:

        private:
};




#endif // LABIRYNT_H
