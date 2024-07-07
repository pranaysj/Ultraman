#pragma once
namespace Element {
	namespace Bunker {
		class BunkerModel {
		public:
			BunkerModel();
			~BunkerModel();

			void Initialize();
			void Update();
			void Render();
		};
	}
}