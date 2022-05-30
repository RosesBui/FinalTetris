#include "Window.h"

void Window::initValue() {
	this->window = nullptr;
	this->score = 0;
	this->level = 1;

	this->font.loadFromFile("Fonts/Montserrat-Bold.ttf");

	this->text.setFont(this->font);
}

void Window::initWindow() {
	this->videoMode.height = 800;
	this->videoMode.width = 600;

	this->window = new sf::RenderWindow(
		this->videoMode,
		"Tetris",
		sf::Style::Close | sf::Style::Titlebar
	);

	this->window->setVerticalSyncEnabled(true);

	
}

void Window::renderLayoutGame() {
	this->drawLayoutGame();
	this->drawGrid();
	this->renderText();
}

Window::Window() {
	this->initValue();
	this->initWindow();
}

Window::~Window() {
	delete this->window;
}

const bool Window::running() const {
	return this->window->isOpen();
}

void Window::drawBrick(float _x, float _y) {
	sf::RectangleShape* rect;
	rect = new sf::RectangleShape(sf::Vector2f(squareLength-5.f, squareLength-5.f));
	rect->setFillColor(sf::Color(255,0,0,200));
	rect->setOutlineThickness(2.f);
	rect->setOutlineColor(sf::Color(0, 0, 0, 255));
	rect->setPosition(_x + 2.f, _y + 2.f);
	this->window->draw(*rect);

	delete rect;
}

void Window::drawBrick(float _x, float _y, float _alpha) {
	sf::RectangleShape* rect;
	rect = new sf::RectangleShape(sf::Vector2f(squareLength - 5.f, squareLength - 5.f));
	rect->setFillColor(sf::Color(255, 0, 0, _alpha));
	rect->setOutlineThickness(2.f);
	rect->setOutlineColor(sf::Color(0, 0, 0, _alpha));
	rect->setPosition(_x + 2.f, _y + 2.f);
	this->window->draw(*rect);

	delete rect;
}

void Window::render() {
	this->renderLayoutGame();
	this->window->display();
}