#include "Map.h"

Map::~Map()
{
}
void Map::printMap(int posx, int posy, SDL_Rect* rect)
{

	background.loadSprite("sprites/map.png");

	int count = 0;
	for (int i = 0; i < spriteHeigth; i++)
	{
		for (int j = 0; j < spriteWidth; j++)
		{
			x[count] = 64 * j;
			y[count] = 64 *i;
			w[count] = 64;
			h[count] = 64;

			count++;
		}
	}

	background.setClips(spriteWidth*spriteHeigth, x, y, w, h);

	printLayer(walkable);
	printLayer(tallgrass);
	printLayer(water);
	printLayer(notwalkable);


}
void Map::printLayer(int *layer)
{
	background.setSequenceB(width*heigth, layer);

	int count = 0;
	for (int i = 0; i < heigth; i++)
		for (int j = 0; j < width; j++)
		{
			background.animateB(64 * j, 64 * i, count);
			count++;
		}
	
	
}