#include <SFML/Graphics.hpp>
#include "Window.h"
#include "GameInfo.h"

class Player
{
	float speed;
public:
	static Player player;
	sf::Texture playerModel;
	sf::Sprite drawPlayerModel;

	static void render();
	static void create();
	static void update();
	void playerMove();
};