#pragma once
#ifndef BRICK_H_
#define BRICK_H_

#include "initGame.h"
#include <time.h>

class Brick
{
private:
	// init game
	void initValue();
	void resetValue();
	void randomBrick(bool ** temp);
	void newBrick();

	void isRotate();

protected:
	Point** a = new Point * [nShape];
	bool** nextBrick = new bool* [nShape];
	int* dx;
	bool rotateBrick;

	// control game
	void setBrick();
	void updateBrick();
	void moveBrick();

public:
	// constructor / deconstructor
	Brick();
	virtual ~Brick();
};

#endif // !BRICK_H_
