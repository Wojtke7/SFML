#pragma once

#include <SFML/Graphics.hpp>
#include <iostream> 

using namespace sf;
using namespace std;

class crossline : public Drawable
{
    private:
        void draw(RenderTarget& target, RenderStates state) const override;
        RectangleShape shape;
        const float crosslineWidth{ 800.0f };
        const float crosslineHeight{ 10.0f };

    public:
        crossline(float t_X, float t_Y);
        ~crossline() = default;        
};