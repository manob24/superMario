#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace sf;

bool arr[900] = { 0 };

char TileMap1[H][W];
time_t t;


void createstairs(int n,char stairs[][6]){
	
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i < j)
				stairs[i][j] = 'r';
			else
				stairs[i][j] = ' ';
		}
	}
}

String tunnel[3] = {
	"t0",
	"00",
	"00",
};

String holes[H-2] = {
	"            ",
	"            ",
	"            ",
	"            ",
	"            ",
	"            ",
	"   uu       ",
	"            ",
	"    u       ",
	"       kk   ",
	" u          ",
	"   kk       ",
	"            ",
	"k           ",
	"            ",
	"            ",
	"            ",
	"            ",
	"            ",
	"            ",
};

void createTilemap1(){
	int c = 0, d = 0, i, j;
	int stair=7,hole = 5,floor=10;
	for (i = 0; i < 10; i++){
		arr[i] = 1;
	}
	
	for (c = 0; c < H; c++){

		for (d = 0; d < W; d++){
			if (c < H && c > H - 4){
				TileMap1[c][d] = 'r';

			}
			else if (c == 0 || d == 0 || d == W - 1 || d == W - 2){
				TileMap1[c][d] = 'r';

			}
			else{
				TileMap1[c][d] = ' ';
			}

		}

	}
	srand((unsigned)time(&t));
	bool f = 0;
	while (stair--){
		int h = rand() % 100;
		h += stair*100+10;
		while (arr[h] && arr[h + 3] && arr[h + 6]){
			h++;
		}
		for (i = 0; i < 6; i++){
			arr[h+i] = 1;
		}
		printf("%d ", h);
		int k = (h % 3) ;
		k += 4;
		char stairs[6][6];
		printf("%d\n", k);
		createstairs(k,stairs);
		for (i = H - 4; i > H - 4-k; i--){
			for (j = h; j < h + k; j++){
				TileMap1[i][j] = stairs[H - 4 - i][j - h];
			}
		}
	}
	

	while (floor--){
		int r = rand() % 15;
		r += 5;
		int h = rand() % 70;
		h += floor * 100+10;
		while (arr[h] && arr[h + 3] && arr[h + 6]){
			h++;
		}
		for (i = 0; i < 6; i++){
			arr[h + i] = 1;
		}
		int k = h % 9;
		j =H- 6;
		if (floor % 3 == 0 || floor % 5 == 0){
			for (i = h; i < h + r; i++){
				TileMap1[j][i] = 'k';
				if (j > k&&j>5)
					j--;
			}
		}
		else{
			for (i = h; i < h + r; i++){
				TileMap1[H-8][i] = 'k';
			}
		}
	}
	int tunnels = 15;
	while (tunnels--){
		int h = rand() % 100;
		h += tunnels * 55 + 10;
		while (arr[h] && arr[h + 2]){
			h += 3;
		}
		arr[h] = 1;
		arr[h + 1] = 1;
		for (i = H - 6; i < H - 3; i++){
			for (j = h; j < h + 2; j++){
				TileMap1[i][j] = tunnel[i - H + 6][j - h];
			}
		}
	}
	for (c = 0; c < H; c++){
		
		for (d = 0; d < W; d++){
			if (c < H && c > H - 4){
				TileMap1[c][d] = 'P';
				
			}
			else if (c == 0 || d == 0 || d == W - 1 || d == W - 2){
				TileMap1[c][d] = 'r';
			
			}
			else if(c>0&&c<10){
				TileMap1[c][d] = ' ';
			}

		}

	}
	while (hole--){
		int h =( rand() % 100)+100;
		h += hole * 100;
		for (i = 2; i < H; i++){
			for (j = h; j < h + 12; j++){
				TileMap1[i][j] = holes[i - 2][j - h];
			}
		}
	}

	FILE *savetilemap;
	savetilemap = fopen("savetilemap.txt", "w+");
	for (i = 0; i < H; i++){
		for (j = 0; j < W; j++){
			fprintf(savetilemap, "%c", TileMap1[i][j]);
		}
		//fprintf(savetilemap,"\n");
	}
	fclose(savetilemap);
}
String TileMap2[H] = {
	"rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr",
	"r                                                                                                                                                                                                                                                       b                                                                                                                                                                           b                                                                                                                                                                                               b                                                                                                                                                                                                                                                         r",
	"r                                                                                                                                                                                                                                                       b                                                                                                                                                                           b                                                                                                                                                                                               b                                                                                                                                                                                                                                                         r",
	"r                                                                                                                                                                                                                                                       b                                                                                                                                                                           b                                                                                                                                                                                               b                                                                                                                                                                                                                                                         r",
	"r                                                                                                                                                                                                                                                       b                                                                                                                                                                           b                                                                                                                                                                                               b                                                                                                                                                                                                                                                         r",
	"r                                                                                                                                                                                                                                                       b                                                                                                                                                                           b                                                                                                                                                                                               b                                                                                                                                                                                                                                                         r",
	"r                                                                                                                                                                    uuuu   uuuu                                                                                                                                         u                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    r",
	"r                                                                                                                                                                                                          uuu                      u  u                                                                                                                                                                                                              uuuuuuuuuu  uuuuu                                                                                                                                                                                                u   u     u    u    u                                                                                                                                                                                                  r",
	"r                                                                                                                                                                                                    uuu                     u  u                   uuuuuuuuu                                                                                                                                                u                                                                                                                                                                                                                                     u                        u       u                                                                                                                                                                                   uuuuuuu               r",
	"r              uuuuuuuu                                                            u                                             uuuu  uuuu     u uuuu  uuuuuuuuuuu                             uu                     u  u                                                                                             uuu                                                                                u   u                                                                                                                                                                                                                                 u                       u    u   u    u                                                               uuuuuuu    uuuuuuuu          uuuuuuu                                                                                                   r",
	"r                                                                                                                                                                                                                                                   uuuuuuuuu                                                                                                                                             u    u                                                                                                     uuuuuuuuuuuuuuuuuuuuu                                                                                                     u                       u        u         u                                                            uuuuuuu    uuuuuuuu          uuuuuuu                                                                                                   r",
	"r                                                                                   uu                                                                                                                                                                                                                                                                                                                         u                                                                                                                                                                                                                             u                                          u                                                              uuuuuuu    uuuuuuuu          uuuuuuu                                                     uuuuuuu                                       r",
	"r                                             uuuuu                                 uu      u                                                                                                                                       uuuuuu                                                                      uuu             uuu                                                                            u         uuu                                                                                                                                                                                                               u                                         uu   uu                                                                                        uuuuuuu                                                                                                   r",
	"r                                                                                   uu                                                                      uuuuuuuuuuuu   uuuuuuuuuuu                                    uuuuuu                                                                                                                                                                               u                                                                                                                                                                                                                         u                                       uuu         uuu                                                                                    uuuuuuu                                          uuuuuuu                                                  r",
	"r                    uuuuu                                                                                                                                                                                                                                                                                                                                                                                     u                                                                                         uu    uu    uuu    uu   uu                                                                                                    u                                    uuuu                 uuuu                                  uuuuuuuuuuu                                  uuuuuuu                                                                                                   r",
	"r                                                                                                                                                                                                                uuuuuu                                                                                                                                                                                        u                                                   uu                                                                                                                                                                u                                                                                                 uuuuuuuuuuu                                  uuuuuuu                                                                      uuuuuuu                      r",
	"r                                                                                                                                                                                                                                                                                                                                                                                                              u                                                                                                                                                                                                                   u                                                                                                   uuuuuuuuuuu                                                                                                                                            r",
	"r                                                        uuuuuu                                                                                                                                                                                                                                                                                                                                                u                                                                                                                                                                                                                 u                                                                                                                                                                                                                                                            r",
	"r                                                                                                                                                                                                                                                                                                                                                                                                              u                                                                                                                                                                                                                                                                                                                                                                                                                                                                              r",
	"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", };
	
