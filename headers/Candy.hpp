#ifndef CANDY_HPP
#define CANDY_HPP

#include<raylib.h>

const float CANDY_RADIUS=25;

class Candy
{
    private:
    float x;
    float y;
    Color color;

    public:
    Candy(float x,float y,Color color);
    void drawCandy();
    bool isClicked();
    bool operator==(const Candy& other) const;
};

#endif