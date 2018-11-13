void collision(int coy, int cox){
	if (TileMap1[coy][cox] == 'P') {
		onground = true;//   Ground Tiles
		blocked = false;
	}
	if (TileMap1[coy][cox] == 'k')  {
		onground = true;//   Air Bricks
		blocked = true;
	}
	if (TileMap1[coy][cox] == 'w')   {
		onground = false;//   Clouds
		blocked = false;
	}
	if (TileMap1[coy][cox] == 'b') {
		onground = true;//   Air Bricks
		blocked = true;
	}
	if (TileMap1[coy][cox] == 'c'){
		onground = true;//   Question marks
		blocked = true;
	}
	if (TileMap1[coy][cox] == 't')  {
		onground = true;//   Tunnels
		blocked = true;
	}
	if (TileMap1[coy][cox] == 'r')   {
		onground = true;//   Stair Bricks
		blocked = true;
	}
	if (TileMap1[coy][cox] == '0')  {
		onground = true;
		blocked = true;
	}
	if (TileMap1[coy][cox] == ' ')  {
		onground = false;
		blocked = false;
	}

}
void enemyMove(positionOfEnemy& enemypos, Sprite& enemy, RenderWindow& window, int k){
	int cox = enemypos.x / 16;
	int coy = enemypos.y / 16;
	collision(coy + 1, cox);
	//enemypos.y += 0.5f;
	if (!onground){
		enemypos.y += 0.5f;
	}
	if (enemypos.y > 300.0f&&enemypos.y<350){
		enemypos.y++;
	}
	//printf("%f ", enemypos.y);

	else{
		if (direction[k] == 1){
			collision(coy, cox + 1);
			enemypos.x += 0.5;
		}
		else if (direction[k] == -1){
			collision(coy, cox);
			enemypos.x -= 0.5;
		}
		if (blocked){
			direction[k] *= -1;
			//	printf("%d %d\n", k, direction[k]);
		}
	}
	//printf("%d\n", direction[k]);
	enemy.setPosition(enemypos.x, enemypos.y - 5);
	window.draw(enemy);
}