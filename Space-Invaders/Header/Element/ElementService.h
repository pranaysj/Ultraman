#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include"../../Header/Element/Bunker/BunkerModel.h"
#include"../../Header/Element/Bunker/BunkerController.h"

namespace Element {
	class BunkerController;
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
		std::vector<Bunker::BunkerController*> flaggedBunkerList;

		void SpawnBunkers();
		void DestroyFlaggedBunkers();
		void Destroy();

	public:
		ElementService();
		virtual ~ElementService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void DestroyBunker(Bunker::BunkerController* bunker_controller);

	};
}