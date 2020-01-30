#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rectRed.setSize(sf::Vector2f(50, 50));
	rectRed.setPosition(100, 100);
	rectRed.setFillColor(sf::Color::Red);
	speedx = 500.f;
	speedy = 500.f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		speedy -= 10;
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		speedy += 10;
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		speedx -= 10;
	}

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		speedx += 10;
	}
}

// Update game objects
void Level::update(float dt)
{
	rectRed.move(speedx * dt, speedy * dt);
	sf::Vector2u winPos = window->getSize(); //Vector2u creating variable with two values (unsigned variable)
	sf::Vector2f objPos = rectRed.getPosition();//Vector2f creating variable with two values (float variable)
	if (objPos.x+50 > winPos.x)
	{
		speedx = speedx * -1;
	}
	
	if (objPos.y+50 > winPos.y)
	{
		speedy = speedy * -1;
	}

	if (objPos.x < 0)
	{
		speedx = speedx * -1;
	}

	if (objPos.y < 0)
	{
		speedy = speedy * -1;
	}
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