#include "block.h"

block::block(float t_X, float t_Y, float t_Width, float t_Height)
{
   shape.setPosition(t_X, t_Y);
   shape.setSize(Vector2f(t_Width, t_Height));
   shape.setFillColor(Color::Yellow);
   shape.setOrigin(t_Width/2.f, t_Height/2.f);
}

void block::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->shape, state);
}

float block::left()
{
    return this->shape.getPosition().x - shape.getSize().x/2.f;
}


float block::right()
{
    return this->shape.getPosition().x + shape.getSize().x/2.f;
}


float block::top()
{
    return this->shape.getPosition().y - shape.getSize().y/2.f;
}


float block::bottom()
{
    return this->shape.getPosition().y + shape.getSize().y/2.f;
}

bool block::isDestroyed()
{
    return this->destroyed;
}

void block::destroy()
{
    this->destroyed = true;
}

Vector2f block::getSize()
{
    return shape.getSize();
}
 
Vector2f block::getPosition()
{
    return shape.getPosition();
}

