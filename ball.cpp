#include "ball.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



ball::ball(float t_X, float t_Y)
{
    shape.setPosition(t_X, t_Y);
    shape.setRadius(this->ballRadius);
    shape.setFillColor(Color::Red);
    shape.setOrigin(this->ballRadius, this->ballRadius);
}

void ball::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->shape, state);
}


void ball::update()
{
    shape.move(this->velocity);

    if (this->left() < 0)
    {
        velocity.x = ballVelocity;
    }
    else if (this->right() > 800)
    {
        velocity.x = -ballVelocity;
    }
    else if (this->top() < 0)
    {
        velocity.y = ballVelocity;
    }
    else if (this->bottom() > 600)
    {
        velocity.y = -ballVelocity;
    }
}

Vector2f ball::getPosition()
{
    return shape.getPosition();
}

void ball::moveUp()
{
    this->velocity.y = -ballVelocity;
}

void ball::moveDown()
{
    this->velocity.y = ballVelocity;
}

void ball::moveRight()
{
    this->velocity.x = ballVelocity;
}

void ball::moveLeft()
{
    this->velocity.x = -ballVelocity;
}

float ball::left()
{
    return this->shape.getPosition().x - shape.getRadius();
}


float ball::right()
{
    return this->shape.getPosition().x + shape.getRadius();
}


float ball::top()
{
    return this->shape.getPosition().y - shape.getRadius();
}


float ball::bottom()
{
    return this->shape.getPosition().y + shape.getRadius();
}
