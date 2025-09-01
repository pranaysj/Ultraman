#pragma once
#include "../../Header/Graphics/GraphicService.h"
#include"../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include"../../Header/UI/UIService.h"

namespace Global {

    class ServiceLocator {
        private:

            Graphics::GraphicService* graphicService;
            Event::EventService* eventService;
            Player::PlayerService* playerService;
            Time::TimeService* timeService;
            UI::UIService* uiService;

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
        };
}
