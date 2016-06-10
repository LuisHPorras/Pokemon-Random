#include "Map.h"

Map::~Map()
{
}
void Map::printMap()
{

	background.loadSprite("map.png");

	int count = 0;
	for (int i = 0; i < spriteHeigth; i++)
	{
		for (int j = 0; j < spriteWidth; j++)
		{
			x[count] = 64 * j;
			y[count] = 1088-(64 *(i+1));
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
	for (int i = 0; i < width; i++)
		for (int j = 0; j < heigth; j++)
		{
			background.animateB(64 * i, 64 * j, count);
			count++;
		}
	
	
}