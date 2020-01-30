#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rectRed.setSize(sf::Vector2f(50, 50));
	rectRed.setPosition(100, 100);
	rectRed.setFillColor(sf::Color::Red);
	speedx = 100.f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	rectRed.move(speed * dt, 0);
	sf::Vector2u pos = window->getSize();
	rectGreen2.setPosition((pos.x - 50), (pos.y - 50));
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rectRed);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}