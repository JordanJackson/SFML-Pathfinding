#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML work!");

	sf::Texture spriteSheet;
	if (!spriteSheet.loadFromFile("../Resources/Textures/RPGpack_sheet.png"))
	{
		std::cerr << "Did not load texture" << std::endl;
	}

	sf::Sprite grass;
	grass.setTexture(spriteSheet);
	grass.setTextureRect(sf::IntRect(64, 64, 64, 64));
	sf::Sprite water;
	water.setTexture(spriteSheet);
	water.setTextureRect(sf::IntRect(704, 64, 64, 64));

	int width = 10;
	int height = 10;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if ((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1))
				{
					grass.setPosition(sf::Vector2f(i * 64, j * 64));
					window.draw(grass);
				}
				else
				{
					water.setPosition(sf::Vector2f(i * 64, j * 64));
					window.draw(water);
				}
				
			}
		}
		window.display();
	}

	return 0;
}