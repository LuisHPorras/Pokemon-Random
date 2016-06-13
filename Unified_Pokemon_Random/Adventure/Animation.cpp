#include "Animation.h"

Animation::Animation(void)
{
	ended = true;
	startBit = false;
}

Animation::~Animation(void)
{
	delete sequence;
	delete timeInterval;
}

//Set the order in wich the clips are shown and the time interval between them
//Parameters: length of the animation (number of frames), number of clip (the 
//array is the order of the frames), time of each frame
void Animation::setSequence(int dim, int *inSequence, int *inTimeInterval)
{
	frames = dim;
	sequence = new int [dim];
	timeInterval = new int [dim];
	for(int i = 0; i<dim; i++)
	{
		sequence[i] = inSequence[i];
		timeInterval[i] = inTimeInterval[i];
	}
}

void Animation::setPosition(Vector2D inpos)
{
	position = inpos;
}

//Set the space distance between the last and the firs frame, all frames move
//the same distance along the line
//Paramenters: start point of the animation (x,y), end point (x,y)
void Animation::setSpaceInterval(Vector2D inStartPosition, Vector2D inEndPosition)
{
	startPosition = inStartPosition;
	endPosition = inEndPosition;
	spaceInterval = (endPosition - startPosition)/frames;
}

//Returns true if the animation has ended
bool Animation::isEnded()
{
	return ended;
}

//Starts the animation
void Animation::start()
{
	startBit = true;
	ended = false;
}

//Starts the animation
void Animation::start(Vector2D inpos)
{
	position = inpos;
	start();
}

//Call this function while the animation is running
void Animation::animate()
{	
	if (startBit)
	{
		timer.start();
		currentFrame = 0;
		position = startPosition;
		startBit = false;
	}

	if (timer.millis() > timeInterval[currentFrame])
	{
		currentFrame++;
		position += spaceInterval;
		timer.reset();
	}

	if (currentFrame == frames)
	{
		currentFrame--;
		timer.stop();
		ended = true;
	}

	render(position.x, position.y);
}

//Animates at a given position of the actual frame, dont change it until true
void Animation::animate(Vector2D inpos)
{
	if (startBit)
	{
		timer.start();
		currentFrame = 0;
		setSpaceInterval(position, inpos);
		position = startPosition;
		startBit = false;
	}

	if (timer.millis() > timeInterval[currentFrame])
	{
		currentFrame++;
		position = inpos;
		timer.reset();
	}
	
	if (currentFrame == frames)
	{
		currentFrame--;
		timer.stop();
		ended = true;
	}

	render(position.x, position.y);

}

//Renders the default frame, use when standing, not moving 
void Animation::hold()
{
	currentFrame = 0;
	render(position.x, position.y);
}

void Animation::hold(Vector2D inpos)
{
	position = inpos;
	hold();
}

//Renders the current frame
void Animation::render(float posx, float posy) 
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	currentClip = &clips[sequence[currentFrame]];
	SDL_Rect renderQuad = { posx + (Constants::TILE_DIM / 2) - (Constants::PLAYER_WIDTH / 2),posy - 10 + (Constants::TILE_DIM) - (Constants::PLAYER_HEIGHT), Constants::PLAYER_WIDTH, Constants::PLAYER_HEIGHT };
	SDL_RenderCopy(gRenderer, sdlTexture, currentClip, &renderQuad);
}
