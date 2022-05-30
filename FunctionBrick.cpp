#include "Brick.h"

void Brick::updateBrick() {
	*(this->dx) = 0;
	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			this->a[i][j].x += 1;
		}
	}

	if (this->rotateBrick) this->isRotate();
}

void Brick::moveBrick() {
	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			this->a[i][j].y += *(this->dx);
		}
	}
}

void Brick::resetValue() {
	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			this->a[i][j].x = i - nShape;
			this->a[i][j].y = j + (nCol - 1) / 2;
			this->a[i][j].state = this->nextBrick[i][j];
		}
	}

	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			this->nextBrick[i][j] = false;
		}
	}
}

void Brick::setBrick() {
	this->resetValue();
	this->newBrick();
}

void Brick::newBrick() {
	this->randomBrick(this->nextBrick);
}

void Brick::isRotate() {
	bool** temp = new bool* [nShape];
	for (int i = 0; i < nShape; i++) temp[i] = new bool[nShape];

	for (int j = nShape; j > 0; j--) {
		for (int i = 0; i < nShape; i++) temp[nShape - j][i] = a[i][j - 1].state;
	}

	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) a[i][j].state = temp[i][j];
	}

	for (int i = 0; i < nShape; i++) delete[] temp[i];
	delete[] temp;

	this->rotateBrick = false;
}