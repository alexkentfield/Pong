#include "soundManager.h"

void SoundManager::Init()
{

	m_Sounds[S_EnemyScore].loadFromFile("Content/enemyScore.wav");
	m_Sounds[S_PlayerScore].loadFromFile("Content/youScore.wav");
	m_Sounds[S_StartSound].loadFromFile("Content/startBall.wav");

	music.openFromFile("Content/backgroundMusic.wav");
	music.setPosition(0, 1, 10); // change its 3D position
	music.setPitch(2);           // increase the pitch
	music.setVolume(100);         // reduce the volume
	music.setLoop(true);         // make it loop
	music.play();
}

void SoundManager::PlaySound(GameSounds sound)
{
	m_currentSound.setBuffer(m_Sounds[(int)sound]);
	m_currentSound.play();
}