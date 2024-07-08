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
	}

	void SoundService::PlaySound(SoundType _soundType){
		switch (_soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
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