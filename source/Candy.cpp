#include "Candy.hpp"
#include<cmath>

Candy::Candy(float x,float y,Color color) : x(x),y(y),color(color) {}

void Candy::drawCandy()
{
    DrawCircle(x,y,CANDY_RADIUS,color);
    Vector2 mouse=GetMousePosition();
    double dx=mouse.x-x;
    double dy=mouse.y-y;
    double distance=sqrt(dx*dx+dy*dy);
    if(distance<=CANDY_RADIUS)
        DrawRing(Vector2{x,y},CANDY_RADIUS+3,CANDY_RADIUS+6,0,360,500,WHITE);
}

bool Candy::isClicked()
{
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse=GetMousePosition();
        double dx=mouse.x-x;
        double dy=mouse.y-y;
        double distance=sqrt(dx*dx+dy*dy);
        if(distance<=CANDY_RADIUS)
            return true;
    }
    return false;
}

bool Candy::operator==(const Candy& other) const
{
    return x==other.x && y==other.y;
}