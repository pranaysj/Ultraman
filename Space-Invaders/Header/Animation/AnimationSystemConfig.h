#pragma once
#include<SFML/Graphics.hpp>

namespace Animation {
	struct AnimationSystemConfig {

		sf::String animationTexturePath;

		float spriteSheetWidth;
		float spriteSheetHeight;

		float tileWidth;
		float tileHeight;

		int numberOfAnimationFrames;
		float frameDuration;

		AnimationSystemConfig() = default;

		AnimationSystemConfig(sf::String _animationTexturePath, float _spriteWidth, float _spriteHeight, float _tileWidth, float _tileHeight, int _numberOfAnimationFrame, int _frameDuration) :
			animationTexturePath(_animationTexturePath),
			spriteSheetWidth(_spriteWidth),
			spriteSheetHeight(_spriteHeight),
			tileWidth(_tileWidth),
			tileHeight(_tileHeight),
			numberOfAnimationFrames(_numberOfAnimationFrame),
			frameDuration(_frameDuration) {}
	};
}