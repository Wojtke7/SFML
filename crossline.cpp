#include "crossline.h"

crossline::crossline(float t_X, float t_Y)
{
    shape.setPosition(t_X, t_Y);
    shape.setSize(Vector2f(this->crosslineWidth, this->crosslineHeight));
    shape.setFillColor(Color::Cyan);
    shape.setOrigin(crosslineWidth/2.f, crosslineHeight/2.f);
}

void crossline::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
}