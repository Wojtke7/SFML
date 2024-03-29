#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define Max_main_menu 3

class MainMenu
{
private:
    int MainMenuSelected;
    Font font;
    Text mainMenu[Max_main_menu];

public:
    MainMenu(float width, float height);
    ~MainMenu();

    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int mainMenuPressed()
    {
        return MainMenuSelected;
    }
};

