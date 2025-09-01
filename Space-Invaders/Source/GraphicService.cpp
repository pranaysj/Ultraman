#include "../Header/GraphicService.h"

void GraphicService::setVideoMode(){
    videoMode = new sf::VideoMode(game_window_width,game_window_height,sf::VideoMode::getDesktopMode().bitsPerPixel);
}

void GraphicService::OnDestory(){
    delete(videoMode);
    delete(gameWindow);
}

GraphicService::GraphicService(){
    videoMode = nullptr;
    gameWindow = nullptr;
}

GraphicService::~GraphicService(){
    OnDestory();
}

RenderWindow *GraphicService::createGameWindow(){
    setVideoMode();
    return new sf::RenderWindow(*videoMode,game_window_title);
}

void GraphicService::Initialize(){
    gameWindow = createGameWindow();
}

void GraphicService::Update(){
    cout << "Graphssss";
}

void GraphicService::Render(){

}

bool GraphicService::isGameWindowOpen(){
    return gameWindow->isOpen();;
}

RenderWindow *GraphicService::GetGameWindow(){
    return gameWindow;
}

Color GraphicService::getColorWindow(){
    return window_color;
}
