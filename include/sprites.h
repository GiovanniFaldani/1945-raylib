#ifndef SPRITES_H
#define SPRITES_H

#include "raylib.h"

#pragma region SpriteAnimation
// based on: https://github.com/AndrewHamel111/raylib-sprite-animation/tree/main
typedef struct SpriteAnimation {
    Texture2D atlas;
    int fps;
    float timeStarted;

    Rectangle* rectangles;
    int rectanglesLength;

} SpriteAnimation;

// Load an array of rectangles over the Atlas to make an animation, uses dynamic allocation so don't forget to call DisposeSpriteAnimation
SpriteAnimation CreateSpriteAnimation(const Texture2D atlas, const int framesPerSecond, const Rectangle rectangles[], const int length);

// Free the dynamically allocated memory from CreateSpriteAnimation
void DisposeSpriteAnimation(SpriteAnimation* animation);

// Draws a frame of an animation at the given destination and origin
void DrawSpriteAnimationPro(const SpriteAnimation* const animation, const Rectangle dest, const Vector2 origin, const float rotation, const Color tint);

#pragma endregion

#endif // SPRITES_H