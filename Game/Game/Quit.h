void quit(RenderWindow& window, Font& font2, Clock& clock){
	sf::Text ques; //confirmation to close?
	ques.setFont(font2);
	ques.setPosition(10.0f, 20.0f);
	ques.setString("Are you sure you want to quit?");
	ques.setFillColor(sf::Color::White);
	ques.setCharacterSize(18);

	sf::Text yes;
	yes.setFont(font2);
	yes.setPosition(10.0f, 80.0f);
	yes.setString("Quit & Save");
	yes.setFillColor(sf::Color::White);
	yes.setCharacterSize(14);

	sf::Text no;
	no.setFont(font2);
	no.setPosition(10.0f, 110.0f);
	no.setString("Don't Quit");
	no.setFillColor(sf::Color::White);
	no.setCharacterSize(14);
	sf::RenderWindow quitWindow(sf::VideoMode(400, 200), "Quit");
	while (quitWindow.isOpen()){
		sf::Event event;
		while (quitWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				quitWindow.close();
			}
		}
		quitWindow.clear(sf::Color::Black);
		sf::Vector2i localPosition2 = sf::Mouse::getPosition(quitWindow);//getting the position of Mouse;

		if (localPosition2.x >= 10 && localPosition2.x <= 239 && localPosition2.y >= 82 && localPosition2.y <= 99){
			yes.setFillColor(sf::Color::Red);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				quitWindow.close();
				window.clear();
				no.setPosition(180.0f, 100.0f);
				no.setCharacterSize(64);
				no.setFillColor(sf::Color::Green);
				no.setString("   THANK YOU\n    for Playing");
				window.draw(no);
				saveGame();
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