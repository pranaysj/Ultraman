#include "../../Header/Graphics/GraphicService.h"

namespace Graphics {
    GraphicService::GraphicService() {
        videoMode = nullptr;
        gameWindow = nullptr;
    }

    GraphicService::~GraphicService() {
        OnDestory();
    }

    void GraphicService::OnDestory() {
        delete(videoMode);
        delete(gameWindow);
    }

    void GraphicService::Initialize() {
        gameWindow = CreateGameWindow();
    }

    RenderWindow* GraphicService::CreateGameWindow() {
        SetVideoMode();
        return new sf::RenderWindow(*videoMode, gameWindowTitle, sf::Style::Default);
    }

    void GraphicService::SetVideoMode() {
        videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
    }

    void GraphicService::Update() {}

    void GraphicService::Render() {}

    bool GraphicService::IsGameWindowOpen() {
        return gameWindow->isOpen();;
    }

    RenderWindow* GraphicService::GetGameWindow() {
        return gameWindow;
    }

    Color GraphicService::GetColorWindow() {
        return windowColor;
    }

}

