#include "Brick.h"

void Brick::moveBrick() {
	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			this->a[i][j].y += *(this->dx);
		}
	}
}