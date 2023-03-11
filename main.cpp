#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Window.hpp>
#include "ball.h"
#include "paddle.h"
#include "block.h"
#include "MainMenu.h"
#include "crossline.h"

using namespace sf;
using namespace std;

template<class T1, class T2> bool isIntersecting(T1& A , T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
};

bool collisionTest(paddle& paddle1, ball& ball1)
{
    if(!isIntersecting(paddle1,ball1)) return false;

    ball1.moveUp();

    if(ball1.getPosition().x < paddle1.getPosition().x)
    {
        ball1.moveLeft();
    }
    else if (ball1.getPosition().x > paddle1.getPosition().x)
    {
        ball1.moveRight();
    }
    
};

bool collisionTest(block& block1, ball& ball1)
{
    if(!isIntersecting(block1,ball1)) return false;

    block1.destroy();

    float overlapLeft{ ball1.right() - block1.left() };
    float overlapRight{ block1.right() - ball1.left() };

    float overlapTop{ ball1.bottom() - block1.top() };
    float overlapBottom { block1.bottom() - ball1.top()};

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{ ballFromTop ? overlapTop : overlapBottom};

    if(abs(minOverlapX) < abs(minOverlapY))
    {
        ballFromLeft ? ball1.moveLeft() : ball1.moveRight();
    }
    else
    {
        ballFromTop ? ball1.moveUp() : ball1.moveDown();
    }
}

int main()
{
    ball ball1(400,300);
    paddle paddle1(400,500);
    crossline crossline1(400,560);

    Texture texture;
    texture.loadFromFile("images/background.jpg");
    Sprite sprite;
    sprite.setTexture(texture);
    
    RenderWindow MENU{ VideoMode{800,600}, "Menu"};
    MENU.setFramerateLimit(60);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
    
    Event event;

    unsigned blocksX { 10 }, blocksY { 6 }, blockWidth { 60 }, blockHeight{ 20 };
    vector<block> blocks;

    for (int i = 0; i < blocksY; i++)
    {
        for (int j = 0; j < blocksX; j++)
        {
            blocks.emplace_back((j+1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
        }
    }    

    while (MENU.isOpen())
    {
        Event event2;
        while (MENU.pollEvent(event2))
        {
            if(event2.type == Event::Closed)
            {
            MENU.close();
            }
            
            if(event2.type == Event::KeyReleased)
            {
                if (event2.key.code == Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if (event2.key.code == Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if (event2.key.code == Keyboard::Return)
                {
                    RenderWindow GAME{ VideoMode{800,600}, "Arcanoid"};
                    GAME.setFramerateLimit(60);
                    RenderWindow OPTIONS{ VideoMode{800,600}, "Options"};
                    OPTIONS.setFramerateLimit(60);

                    int x = mainMenu.mainMenuPressed();
                    if (x == 0)
                    {
                        while (true)
                        {
                            GAME.pollEvent(event);
                            GAME.clear(Color::Black);
                            GAME.draw(sprite);

                            OPTIONS.close();  


                            ball1.update();
                            paddle1.update();
                            
                            for(auto& block1 : blocks) if(collisionTest(block1, ball1)) break;

                            
                            auto iterator = remove_if(begin(blocks), end(blocks), [](block& block1) {return block1.isDestroyed();});
                            blocks.erase(iterator, end(blocks));

                            GAME.draw(ball1);
                            GAME.draw(paddle1);
                            GAME.draw(crossline1);

                            for(auto& block1 : blocks)
                            GAME.draw(block1);

                                
                            GAME.display();
                            collisionTest(paddle1, ball1);

                           /* if(ball1.getPosition().y >= 550)
                            {
                                //Dopisać okno "YOU LOSE, TRY AGAIN !"
                                GAME.();
                                break;
                            }
                               */ 
                            if (event.type == Event::Closed)
                            {
                                GAME.close();
                                break;
                            }
                            if (event.type == Event::KeyPressed)
                            {
                            if (event.key.code == Keyboard::Escape)
                                {
                                    GAME.close();
                                    break;
                                }
                            }
                        }
                    }
                    if(x == 1)
                    {
                        while(OPTIONS.isOpen())
                        {
                            Event event3;
                            while (OPTIONS.pollEvent(event3))
                            {
                                if (event3.type == Event::Closed)
                                {
                                    OPTIONS.close();
                                }
                                if (event3.type == Event::KeyPressed)
                                {
                                    if (event3.key.code == Keyboard::Escape)
                                    {
                                        OPTIONS.close();
                                    }
                                }
                            }  
                        GAME.close();
                        OPTIONS.clear(Color::Black);

                        OPTIONS.display();
                        }
                    }
                    if(x == 2)
                    {
                        MENU.close();
                        break;
                    }
                }
            }
        }    
    MENU.clear();
    MENU.draw(sprite);
    mainMenu.draw(MENU);
    MENU.display();    
    }
    
    return 0;
}