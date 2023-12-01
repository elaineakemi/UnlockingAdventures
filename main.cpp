#include "raylib.h"
#include "Player.h"
#include "Menu.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "LevelBoss.h"
#include "EndingScreen.h"

//----------------------------------------------------------------------------------
// Global Variables
//----------------------------------------------------------------------------------
int currentScreen = 0;
int score = 0;
int playerLives = 3;
int playerSelected = 0;
bool isGameOver = false;
bool isEnd = false;

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

    Font customFont{LoadFont("resources/fonts/playpenSans.ttf")};

    Player player1(LoadTexture("resources/textures/characters/frog.png"), 11, {15.0f, 400.0f});

    // Declare and initialize levels
    Menu mainMenu;
    mainMenu.Init();
    Level1 lvl1;
    lvl1.Init();
    Level2 lvl2;
    lvl2.Init();
    Level3 lvl3;
    lvl3.Init();
    LevelBoss lvlBoss;
    lvlBoss.Init();
    EndingScreen ending;
    ending.Init();

    SetTargetFPS(60); // Set game to run at 60 fps
    int framesCounter = 0;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Check which screen should render
        switch (currentScreen)
        {
        case 0:
            framesCounter = 0;
            mainMenu.Render();
            mainMenu.Update();
            break;
        case 1:
            lvl1.RenderBackground();
            lvl1.RenderItems();
            player1.Init(playerSelected);
            player1.Render();

            player1.Update();
            lvl1.Update(player1);
            break;
        case 2:
            lvl2.RenderBackground();
            lvl2.RenderItems();
            player1.Init(playerSelected);
            player1.Render();

            player1.Update();
            lvl2.Update(player1);
            break;
        case 3:
            lvl3.RenderBackground();
            lvl3.RenderItems();
            player1.Init(playerSelected);
            player1.Render();

            player1.Update();
            lvl3.Update(player1);
            break;
        case 4:
            lvlBoss.RenderBackground();
            lvlBoss.RenderItems();
            player1.Init(playerSelected);
            player1.Render();

            player1.Update();
            lvlBoss.Update(player1);
            break;

        default:
            break;
        }

        // Show game over message or ending screen
        if (isGameOver || isEnd)
        {
            if (isEnd)
            {
                DrawTextEx(customFont, "VICTORY!", (Vector2){170, 150}, 80, 20, GREEN);
                framesCounter++;

                // Wait 5 seconds then show ending screen
                if (framesCounter > 300)
                {
                    ending.Init();
                    ending.Render(player1);
                }
            }
            else
            {
                DrawTextEx(customFont, "GAME OVER", (Vector2){170, 150}, 80, 20, RED);
                framesCounter++;

                // Wait 2 seconds then write text
                if (framesCounter > 120)
                {
                    DrawTextEx(customFont, "Press ENTER to go back to menu", (Vector2){160, 300}, 40, 2, BLACK);
                }
            }
            if (IsKeyPressed(KEY_ENTER))
            {
                // Restart variables
                score = 0;
                playerLives = 3;
                playerSelected = 0;
                isGameOver = false;
                currentScreen = 0;
                isEnd = false;

                // Restart levels
                mainMenu.Init();
                lvl1.Init();
                lvl2.Init();
                lvl3.Init();
                lvlBoss.Init();
                player1.Restart();
                player1.ResetPosition();
            }
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
    lvl3.Unload();
    lvlBoss.Unload();
    player1.Unload();
    ending.Unload();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
