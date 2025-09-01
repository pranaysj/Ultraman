#pragma once
#include<SFML/Graphics.hpp>

namespace Player {
    using namespace sf;

    class PlayerController;

    class PlayerService {
    private:
        PlayerController* playerController;
    public:

        PlayerService();
        ~PlayerService();

        void Initialize();
        void Update();
        void Render();

    };
}

