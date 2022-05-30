#include "Game.h"

void Game::drawBrick(float _x, float _y) {
	sf::RectangleShape* rect;
	rect = new sf::RectangleShape(sf::Vector2f(squareLength, squareLength));
	rect->setFillColor(sf::Color::Red);
	rect->setOutlineColor(sf::Color::Red);
	rect->setPosition(_x, _y);
	this->window->draw(*rect);

	delete rect;
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
}

void Game::renderField() {
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			if (!this->field[i][j + 1]) continue;
			this->drawBrick(j * squareLength, i * squareLength);
		}
	}
}