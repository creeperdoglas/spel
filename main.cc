#include <SFML/Graphics.hpp>
// för kompilering på min dator, g++ -o platformer.exe main.cc -IC:\Users\boren\Downloads\SFML-2.6.1\include -LC:\Users\boren\Downloads\SFML-2.6.1\lib -lsfml-graphics -lsfml-window -lsfml-system
int main()
{
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Platformer");

  // Create a player
  sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
  player.setFillColor(sf::Color::Cyan);
  player.setPosition(200, 100); // Initial position of the player

  // Create a platform
  sf::RectangleShape platform(sf::Vector2f(200.0f, 30.0f));
  platform.setFillColor(sf::Color::Red);
  platform.setPosition(200, 500); // Position of the platform

  // Start the game loop
  while (window.isOpen())
  {
    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
      // Close window: exit
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    // Handle player movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      player.move(-0.5f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      player.move(0.5f, 0.f);

    // Collision detection
    if (player.getGlobalBounds().intersects(platform.getGlobalBounds()))
    {
      // Prevent the player from falling through the platform
      player.setPosition(player.getPosition().x, platform.getPosition().y - player.getSize().y);
    }

    // Clear screen
    window.clear();

    // Draw the player and the platform
    window.draw(player);
    window.draw(platform);

    // Update the window
    window.display();
  }

  return 0;
}
