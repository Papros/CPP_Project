#include <SFML/Graphics.hpp>
#include <iostream>
#include "labirynt.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>


using namespace sf;

RenderWindow oknoAplikacji;
Event zdarzenie;
ContextSettings settings;

Texture cell_text[17];
Texture gracz_t;

RectangleShape cells[42][42];
RectangleShape gracz;
int x_gracza,y_gracza;
int SZER = 840,WYS = 840, bpp = 32;
int SZ_cell=20,WY_cell=20;
labirynt Labirynt;


void tworz() // ładuje textury i tworzy pola, ubiera ramke
{
    for(int a=0;a<42;a++)
        for(int b=0;b<42;b++)
    {
        cells[a][b].setSize(Vector2f(SZ_cell,WY_cell));
        cells[a][b].setPosition(a*SZ_cell,b*WY_cell);
    }

    gracz.setSize(Vector2f(10,10));
    x_gracza = 1;
    y_gracza = 1;


    if (!cell_text[0].loadFromFile("image/cell_0.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[1].loadFromFile("image/cell_1.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[2].loadFromFile("image/cell_2.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[3].loadFromFile("image/cell_3.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[4].loadFromFile("image/cell_4.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[5].loadFromFile("image/cell_12.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[6].loadFromFile("image/cell_13.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[7].loadFromFile("image/cell_14.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[8].loadFromFile("image/cell_23.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[9].loadFromFile("image/cell_24.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[10].loadFromFile("image/cell_34.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[11].loadFromFile("image/cell_123.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[12].loadFromFile("image/cell_124.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[13].loadFromFile("image/cell_134.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[14].loadFromFile("image/cell_234.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[15].loadFromFile("image/cell_1234.png"))
    std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
    else
    if (!cell_text[16].loadFromFile("image/cell_brick.png"))
	std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;
	else
    if (!gracz_t.loadFromFile("image/gracz.png"))
	std::cerr << "Nie mozna zaladowac grafiki planszy"<<std::endl;

    for(int a=0;a<42;a++)
    {
        cells[a][0].setTexture(& cell_text[16]);
        cells[a][41].setTexture(& cell_text[16]);
        cells[0][a].setTexture(& cell_text[16]);
        cells[41][a].setTexture(& cell_text[16]);
    }

    gracz.setTexture(&gracz_t);
}

void buduj(labirynt maze,int x,int y) // buduje labirynt
{
    Labirynt.generuj(40,40);
    Labirynt.losuj_start(40,40);


    while(!Labirynt.koniec())
    {
    while(!Labirynt.test())
    {
    Labirynt.ruch(Labirynt.test());




    }
    Labirynt.usun_scianke(Labirynt.losuj_scianke());
    }

}

void ubierz(labirynt maze) // ubiera pozostałe pola, moga byc bledy !!!!
{

    for(int a=1;a<maze.SZEROKOSC_lab+1;a++)
        for(int b=1;b<maze.WYSOKOSC_lab+1;b++)
        {

        if(!maze.cell[a][b][0] && !maze.cell[a][b][1] && !maze.cell[a][b][2] && !maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[0]);
            else
        if(maze.cell[a][b][0] && !maze.cell[a][b][1] && !maze.cell[a][b][2] && !maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[1]);
            else
        if(!maze.cell[a][b][0] && maze.cell[a][b][1] && !maze.cell[a][b][2] && !maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[2]);
            else
        if(!maze.cell[a][b][0] && !maze.cell[a][b][1] && maze.cell[a][b][2] && !maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[3]);
            else
        if(!maze.cell[a][b][0] && !maze.cell[a][b][1] && !maze.cell[a][b][2] && maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[4]);
            else
        if(maze.cell[a][b][0] && maze.cell[a][b][1] && !maze.cell[a][b][2] && !maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[5]);
            else
        if(maze.cell[a][b][0] && !maze.cell[a][b][1] && maze.cell[a][b][2] && !maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[6]);
            else
        if(maze.cell[a][b][0] && !maze.cell[a][b][1] && !maze.cell[a][b][2] && maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[7]);
            else
        if(!maze.cell[a][b][0] && maze.cell[a][b][1] && maze.cell[a][b][2] && !maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[8]);
            else
        if(!maze.cell[a][b][0] && maze.cell[a][b][1] && !maze.cell[a][b][2] && maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[9]);
            else
        if(!maze.cell[a][b][0] && !maze.cell[a][b][1] && maze.cell[a][b][2] && maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[10]);
            else
        if(maze.cell[a][b][0] && maze.cell[a][b][1] && maze.cell[a][b][2] && !maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[11]);
            else
        if(maze.cell[a][b][0] && maze.cell[a][b][1] && !maze.cell[a][b][2] && maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[12]);
            else
        if(maze.cell[a][b][0] && !maze.cell[a][b][1] && maze.cell[a][b][2] && maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[13]);
            else
        if(!maze.cell[a][b][0] && maze.cell[a][b][1] && maze.cell[a][b][2] && maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[14]);
            else
        if(maze.cell[a][b][0] && maze.cell[a][b][1] && maze.cell[a][b][2] && maze.cell[a][b][3])
            cells[a][b].setTexture(& cell_text[15]);
            else
            std::cout<<"BŁAD W LABIRYNCIE, NIE MOZNA DOPASOWAC TEXTURY"<<std::endl;
        }



}

void maluj()
{
     srand(time(NULL));

    for(int a=1;a<41;a++)
        for(int b=1;b<41;b++)
            cells[a][b].setTexture(& cell_text[ rand() % 16 ] );

}

void rysuj() // rysuje pola
{
    for(int a=0;a<42;a++)
        for(int b=0;b<42;b++)
        oknoAplikacji.draw(cells[a][b]);

        oknoAplikacji.draw(gracz);
}

void ustaw_gracza()
{
        gracz.setPosition(x_gracza*SZ_cell+5,y_gracza*WY_cell+5);
}



void gracz_ruch(Event ruch)
{
        if(zdarzenie.key.code == Keyboard::Left)
        {
            if(!Labirynt.cell[x_gracza][y_gracza][3])
                x_gracza--;
        }
        else
        if(zdarzenie.key.code == Keyboard::Up)
        {
            if(!Labirynt.cell[x_gracza][y_gracza][0])
                y_gracza--;

        }
        else
        if(zdarzenie.key.code == Keyboard::Right)
        {
            if(!Labirynt.cell[x_gracza][y_gracza][1])
                x_gracza++;
        }
        else
        if(zdarzenie.key.code == Keyboard::Down)
        {
            if(!Labirynt.cell[x_gracza][y_gracza][2])
                y_gracza++;
        }



}

void help_1()
{
    std::cout<<"Nie przypisano ¿adnych akcji dla tego klawisza"<<std::endl;
}

int main()
{
    settings.antialiasingLevel = 8;
    oknoAplikacji.create(VideoMode(SZER,WYS,bpp),"MAZE",Style::Default,settings);
    tworz();
    ustaw_gracza();


    //buduj(Labirynt,40,40);



    Labirynt.generuj(40,40);
    Labirynt.losuj_start(40,40);


    while(!Labirynt.koniec())
    {
    while(!Labirynt.test())
    {
    Labirynt.ruch(Labirynt.test());

    }
    Labirynt.usun_scianke(Labirynt.losuj_scianke());
    ubierz(Labirynt);
    oknoAplikacji.clear();
    rysuj();
    oknoAplikacji.display();
    // Sleep(0);

    }

    std::cout<<"KONIEC"<<std::endl;

    ubierz(Labirynt);
    oknoAplikacji.clear();
    rysuj();
    oknoAplikacji.display();

    while (oknoAplikacji.isOpen())
    {
        while (oknoAplikacji.pollEvent(zdarzenie))  //Petla eventow
					{

							if (zdarzenie.type == Event::Closed || zdarzenie.key.code == Keyboard::Escape)
							{
								//tu np. zapisanie stanu gry
                                oknoAplikacji.close();
							}

							if (zdarzenie.key.code == Keyboard::Space && zdarzenie.type == Event::KeyPressed)
							{
								buduj(Labirynt,40,40);
								ubierz(Labirynt);
								//x_gracza = 1;y_gracza = ;
								//ustaw_gracza();
							}

							if (zdarzenie.mouseButton.button == Mouse::Left && zdarzenie.type == Event::MouseButtonPressed)
							{
								help_1();
							}

							if (zdarzenie.type == Event::LostFocus)
                            {
                                std::cout<<"PAUZA"<<std::endl;
                            }


                            if (zdarzenie.type == Event::GainedFocus)
                            {
                                std::cout<<"START"<<std::endl;
                            }

                            if(zdarzenie.type == Event::KeyPressed && (zdarzenie.key.code == Keyboard::Left || zdarzenie.key.code == Keyboard::Right || zdarzenie.key.code == Keyboard::Up || zdarzenie.key.code == Keyboard::Down) )
                            {
                                gracz_ruch(zdarzenie);
                                ustaw_gracza();
                            }

					}

        oknoAplikacji.clear();
        rysuj();
        oknoAplikacji.display();
    }


    return 0;
}
