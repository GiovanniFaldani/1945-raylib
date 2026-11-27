#include "player.h"
#include <stdlib.h> // TODO use for pooling? Or just make fixed size array and delete

void InitPlayer(Player* const player, const Texture2D atlas, const unsigned int lives, const float hSpeed, const float vSpeed, const Vector2 startPos)
{
    // Load behavior vars
    player->lives = lives;
    player->hSpeed = hSpeed;
    player->vSpeed = vSpeed;
    player->startPos = startPos;
    player->currPos = startPos;

    player->deathTimer = 0.f;
    player->spawnTimer = 1.f;

    // Load animation data
    player->idle = CreateSpriteAnimation(atlas, 18, (Rectangle[]) {
		(Rectangle){4, 400, 65, 65},
		(Rectangle){70, 400, 65, 65},
		(Rectangle){136, 400, 65, 65},
	}, 3);

    player->death = CreateSpriteAnimation(atlas, 20, (Rectangle[]) {
        (Rectangle){4, 301, 65, 65},
        (Rectangle){70, 301, 65, 65},
        (Rectangle){136, 301, 65, 65},
        (Rectangle){202, 301, 65, 65},
        (Rectangle){268, 301, 65, 65},
        (Rectangle){334, 301, 65, 65},
        (Rectangle){400, 301, 65, 65},
    }, 7);

    player->spawn = CreateSpriteAnimation(atlas, 30, (Rectangle[]) {
        (Rectangle){136, 400, 65, 65},
        (Rectangle){202, 400, 65, 65},
    }, 2);
}

void FreePlayer(Player* player)
{
    // TODO Free bulet pool when implemented

    // Free animation data
    DisposeSpriteAnimation(&player->idle);
    DisposeSpriteAnimation(&player->death);
    DisposeSpriteAnimation(&player->spawn);
}

void HandleInput(Player* const player, const float deltaTime)
{
    if(player->lives <= 0) return; // No more lives, game over
    else if(player->spawnTimer > 0)
    {
        // Move player into screen from startPos and allow no control
        player->currPos.y -= player->vSpeed * deltaTime;
        // decrease timer
        player->spawnTimer -= deltaTime;
    }
    else if(player->deathTimer > 0) // animation duration for 1 full cycle= 7/20 = 0,35s
    {
        // Accept no input and decrease timer
        player->deathTimer -= deltaTime;
    }
    else
    {
        // Movement input handling
        if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
            player->currPos.x -= player->hSpeed * deltaTime;
        if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
            player->currPos.x += player->hSpeed * deltaTime;
        if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
            player->currPos.y -= player->vSpeed * deltaTime;
        if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
            player->currPos.y += player->vSpeed * deltaTime;

        // TODO Shooting input handling

    }
}

void DrawPlayer(Player* const player)
{
    Rectangle dest = { player->currPos.x, player->currPos.y, 65, 65 };
    Vector2 origin = { 0 };

    if(player->spawnTimer > 0) 
    {
        DrawSpriteAnimationPro(&player->spawn, dest, origin, 0, WHITE);
    }
    else if(player->deathTimer > 0)
    {
        DrawSpriteAnimationPro(&player->spawn, dest, origin, 0, BLUE);
    }
    else
    {
        DrawSpriteAnimationPro(&player->idle, dest, origin, 0, WHITE);
    }
}