void printMap(Sprite& tile, RectangleShape& coin, RenderWindow& window, int coy, int cox)
{
	//  Coins in here

	for (int i = 0; i < H; i++)
	for (int j = 0; j < W; j++)
	{
		//if (TileMap1[i][j] == 'u')  coins.setTextureRect(IntRect(0, 0, 50, 50));  //   Coins
		if (TileMap2[i][j] == ' ' || TileMap2[i][j] == '0' || TileMap2[i][j] == 'r') continue;
		if (TileMap2[i][j] == 'u' && path[i][j] == 0)

			coin.setPosition(j * 16, i * 16);
		if (TileMap2[i][j] == 'u' && path[i][j] == 1)
			maxscore2 += 2;
		window.draw(coin);

	}

	//ForeScreen Tiles
	for (int i = 0; i < H; i++)
	for (int j = 0; j < W; j++)
	{
		if (TileMap1[i][j] == 'P')  tile.setTextureRect(IntRect(111, 112, 17, 17));  //   Ground Tiles
		if (TileMap1[i][j] == 'k')  tile.setTextureRect(IntRect(143, 112, 16, 16));  //   Air Bricks
		if (TileMap1[i][j] == 'w')  tile.setTextureRect(IntRect(99, 224, 41, 31));  //  Clouds
		if (TileMap1[i][j] == 'b')  tile.setTextureRect(IntRect(143, 128, 16, 16));  //   Air Bricks
		if (TileMap1[i][j] == 'c')  tile.setTextureRect(IntRect(127, 112, 16, 16));  //    Question marks
		if (TileMap1[i][j] == 't')  tile.setTextureRect(IntRect(0, 47, 32, 48));  //   Tunnels
		if (TileMap1[i][j] == 'r')  tile.setTextureRect(IntRect(111, 112, 16, 16));  //   Stair Bricks
		if (TileMap1[i][j] == ' ' || TileMap1[i][j] == '0' || TileMap1[i][j] == 'u') continue;

		//int k = posX / 2;
		tile.setPosition(j * 16, i * 16);
		window.draw(tile);

	}
}