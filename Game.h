#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "Window.h"
#include "Brick.h"
#include "initGame.h"
#include <iostream>

class Game : private Window, private Brick {
protected:
    bool field[nRow+1][nCol+2];
    bool endGame;

    sf::Clock clock;
    float delay = 0.9f;
    float timer = 0.f;

    // init game
    void initValue();
    void resetTime();

    // check game
    const bool isBottom() const;
    const bool isTop() const;
    const bool isMove() const;
    void checkLine();
    void deleteLine(int x);

    void pollEvents();
    void updateLevel();

    // render
    void renderBrick();
    void renderField();

public:
    // constructor / deconstructor
    Game();
    virtual ~Game();
    void resetValue();

    // update
    void update();
    void updateField();


    // game over
    const bool gameOver() const;
    void closeWindow();
};

#endif // GAME_H_