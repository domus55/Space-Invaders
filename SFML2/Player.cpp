#include "Player.h"

Player Player::player;
bool Player::renderHitbox = true;
sf::Text Player::text;
sf::Font Player::font;

Player::Player()
{
	shootSpeed = 5;
	shootDmg = 1;
	shootDuration = 500;
	speed = 0.5;
	hp = 6;
	deathDelay = false;
	renderDeath = false;

	playerModel.loadFromFile("Images/spaceship.png");
	drawPlayerModel.setTexture(playerModel);
	drawPlayerModel.setPosition(1600 / 2, 800);
	sf::Vector2u size = playerModel.getSize();
	drawPlayerModel.setOrigin(size.x / 2, size.y / 2);
	drawPlayerModel.setScale(0.2, 0.2);

	heart.loadFromFile("Images/heart.png");
	halfHeart.loadFromFile("Images/halfheart.png");
	emptyHeart.loadFromFile("Images/emptyheart.png");

	drawHeartModel1.setTexture(heart);
	drawHeartModel2.setTexture(heart);
	drawHeartModel3.setTexture(heart);

	Player::player.playerHp();

	hitboxTexture.loadFromFile("Images/hitbox.png");
	hitbox1.setTexture(hitboxTexture);
	hitbox2.setTexture(hitboxTexture);
	sf::Vector2u Hitboxsize = hitboxTexture.getSize();
	hitbox1.setOrigin(Hitboxsize.x / 2, Hitboxsize.y / 2);
	hitbox1.setScale(0.45, 0.9);

	hitbox2.setOrigin(Hitboxsize.x / 2, Hitboxsize.y / 2);
	hitbox2.setScale(1.1, 0.2);
}

void Player::render()
{
	Window::window.draw(Player::player.drawPlayerModel);
	Window::window.draw(Player::player.drawHeartModel1);
	Window::window.draw(Player::player.drawHeartModel2);
	Window::window.draw(Player::player.drawHeartModel3);
	if (Player::player.renderDeath) Window::window.draw(text);

	if (renderHitbox) Window::window.draw(Player::player.hitbox1);
	if (renderHitbox) Window::window.draw(Player::player.hitbox2);
}

void Player::update()
{
	Player::player.playerMove();
	Player::player.playerShoot();
	Player::player.checkCollision();
	if (Player::player.deathDelay == true) Player::player.playerDeathTime();
}

void Player::playerMove()
{
	sf::Vector2f pos;
	pos = drawPlayerModel.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pos.x -= GameInfo::getDeltaTime() * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pos.x += GameInfo::getDeltaTime() * speed;

	if (pos.x < 80) pos.x = 80;
	if (pos.x > 1520) pos.x = 1520;

	drawPlayerModel.setPosition(pos);
}

void Player::playerShoot()
{
	static int myDeltaTime = 0;
	myDeltaTime += GameInfo::getDeltaTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && myDeltaTime > shootDuration)
	{
		sf::Vector2f pos;
		pos = drawPlayerModel.getPosition();
		Shoot::create(pos.x, pos.y, 0, -shootSpeed, shootDmg, true, 1, 1);
		myDeltaTime = 0;
	}
}

void Player::checkCollision()
{
	hitbox1.setPosition(drawPlayerModel.getPosition());
	hitbox2.setPosition(drawPlayerModel.getPosition().x, drawPlayerModel.getPosition().y + 35);

	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		if (Shoot::shoot[i]->playerShoot == false && (Collider::checkCollision(hitbox1, Shoot::shoot[i]->sprite) || Collider::checkCollision(hitbox2, Shoot::shoot[i]->sprite)))
		{
			hp -= Shoot::shoot[i]->getDmg();
			Shoot::shoot.erase(Shoot::shoot.begin() + i);

			switch (hp)
			{
			case 6: drawHeartModel3.setTexture(heart); break;
			case 5:	drawHeartModel3.setTexture(halfHeart); break;
			case 4:	drawHeartModel3.setTexture(emptyHeart); break;
			case 3:	drawHeartModel2.setTexture(halfHeart); break;
			case 2:	drawHeartModel2.setTexture(emptyHeart); break;
			case 1:	drawHeartModel1.setTexture(halfHeart); break;
			case 0: 
			{
				drawHeartModel1.setTexture(emptyHeart);
				playerDeath();
			}	break;
			}	
		}
	}
}

void Player::playerHp()
{
	drawHeartModel1.setPosition(20, 10);
	drawHeartModel2.setPosition(100, 10);
	drawHeartModel3.setPosition(180, 10);
}

void Player::playerDeath()
{
	font.loadFromFile("Images/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(100);
	text.setPosition(800, 425);
	text.setStyle(sf::Text::Bold);
	text.setString("YOU DIED");

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	hp = 6;

	drawHeartModel1.setTexture(heart);
	drawHeartModel2.setTexture(heart);
	drawHeartModel3.setTexture(heart);
	
	renderDeath = true;
	deathDelay = true;
}

void Player::playerDeathTime()
{
	static float time = 0;
	time += GameInfo::getDeltaTime();

	if (time > 1000)
	{
		renderDeath = false;
		LevelManager::actualLevel = 0;
		BasicEnemy::enemy.clear();
		Shoot::shoot.clear();
		deathDelay = false;
		time = 0;
	}
}