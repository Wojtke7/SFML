#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class ball : public sf::Drawable
{
private:
    CircleShape shape;
    const float ballRadius{ 10.0f };
    const float ballVelocity{ 3.0f };
    Vector2f velocity{ ballVelocity, ballVelocity };
    void draw(RenderTarget& target, RenderStates state) const override;
public:
    ball(float t_X, float t_Y);
    ~ball() = default;

    void update();

    float left();
    float right();
    float top();
    float bottom();
};


