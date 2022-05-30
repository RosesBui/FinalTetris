#pragma once
#ifndef INITGAME_H_
#define INITGAME_H_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>

const int nRow = 20;
const int nCol = 10;

const float squareLength = 40.f;

const int countBrickShape = 6;

const int nShape = 3;

const int nNext = 3;

struct Point {
    int x, y;
    bool state;
    Point() {
        this->x = 0;
        this->y = 0;
        this->state = 0;
    }
};

struct Coordinates {
    float x, y;
    Coordinates(float, float);
};

const std::string convertIntToString(int number);

#endif // !INITGAME_H_
