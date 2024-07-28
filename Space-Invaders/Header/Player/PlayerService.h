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
        virtual ~PlayerService();

        void Initialize();
        void Update();
        void Render();

        void EnableShield();
        void EnableRapidFire();
        void EnableTrippleLaser();

        void Reset();
    };
}

