#include "initGame.h"

const std::string convertIntToString(int number){
	return std::to_string(number);
}

Coordinates::Coordinates(float _x, float _y) {
	this->x = _x;
	this->y = _y;
}