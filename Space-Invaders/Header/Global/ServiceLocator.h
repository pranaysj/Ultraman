#pragma once
#include "../../Header/Graphics/GraphicService.h"
#include"../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include"../../Header/UI/UIService.h"
#include"../../Header/Enemy/EnemyService.h"
#include"../../Header/Gameplay/GameplayService.h"
#include"../../Header/Element/ElementService.h"
#include "../../Header/Sound/SoundService.h"

namespace Global {

    class ServiceLocator {
        private:

            Event::EventService* eventService;
            Graphics::GraphicService* graphicService;
            UI::UIService* uiService;
            Time::TimeService* timeService;
            Gameplay::GameplayService* gameplayService;
            Player::PlayerService* playerService;
            Enemy::EnemyService* enemyService;
            Element::ElementService* elementService;
            Sound::SoundService* soundService;

            ServiceLocator();
            ~ServiceLocator();

            void CreateService();
            void ClearAllService();

        public:
            static ServiceLocator* GetInstance();

            void Initialize();
            void Update();
            void Render();

            Graphics::GraphicService* GetGraphicsService();
            Event::EventService* GetEventService();
            Player::PlayerService* GetPlayerService();
            Time::TimeService* GetTimeService();
            UI::UIService* GetUIService();
            Enemy::EnemyService* GetEnemyService();
            Gameplay::GameplayService* GetGameplayService();
            Element::ElementService* GetElementService();
            Sound::SoundService* GetSoundService();
            void DeleteServiceLocator();
        };
}
