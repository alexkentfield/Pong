#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "soundManager.h"
#include <sstream>
#include "ball.h"
#include "paddle.h"

using namespace std;

class PongGame
{
private:

	bool isPlaying;
	sf::Text playerScore;
	std::ostringstream playerConvert;

	sf::Text computerScore;
	std::ostringstream compConvert;

	sf::RenderWindow* window;

	SoundManager soundManager;

	int m_playerScore;
	int m_compScore;

	int screenWidth;
	int screenHeight;

	
	Ball* GameBall;
	Paddle* PlayerPaddle;
	Paddle* EnemyPaddle;

	sf::Font font;
	sf::Text text;

public:

	void Init();

	void Update();

	PongGame(sf::RenderWindow* gameWindow, int screenX, int screenY);
};
