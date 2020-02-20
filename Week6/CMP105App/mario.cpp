#include "mario.h"
#include "Framework/Vector.h"

mario::mario()
{
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 3.f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 4.f);

	duck.addFrame(sf::IntRect(0, 42, 16, 20));
	duck.addFrame(sf::IntRect(16, 42, 16, 20));
	duck.setFrameSpeed(2.f / 3.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());

	scale = 200.0f;
	speed = 0;
	direction = sf::Vector2f();
	scale = 21;
	

}

mario::~mario() {}

void mario::handleInput(float dt)
{
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
		currentAnimation->setFlipped(true);
	}

	//move right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(50 * dt, 0);
		currentAnimation->setFlipped(false);
	}


}


void mario::update(float dt)
{
	pointA = sf::Vector2f(getPosition().x, getPosition().y);
	pointB = sf::Vector2f(input->getMouseX(), input->getMouseY());

	speed += 2 * dt;

	direction = pointB - pointA;
	direction = Vector::normalise(direction);
	velocity = (direction * speed) * scale;

	move(velocity * dt);

	if (Vector::magnitude(pointB - getPosition()) <= 2.f)
	{
		setPosition(pointB);
		speed = 0;
	}

	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::W))
	{
		currentAnimation = &walk;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		currentAnimation = &swim;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::D))
	{
		currentAnimation = &duck;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}

}