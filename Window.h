#pragma once
#ifndef WINDOW_H_
#define WINDOW_H_

#include "initGame.h"

class Window {
private:
	sf::VideoMode videoMode;
	sf::Font font;
	sf::Text text;

	// init game
	void initValue();
	void initWindow();

	// draw layoutGame
	void drawLayoutGame();
	void drawGrid();
	void renderLevel();
	void renderScore();
	void renderText();
	void renderLayoutGame();

protected:
	sf::RenderWindow* window;
	sf::Event event;

	int score;
	int level;

	// control game
	const bool running() const;
	virtual void pollEvents() = 0;

	// render
	void drawBrick(float _x, float _y);
	void drawBrick(float _x, float _y, float _alpha);
	void renderNextBrick(bool** temp);
	void render();

public:
	// constructor / deconstructor
	Window();
	virtual ~Window();
};

#endif // !WINDOW_H_
