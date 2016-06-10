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

//Load sprite image from the given path
bool Animation::loadSprite(std::string path)
{
	if (!texture.loadFromFile(path.c_str()))
	{
		cout << "Failed to load animation texture!\n" << endl;
		system("PAUSE");
		return false;
	}
	return true;
}

//Set the rectangles in the sprite that are going to be the clips of the animation. 
//Parameters: number of clips, points (vector of x's and vector of y's) lower-left 
//corner of the rectangle, dimensions (vector of width's, vector of heigth's)
void Animation::setClips(int inFrames, int *xvec, int *yvec, int *wvec, int *hvec)
{
	if (inFrames > 0)
	{
		frames = inFrames;
		clips = new SDL_Rect[frames];

		for (int i = 0; i < frames; i++)
		{
			(clips + i)->x = xvec[i];
			(clips + i)->y = yvec[i];
			(clips + i)->w = wvec[i];
			(clips + i)->h = hvec[i];
		}
	}
}

//Set the order in wich the clips are shown and the time interval between them
//Parameters: length of the animation (number of frames), number of clip (the 
//array is the order of the frames), time of each frame
void Animation::setSequence(int dim, int *inSequence, int *inTimeInterval)
{
	sequence = new int [dim];
	timeInterval = new int [dim];
	for(int i = 0; i<dim; i++)
	{
		sequence[i] = inSequence[i];
		timeInterval[i] = inTimeInterval[i];
	}
}

void Animation::setSequenceB(int dim, int *inSequence)
{
	sequence = new int[dim];
	for (int i = 0; i<dim; i++)
	{
		sequence[i] = inSequence[i];
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
	ended = false;
	currentFrame = 0;
	position = startPosition;
}

//Starts the animation
void Animation::start(Vector2D inpos)
{
	ended = false;
	currentFrame = 0;
	position = inpos;
}


//Call this function while the animation is running
void Animation::animate()
{	
	if(!timer.isRunning())
		timer.start();

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

void Animation::animateB(int inposx, int inposy, int frame)
{
	currentFrame=frame;
	position.x = inposx;
	position.y = inposy;
	renderB(position.x, position.y);

}

//Animates at a given position of the actual frame, dont change it until true
bool Animation::animate(Vector2D inpos)
{
	bool flag = false;

	if (!timer.isRunning())
		timer.start();

	if (timer.millis() > *(timeInterval + currentFrame))
	{
		currentFrame++;
		if (currentFrame == frames)
			ended = true;
		timer.reset();
		flag = true;
	}

	position = inpos;
	render(position.x, position.y);
		
	return flag;
	
}

//Renders the default frame, use when standing, not moving 
void Animation::hold()
{
	currentFrame = 0;
	render(position.x, position.y);
}

void Animation::hold(Vector2D inpos)
{
	currentFrame = 0;
	position = inpos;
	render(position.x, position.y);
}

//Renders the current frame
void Animation::render(float posx, float posy) 
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	currentClip = &clips[sequence[currentFrame]];
	texture.render(posx + ((Constants::SCREEN_WIDTH - currentClip->w) / 2), posy + ((Constants::SCREEN_HEIGHT - currentClip->h) / 2), currentClip);
}

void Animation::renderB(float posx, float posy)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	currentClip = &clips[sequence[currentFrame]];
	if (sequence[currentFrame] == 0)
		return;
	texture.render(posx, posy, currentClip);
	//texture.render((posx - (currentClip->w / 2)), (posy - (currentClip->h / 2)), currentClip);
}