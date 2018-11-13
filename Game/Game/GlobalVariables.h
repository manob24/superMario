#include <SFML/Graphics.hpp>


#define Winwidth 850.0
#define Winheight 350.0
#define gravity  2
#define groundHeight  307
#define jumpheight 80.0


const int H = 22;
const int W = 864;

struct pos{
	float x;
	float y;
}pos;

struct positionOfEnemy{
	float x;
	float y;
};



float jumped = 0.0f;
positionOfEnemy enemypos[1000];
int noOfEnemy = 20;
//float posx = 30.0, posy = 257.0;//position of Charcter
sf::String s;
int level = 1, maxdistance, maxs = 0, maxscore, maxscore2;
int lives = 5, by[2300], bx, ty;
bool gameStarted = false;
bool HighScore = false;
bool Quit = false;
bool onground = false;
bool blocked = false;
int path[22][864] = { 0 };
bool gover = false;
bool started = false;
bool jump = false;
bool typing = false;

sf::Time t1 = sf::seconds(3);

int direction[1000];

//enemy
sf::Sprite enemy[1000];
//enemy.setPosition(120, 282);
sf::Texture sa;

void makePathNull(){
	pos.x = 30.0;
	pos.y = 257.0;
	for (int i = 0; i < H; i++)
	for (int j = 0; j < W; j++)
	{
		path[i][j] = 0;
	}
}