#include "raylib.h"
#include "Player.h"
#include "Menu.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "LevelBoss.h"
#include "EndingScreen.h"
#include "Assets.h"

//----------------------------------------------------------------------------------
// Global Variables
//----------------------------------------------------------------------------------
int currentScreen = 0;
int score = 0;
int playerLives = 3;
int playerSelected = 0;
bool isGameOver = false;
bool isEnd = false;

//----------------------------------------------------------------------------------
// Global Shared Assets
//----------------------------------------------------------------------------------
Font customFont{0};
StatusBarTextures statusbarTextures;
BackgroundTextures backgroundTextures;
PlayerTextures playerTextures;
EnemyTextures enemyTextures;
ItemTextures itemTextures;

//----------------------------------------------------------------------------------
// Local Variables
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

//----------------------------------------------------------------------------------
// Program main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    InitWindow(screenWidth, screenHeight, "Game Name");
    InitAudioDevice();

    //------------------------------------------------------------------------------
    // Load Assets
    //------------------------------------------------------------------------------
    // Font
    customFont = LoadFont("resources/fonts/playpenSans.ttf");

    // Textures
    statusbarTextures.lifebar = {LoadTexture("resources/textures/items/life_bar.png"), 1};
    statusbarTextures.heart = {LoadTexture("resources/textures/items/life.png"), 8};
    statusbarTextures.checkpointBar = {LoadTexture("resources/textures/items/checkpoint_bar.png"), 1};
    statusbarTextures.checkpointBarCollected = {LoadTexture("resources/textures/items/checkpoint_bar_collected.png"), 10};
    backgroundTextures.border = LoadTexture("resources/textures/background/border.png");
    backgroundTextures.menu = LoadTexture("resources/textures/background/menu.png");
    backgroundTextures.level1 = LoadTexture("resources/textures/background/level1.png");
    backgroundTextures.level2 = LoadTexture("resources/textures/background/level2.png");
    backgroundTextures.level3 = LoadTexture("resources/textures/background/level3.png");
    backgroundTextures.levelBoss = LoadTexture("resources/textures/background/levelBoss.png");
    playerTextures.frog = {LoadTexture("resources/textures/characters/frog.png"), 11};
    playerTextures.blueGuy = {LoadTexture("resources/textures/characters/blue_guy.png"), 11};
    playerTextures.pinkGuy = {LoadTexture("resources/textures/characters/pink_guy.png"), 11};
    enemyTextures.pig = {LoadTexture("resources/textures/characters/enemy_pig.png"), 16};
    enemyTextures.pigBoss = {LoadTexture("resources/textures/characters/pig_boss.png"), 12};
    enemyTextures.spikeHead = {LoadTexture("resources/textures/characters/enemy_spike_head.png"), 4};
    enemyTextures.turtle = {LoadTexture("resources/textures/characters/enemy_spike_turtle.png"), 14};
    itemTextures.apple = {LoadTexture("resources/textures/items/apple.png"), 17};
    itemTextures.checkpoint = {LoadTexture("resources/textures/items/checkpoint.png"), 10};
    itemTextures.checkpointCollected = {LoadTexture("resources/textures/items/checkpoint_collected.png"), 1};
    itemTextures.doorClosed = {LoadTexture("resources/textures/items/door_closed.png"), 1};
    itemTextures.doorOpened = {LoadTexture("resources/textures/items/door_open.png"), 1};
    itemTextures.collect = {LoadTexture("resources/textures/items/collected.png"), 5};
    itemTextures.bombOff = {LoadTexture("resources/textures/items/bomb_off.png"), 1};
    itemTextures.bombOn = {LoadTexture("resources/textures/items/bomb_on.png"), 4};
    itemTextures.bombExplosion = {LoadTexture("resources/textures/items/bomb_explosion.png"), 6};

    Player player1(playerTextures.frog, {15.0f, 400.0f});

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
