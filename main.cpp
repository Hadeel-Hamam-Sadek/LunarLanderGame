#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
int main()
{

    Clock clock;
    srand(time(0));
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 700), "SFML window");
    app.setFramerateLimit(60);

    // Load a sprite to display
    Texture rocket,line,bom;
    rocket.loadFromFile("images/rocket2.png");
    line.loadFromFile("images/line.png");
    bom.loadFromFile("images/bom.png");

    Sprite sRocket(rocket),sLine(line),sBom(bom);
    sLine.setPosition(0,300);
    sBom.setScale(0,0);

    RectangleShape Line1 (sf::Vector2f(150,10));
    Line1.setFillColor(sf::Color::Blue);
    Line1.setPosition(5,600);
    Line1.rotate(30);

    RectangleShape Line2 (sf::Vector2f(150,10));
    Line2.setFillColor(sf::Color::Blue);
    Line2.setPosition(135,680);
    Line2.rotate(-50);

    RectangleShape Line3 (sf::Vector2f(150,10));
    Line3.setFillColor(sf::Color::Blue);
    Line3.setPosition(225,568);
    Line3.rotate(50);

    RectangleShape Line4 (sf::Vector2f(150,10));
    Line4.setFillColor(sf::Color::Blue);
    Line4.setPosition(320,680);
    Line4.rotate(-50);

    RectangleShape Line5 (sf::Vector2f(150,10));
    Line5.setFillColor(sf::Color::Blue);
    Line5.setPosition(405,572);
    //Line5.rotate(-50);

    RectangleShape Line6 (sf::Vector2f(250,10));
    Line6.setFillColor(sf::Color::Blue);
    Line6.setPosition(765,700);
    Line6.rotate(-150);


    // Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                sRocket.move(-5,0);
                //sRocket.rotate(-2);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                sRocket.move(5,0);
                //sRocket.rotate(2);
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                sRocket.move(0,1);
                //sRocket.rotate(-2);
            }
            /*if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                sRocket.move(0,-.7);
                //sRocket.rotate(2);
            }*/




        }
        //Left Collision
        if (sRocket.getPosition().x < 0.0)
        {
            sRocket.setPosition(0, sRocket.getPosition().y);
        }

        //Top Collision
        if (sRocket.getPosition().y < 0)
        {
            sRocket.setPosition(sRocket.getPosition().x, 0);
        }

        //Bottom Collision
        if (sRocket.getPosition().y + sRocket.getGlobalBounds().height > app.getSize().y)
        {
            sRocket.setPosition(sRocket.getPosition().x, app.getSize().y - sRocket.getGlobalBounds().height);
        }
        //Right Collision

        if (sRocket.getPosition().x + sRocket.getGlobalBounds().width > app.getSize().x)
        {
            sRocket.setPosition(app.getSize().x - sRocket.getGlobalBounds().width, sRocket.getPosition().y);
        }


        if (sRocket.getGlobalBounds().intersects(Line5.getGlobalBounds()) == true)
            sRocket.move(0,-0.3);

        if (sRocket.getGlobalBounds().intersects(Line1.getGlobalBounds()) == true )
        {
            sRocket.setScale(0,0);
            sBom.setScale(3,3);
            sBom.setPosition(0,600);
            app.draw(sBom);
        }

        if (sRocket.getGlobalBounds().intersects(Line2.getGlobalBounds()) == true )
        {
            sRocket.setScale(0,0);
            sBom.setScale(3,3);
            sBom.setPosition(135,600);
            app.draw(sBom);
        }
        if (sRocket.getGlobalBounds().intersects(Line3.getGlobalBounds()) == true )
        {
            sRocket.setScale(0,0);
            sBom.setScale(3,3);
            sBom.setPosition(225,568);
            app.draw(sBom);
        }
        if (sRocket.getGlobalBounds().intersects(Line4.getGlobalBounds()) == true )
        {
            sRocket.setScale(0,0);
            sBom.setScale(3,3);
            sBom.setPosition(300,600);
            app.draw(sBom);
        }
        if (sRocket.getGlobalBounds().intersects(Line6.getGlobalBounds()) == true )
        {
            sRocket.setScale(0,0);
            sBom.setScale(3,3);
            sBom.setPosition(600,600);
            app.draw(sBom);
        }
        /*if (sRocket.getGlobalBounds().intersects(sLine.getGlobalBounds()) == true)
            sRocket.move(0,-.3);
        else
            sRocket.move(0,.3);*/

        /*if (sRocket.getPosition().y + sRocket.getGlobalBounds().height > sLine.getScale().y)
        {
            sRocket.setPosition(sRocket.getPosition().x, sLine.getScale().y - sRocket.getGlobalBounds().height);
        }*/

        // Clear screen
        app.clear();
        sRocket.move(0,.3);

        //app.draw(sRocket);
        app.draw(Line1);
        app.draw(Line2);
        app.draw(Line3);
        app.draw(Line4);
        app.draw(Line5);
        app.draw(Line6);
        app.draw(sBom);
        app.draw(sRocket);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
