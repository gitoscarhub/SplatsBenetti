
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
Texture texture;
Texture texture2;
Sprite sprite;
Sprite sprite2;



int main(){
	
	texture.loadFromFile("rcircle.png");
	texture.setRepeated(true);
	texture2.loadFromFile("rcircleb.png");
	texture2.setRepeated(true);

	sprite.setTexture(texture);
	sprite2.setTexture(texture2);

	

	RenderWindow *App;
	

	App= new RenderWindow(VideoMode(800, 600, 32),
		"Benetti Jugando con Splats");
	std::vector<sf::Sprite> sprites;

	
	while (App->isOpen())
	{
		
		int p = 0;
	

		Event evt{};

		evt.type;

		while (App->pollEvent(evt)){


			
		      if(evt.type== Event::EventType::Closed)
				App->close();
		
				
			  if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Left)
			  {
				
				  sprite.setTexture(texture);
				  sprite.setPosition(evt.mouseButton.x, evt.mouseButton.y);
				  sprites.push_back(sprite);
			  }
			  if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Right)
			  {

				  sprite2.setTexture(texture2);
				  sprite2.setPosition(evt.mouseButton.x, evt.mouseButton.y);
				  sprites.push_back(sprite2);
			  }

			  App->clear(Color::White);

		for (const auto& sprite : sprites)
		{
			App->draw(sprite);
		
		}
			

		for (const auto& sprite : sprites)
		{
			App->draw(sprite2);

		}
			
		}

		    
			//_player->Dibujar2(App);
			App->display();
	}	
	
	return 0;
}
