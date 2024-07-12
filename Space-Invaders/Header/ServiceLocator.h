#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"
#include "../Header/PlayerService.h"
#include "../Header/TimeService.h"

class ServiceLocator{
    private :

        GraphicService *graphicService;
        EventService *eventService;
        PlayerService *playerService;
        TimeService *timeService;

        ServiceLocator();
        ~ServiceLocator();

        void CreateService();
        void ClearAllService();

    public :
        static ServiceLocator* GetInstance();

        void Initialize();
        void Update();
        void Render();

        GraphicService *GetGraphicsService();
        EventService *GetEventService();
        PlayerService *GetPlayerService();
        TimeService *GetTimeService();
};