#include "Player.h"

Player Player::player;
sf::Text Player::text;
sf::Font Player::font;
bool Player::renderHitbox = false;
bool Player::blockShoots = false;

Player::Player()
{
	shooted = false;
	deathDelay = false;
	renderDeath = false;
	checkDeathFx = false;
	canMove = true;
	canShoot = true;
	light = false;

	resetStats();

	playerModel.loadFromFile("Images/spaceship.png");
	playerModelLighted.loadFromFile("Images/spaceshipLighted.png");
	drawPlayerModel.setTexture(playerModel);
	drawPlayerModel.setPosition(1600 / 2, 800);
	sf::Vector2u size = playerModel.getSize();
	drawPlayerModel.setOrigin(size.x / 2, size.y / 2);

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

	hitbox2.setOrigin(Hitboxsize.x / 2, Hitboxsize.y / 2);

	playerShootSoundBuffer.loadFromFile("Sounds/playerShootSound.wav");
	playerShootSound.setBuffer(playerShootSoundBuffer);

	playerDeathSoundBuffer.loadFromFile("Sounds/playerDeathSound.wav");
	playerDeathSound.setBuffer(playerDeathSoundBuffer);
	playerDeathSound.setPitch(5);
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
	if (Player::player.canMove == true) Player::player.playerMove();
	Player::player.playerShoot();
	Player::player.checkCollision();
	if (Player::player.deathDelay == true) Player::player.playerDeathTime();
	if (Player::player.checkDeathFx == true) Player::player.deathFx();
	if (Player::player.shooted == true) Player::player.playerShooted();
	if (Player::player.light == true) Player::player.playerLighted();
}

void Player::resetStats()
{
	shootSpeed = 3;				//3
	shootDuration = 1500;		//1500
	speed = 0.5;
	hp = 6;
	shootAmmount = 1;

	hitbox2PosY = 35;
	drawPlayerModel.setScale(0.2, 0.2);
	hitbox1.setScale(0.45, 0.9);
	hitbox2.setScale(1.1, 0.2);
}

