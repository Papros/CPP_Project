#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace sf;

int SZER = 600, WYSO = 600,bpp = 32;
int pom[100][2];
int body[100][2];
int BODY_S;
int WektorX,WektorY;

RenderWindow oknoAplikacji;
ContextSettings settings;


RectangleShape cialo;
int p_X,p_Y;
bool punkt,koniec;

void punkty()
{
     srand (time(NULL));
     srand (rand());
     p_X = (rand() % 100)*6;
     p_Y = (rand() % 100)*6;
}

void kolizja()
{
    for(int a=1;a<BODY_S;a++)
    {
        if(body[0][0] == body[a][0] && body[0][1]== body[a][1])
            koniec = true;
    }

    if(body[0][0] > 600 || body[0][0] < 0 || body[0][1] > 600 || body[0][1]<0 || BODY_S > 99)
    {
        koniec = true;
    }

    if(body[0][0] == p_X && body[0][1] == p_Y)
        {
            punkt = false;
            BODY_S++;
        }

}


void waz()
{

    for(int a=0;a<BODY_S;a++)
    {
        pom[a][0] = body[a][0];
        pom[a][1] = body[a][1];
    }

    body[0][0] += WektorX*6;
    body[0][1] += WektorY*6;

    for(int a=1;a<BODY_S;a++)
    {
        body[a][0] = pom[a-1][0];
        body[a][1] =  pom[a-1][1];
    }

}

void ubierz()
{
    for(int a=1;a<BODY_S;a++)
    {
        cialo.setPosition(body[a][0],body[a][1]);
        oknoAplikacji.draw(cialo);
    }

}


void reset()
{
    BODY_S = 3;
    body[0][0] = 300;
    body[0][1] = 300;
    punkt = false;
    cialo.setPosition(300,300);
    waz();
    koniec = false;
}

int main()
{
    reset();
    cialo.setSize(Vector2f(6,6));
    cialo.setFillColor(Color::Green);
    settings.antialiasingLevel = 8;
    oknoAplikacji.create(VideoMode(SZER,WYSO,bpp),"SNAKE",Style::Default,settings);

    while( oknoAplikacji.isOpen() )
    {
        Event event;
        while( oknoAplikacji.pollEvent( event ) )
        {
            if( event.type == Event::Closed || event.key.code == Keyboard::Escape)
                 oknoAplikacji.close();
            else
            if( event.key.code == Keyboard::W)
                {
                    WektorX = 0;
                    WektorY = -1;
                }
            else
             if( event.key.code == Keyboard::S)
                {
                    WektorX = 0;
                    WektorY = 1;
                }
            else
            if( event.key.code == Keyboard::D)
                {
                    WektorX = 1;
                    WektorY = 0;
                }
            else
            if( event.key.code == Keyboard::A)
                {
                    WektorX = -1;
                    WektorY = 0;
                }



        } //while
        oknoAplikacji.clear();
        waz();
        ubierz();

        if(!punkt)
            {
                punkty();
                punkt = true;
            }
        cialo.setPosition(p_X,p_Y);
        oknoAplikacji.draw(cialo);

        kolizja();

        if(koniec)reset();
        oknoAplikacji.display();
        Sleep(100);

    } //while


    return 0;
}
