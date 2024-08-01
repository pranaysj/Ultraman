#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		BULLET_FIRE,
		EXPLOSION,
		POWERUP_ENABLED,
		POWERUP_DISABLED,
	};

	class SoundService
	{
	private:
		const int backgroundMusicVolume = 10;

		sf::Music backgroundMusic;
		sf::Sound soundEffect;

		sf::Sound powerup_sound_effect;


		sf::SoundBuffer buffer_bullet_fire;
		sf::SoundBuffer bufferButtonClick;

		sf::SoundBuffer buffer_powerup_enabled;
		sf::SoundBuffer buffer_powerup_disabled;

		void LoadBackgroundMusicFromFile();
		void LoadSoundFromFile();

	public:
		void Initialize();

		void PlaySound(SoundType _soundType);
		void PlayBackgroundMusic();
	};
}