void Player::playerLighted()
{
	static int time = 0;
	time += GameInfo::getDeltaTime();

	drawPlayerModel.setTexture(playerModelLighted);

	if (time > 200)
	{
		drawPlayerModel.setTexture(playerModel);
		light = false;
		time = 0;
	}
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

	if (shootAmmount > 12) shootAmmount = 12;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && myDeltaTime > shootDuration && canShoot == true)
	{
		playerShootSound.stop();
		playerShootSound.play();
		
		light = true;

		sf::Vector2f pos;
		pos = drawPlayerModel.getPosition();

		switch (shootAmmount)
		{
		case 1: Shoot::create(pos.x, pos.y, 0, -shootSpeed, true, 1, 1); break;
		case 2:
		{
			Shoot::create(pos.x - 25, pos.y, 0, -shootSpeed, true, 1, 0.9);
			Shoot::create(pos.x + 25, pos.y, 0, -shootSpeed, true, 1, 0.9);
		}	break;
		case 3:
		{
			Shoot::create(pos.x - 40, pos.y + 15, 0, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x, pos.y - 40, 0, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x + 40, pos.y + 15, 0, -shootSpeed, true, 1, 0.8);
		}	break;
		case 4:
		{
			Shoot::create(pos.x - 40, pos.y + 15, -shootSpeed / 6, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x - 25, pos.y - 40, 0, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x + 25, pos.y - 40, 0, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x + 40, pos.y + 15, shootSpeed / 6, -shootSpeed, true, 1, 0.8);
		}	break;
		case 5:
		{
			Shoot::create(pos.x - 40, pos.y + 15, -shootSpeed / 3, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x - 25, pos.y - 40, -shootSpeed / 10, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x, pos.y - 40, 0, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x + 25, pos.y - 40, shootSpeed / 10, -shootSpeed, true, 1, 0.8);
			Shoot::create(pos.x + 40, pos.y + 15, shootSpeed / 3, -shootSpeed, true, 1, 0.8);
		}	break;
		case 6:
		{
			Shoot::create(pos.x - 50, pos.y - 20, -shootSpeed / 6, -shootSpeed * 1.0, true, 1, 0.7);
			Shoot::create(pos.x - 30, pos.y - 30, -shootSpeed / 10, -shootSpeed * 1.1, true, 1, 0.7);
			Shoot::create(pos.x - 20, pos.y - 40, 0, -shootSpeed * 1.2, true, 1, 0.7);
			Shoot::create(pos.x + 20, pos.y - 40, 0, -shootSpeed * 1.2, true, 1, 0.7);
			Shoot::create(pos.x + 30, pos.y - 30, shootSpeed / 10, -shootSpeed * 1.1, true, 1, 0.7);
			Shoot::create(pos.x + 50, pos.y - 20, shootSpeed / 6, -shootSpeed * 1.0, true, 1, 0.7);
		}	break;
		case 7:
		{
			Shoot::create(pos.x - 40, pos.y - 10, -shootSpeed / 4, -shootSpeed * 1.1, true, 1, 0.6);
			Shoot::create(pos.x - 30, pos.y - 20, -shootSpeed / 6, -shootSpeed * 1.2, true, 1, 0.6);
			Shoot::create(pos.x - 20, pos.y - 30, -shootSpeed / 10, -shootSpeed * 1.3, true, 1, 0.6);
			Shoot::create(pos.x, pos.y - 50, 0, -shootSpeed * 1.35, true, 1, 0.6);
			Shoot::create(pos.x + 20, pos.y - 30, shootSpeed / 10, -shootSpeed * 1.3, true, 1, 0.6);
			Shoot::create(pos.x + 30, pos.y - 20, shootSpeed / 6, -shootSpeed * 1.2, true, 1, 0.6);
			Shoot::create(pos.x + 40, pos.y - 10, shootSpeed / 4, -shootSpeed * 1.1, true, 1, 0.6);
		}	break;
		case 8:
		{
			Shoot::create(pos.x - 50, pos.y, -shootSpeed / 4, -shootSpeed, true, 1, 0.5);
			Shoot::create(pos.x - 40, pos.y - 10, -shootSpeed / 6, -shootSpeed * 1.1, true, 1, 0.5);
			Shoot::create(pos.x - 30, pos.y - 20, -shootSpeed / 10, -shootSpeed * 1.2, true, 1, 0.5);
			Shoot::create(pos.x - 20, pos.y - 30, 0, -shootSpeed * 1.3, true, 1, 0.5);
			Shoot::create(pos.x + 20, pos.y - 30, 0, -shootSpeed * 1.3, true, 1, 0.5);
			Shoot::create(pos.x + 30, pos.y - 20, shootSpeed / 10, -shootSpeed * 1.2, true, 1, 0.5);
			Shoot::create(pos.x + 40, pos.y - 10, shootSpeed / 6, -shootSpeed * 1.1, true, 1, 0.5);
			Shoot::create(pos.x + 50, pos.y, shootSpeed / 4, -shootSpeed, true, 1, 0.5);
		}	break;
		case 9:
		{
			Shoot::create(pos.x - 50, pos.y - 10, -shootSpeed / 3, -shootSpeed * 1, true, 1, 0.45);
			Shoot::create(pos.x - 40, pos.y - 20, -shootSpeed / 4, -shootSpeed * 1.1, true, 1, 0.45);
			Shoot::create(pos.x - 30, pos.y - 30, -shootSpeed / 6, -shootSpeed * 1.2, true, 1, 0.45);
			Shoot::create(pos.x - 20, pos.y - 40, -shootSpeed / 10, -shootSpeed * 1.3, true, 1, 0.45);
			Shoot::create(pos.x, pos.y - 50, 0, -shootSpeed * 1.4, true, 1, 0.45);
			Shoot::create(pos.x + 20, pos.y - 40, shootSpeed / 10, -shootSpeed * 1.3, true, 1, 0.45);
			Shoot::create(pos.x + 30, pos.y - 30, shootSpeed / 6, -shootSpeed * 1.2, true, 1, 0.45);
			Shoot::create(pos.x + 40, pos.y - 20, shootSpeed / 4, -shootSpeed * 1.1, true, 1, 0.45);
			Shoot::create(pos.x + 50, pos.y - 10, shootSpeed / 3, -shootSpeed * 1, true, 1, 0.45);
		}	break;
		case 10:
		{
			Shoot::create(pos.x - 60, pos.y + 10, -shootSpeed / 3, -shootSpeed * 0.9, true, 1, 0.4);
			Shoot::create(pos.x - 50, pos.y - 0, -shootSpeed / 4, -shootSpeed * 1, true, 1, 0.4);
			Shoot::create(pos.x - 40, pos.y - 10, -shootSpeed / 6, -shootSpeed * 1.1, true, 1, 0.4);
			Shoot::create(pos.x - 30, pos.y - 20, -shootSpeed / 10, -shootSpeed * 1.2, true, 1, 0.4);
			Shoot::create(pos.x - 20, pos.y - 30, 0, -shootSpeed * 1.3, true, 1, 0.4);
			Shoot::create(pos.x + 20, pos.y - 30, 0, -shootSpeed * 1.3, true, 1, 0.4);
			Shoot::create(pos.x + 30, pos.y - 20, shootSpeed / 10, -shootSpeed * 1.2, true, 1, 0.4);
			Shoot::create(pos.x + 40, pos.y - 10, shootSpeed / 6, -shootSpeed * 1.1, true, 1, 0.4);
			Shoot::create(pos.x + 50, pos.y - 0, shootSpeed / 4, -shootSpeed * 1, true, 1, 0.4);
			Shoot::create(pos.x + 60, pos.y + 10, shootSpeed / 3, -shootSpeed * 0.9, true, 1, 0.4);
		}	break;
		case 11:
		{
			Shoot::create(pos.x - 60, pos.y - 0, -shootSpeed / 2.5, -shootSpeed * 0.9, true, 1, 0.35);
			Shoot::create(pos.x - 50, pos.y - 10, -shootSpeed / 3, -shootSpeed * 1, true, 1, 0.35);
			Shoot::create(pos.x - 40, pos.y - 20, -shootSpeed / 4, -shootSpeed * 1.1, true, 1, 0.35);
			Shoot::create(pos.x - 30, pos.y - 30, -shootSpeed / 6, -shootSpeed * 1.2, true, 1, 0.35);
			Shoot::create(pos.x - 20, pos.y - 40, -shootSpeed / 10, -shootSpeed * 1.3, true, 1, 0.35);
			Shoot::create(pos.x, pos.y - 50, 0, -shootSpeed * 1.4, true, 1, 0.35);
			Shoot::create(pos.x + 20, pos.y - 40, shootSpeed / 10, -shootSpeed * 1.3, true, 1, 0.35);
			Shoot::create(pos.x + 30, pos.y - 30, shootSpeed / 6, -shootSpeed * 1.2, true, 1, 0.35);
			Shoot::create(pos.x + 40, pos.y - 20, shootSpeed / 4, -shootSpeed * 1.1, true, 1, 0.35);
			Shoot::create(pos.x + 50, pos.y - 10, shootSpeed / 3, -shootSpeed * 1, true, 1, 0.35);
			Shoot::create(pos.x + 60, pos.y - 0, shootSpeed / 2.5, -shootSpeed * 0.9, true, 1, 0.35);
		}	break;
		case 12:
		{
			Shoot::create(pos.x - 70, pos.y + 20, -shootSpeed / 2.5, -shootSpeed * 0.8, true, 1, 0.4);
			Shoot::create(pos.x - 60, pos.y + 10, -shootSpeed / 3, -shootSpeed * 0.9, true, 1, 0.4);
			Shoot::create(pos.x - 50, pos.y - 0, -shootSpeed / 4, -shootSpeed * 1, true, 1, 0.4);
			Shoot::create(pos.x - 40, pos.y - 10, -shootSpeed / 6, -shootSpeed * 1.1, true, 1, 0.4);
			Shoot::create(pos.x - 30, pos.y - 20, -shootSpeed / 10, -shootSpeed * 1.2, true, 1, 0.4);
			Shoot::create(pos.x - 20, pos.y - 30, 0, -shootSpeed * 1.3, true, 1, 0.4);
			Shoot::create(pos.x + 20, pos.y - 30, 0, -shootSpeed * 1.3, true, 1, 0.4);
			Shoot::create(pos.x + 30, pos.y - 20, shootSpeed / 10, -shootSpeed * 1.2, true, 1, 0.4);
			Shoot::create(pos.x + 40, pos.y - 10, shootSpeed / 6, -shootSpeed * 1.1, true, 1, 0.4);
			Shoot::create(pos.x + 50, pos.y - 0, shootSpeed / 4, -shootSpeed * 1, true, 1, 0.4);
			Shoot::create(pos.x + 60, pos.y + 10, shootSpeed / 3, -shootSpeed * 0.9, true, 1, 0.4);
			Shoot::create(pos.x + 70, pos.y + 20, shootSpeed / 2.5, -shootSpeed * 0.8, true, 1, 0.4);
		}	break;
		}
		myDeltaTime = 0;
	}
}

