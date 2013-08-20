#include "paddle.h"
#include "gameObject.h"

Paddle::Paddle(bool isPlayer, int screenWidth, int screenHeight)
{
	player = isPlayer;
	screenX = screenWidth;
	screenY = screenHeight;
}

void Paddle::Init()
{
	paddleWidth = 15;
	paddleHeight = 150;
	playerSpin = 0.1f;
	compSpin = 0.1f;
	paddleBuffer.loadFromFile("Content/paddleHit.wav");
	paddleSound.setVolume(80);
	paddleSound.setBuffer(paddleBuffer);
	velocity.x = 0.1f;
	velocity.y = 0.1f;
	m_Paddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	m_Paddle.setOutlineThickness(5);

	if (player)
	{
		m_Paddle.setOutlineColor(sf::Color::Blue);
		m_Paddle.setPosition(20,20);
	}
	else
	{
		m_Paddle.setOutlineColor(sf::Color::Red);
		m_Paddle.setPosition(screenX - 40,20);
	}

}

void Paddle::Update(Ball* ball)
{
	CheckCollisions(ball);

	position = m_Paddle.getPosition();
	if (player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_Paddle.move(0, -0.2f);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_Paddle.move(0, 0.2f);

		}
	}
	else
	{	// Comp Paddle AI
		if (m_Paddle.getPosition().y + 65 >= ball->gameBall.getPosition().y)
		{
			m_Paddle.move(0, -0.16f);
		}
		else if (m_Paddle.getPosition().y + 65 <= ball->gameBall.getPosition().y)
		{
			m_Paddle.move(0, 0.16f);
		}
	}
}

void Paddle::Draw(sf::RenderWindow *window)
{
	window->draw(m_Paddle);
}

void Paddle::CheckCollisions(Ball* m_ball)
{
	if (m_Paddle.getPosition().y <= 0)
	{
		m_Paddle.setPosition(sf::Vector2f(position.x,0));
	}

	if (m_Paddle.getPosition().y >= screenY - paddleHeight)
	{
		m_Paddle.setPosition(sf::Vector2f(position.x,screenY - paddleHeight));
	}

	if (player)
	{
		if ((m_ball->gameBall.getPosition().x < m_Paddle.getPosition().x + 20) && 
			(m_ball->gameBall.getPosition().x > m_Paddle.getPosition().x))
		{
			if ((m_ball->gameBall.getPosition().y < m_Paddle.getPosition().y + paddleHeight) &&
				(m_ball->gameBall.getPosition().y > m_Paddle.getPosition().y))
			{
				m_ball->Velocity(sf::Vector2f(m_ball->Velocity().x * 1.1f, m_ball->Velocity().y * 1.1f));
				m_ball->Velocity(sf::Vector2f(m_ball->Velocity().x * -1, m_ball->Velocity().y));
				paddleSound.play();
				m_ball->gameBall.setPosition(m_Paddle.getPosition().x + paddleWidth + 15, m_ball->gameBall.getPosition().y);
				paddleHeight -= 5;
				m_Paddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					m_ball->Velocity(sf::Vector2f(m_ball->Velocity().x, m_ball->Velocity().y - 0.04f));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					m_ball->Velocity(sf::Vector2f(m_ball->Velocity().x, m_ball->Velocity().y + 0.04f));
				}
			}
		}
	}
	else
	{
		if ((m_ball->gameBall.getPosition().x < m_Paddle.getPosition().x) && 
			(m_ball->gameBall.getPosition().x > m_Paddle.getPosition().x - 20))
		{
			if ((m_ball->gameBall.getPosition().y < m_Paddle.getPosition().y + paddleHeight) &&
				(m_ball->gameBall.getPosition().y > m_Paddle.getPosition().y - 50))
			{
				m_ball->Velocity(sf::Vector2f(m_ball->Velocity().x * 1.1f, m_ball->Velocity().y * 1.1f));
				m_ball->Velocity(sf::Vector2f(m_ball->Velocity().x * -1, m_ball->Velocity().y));
				paddleSound.play();
				m_ball->gameBall.setPosition(m_Paddle.getPosition().x - paddleWidth - 15, m_ball->gameBall.getPosition().y);
				paddleHeight -= 5;
				m_Paddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
			}
		}
	}
}

void Paddle::resetPaddleSize()
{
	paddleHeight = 150;
}