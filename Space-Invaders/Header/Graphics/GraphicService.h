#pragma once
//#include <iostream>
#include <SFML/Graphics.hpp>


namespace Graphics {

    using namespace std;
    using namespace sf;

    class GraphicService {
    private:

        const int frameRate = 60;

        const string gameWindowTitle = "Outscal Presents - Alien Invader";
        
        const int gameWindowWidth = 1920;
        const int gameWindowHeight = 1080;
        
        const Color windowColor = Color::Blue;

        VideoMode* videoMode;
        RenderWindow* gameWindow;

        void SetVideoMode();
        void OnDestory();

    public:
        GraphicService();
        ~GraphicService();

        RenderWindow* CreateGameWindow();

        void Initialize();
        void Update();
        void Render();
        bool IsGameWindowOpen();

        RenderWindow* GetGameWindow();
        Color GetColorWindow();
    };
}
