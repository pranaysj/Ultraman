#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include"../../Header/Element/Bunker/BunkerModel.h"
#include"../../Header/Element/Bunker/BunkerController.h"

namespace Element {
	//class BunkerController;
	using namespace Bunker;

	class ElementService {
	private:
		const std::vector<BunkerData> bunkerDataList = {BunkerData(sf::Vector2f(130.f, 800.f)),
																BunkerData(sf::Vector2f(430.0f, 800.f)),
																BunkerData(sf::Vector2f(730.0f, 800.f)),
																BunkerData(sf::Vector2f(1130.0f, 800.f)),
																BunkerData(sf::Vector2f(1430.0f, 800.f)),
																BunkerData(sf::Vector2f(1730.0f, 800.f)) };

		std::vector<Bunker::BunkerController*> bunkerList;

		void Destroy();

	public:
		ElementService();
		virtual ~ElementService();

		void Initialize();
		void Update();
		void Render();
	};
}