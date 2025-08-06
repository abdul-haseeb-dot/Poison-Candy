#include "Candy.hpp"
#include "Screens.hpp"
#include "Utils.hpp"
#include<raylib.h>
#include<vector>
#include<string>
#include<list>
#include<random>
using namespace std;

const int SCREEN_WIDTH=1200;
const int SCREEN_HEIGHT=700;
const Color TABLE_COLOR=DARKBROWN;

int main()
{
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Poison Candy");
    SetTargetFPS(60);

    list<Candy> candies;
    auto chooseColor=[]()
    {
        vector<Color> colors={ORANGE,RED,GREEN,LIME,PURPLE,BEIGE,VIOLET,MAGENTA,PINK};
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0,colors.size()-1);
        return colors[dist(gen)];
    };
    int startX=150;
    int startY=250;
    int gapX=180;
    int gapY=95;
    for(int i=1;i<=5;i++)
    {
        int x=startX;
        for(int j=1;j<=6;j++)
        {
            Candy candy(x,startY,chooseColor());
            candies.push_back(candy);
            x+=gapX;
        }
        startY+=gapY;
    }

    Screens current=Screens::INSTRUCTIONS;
    Candy* poison1=nullptr;
    Candy* poison2=nullptr;
    bool isPlayer1Turn=true;

    char title[]="POISON CANDY";
    int titleSize=80;
    int titleX=(SCREEN_WIDTH-MeasureText(title,titleSize))/2;
    int titleY=50;

    string instructions="1. Candies are spread on the table.\n2. Player 1 chooses a candy first to poison while Player 2 looks away.\n3. Player 2 chooses a candy to poison next while Player 1 looks away.\n4. Once two candies are poisoned,  players will simultaneously eat a candy.\n5. If any player eats a poisoned candy, they die and the other player wins.";
    auto lines=SplitLines(instructions);
    int fontSize=30;
    int lineSpacing=15;
    int x;
    int y;

    const char* prompt;
    int promptSize=35;
    int promptX;
    int promptY=titleY+titleSize+lineSpacing;

    bool gameRunning=true;
    while(!WindowShouldClose() && gameRunning)
    {
        BeginDrawing();

        switch(current)
        {
            case Screens::INSTRUCTIONS:
                ClearBackground(MAROON);
                DrawText(title,titleX,titleY,titleSize,YELLOW);
                x=25;
                y=220;
                DrawText("Instructions:",x,y,30,GOLD);
                y+=fontSize+lineSpacing;
                for(const auto &line:lines)
                {
                    DrawText(line.c_str(),x,y,fontSize,WHITE);
                    y+=fontSize+lineSpacing;
                }
                DrawText("Click anywhere to continue...",x,y,30,GOLD);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    current=Screens::CHOOSE_POISON;
                }
                break;

            case Screens::CHOOSE_POISON:
                ClearBackground(TABLE_COLOR);
                DrawText(title,titleX,titleY,titleSize,YELLOW);
                if(!poison1)
                {
                    prompt="Player 1 Choose A Candy To Poison";
                }
                else
                {
                    prompt="Player 2 Choose A Candy To Poison";
                }
                promptX=(SCREEN_WIDTH-MeasureText(prompt,promptSize))/2;
                DrawText(prompt,promptX,promptY,promptSize,WHITE);
                for(auto &candy:candies)
                {
                    candy.drawCandy();
                    if(candy.isClicked())
                    {
                        if(!poison1)
                        {
                            poison1=&candy;
                        }
                        else
                        {
                            poison2=&candy;
                            current=Screens::PLAYER_TURN;
                        }
                    }
                }
                break;

            case Screens::PLAYER_TURN:
                ClearBackground(TABLE_COLOR);
                DrawText(title,titleX,titleY,titleSize,YELLOW);
                prompt=isPlayer1Turn?"Player 1 Choose A Candy To Eat":"Player 2 Choose A Candy To Eat";
                promptX=(SCREEN_WIDTH-MeasureText(prompt,promptSize))/2;
                DrawText(prompt,promptX,promptY,promptSize,WHITE);
                for(auto it=candies.begin();it!=candies.end();++it)
                {
                    it->drawCandy();
                    if(it->isClicked())
                    {
                        if(*it==*poison1 || *it==*poison2)
                        {
                            current=Screens::GAME_OVER;
                        }
                        else
                        {
                            candies.erase(it);
                            isPlayer1Turn=!isPlayer1Turn;
                        }
                        break;
                    }
                }
                break;
            
            case Screens::GAME_OVER:
                ClearBackground(BEIGE);
                DrawText(title,titleX,titleY,titleSize,GOLD);
                
                const char* deathMessage=isPlayer1Turn?"PLAYER 1 GOT POISONED AND DIED":"PLAYER 2 GOT POISONED AND DIED";
                const char* winMessage=isPlayer1Turn?"PLAYER 2 WON!":"PLAYER 1 WON!";
                
                int deathSize=40;
                int winSize=55;
                int exitSize=30;
                
                int deathX=(SCREEN_WIDTH-MeasureText(deathMessage,deathSize))/2;
                int winX=(SCREEN_WIDTH-MeasureText(winMessage,winSize))/2;
                int exitX=(SCREEN_WIDTH-MeasureText("Click Anywhere To Exit",exitSize))/2;
                
                int deathY=270;
                int winY=340;
                int exitY=410;
                
                DrawText(deathMessage,deathX,deathY,deathSize,MAROON);
                DrawText(winMessage,winX,winY,winSize,DARKGREEN);
                DrawText("Click Anywhere To Exit",exitX,exitY,exitSize,WHITE);
                
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    gameRunning=false;
                break;
        }

        EndDrawing();
    }

    return 0;
}