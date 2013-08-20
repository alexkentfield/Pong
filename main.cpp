#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "gameObject.h"
#include "ball.h"
#include "paddle.h"
#include "pongGame.h"
#include "soundManager.h"


using namespace std;

int main()
{
	int screenWidth = 1280;
	int screenHeight = 800;

	sf::RenderWindow* window = new sf::RenderWindow(sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "-= Pong =-"));

	PongGame pongGame(window, screenWidth, screenHeight);


	pongGame.Init();

	pongGame.Update();

    return 0;
}
