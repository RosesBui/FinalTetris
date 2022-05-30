#include "Brick.h"

void Brick::initValue() {
	for (int i = 0; i < nShape; i++) {
		this->a[i] = new Point[nShape];
	}

	for (int i = 0; i < nShape; i++) {
		this->nextBrick[i] = new bool[nShape];
		for (int j = 0; j < nShape; j++) this->nextBrick[i][j] = false;
	}

	this->dx = new int;
	*this->dx = 0;
}

// constructor / deconstructor
Brick::Brick() {
	this->initValue();

	for (int i = 0; i < nNext; i++) this->newBrick();

	this->setBrick();

	this->rotateBrick = false;
}

Brick::~Brick() {
	for (int i = 0; i < nShape; i++) {
		delete[] this->a[i];
	}
	delete[] this->a;

	for (int i = 0; i < nShape; i++) {
		delete[] this->nextBrick[i];
	}

	delete[] this->nextBrick;

	delete this->dx;
}

void Brick::randomBrick(bool** temp) {
	srand(time(0));
	int x = rand() % countBrickShape;
	//x = 0;
	if (x == 0) { // o brick
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				temp[i][j] = true;
			}
		}
	}
	if (x == 1) {
		for (int j = 0; j < nShape; j++) temp[0][j] = 1;
		temp[1][1] = 1;
	}

	if (x == 2) {
		for (int i = 0; i < nShape; i++) {
			temp[i][1] = 1;
		}
		temp[2][0] = 1;
	}

	if (x == 3) {
		temp[0][0] = 1;
		temp[0][1] = 1;
		temp[1][1] = 1;
		temp[1][2] = 1;
	}

	if (x == 4) {
		temp[0][0] = 1;
		temp[0][1] = 1;
		temp[1][0] = 1;
		temp[1][1] = 1;
	}

	if (x == 5) {
		for (int i = 0; i < nShape; i++) {
			temp[i][1] = 1;
		}
	}
}