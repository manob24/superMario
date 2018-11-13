


void beforeGameStarting(RenderWindow& window, Font& font, Font& font2, Vector2u& texturesize){
	sf::RectangleShape wlcm(sf::Vector2f(850.0f, 440.0f));
	sf::Texture welcome;
	welcome.loadFromFile("welcomeback.jpg");
	wlcm.setTexture(&welcome);

	sf::Clock clock;

	sf::RectangleShape ratmn(sf::Vector2f(100.0f, 210.0f));
	ratmn.setPosition(0, 30);
	sf::Texture ratmnf;
	ratmnf.loadFromFile("char.png");
	ratmn.setTexture(&ratmnf);

	sf::Text ng;//newGame

	// select the font
	ng.setFont(font); // font is a sf::Font

	ng.setPosition(550.0f, 120.0f);
	// set the string to display
	ng.setString("New Game");

	// set the character size
	ng.setCharacterSize(32); // in pixels, not points!

	// set the color
	ng.setFillColor(sf::Color::White);

	// set the text style
	ng.setStyle(sf::Text::Bold);

	sf::Text cont; //continue
	cont.setFont(font);
	cont.setPosition(550.0f, 80.0f);
	cont.setString("Continue");
	cont.setFillColor(sf::Color::White);
	cont.setStyle(sf::Text::Bold);

	sf::Text hs; //High Score
	hs.setFont(font);
	hs.setPosition(550.0f, 160.0f);
	hs.setString("Highest Score");
	hs.setStyle(sf::Text::Bold);

	sf::Text quit; //Quit
	quit.setFont(font);
	quit.setPosition(550.0f, 200.0f);
	quit.setString("Quit");
	quit.setStyle(sf::Text::Bold);

	//Welcome page content ended
	//Quit window
	sf::Text ques; //confirmation to close?
	ques.setFont(font2);
	ques.setPosition(10.0f, 20.0f);
	ques.setString("Are you sure you want to quit me?");
	ques.setFillColor(sf::Color::White);
	ques.setCharacterSize(18);

	sf::Text yes;
	yes.setFont(font2);
	yes.setPosition(10.0f, 80.0f);
	yes.setString("Yes. See you again");
	yes.setFillColor(sf::Color::White);
	yes.setCharacterSize(14);

	sf::Text no;
	no.setFont(font2);
	no.setPosition(10.0f, 110.0f);
	no.setString("Sorry, it was a mistake");
	no.setFillColor(sf::Color::White);
	no.setCharacterSize(14);
	// set the font size
	ng.setCharacterSize(32); // in pixels, not points!

	// set the color
	ng.setFillColor(sf::Color::White);
	cont.setCharacterSize(32);
	cont.setFillColor(sf::Color::White);
	hs.setCharacterSize(32);
	hs.setFillColor(sf::Color::White);
	quit.setCharacterSize(32);
	quit.setFillColor(sf::Color::White);



	ratmn.setTextureRect(sf::IntRect(texturesize.x * 10, texturesize.y * 19, texturesize.x, texturesize.y));
	ratmnf.setSmooth(true);

	sf::Vector2i localPosition = sf::Mouse::getPosition(window);//getting the position of Mouse;
	if (!gameStarted&&localPosition.y >= 165 && localPosition.y <= 197 && localPosition.x >= 550 && localPosition.x <= 730){
		hs.setCharacterSize(40);
		hs.setFillColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			HighScore = true;
			return;
		}
	}
	else if (!gameStarted&&localPosition.y >= 125 && localPosition.y <= 157 && localPosition.x >= 550 && localPosition.x <= 730){
		// set the font size
		ng.setCharacterSize(40); // in pixels, not points!

		// set the color
		ng.setFillColor(sf::Color::Red);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			gameStarted = true;
			createTilemap1();
			level = 1;
			maxscore2 = 0;
			maxs = 0;
			maxscore = 0;
			lives = 5;
			makePathNull();
			started = true;
			for (int k = 0; k < noOfEnemy; k++){

				direction[k] = 1;
				enemy[k].setTexture(sa);
				int h = (rand() % ((864 * 16) / noOfEnemy)) + 120;
				enemypos[k].x = h;
				enemypos[k].x *= (k + 1);

				enemypos[k].y = 240;
			}
		}
	}
	else if (!gameStarted&&localPosition.y >= 85 && localPosition.y <= 117 && localPosition.x >= 550 && localPosition.x <= 730){
		cont.setCharacterSize(40);
		cont.setFillColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			gameStarted = true;
		}
		FILE *loadtilemap, *others;
		loadtilemap = fopen("savetilemap.txt", "r+");
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				char c;
				fscanf(loadtilemap, "%c", &c);
				TileMap1[i][j] = c;
			}
		}
		fclose(loadtilemap);
		others = fopen("others.txt", "r+");
		fscanf(others, "%f %f", &pos.x, &pos.y);
		fscanf(others, "%d %d %d", &lives, &level, &maxscore2);
		fclose(others);
		maxscore = maxscore2;
		for (int k = 0; k < noOfEnemy; k++){

			direction[k] = 1;
			enemy[k].setTexture(sa);
			int h = (rand() % ((864 * 16) / noOfEnemy)) + 120;
			enemypos[k].x = h;
			enemypos[k].x *= (k + 1);
			enemypos[k].y = 240;
		}

	}

	else if (!gameStarted&&localPosition.y >= 205 && localPosition.y <= 237 && localPosition.x >= 550 && localPosition.x <= 730){
		quit.setCharacterSize(40);
		quit.setFillColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::RenderWindow quitWindow(sf::VideoMode(400, 200), "Quit");
			while (quitWindow.isOpen()){
				quitWindow.clear(sf::Color::Black);
				sf::Vector2i localPosition2 = sf::Mouse::getPosition(quitWindow);//getting the position of Mouse;

				if (localPosition2.x >= 10 && localPosition2.x <= 239 && localPosition2.y >= 82 && localPosition2.y <= 99){
					yes.setFillColor(sf::Color::Red);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						quitWindow.close();
						window.clear();
						no.setPosition(180.0f, 160.0f);
						no.setCharacterSize(64);
						no.setFillColor(sf::Color::Green);
						no.setString("   THANK YOU\n    for Playing");
						window.draw(no);
						window.display();
						clock.restart();
						while (1){
							sf::Time elapsed1 = clock.getElapsedTime();
							if (elapsed1 > t1)
								break;

						}
						window.close();
					}

				}
				else if (localPosition2.x >= 10 && localPosition2.x <= 200 && localPosition2.y >= 113 && localPosition2.y <= 130){
					no.setFillColor(sf::Color::Green);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						quitWindow.close();
					}
				}
				else{
					yes.setFillColor(sf::Color::White);
					no.setFillColor(sf::Color::White);
				}

				quitWindow.draw(ques);
				quitWindow.draw(yes);
				quitWindow.draw(no);
				quitWindow.display();
			}
		}
	}
	window.draw(wlcm);
	window.draw(ng);
	window.draw(cont);
	window.draw(hs);
	window.draw(quit);
	window.draw(ratmn);
}