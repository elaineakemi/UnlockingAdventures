#include "raylib.h"
#include "Player.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game Name");

    Texture2D border = LoadTexture("resources/textures/background/border.png");
    Texture2D background1 = LoadTexture("resources/textures/background/background1.png");

    Player player(LoadTexture("resources/textures/characters/frog_idle.png"), 11, {350.0f, 280.0f}, RAYWHITE);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        player.Animate();

        if (IsKeyDown(KEY_RIGHT))
            player.Move({5, 0});

        if (IsKeyDown(KEY_LEFT))
            player.Move({-5, 0});

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background1, 0, 0, WHITE); // Background
        DrawTexture(border, 0, 0, WHITE);      // Border

        player.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background1);
    UnloadTexture(border);

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}