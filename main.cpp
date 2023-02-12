#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ball.h"

using namespace sf;
using namespace std;

int main()
{
    ball ball1(400,300);
    RenderWindow window{ VideoMode{800,600}, "Arcanoid tutorial"};
    window.setFramerateLimit(60);
    Event event;
    while(true)
    {
        window.clear(Color::Black);
        window.pollEvent(event);

        if(event.type == Event::Closed)
        {
            window.close();
            break;
        }
        
        ball1.update();
        window.draw(ball1);
        window.display();

    }

    return 0;
}