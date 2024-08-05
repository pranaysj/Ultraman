#pragma
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"


namespace Sound
{
	using namespace Global;


	void SoundService::Initialize(){
		LoadBackgroundMusicFromFile();
		LoadSoundFromFile();
	}

	void SoundService::LoadBackgroundMusicFromFile(){
		if (!backgroundMusic.openFromFile(Config::background_music_path)) {

			printf("Error loading background music file");
		}
	}

	void SoundService::LoadSoundFromFile(){
		if (!bufferButtonClick.loadFromFile(Config::button_click_sound_path)) {

			printf("Error loading background music file");

		}
		if (!buffer_bullet_fire.loadFromFile(Config::bullet_fire_sound_path))
			printf("Error loading background music file");
		if (!buffer_powerup_enabled.loadFromFile(Config::powerup_enabled_sound_path))
			printf("Error loading background music file");
		if (!buffer_powerup_disabled.loadFromFile(Config::powerup_disabled_sound_path))
			printf("Error loading background music file");
	}

	void SoundService::PlaySound(SoundType _soundType){
		switch (_soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			soundEffect.play();
			break;

		case SoundType::BULLET_FIRE:
			soundEffect.setBuffer(buffer_bullet_fire);
			soundEffect.play();
			break;

		case SoundType::EXPLOSION:
			explosion_sound_effect.setBuffer(buffer_explosion);
			explosion_sound_effect.play();
			break;

		case SoundType::POWERUP_ENABLED:
			powerup_sound_effect.setBuffer(buffer_powerup_enabled);
			powerup_sound_effect.play();
			break;

		case SoundType::POWERUP_DISABLED:
			powerup_sound_effect.setBuffer(buffer_powerup_disabled);
			powerup_sound_effect.play();
			break;

		default:
			printf("Invalid sound type");
			return;
		}

		soundEffect.play();
	}

	void SoundService::PlayBackgroundMusic(){
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(backgroundMusicVolume);
		backgroundMusic.play();
	}
}