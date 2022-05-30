#include "Game.h"

void Game::updateField() {
	if (!this->isBottom()) return;

	this->score += 1;

	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			if (!this->a[i][j].state) continue;
			int x = this->a[i][j].x;
			int y = this->a[i][j].y;

			if (x < 0) continue;

			this->field[x][y + 1] = true;
		}
	}

	this->setBrick();
}

void Game::update() {
	this->endGame = this->isTop();

	this->resetTime();
	this->pollEvents();
	this->checkLine();

	if (this->timer > this->delay) {
		this->updateField();
		if (this->isMove()) this->moveBrick();
		this->updateLevel();
		this->updateBrick();

		this->timer = 0;
	}

	this->window->clear(sf::Color(0, 0, 0, 100));
	this->renderBrick();
	this->renderField();
	this->render();
}

void Game::renderBrick() {
	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			if (!this->a[i][j].state) continue;

			float x = this->a[i][j].x;
			float y = this->a[i][j].y;

			if (x < 0) continue;

			this->drawBrick(y * squareLength, x * squareLength);
		}
	}

	this->renderNextBrick(this->nextBrick);
}

void Game::renderField() {
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			if (!this->field[i][j + 1]) continue;
			this->drawBrick(j * squareLength, i * squareLength);
		}
	}
}

void Game::updateLevel() {
	this->level += this->score / 100;
	this->score %= 100;

	this->delay = 0.9f;
	this->delay -= this->level * 1.0 / 10;
}

void Game::resetTime() {
	float time = this->clock.getElapsedTime().asSeconds();
	this->clock.restart();
	this->timer += time;
}