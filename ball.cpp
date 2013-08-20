#include "ball.h"
#include "gameObject.h"

Ball::Ball(int screenWidth, int screenHeight)
{
	screenX = screenWidth;
	screenY = screenHeight;
}

void Ball::Init()
{
	ballRadius = 10;
	gameBall.setRadius(ballRadius);
	velocity = sf::Vector2f(0.1f, 0.08f);
	gameBall.setFillColor(sf::Color::Green);
	gameBall.setPosition(screenX / 2, screenY / 3);
	wallBuffer.loadFromFile("Content/wallHit.wav");
	wallSound.setVolume(20);
	wallSound.setBuffer(wallBuffer);
}

void Ball::Update()
{
	position = gameBall.getPosition();
	gameBall.move(velocity.x, velocity.y);
	CheckCollisions();
}

void Ball::Draw(sf::RenderWindow *window)
{
	window->draw(gameBall);
}

void Ball::CheckCollisions()
{
	// Wall collisions
	if (gameBall.getPosition().y >= screenY - 10)
	{
		velocity.y *= -1;
		wallSound.play();
	}

	if (gameBall.getPosition().y <= 0)
	{
		velocity.y *= -1;
		wallSound.play();
	}
}