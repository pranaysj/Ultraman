#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


namespace Graphics {
    using namespace std;
    using namespace sf;
    class GraphicService {
    private:

        const string game_window_title = "Outscal Presents - Alien Invader";
        const int game_window_width = 800;
        const int game_window_height = 600;
        const Color window_color = Color::Blue;
        const int frameRate = 60;

        VideoMode* videoMode;
        RenderWindow* gameWindow;

        void setVideoMode();
        void OnDestory();

    public:
        GraphicService();
        ~GraphicService();

        RenderWindow* createGameWindow();

        void Initialize();
        void Update();
        void Render();
        bool isGameWindowOpen();

        RenderWindow* GetGameWindow();
        Color getColorWindow();
    };
}
