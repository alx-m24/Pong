#pragma once
#include <SFML/Graphics.hpp>
#include "Common.hpp"

class Paddle : public sf::RectangleShape {
private:
	float speed = 600.0f;

private:
	sf::Vector2f pos;

public:
	enum Type
	{
		player,
		AI
	};
	Type type;
	unsigned int score = 0;

public:
	Paddle(Type myType, sf::Vector2f Pos, sf::Color color);

public:
	unsigned int getScore();
	void updatePaddle(float dt, sf::Vector2f ballPos, sf::Vector2f ballVel, float r);
};