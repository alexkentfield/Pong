#include "pongGame.h"

PongGame::PongGame(sf::RenderWindow* gameWindow, int screenX, int screenY)
{
	screenWidth = screenX;
	screenHeight = screenY;
	window = gameWindow;
}

void PongGame::Init()
{
		 
	soundManager.Init();
	isPlaying = false;
	GameBall = new Ball(screenWidth,screenHeight);
	PlayerPaddle = new Paddle(true, screenWidth, screenHeight);
	EnemyPaddle = new Paddle(false, screenWidth, screenHeight);

	m_playerScore = 0;
	m_compScore = 0;

	playerScore.setCharacterSize(50);
	playerScore.setFont(font);
	playerScore.setColor(sf::Color::Blue);
	playerScore.setPosition(screenWidth / 2 - 50, screenHeight - 60);
	playerConvert << m_playerScore;

	computerScore.setCharacterSize(50);
	computerScore.setFont(font);
	computerScore.setColor(sf::Color::Red);
	computerScore.setPosition(screenWidth / 2 + 65, screenHeight - 60);
	compConvert << m_compScore;

	font.loadFromFile("Content/gothic.ttf");

	text.setFont(font);
	text.setCharacterSize(40);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	text.setPosition(screenWidth / 2 - 15, screenHeight - 50);
	text.setString("SCORE");

	GameBall->Init();
	PlayerPaddle->Init();
	EnemyPaddle->Init();
}

void PongGame::Update()
{


	while (window->isOpen())
	{
		window->display();
		window->clear();


		window->draw(text);
		window->draw(playerScore);
		window->draw(computerScore);

		GameBall->Draw(window);
		PlayerPaddle->Draw(window);
		EnemyPaddle->Draw(window);

		computerScore.setString(compConvert.str());
		playerScore.setString(playerConvert.str());

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		if (!isPlaying)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				GameBall->gameBall.setPosition(screenWidth / 2,screenHeight / 3);
				PlayerPaddle->m_Paddle.setSize(sf::Vector2f(15, 150));
				PlayerPaddle->resetPaddleSize();
				EnemyPaddle->m_Paddle.setSize(sf::Vector2f(15, 150));
				EnemyPaddle->resetPaddleSize();
				GameBall->Velocity(sf::Vector2f(0.1f, 0.06f));
				isPlaying = true;
				soundManager.PlaySound(SoundManager::S_StartSound);
			}
		}

		if (isPlaying)
		{

			GameBall->Update();
			PlayerPaddle->Update(GameBall);
			EnemyPaddle->Update(GameBall);

			// Player Scores
			if (GameBall->gameBall.getPosition().x >= screenWidth)
			{	
				m_playerScore++;
				soundManager.PlaySound(SoundManager::S_PlayerScore);
				playerConvert = std::ostringstream();
				playerConvert << m_playerScore;
				isPlaying = false;
			}

			// Computer Scores
			if (GameBall->gameBall.getPosition().x <= -20)
			{
				m_compScore++;
				soundManager.PlaySound(SoundManager::S_EnemyScore);
				compConvert = std::ostringstream();
				compConvert << m_compScore;
				isPlaying = false;
			}
		}
	}
}