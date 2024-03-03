#include "Ball.hpp"

Ball::Ball(Paddle* P1, Paddle* P2, float r) : p1(P1), p2(P2)
{
	this->setRadius(r);
	this->setOrigin(sf::Vector2f(r, r));
	this->setPosition(500, 300);
	pos = sf::Vector2f(500, 300);
	this->update();

	vel = sf::Vector2f(speed + rand() % (int)speed, speed + rand() % (int)speed);

	float dir = (int(rand() & 1) == 0) ? -1 : 1;
	vel.x *= dir;

	dir = (int(rand() & 1) == 0) ? -1 : 1;
	vel.y *= dir;
}

void Ball::updateBall(float dt)
{
	if (pos.y <= this->getRadius() || pos.y >= window->getSize().y - this->getRadius()) {
		pos.y -= vel.y * dt;
		vel.y *= -1;
	}
	else if (p1->getGlobalBounds().intersects(this->getGlobalBounds())){
		pos.x -= vel.x * dt;
		vel.x *= -1;
		this->setFillColor(p1->getFillColor());
	} 
	else if (p2->getGlobalBounds().intersects(this->getGlobalBounds())) {
		pos.x -= vel.x * dt;
		vel.x *= -1;
		this->setFillColor(p2->getFillColor());
	}
	else {
		if (pos.x < getRadius()) {
			p2->score += 1;
			reset();
		}
		else if (pos.x > window->getSize().x - getRadius()) {
			p1->score += 1;
			reset();
		}
	}

	pos += vel * dt;

	this->setPosition(pos);
}

void Ball::reset()
{
	this->setFillColor(sf::Color::White);

	this->setPosition(500, 300);
	pos = sf::Vector2f(500, 300);

	vel = sf::Vector2f(speed + rand() % (int)speed, speed + rand() % (int)speed);

	float dir = (int(rand() & 1) == 0) ? -1 : 1;
	vel.x *= dir;

	dir = (int(rand() & 1) == 0) ? -1 : 1;
	vel.y *= dir;
}
