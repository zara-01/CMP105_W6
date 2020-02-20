#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include <SFML/Graphics.hpp>

class Zombie : public GameObject
{

public:

	Zombie(sf::RenderWindow* hwnd);
	~Zombie();

	void handleInput(float dt);
	//void update(float dt);

	void update(float dt) override;


protected:

	sf::RenderWindow* window;

	Animation walk;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	bool isJumping;


};

//zara