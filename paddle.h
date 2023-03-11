#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class paddle : public Drawable
{
private:
    void draw(RenderTarget& target, RenderStates state) const override;
    RectangleShape shape;
    const float paddleWidth{ 80.0f };
    const float paddleHeight{ 20.0f };
    const float paddleVelocity { 6.0f };
    Vector2f velocity { paddleVelocity, 0.f };

public:
    paddle(float t_X, float t_Y);
    ~paddle() = default;    
    void update();

    Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();
};
