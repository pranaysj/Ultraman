#include"Header/GameService.h"

// #include<SFML/Graphics.hpp>
// #include<iostream>

// using namespace sf;
// using namespace std;

// class Player {
//     private :
//         int health = 3;
//         Vector2f position = Vector2f(200.0f, 100.0f);
//         int movement_speed = 5;
//         int player_score = 0;
        
//     public :
//         Texture player_texture;
//         Sprite player_sprite;

//         void move(float offset){
//             position.x += offset;
//         }
//         int GetMovementSpeed(){
//             return movement_speed;
//         }
//         Vector2f GetPosition(){
//             return position;
//         }
//         void takeDamage();
//         void shootBullets();
// };

int main() {

    // // Define the video mode (dimensions)
    // VideoMode* videoMode = new VideoMode(800, 600);

    // // Create a window object with specific dimensions and a title
    // RenderWindow* window= new RenderWindow(*videoMode, "SFML Window");

    // //Set the Frame rate of the game
    // window->setFramerateLimit(60);

    // //Declare the player object and assign sprite to it.
    // Player playerShip;
    // playerShip.player_texture.loadFromFile("assets/textures/player_ship.png");
    // playerShip.player_sprite.setTexture(playerShip.player_texture);

    // while (window->isOpen()) {
    //     sf::Event event;
    //     while (window->pollEvent(event)) {
    //         // Check for window closure
    //         if (event.type == Event::Closed)
    //             window->close();
    //     }

    //     //Left and Right keyboard input
    //     if(Keyboard::isKeyPressed(Keyboard::Left)){
    //         //leftMove()
    //         playerShip.move(-1.0 * playerShip.GetMovementSpeed());
    //     }
    //     if(Keyboard::isKeyPressed(Keyboard::Right)){
    //         //rightMove()
    //         playerShip.move(1.0 * playerShip.GetMovementSpeed());
    //     }

    //     // Clear the window
    //     window->clear(Color::Blue);

    //     //set the positon of the sprite
    //     playerShip.player_sprite.setPosition(playerShip.GetPosition());
    //     //drawing the sprite on the screen
    //     window->draw(playerShip.player_sprite);


    //     // Display whatever you draw
    //     window->display();
    // }

    GameService *gameService = new GameService();
    
    gameService->Ignite();
    
    while (gameService->IsRunning())
    {
        
        gameService->Update();
        gameService->Render();
    }
     
    return 0;
}