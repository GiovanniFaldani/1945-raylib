#include "sprites.h"
#include <stdlib.h>

#pragma region SpriteAnimation
SpriteAnimation CreateSpriteAnimation(const Texture2D atlas, const int framesPerSecond, const Rectangle rectangles[], const int length)
{
    SpriteAnimation spriteAnimation =
	{
		.atlas = atlas,
		.fps = framesPerSecond,
		.timeStarted = GetTime(),
		.rectangles = NULL,
		.rectanglesLength = length
	};
	
	Rectangle* mem = (Rectangle*)malloc(sizeof(Rectangle) * length);
    // allocation error check
	if (mem == NULL)
	{
		TraceLog(LOG_FATAL, "No memory for CreateSpriteAnimation");
		spriteAnimation.rectanglesLength = 0;
		return spriteAnimation;
	}

	spriteAnimation.rectangles = mem;

	for (int i = 0; i < length; i++)
	{
		spriteAnimation.rectangles[i] = rectangles[i];		
	}

	return spriteAnimation;
}

void DisposeSpriteAnimation(SpriteAnimation* animation)
{
    free(animation->rectangles);
}

void DrawSpriteAnimationPro(const SpriteAnimation* const animation, const Rectangle dest, const Vector2 origin, const float rotation, const Color tint)
{
    const int index = (int)((GetTime() - animation->timeStarted) * animation->fps) % animation->rectanglesLength;

	const Rectangle source = animation->rectangles[index];
	DrawTexturePro(animation->atlas, source, dest, origin, rotation, tint);
}
#pragma endregion