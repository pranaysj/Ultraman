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

    void GraphicService::setVideoMode() {
        videoMode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
    }

    RenderWindow* GraphicService::createGameWindow() {
        setVideoMode();
        return new sf::RenderWindow(*videoMode, game_window_title, sf::Style::Fullscreen);
    }

    void GraphicService::Initialize() {
        gameWindow = createGameWindow();
        //gameWindow->setFramerateLimit(frameRate);
    }

    void GraphicService::Update() {

    }

    void GraphicService::Render() {

    }

    bool GraphicService::isGameWindowOpen() {
        return gameWindow->isOpen();;
    }

    RenderWindow* GraphicService::GetGameWindow() {
        return gameWindow;
    }

    Color GraphicService::getColorWindow() {
        return window_color;
    }

}

