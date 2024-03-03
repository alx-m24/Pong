#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class Ball : public sf::CircleShape {
private:
	Paddle* p1 = nullptr;
	Paddle* p2 = nullptr;
	float speed = 400;

public:
	sf::Vector2f pos = { 0, 0 }, vel = { 0 , 0 };

public:
	Ball(Paddle* P1, Paddle* P2, float r);

public:
	void updateBall(float dt);
	void reset();
};