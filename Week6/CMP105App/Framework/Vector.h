// This vector class provides a few addition vector functions for working with sf::Vector2f
// The functions are static and therefore the class does not require to be initialised.
// @author Paul Robertson

#pragma once
#include "SFML\System\Vector2.hpp"
#include <math.h>

class Vector
{
public:
	// Returns a normalised vector
	static sf::Vector2f normalise(const sf::Vector2f &source);
	// Returns the Vector magnitude
	static float magnitude(const sf::Vector2f vec);
	// 
	static float dot(const sf::Vector2f& s1, const sf::Vector2f& s2);
	static float determinte(const sf::Vector2f& s1, const sf::Vector2f& s2);
};

