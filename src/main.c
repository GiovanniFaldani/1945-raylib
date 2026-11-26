/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2026 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

// Build command: clang -I .\include\ -o .\bin\1945.exe -L .\lib -l raylibdll .\src\main.c

#include "raylib.h"
#include "sprites.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    const char* appDir = GetApplicationDirectory();
    TraceLog(LOG_INFO, "App Directory: %s", appDir);

    ChangeDirectory(appDir);

    Texture2D atlas = LoadTexture("./assets/1945_atlas.png");
    if(atlas.id == 0)
    {
        TraceLog(LOG_ERROR, "Error loading sprite atlas!");
        exit(-1);
    }

    SpriteAnimation playerIdleAnim = CreateSpriteAnimation(atlas, 18, (Rectangle[]) {
		(Rectangle){4, 400, 65, 65},
		(Rectangle){70, 400, 65, 65},
		(Rectangle){136, 400, 65, 65},
	}, 3);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    char title[100];
    float time = 0.f;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        float deltaTime = GetFrameTime();
        int fps = GetFPS();

        sprintf(title, "Delta: %f, FPS: %d", deltaTime, fps);
        SetWindowTitle(title);

        time += deltaTime;

        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------



        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLUE);

            // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            // DrawRectangle(200, 200, 150, 100, RED);
            // DrawRectangleLines(200, 350, 150, 100, PINK);
            // DrawRectangleLinesEx((Rectangle){200, 450, 150, 100}, 4, DARKGRAY);

            // DrawTextureEx(atlas, (Vector2){400, 300}, 0.f, 0.5f, WHITE);

            // DrawText();
            // DrawTextEx();

            // GetMousePosition();
            // IsMouseButtonDown();
            // IsKeyDown();

            Rectangle dest = { 200, 200, 65, 65 };
		    Vector2 origin = { 0 };
		    DrawSpriteAnimationPro(&playerIdleAnim, dest, origin, 0, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // Deallocate all animations
    DisposeSpriteAnimation(&playerIdleAnim);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}