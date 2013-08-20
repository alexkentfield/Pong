#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "ball.h"
#include "gameObject.h"

class Paddle : public GameObject
{
private:
	bool player;

	float playerSpin;
	float compSpin;

	int paddleWidth;
	int paddleHeight;
	sf::SoundBuffer paddleBuffer;
	sf::Sound paddleSound;

public:
	sf::RectangleShape m_Paddle;
	Paddle(bool isPlayer, int screenWidth, int screenHeight);
	~Paddle();

	virtual void Init();
	virtual void Update(Ball* ball);
	virtual void Draw(sf::RenderWindow *window);
	virtual void CheckCollisions(Ball* ball);
	void resetPaddleSize();

};
