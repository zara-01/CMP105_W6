#include "Zombie.h"
#include "Framework/Vector.h"
#include <SFML/Graphics.hpp>

Zombie::Zombie(sf::RenderWindow* hwnd)
{
	// setting up walk animation 

	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	//initialise gravity

	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;

	window = hwnd;
	sf::Event event;
}

Zombie::~Zombie() {}



void Zombie::handleInput(float dt)
{
	if (input->isMouseLDown())
	{
		stepVelocity = sf::Vector2f(0, 0);
		int x = input->getMouseX();
		int y = input->getMouseY();
		setPosition(x, y);

	}

	/*if (input->isKeyDown(sf::Keyboard::S))
	{
		int x = input->getMouseX();
		int y = input->getMouseY();
		setPosition(x, y);
		
	}*/

	//jump and check if already jumping
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

	//move up
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		move(0, -50 * dt);
	}

	//move down
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		move(0, 50 * dt);
	}

	//move left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		move(-50 * dt, 0);
		walk.setFlipped(true);
	}

	//move right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(50 * dt, 0);
		walk.setFlipped(false);
	}


}

void Zombie::update(float dt)
{

	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());

	
	/*if (getPosition().y >= window->getSize().y)
	{
		setPosition(window->getSize().x, 500);
		stepVelocity=sf::Vector2f(0,0);
	}*/

	// check for collision with bottom of window
	if (getPosition().y > window->getSize().y-108)
	{
		isJumping = false;
		setPosition(getPosition().x, window->getSize().y-108);
		stepVelocity = sf::Vector2f(0, 0);
	}
	else 
	{
		// applying gravity force
		sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; // ut + 1/2at^2
		stepVelocity += gravity * dt;
		setPosition(getPosition() + pos);
	}



}
//zara
