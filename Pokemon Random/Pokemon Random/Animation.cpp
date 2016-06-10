#include "Animation.h"


Animation::Animation(void)
{
	ended = true;
}

Animation::~Animation(void)
{
	delete sequence;
	delete timeInterval;
}

void Animation::loadSprite(std::string path)
{
	if (!texture.loadFromFile(path.c_str()))
	{
		printf("Failed to load animation texture!\n");
		system("PAUSE");
	}
}

void Animation::setClips(int inFrames, int xvec[], int yvec[], int wvec[], int hvec[])
{
	frames = inFrames;
	clips = new SDL_Rect[frames];

	for(int i = 0; i < frames; i++)
	{
		(clips + i)->x = xvec[i];
		(clips + i)->y = yvec[i];
		(clips + i)->w = wvec[i];
		(clips + i)->h = hvec[i];
	}
}

void Animation::setSequence(int dim, int inSequence[], int inTimeInterval[])
{
	sequence = new int[dim];
	timeInterval = new int[dim];
	for(int i = 0; i<dim; i++)
	{
		inSequence[i] = *(sequence + i);
		inTimeInterval[i] = *(timeInterval + i);
	}
}

void Animation::setSpaceInterval(Vector2D inStartPosition, Vector2D inEndPosition)
{
	inStartPosition = startPosition;
	inEndPosition = endPosition;
	spaceInterval = (startPosition - endPosition)/frames;
}

bool Animation::isEnded()
{
	return ended;
}

void Animation::start()
{
	ended = false;

	currentFrame = 0;
	render();

	timer.start();
}

void Animation::animate()
{	
	if (timer.millis > *(timeInterval + currentFrame))
	{
		currentFrame++;
		timer.reset();
	}
	render();
}

void Animation::hold()
{
	currentFrame = 0;
	render();
}

void Animation::render() 
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	currentClip = &clips[currentFrame];
	texture.render(((SCREEN_WIDTH - currentClip->w) / 2) + (startPosition.x / FRAMES_RATE), ((SCREEN_HEIGHT - currentClip->h) / 2) + (startPosition.y / FRAMES_RATE), currentClip);
}