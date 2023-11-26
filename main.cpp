#include "raylib.h"
#include "Player.h"
#include "Menu.h"
#include "Level1.h"
#include "Level2.h"

//----------------------------------------------------------------------------------
// Global Variables
//----------------------------------------------------------------------------------
int currentScreen = 0;
int score = 0;
int playerLives = 3;
int playerSelected = 0;
bool isGameOver = false;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game Name");
    InitAudioDevice();

    Player player1(LoadTexture("resources/textures/characters/frog.png"), 11, {15.0f, 400.0f}, RAYWHITE);

    Menu mainMenu;
    Level1 lvl1;
    Level2 lvl2;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen)
        {
        case 0:
            mainMenu.Init();
            mainMenu.Render();
            mainMenu.Update();
            break;
        case 1:
            lvl1.Init();
            lvl1.RenderBackground();
            lvl1.RenderItems();
            player1.Init(playerSelected);
            player1.Render();

            player1.Update();
            lvl1.Update(player1);
            break;
        case 2:
            lvl2.Init();
            lvl2.RenderBackground();
            lvl2.RenderItems();
            player1.Render();

            lvl2.Update(player1);
            player1.Update();
            break;

        default:
            break;
        }

        if (isGameOver)
        {
            DrawText("GAME OVER", 180, 180, 80, RED);
        }

        //----------------------------------------------------------------------------------
        // End
        //----------------------------------------------------------------------------------
        EndDrawing();
    }

    //----------------------------------------------------------------------------------
    // Unload and Close
    //----------------------------------------------------------------------------------
    mainMenu.Unload();
    lvl1.Unload();
    lvl2.Unload();
    player1.Unload();
    CloseAudioDevice();
    CloseWindow();

    return 0;
}