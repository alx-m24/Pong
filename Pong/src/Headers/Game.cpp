#include "Game.hpp"

Game::Game()
{
	player = new Paddle(Paddle::AI, sf::Vector2f(30, window->getSize().y / 2.0f), sf::Color::Red);
	AI = new Paddle(Paddle::AI, sf::Vector2f(window->getSize().x - 30, window->getSize().y / 2.0f), sf::Color::Blue);

	ball = new Ball(player, AI, 8.f);

	arial.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

	score1.setStyle(sf::Text::Bold);
	score1.setFont(arial);
	score1.setCharacterSize(36);
	score1.setFillColor(player->getFillColor());
	score1.setPosition(400, 100);

	score2.setStyle(sf::Text::Bold);
	score2.setFont(arial);
	score2.setCharacterSize(36);
	score2.setFillColor(AI->getFillColor());
	score2.setPosition(600, 100);

	line.setSize(sf::Vector2f(10, window->getSize().y));
	line.setOrigin(sf::Vector2f(line.getSize()) / 2.0f);
	line.setPosition(sf::Vector2f(window->getSize()) / 2.0f);
}

void Game::Input()
{
	sf::Event events;
	while (window->pollEvent(events)) {
		switch (events.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		default:
			break;
		}
	}
}

void Game::Update()
{
	window->clear();

	float time = clock.restart().asSeconds();
	float r = ball->getRadius();
	sf::Vector2f ballPos = ball->getPosition();
	sf::Vector2f ballVel = ball->vel;

	player->updatePaddle(time, ballPos, ballVel, r);
	AI->updatePaddle(time, ballPos, ballVel, r);
	
	ball->updateBall(time);

	score1.setString(std::to_string(player->score));
	score2.setString(std::to_string(AI->score));
}

void Game::Render()
{
	window->draw(line);
	window->draw(score1);
	window->draw(score2);
	window->draw(*player);
	window->draw(*AI);
	window->draw(*ball);

	window->display();
}
