#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "sprites.h"

typedef struct Player{
    //
    unsigned int lives;
    float hSpeed;
    float vSpeed;
    Vector2 startPos;
    Vector2 currPos;

    // States and animations
    float deathTimer;
    float spawnTimer;

    SpriteAnimation idle;
    SpriteAnimation death;
    SpriteAnimation spawn;

    // TODO bullet pooling

    // TODO Check how to implement collisions and delegate calls for taking damage

} Player;

void InitPlayer(Player* const player, const Texture2D atlas, const unsigned int lives, const float hSpeed, const float vSpeed, const Vector2 startPos);

void FreePlayer(Player* player);

void HandleInput(Player* const player, const float deltaTime);

void DrawPlayer(Player* const player);

#endif // PLAYER_H