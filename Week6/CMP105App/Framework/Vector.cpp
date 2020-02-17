#include "Vector.h"

// Returns a normalised vector
sf::Vector2f Vector::normalise(const sf::Vector2f &source)
{
	float length = (float)sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

// Returns the Vector magnitude
float Vector::magnitude(const sf::Vector2f vec)
{
	return (float)sqrt((vec.x*vec.x) + (vec.y*vec.y));
}

float Vector::dot(const sf::Vector2f& s1, const sf::Vector2f& s2)
{
	return s1.x * s2.x + s1.y * s2.y;
}

float Vector::determinte(const sf::Vector2f& s1, const sf::Vector2f& s2)
{
	return -s1.x * s2.y + s1.y * s2.x;
}
