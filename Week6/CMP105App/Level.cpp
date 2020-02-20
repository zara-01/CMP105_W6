#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in):
	zombie(hwnd)
{
	window = hwnd;
	input = in;

	// initialise game objects

	zombieTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombieTexture);
	zombie.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zombie.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}