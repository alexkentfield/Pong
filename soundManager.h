#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SoundManager
{
private:

	sf::Sound m_currentSound;

	sf::Music music;

public:

	enum GameSounds
	{
		S_EnemyScore,
		S_PlayerScore,
		S_StartSound,
		S_MAX
	};

	sf::SoundBuffer m_Sounds[S_MAX];

	void Init();

	void PlaySound(GameSounds sound);
};