void Player::checkCollision()
{
	hitbox1.setPosition(drawPlayerModel.getPosition());
	hitbox2.setPosition(drawPlayerModel.getPosition().x, drawPlayerModel.getPosition().y + hitbox2PosY);

	for (int i = Shoot::shoot.size() - 1; i >= 0; i--)
	{
		if(i >= Shoot::shoot.size() || i < 0) goto end;

		if (Shoot::shoot[i]->playerShoot == false && (Shoot::shoot[i]->checkCollision(hitbox1) || Shoot::shoot[i]->checkCollision(hitbox2)))
		{
			if (shooted == false)
			{
				hp -= Shoot::shoot[i]->getDmg();
				Particle::addParticle(drawPlayerModel.getPosition().x, drawPlayerModel.getPosition().y, "BasicEnemy", 5, 0.25);
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
					goto end;
				}	break;
				}

			}
			Shoot::shoot.erase(Shoot::shoot.begin() + i);
			shooted = true;
		}
	}
end:;
}

void Player::playerHp()
{
	drawHeartModel1.setPosition(20, 10);
	drawHeartModel2.setPosition(100, 10);
	drawHeartModel3.setPosition(180, 10);
}

void Player::playerShooted()
{
	static float time = 0;
	time += GameInfo::getDeltaTime();

	if (time < 333) drawPlayerModel.setColor(sf::Color(255, 255, 255, 0));
	if (time > 333 && time < 666) drawPlayerModel.setColor(sf::Color(255, 255, 255, 255));
	if (time > 666 && time < 999) drawPlayerModel.setColor(sf::Color(255, 255, 255, 0));

	if (time > 1000)
	{
		drawPlayerModel.setColor(sf::Color(255, 255, 255, 255));
		shooted = false;
		time = 0;
	}
}

