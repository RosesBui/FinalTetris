#include "Game.h"

void Game::initValue() {
	for (int i = 0; i < nRow + 1; i++) {
		for (int j = 0; j < nCol + 2; j++) {
			this->field[i][j] = false;
		}
	}

	for (int i = 0; i < nRow + 1; i++) {
		this->field[i][0] = this->field[i][nCol + 1] = true;
	}
	for (int j = 0; j < nCol + 2; j++) this->field[nRow][j] = true;

	this->endGame = false;
}

void Game::pollEvents() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->closeWindow();
		}
		else if (this->event.type == sf::Event::KeyPressed) {
			if (this->event.key.code == sf::Keyboard::Escape) {
				this->closeWindow();
			}
			else if (this->event.key.code == sf::Keyboard::Space) {
				this->rotateBrick = true;
			}
			else if (this->event.key.code == sf::Keyboard::Left) {
				*(this->dx) = -1;
			}
			else if (this->event.key.code == sf::Keyboard::Right) {
				*(this->dx) = 1;
			}
			else if (this->event.key.code == sf::Keyboard::Down) {
				this->delay = this->delay / 2;
			}
		}
	}
}

Game::Game() {
	this->initValue();
	this->setBrick();
}

Game::~Game() {
}

void Game::resetValue() {
	this->updateField();
	this->setBrick();
}

void Game::closeWindow() {
	this->window->close();
}