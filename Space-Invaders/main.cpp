#include<SFML/Graphics.hpp>
#include "MAIN.H"
#include <iostream>

using namespace sf;

int main()
{
    VideoMode* videoMode = new VideoMode(1920,1080);
    RenderWindow* window = new RenderWindow(*videoMode,"SFML",Style::Default);

    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window->close();
            }
        }

        //Background colour
        window->clear(Color::Black);

        //Green Circle
        CircleShape circle(100);
        circle.setFillColor(Color::Green);
        //Red Square 
        RectangleShape square(Vector2f(180,180));
        square.setFillColor(Color::Red);
        //Blue Triangle
        CircleShape triangle(130,3);
        triangle.setFillColor(Color::Blue);

        //Set the Positioin of all shapes
        circle.setPosition(
            (window->getSize().x / 2) - (circle.getRadius() * 3.5),
            (window->getSize().y / 2) - circle.getRadius());
        square.setPosition(
            (window->getSize().x / 2) - square.getSize().x / 2,
            (window->getSize().y / 2) - square.getSize().y / 2);
        triangle.setPosition(
            (window->getSize().x / 2) + (triangle.getRadius()),
            (window->getSize().y / 2) - (triangle.getRadius() - 15));

        //Loading the texture
        Texture outscalImage;
        outscalImage.loadFromFile("assets/textures/outscal_logo.png");
        Sprite outscalSprite;
        outscalSprite.setTexture(outscalImage);
        outscalSprite.setScale(0.5, 0.5);
        outscalSprite.setPosition((window->getSize().x / 2) - (outscalSprite.getGlobalBounds().width / 2), 30);
        

        Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        Text text("SFML is Awesome", font, 25);
        text.setFillColor(Color::White);
        text.setPosition((window->getSize().x / 2) - (text.getGlobalBounds().width / 2), outscalSprite.getGlobalBounds().height + text.getGlobalBounds().height + 20);


        //Drawing the shapes,texture and sprite with specific order
        window->draw(circle);
        window->draw(square);
        window->draw(triangle);
        window->draw(outscalSprite);
        window->draw(text);



        window->display();
    }

   
    
    return 0;
}