//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//using namespace sf;
//
//int main()
//{
//	RenderWindow app(VideoMode(690, 690), "8-Puzzle!");
//	app.setFramerateLimit(60);
//	
//	Texture t;
//	t.loadFromFile("E:\\SFML\\Project1\\images\\8_p.png");
//
//	int w = 230;
//	int grid[6][6] = { 0 };
//	Sprite sprite[20];
//
//	int n = 0;
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 3; j++)
//		{
//			n++;
//			sprite[n].setTexture(t);
//			sprite[n].setTextureRect(IntRect(i * w, j * w, w, w));
//			grid[i + 1][j + 1] = n;
//		}
//
//	while (app.isOpen())
//	{
//		Event e;
//		while (app.pollEvent(e))
//		{
//			if (e.type == Event::Closed)
//				app.close();
//
//			if (e.type == Event::MouseButtonPressed)
//				if (Mouse::isButtonPressed(Mouse::Left))
//				{
//					Vector2i pos = Mouse::getPosition(app);
//					int x = pos.x / w + 1;
//					int y = pos.y / w + 1;
//
//					int dx = 0;
//					int dy = 0;
//
//					if (grid[x + 1][y] == 9)
//					{
//						dx = 1;
//						dy = 0;
//					};
//					if (grid[x][y + 1] == 9)
//					{
//						dx = 0;
//						dy = 1;
//					};
//					if (grid[x][y - 1] == 9)
//					{
//						dx = 0;
//						dy = -1;
//					};
//					if (grid[x - 1][y] == 9)
//					{
//						dx = -1;
//						dy = 0;
//					};
//
//					int n = grid[x][y];
//					grid[x][y] = 9;
//					grid[x + dx][y + dy] = n;
//
//					sprite[9].move(-dx * w, -dy * w);
//					float speed = 3;
//
//					for (int i = 0; i < w; i += speed)
//					{
//						sprite[n].move(speed * dx, speed * dy);
//						app.draw(sprite[9]);
//						app.draw(sprite[n]);
//						app.display();
//					}
//				}
//		}
//
//		app.clear(Color::White);
//		for (int i = 0; i < 3; i++)
//			for (int j = 0; j < 3; j++)
//			{
//				int n = grid[i + 1][j + 1];
//				sprite[n].setPosition(i * w, j * w);
//				app.draw(sprite[n]);
//			}
//
//		
//		app.display();
//		
//	}
//
//	return 0;
//}