void Player::playerDeath()
{
	Shoot::shoot.clear();
	resetStats();
	drawPlayerModel.setPosition(1600 / 2, 800);
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

	playerDeathSound.stop();
	playerDeathSound.play();
	
	GameHud::resetHud();
	Shoot::shoot.clear();

	renderDeath = true;
	deathDelay = true;
	checkDeathFx = true;
	canMove = false;
	canShoot = false;
	blockShoots = true;
}

void Player::playerDeathTime()
{
	static float time = 0;
	time += GameInfo::getDeltaTime();
	drawPlayerModel.setColor(sf::Color(255, 255, 255, 0));

	if (time <= 2785 && time > 1000)
	{
		drawPlayerModel.setColor(sf::Color(255, 255, 255, (time - 1000) / 7));
	}
	if (time > 2785) drawPlayerModel.setColor(sf::Color(255, 255, 255, 255));

	if (time > 3000)
	{
		renderDeath = false;
		LevelManager::actualLevel = 0;
		BasicEnemy::enemy.clear();
		deathDelay = false;
		canMove = true;
		canShoot = true;
		blockShoots = false;
		time = 0;
	}
}

void Player::addHp()
{
	hp += 2;
	if (hp > 6) hp = 6;

	switch (hp)
	{
	case 6: drawHeartModel3.setTexture(heart); break;
	case 5:	drawHeartModel2.setTexture(heart); drawHeartModel3.setTexture(halfHeart);  break;
	case 4:	drawHeartModel2.setTexture(heart); drawHeartModel3.setTexture(emptyHeart); break;
	case 3:	drawHeartModel1.setTexture(heart); drawHeartModel2.setTexture(halfHeart); break;
	case 2:	drawHeartModel1.setTexture(heart); drawHeartModel2.setTexture(emptyHeart); break;
	case 1:	drawHeartModel1.setTexture(halfHeart); break;
	}
}

void Player::addShootDelay()
{
	if (shootDuration == 1500)
	{
		shootDuration *= 0.7;
	}
	shootDuration *= 0.88;

	GameHud::shootDelayLevel();
}

void Player::addShootSpeed()
{
	if (shootSpeed == 3)
	{
		shootSpeed *= 1.5;
	}
	shootSpeed *= 1.12;

	GameHud::shootSpeedLevel();
}

void Player::addShootAmmount()
{
	shootAmmount++;

	GameHud::shootAmmountLevel();
}

void Player::sizeDown()
{
	static bool firstTime = true;
	if (firstTime)
	{
		drawPlayerModel.setScale(drawPlayerModel.getScale().x * 0.85, drawPlayerModel.getScale().y * 0.85);
		hitbox1.setScale(hitbox1.getScale().x * 0.85, hitbox1.getScale().y * 0.85);
		hitbox2.setScale(hitbox2.getScale().x * 0.85, hitbox2.getScale().y * 0.85);
		hitbox2PosY *= 0.85;
		firstTime = false;
	}

	drawPlayerModel.setScale(drawPlayerModel.getScale().x * 0.97, drawPlayerModel.getScale().y * 0.97);
	hitbox1.setScale(hitbox1.getScale().x * 0.97, hitbox1.getScale().y * 0.97);
	hitbox2.setScale(hitbox2.getScale().x * 0.97, hitbox2.getScale().y * 0.97);
	hitbox2PosY *= 0.97;

	GameHud::sizeDownLevel();
}

void Player::deathFx()
{
	Explosion::create(drawPlayerModel.getPosition());
	Particle::addParticle(drawPlayerModel.getPosition().x, drawPlayerModel.getPosition().y, "BasicEnemy", 25, 1);
	checkDeathFx = false;
}
