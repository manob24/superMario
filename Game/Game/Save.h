


int highscore(float x){
	if (x + maxs>maxdistance) maxdistance = x;
	return maxdistance;
}



void saveGame(){
	FILE *savePath, *others;
	savePath = fopen("savepath.txt", "w+");
	for (int k = 0; k < H; k++){
		for (int l = 0; l < W; l++){
			fprintf(savePath, "%d", path[k][l]);
		}
		fprintf(savePath, "\n");
	}
	fclose(savePath);

	others = fopen("others.txt", "w+");
	fprintf(others, "%f %f ", pos.x, pos.y);
	fprintf(others, "%d %d %d", lives, level, maxscore2);
	fclose(others);
}



void typeName(RenderWindow& window, Font& font, int k, Text& text){
	window.clear();

	sf::Text name;
	name.setFont(font);
	name.setPosition(100.0f, 200.0f);
	name.setStyle(sf::Text::Bold);
	char n[100];
	std::string playerName;
	window.draw(text);
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == event.Closed){
				window.close();
			}

			if (event.type == sf::Event::TextEntered)
			{

				if (event.text.unicode > 64 && event.text.unicode<91 || event.text.unicode>96 && event.text.unicode < 123)
				{
					playerName += event.text.unicode;
					n[k] = event.text.unicode;
					k++;
				}
				name.setString(playerName);

			}
			window.draw(text);
			window.draw(name);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
				n[k] = '\0';
				FILE *highscore;
				highscore = fopen("highscore.txt", "w+");
				fprintf(highscore, "%s %d", n, maxscore2);
				fclose(highscore);
				return;
			}

			window.display();
		}
	}
	//window.draw(enterUrName);
	return typeName(window, font, k, text);
}
