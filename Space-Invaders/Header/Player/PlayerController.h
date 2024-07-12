#pragma once
#include <SFML/Graphics.hpp>

namespace Player {
	using namespace sf;


	enum class PlayerState;
	class PlayerModel;
	class PlayerView;

	class PlayerController {
	private:
		PlayerModel* playerModel;
		PlayerView* playerView;

		void ProcessPlayerInput();
		void MoveLeft();
		void MoveRight();

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		Vector2f GetPlayerPosition();
	};
}

