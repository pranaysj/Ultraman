#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"
#include "../Header/PlayerService.h"

class ServiceLocator{
    private :

        GraphicService *graphicService;
        EventService *eventService;
        PlayerService *playerService;

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
};