#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Common.hpp"

class Game {
private:
	sf::Clock clock;
	Paddle* player;
	Paddle* AI;
	Ball* ball;

private:
	sf::RectangleShape line;
	sf::Font arial;
	sf::Text score1, score2;

public:
	Game();

public:
	void Input();
	void Update();
	void Render();
};