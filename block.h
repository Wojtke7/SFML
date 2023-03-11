#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class block : public Drawable
{
    public:
    
    block(float t_X, float t_Y, float t_Width, float t_Height);
    ~block() = default; 

    void update();
    Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();

    bool isDestroyed();
    void destroy();
    Vector2f getSize();

    private:
    virtual void draw(RenderTarget& target, RenderStates states) const override;
    RectangleShape shape;
    bool destroyed{ false };
};



