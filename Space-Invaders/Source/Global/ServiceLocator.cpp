#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"


namespace Global {

    using namespace Main;
    using namespace Graphics;
    using namespace Time;
    using namespace Event;
    using namespace Player;
    using namespace UI;
    using namespace Enemy;
    using namespace Gameplay;
    using namespace Element;
    using namespace Bullet;
    using namespace Sound;
    using namespace Powerup;
    using namespace Collision;

    ServiceLocator::ServiceLocator() {
        graphicService = nullptr;
        eventService = nullptr;
        playerService = nullptr;
        timeService = nullptr;
        uiService = nullptr;
        enemyService = nullptr;
        gameplayService = nullptr;
        elementService = nullptr;
        bulletService = nullptr;
        soundService = nullptr;
        powerupService = nullptr;
        collisionService = nullptr;
        CreateService();
    }

    ServiceLocator::~ServiceLocator() {
        ClearAllService();
    }

    void ServiceLocator::CreateService() {
        graphicService = new GraphicService();
        eventService = new EventService();
        playerService = new PlayerService();
        timeService = new TimeService();
        uiService = new UIService();
        enemyService = new EnemyService();
        gameplayService = new GameplayService();
        elementService = new ElementService();
        bulletService = new BulletService();
        soundService = new SoundService();
        powerupService = new PowerupService();
        collisionService = new CollisionService();
    }

    void ServiceLocator::ClearAllService() {
        delete(graphicService);
        delete(eventService);
        delete(playerService);
        delete(timeService);
        delete(uiService);
        delete(enemyService);
        delete(gameplayService);
        delete(elementService);
        delete(bulletService);
        delete(soundService);
        delete(powerupService);
        delete(collisionService);
    }

    ServiceLocator* ServiceLocator::GetInstance() {
        static ServiceLocator instance;
        return &instance;
    }

    void ServiceLocator::Initialize() {
        graphicService->Initialize();
        timeService->Initialize();
        eventService->Initialize();
        playerService->Initialize();
        uiService->Initialize();
        enemyService->Initialize();
        gameplayService->Initialize();
        elementService->Initialize();
        bulletService->Initialize();
        powerupService->Initialize();
        soundService->Initialize();
        collisionService->Initialize();
    }

    void ServiceLocator::Update() {
        graphicService->Update();
        timeService->Update();
        eventService->Update();

        if (GameService::GetGameState() == GameState::GAMEPLAY) {
            gameplayService->Update();
            playerService->Update();
            enemyService->Update();
            bulletService->Update();
            elementService->Update();
            powerupService->Update();
            collisionService->Update();
        }

        uiService->Update();
    }

    void ServiceLocator::Render() {
        graphicService->Render();

        if (GameService::GetGameState() == GameState::GAMEPLAY) {
            gameplayService->Render();
            playerService->Render();
            enemyService->Render();
            bulletService->Render();
            elementService->Render();
            powerupService->Render();
        }

        uiService->Render();
    }

    GraphicService* ServiceLocator::GetGraphicsService()
    {
        return graphicService;
    }

    EventService* ServiceLocator::GetEventService()
    {
        return eventService;
    }

    PlayerService* ServiceLocator::GetPlayerService()
    {
        return playerService;
    }

    TimeService* ServiceLocator::GetTimeService()
    {
        return timeService;
    }

    UIService* ServiceLocator::GetUIService()
    {
        return uiService;
    }

    Enemy::EnemyService* ServiceLocator::GetEnemyService()
    {
        return enemyService;
    }

    Gameplay::GameplayService* ServiceLocator::GetGameplayService()
    {
        return gameplayService;;
    }

    Element::ElementService* ServiceLocator::GetElementService()
    {
        return elementService;
    }

    Bullet::BulletService* ServiceLocator::GetBulletService()
    {
        return bulletService;
    }

    SoundService* ServiceLocator::GetSoundService()
    {
        return soundService;
    }

    Powerup::PowerupService* ServiceLocator::GetPowerupService()
    {
        return powerupService;
    }

    Collision::CollisionService* ServiceLocator::GetCollisionService()
    {
        return collisionService;
    }

    void ServiceLocator::DeleteServiceLocator(){
        delete(this);
    }
}
