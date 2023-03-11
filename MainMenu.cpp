#include "MainMenu.h"


MainMenu::MainMenu(float width, float height)
{
    if(!font.loadFromFile("Fonts/AlexandriaFLF.ttf"))
    {
        cout << "No font here !!!";
    }

    //Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(300,150);

    //Options
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Options");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(300,250);

    //Exit

    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("Exit");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(300,350);

    MainMenuSelected = -1;
}

MainMenu::~MainMenu()
{

}

void MainMenu::draw(RenderWindow& window)
{
    for (int i = 0; i < Max_main_menu; i++)
    {
        window.draw(mainMenu[i]);
    }
}

void MainMenu::MoveUp()
{
    if (MainMenuSelected - 1 >= 0)
    {
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected--;
        if (MainMenuSelected == -1)
        {
            MainMenuSelected == 2;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

void MainMenu::MoveDown()
{
    if (MainMenuSelected + 1 <= Max_main_menu)
    {
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected++;
        if (MainMenuSelected == 3)
        {
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}
