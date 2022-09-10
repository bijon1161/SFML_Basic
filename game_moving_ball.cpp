#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<cstdlib>
#include<vector>

using namespace sf;

//VECTOR MATH
//LENGTH OF VECTOR
//|V| = sqrt(pow(2, Vx) + pow(2, Vy));
//NORMALIZE
//U = V/|V| = (Vx, Vy) / sqrt(pow(2, Vx) + pow(2, Vy));






class Enemy
{
public:
	RectangleShape object;
	int HP;
	int HPMax;

	Enemy(Vector2u windowSize)
	{
		this->HPMax = rand() % 3 + 1;
		this->HP = this->HPMax;

		int r = rand() % 255;
		int g = rand() % 255;
		int b = rand() % 255;

		this->object.setFillColor(Color(r,g,b));

		this->object.setSize(Vector2f(50.f, 50.f));

		this->object.setPosition(windowSize.x - this->object.getGlobalBounds().width, rand() % (int)(windowSize.y - this->object.getGlobalBounds().height));
	}

	~Enemy() {}
};

int main()
{
	srand(time(NULL));
	

	RenderWindow window(VideoMode(1280, 720), "Moving Ball!", Style::Default);
	window.setFramerateLimit(200);

	//player(ball)
	CircleShape ball;
	

	int HP;
	int HPMax;
	HPMax = 10;
	HP = HPMax;
	int status = 0;
	//color = color;
	ball.setFillColor(Color::Blue);
	ball.setRadius(20.f);
	ball.setPosition(20.f, 360.f);

	//hp bar
	RectangleShape hpbar;
	hpbar.setFillColor(Color::Red);
	hpbar.setSize(Vector2f(200.f, 20.f));
	hpbar.setPosition(window.getSize().x / 2 + 50.f, 20.f);
	//framerate
	Clock clock;
	float dt = 0.f;
	float dtMultiplier = 62.5f;

	//Init text
	Font font;
	font.loadFromFile("Fonts/Dosis-Light.ttf");

	//UI init
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(window.getSize().x / 2-50.f, 10.f);

	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(40);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(window.getSize().x / 2-60.f, window.getSize().y / 2);
	gameOverText.setString("GAME OVER!");

	//Player init
	int score = 0;
	
	Text hpText;
	hpText.setFont(font);
	hpText.setCharacterSize(12);
	hpText.setFillColor(Color::White);
	hpText.setPosition(window.getSize().x / 2 + 50.f, 10.f);

	//Enemy init
	float enemySpawnTimer = 0.f;
	std::vector<Enemy> enemies;

	Text eHpText;
	eHpText.setFont(font);
	eHpText.setCharacterSize(12);
	eHpText.setFillColor(Color::White);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//dt = 0,016 seconds / frame at 60fps
		dt = clock.restart().asSeconds();
		std::cout << dt << "\n";

		//UPDATE ========================================================UPDATE
		if (HP > 0 && status==0 )
		{
			//Player
			if (Keyboard::isKeyPressed(Keyboard::W))
				ball.move(0.f, -10.f * dt * dtMultiplier);
			if (Keyboard::isKeyPressed(Keyboard::A))
				ball.move(-10.f * dt * dtMultiplier, 0.f);
			if (Keyboard::isKeyPressed(Keyboard::S))
				ball.move(0.f, 10.f * dt * dtMultiplier);
			if (Keyboard::isKeyPressed(Keyboard::D))
				ball.move(10.f * dt * dtMultiplier, 0.f);

			hpText.setPosition(ball.getPosition().x, ball.getPosition().y - hpText.getGlobalBounds().height);
			hpText.setString(std::to_string(HP) + "/" + std::to_string(HPMax));

			//Collision with window
			if (ball.getPosition().x <= 0) {
				//ball.setPosition(0.f, ball.getPosition().y);
				status = 1;
			}//Left
				
			if (ball.getPosition().x >= window.getSize().x - ball.getGlobalBounds().width) {
				//ball.setPosition(window.getSize().x - ball.getGlobalBounds().width, ball.getPosition().y);
				status = 1;
			}//Right
				
			if (ball.getPosition().y <= 0) {
			//	ball.setPosition(ball.getPosition().x, 0.f);
				status = 1;
			}//Top
				
			if (ball.getPosition().y >= window.getSize().y - ball.getGlobalBounds().height) {
				//.setPosition(ball.getPosition().x, window.getSize().y - ball.getGlobalBounds().height);
				status = 1;
			} //Bottom
				

			
			//Enemy
			if (enemySpawnTimer < 25)
				enemySpawnTimer += 1.f * dt * dtMultiplier;

			//enemy spawn
			if (enemySpawnTimer >= 25)
			{
				enemies.push_back(Enemy(window.getSize()));
				enemySpawnTimer = 0; //reset timer
			}

			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies[i].object.move(-6.f * dt * dtMultiplier, 0.f);

				if (enemies[i].object.getPosition().x <= 0 - enemies[i].object.getGlobalBounds().width)
				{
					enemies.erase(enemies.begin() + i);
					break;
				}

				if (enemies[i].object.getGlobalBounds().intersects(ball.getGlobalBounds()))
				{
					enemies.erase(enemies.begin() + i);

					HP--; // PLAYER TAKE DAMAGE
					break;
				}
				
				score++;

			}
			
			//UI Update
			scoreText.setString("Score: " + std::to_string(score/10));
			hpbar.setSize(Vector2f((float)HP * 20.f, 10.f));
		}


		//Draw ===================================================================== DRAW
		window.clear();

		//player
		window.draw(ball);

		//enemy
		for (size_t i = 0; i < enemies.size(); i++)
		{
			//eHpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
			//eHpText.setPosition(enemies[i].object.getPosition().x, enemies[i].object.getPosition().y - eHpText.getGlobalBounds().height);
			//window.draw(eHpText);
			window.draw(enemies[i].object);
		}

		//UI
		window.draw(scoreText);
		//window.draw(hpText);
		window.draw(hpbar);

		if (HP <= 0)
			window.draw(gameOverText);
		if (status == 1)
			window.draw(gameOverText);

		window.display();
	}

	return 0;
}