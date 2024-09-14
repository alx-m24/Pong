#include "Paddle.hpp"

Paddle::Paddle(Type myType, sf::Vector2f Pos, sf::Color color) : type(myType), pos(Pos)
{
	this->setSize(sf::Vector2f(10, 100));
	this->setOrigin(sf::Vector2f(this->getSize()) / 2.0f);
	this->setPosition(Pos);
	this->setFillColor(color);
	this->update();
}

unsigned int Paddle::getScore()
{
	return score;
}

void Paddle::updatePaddle(float dt, sf::Vector2f ballPos, sf::Vector2f ballVel, float r)
{
	sf::Vector2u winSize = window->getSize();

	switch (type)
	{
	case Paddle::player: {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) pos.y -= speed * dt;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) pos.y += speed * dt;
		break;
	}
	case Paddle::AI: {
		bool towardsMe = (pos.x < winSize.x / 2.0f) ? ballVel.x < 0 : ballVel.x > 0;

		if (towardsMe) {
			unsigned int n = 0;
			while (ballPos.x > 35 && ballPos.x < winSize.x - 35) {
				++n;

				if (ballPos.y <= r || ballPos.y >= winSize.y - r) {
					ballPos.y -= ballVel.y * dt;
					ballVel.y *= -1;
				}
				ballPos += ballVel * dt;
			}
			float tempVelY = (ballPos.y - pos.y) / n;
			pos.y += tempVelY;
		}
		break;
	}
	default:
		break;
	}

	float limit = winSize.y - this->getSize().y / 2.0f;
	if (pos.y > limit) pos.y = limit;
	else {
		limit = this->getSize().y / 2.0f;
		if (pos.y < limit) pos.y = limit;
	}

	this->setPosition(pos);
}
