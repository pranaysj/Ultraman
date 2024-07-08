#pragma once
#include"../../Header/Element/Bunker/BunkerModel.h"

namespace Element {
	namespace Bunker {
		BunkerData::BunkerData() {}
		BunkerData::BunkerData(sf::Vector2f _position) {
			this->position = _position
		}
	}
}