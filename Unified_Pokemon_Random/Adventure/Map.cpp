#include "Map.h"

Map::~Map()
{
}

void Map::loadFromFile()
{
	background.loadFromFile("sprites/map.png");
	background.setClips(spriteWidth, spriteHeigth, 64, 64);
}

void Map::printMap()
{
	printLayer(walkable);
	printLayer(tallgrass);
	printLayer(water);
	printLayer(notwalkable);
}


void Map::printSubMap(int x, int y, int w, int h)
{
	printLayer(walkable, x, y, w, h);
	printLayer(tallgrass, x, y, w, h);
	printLayer(water, x, y, w, h);
	printLayer(notwalkable, x, y, w, h);
}

void Map::printLayer(int *layer)
{
	int count = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			background.render(64 * j, 64 * i, layer[count]-1);
			count++;
		}
}

void Map::printLayer(int *layer, int x, int y, int w, int h)
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			unsigned tile = ((i + y)* width) + (j + x);
			if (tile >= 400) system("PAUSE");
			if(layer[tile] != 0)
				background.render(64 * j, 64 * i, layer[tile]-1);
		}
}