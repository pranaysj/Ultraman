#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/Element/Bunker/BunkerModel.h"

namespace Element {
	namespace Bunker {

		class BunkerView;

		class BunkerController {

		private:
			BunkerView* bunkerView;
			BunkerData bunkerData;

		public:
			BunkerController();
			~BunkerController();

			void Initialize(BunkerData _data);
			void Update();
			void Render();

			sf::Vector2f GetBunkerPosition();
		};
	}
}