#include "Game.h"

const bool Game::isBottom() const {
	for (int i = nShape; i > 0; i--) {
		for (int j = 0; j < nShape; j++) {
			if (!this->a[i - 1][j].state) continue;
			int x = this->a[i - 1][j].x;
			int y = this->a[i - 1][j].y;

			if (x < 0) continue;

			if (this->field[x + 1][y + 1]) return true;
		}
	}

	return false;
}

const bool Game::isTop() const {
	for (int j = 0; j < nCol; j++) {
		if (this->field[0][j + 1]) return true;
	}
	return false;
}

const bool Game::isMove() const {
	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			if (!this->a[i][j].state) continue;

			int x = this->a[i][j].x;
			int y = this->a[i][j].y + 1 + *(this->dx);

			if (x < 0) continue;

			if (this->field[x][y]) return false;
		}
	}

	return true;
}

void Game::checkLine() {
	for (int i = 0; i < nRow; i++) {
		bool isCheckLine = true;
		for (int j = 1; j <= nCol; j++) {
			if (!this->field[i][j]) {
				isCheckLine = false;
				break;
			}
		}
		if (isCheckLine) {
			this->deleteLine(i);
			this->score += 10;
		}
	}
}

void Game::deleteLine(int x) {
	for (int i = x; i > 0; i--) {
		for (int j = 1; j <= nCol; j++) {
			this->field[i][j] = this->field[i - 1][j];
		}
	}
}

const bool Game::gameOver() const {
	return this->endGame && this->running();
}