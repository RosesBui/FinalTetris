#include "Window.h"

void Window::drawLayoutGame() {
	sf::RectangleShape* line = new sf::RectangleShape(sf::Vector2f(squareLength * nRow, 5.f));
	line->setPosition(squareLength * nCol, 0.f);
	line->setFillColor(sf::Color(0, 0, 0, 200));
	line->rotate(90.f);
	this->window->draw(*line);
	delete line;
}

void Window::drawGrid() {
	/*for (int i = 0; i < nCol; i++) {
		sf::RectangleShape* line = new sf::RectangleShape(sf::Vector2f(squareLength * nRow, 2.f));
		line->setPosition(i * squareLength, 0.f);
		line->setFillColor(sf::Color(100, 100, 100, 50));
		line->rotate(90.f);
		this->window->draw(*line);
		delete line;
	}

	for (int j = 0; j < nRow; j++) {
		sf::RectangleShape* line = new sf::RectangleShape(sf::Vector2f(squareLength * nCol, 2.f));
		line->setPosition(0.f, j * squareLength);
		line->setFillColor(sf::Color(100, 100, 100, 50));
		this->window->draw(*line);
		delete line;
	}*/

	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			this->drawBrick(j * squareLength, i * squareLength, 100);
		}
	}
}

void Window::renderScore() {
	float x = squareLength * nCol + 10.f;
	float y = 6 * squareLength;

	this->text.setString("SCORE:");
	this->text.setFillColor(sf::Color::Red);
	this->text.setCharacterSize(30);
	this->text.setStyle(sf::Text::Underlined | sf::Text::Italic);
	this->text.setPosition(x, y);

	this->window->draw(this->text);

	this->text.setString(convertIntToString(this->score));
	this->text.setFillColor(sf::Color::Blue);
	this->text.setCharacterSize(30);
	this->text.setStyle(sf::Text::Bold | sf::Text::Italic);
	this->text.setPosition(x, y + 2 * squareLength);

	this->window->draw(this->text);
}

void Window::renderLevel() {
	float x = squareLength * nCol + 10.f;
	float y = 10 * squareLength;

	this->text.setString("LEVEL:");
	this->text.setFillColor(sf::Color::Red);
	this->text.setCharacterSize(30);
	this->text.setStyle(sf::Text::Underlined | sf::Text::Italic);
	this->text.setPosition(x, y);

	this->window->draw(this->text);

	this->text.setString(convertIntToString(this->level));
	this->text.setFillColor(sf::Color::Blue);
	this->text.setCharacterSize(30);
	this->text.setStyle(sf::Text::Bold | sf::Text::Italic);
	this->text.setPosition(x, y + 2 * squareLength);

	this->window->draw(this->text);
}

void Window::renderText() {
	this->renderScore();
	this->renderLevel();
}

void Window::renderNextBrick(bool** temp) {
	float x = squareLength * nCol + 10.f;
	float y = 0.f;

	this->text.setString("NEXT:");
	this->text.setFillColor(sf::Color::Red);
	this->text.setCharacterSize(30);
	this->text.setStyle(sf::Text::Underlined | sf::Text::Italic);
	this->text.setPosition(x, y);

	this->window->draw(this->text);

	for (int i = 0; i < nShape; i++) {
		for (int j = 0; j < nShape; j++) {
			if (!temp[i][j]) continue;

			float y = (2 + i) * squareLength;
			float x = (nCol + j) * squareLength + 10.f;

			this->drawBrick(x, y);
		}
	}
}