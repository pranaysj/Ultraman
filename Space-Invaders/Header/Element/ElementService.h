#pragma once

namespace Element {
	class ElementService {
	public:
		ElementService();
		~ElementService();

		void Initialize();
		void Update();
		void Render();
	};
}