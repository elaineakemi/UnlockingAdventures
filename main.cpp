#include "raylib.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Platform.h"

#include "Level1.h"

//----------------------------------------------------------------------------------
// Global Variables
//----------------------------------------------------------------------------------
int score = 0;
int playerLives = 3;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game Name");

    Texture2D disappearChar = LoadTexture("resources/textures/items/collected.png");
    Player player1(LoadTexture("resources/textures/characters/frog_idle.png"), 11, {15.0f, 400.0f}, RAYWHITE, disappearChar);

    Level1 lvl1;
    lvl1.Init();

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        lvl1.RenderBackground();
        lvl1.RenderItems();
        lvl1.Update(player1);

        player1.Render();

        player1.Update();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    lvl1.Unload();
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}