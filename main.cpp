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
bool isMute = false;

//----------------------------------------------------------------------------------
// Global Shared Assets
//----------------------------------------------------------------------------------
Font customFont{0};
StatusBarTextures statusbarTextures;
BackgroundTextures backgroundTextures;
PlayerTextures playerTextures;
EnemyTextures enemyTextures;
ItemTextures itemTextures;
GameSounds gameSounds;
Texture2D logo;

//----------------------------------------------------------------------------------
// Local Variables
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

static void LoadAssets(void);
static void UnloadAssets(void);
//----------------------------------------------------------------------------------
// Program main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    InitWindow(screenWidth, screenHeight, "Unlocking Adventures");
    InitAudioDevice();

    //------------------------------------------------------------------------------
    // Load Assets
    // We load all assets at the start as they are reused across all levels
    //------------------------------------------------------------------------------
    LoadAssets();

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
    Player player1(playerTextures.frog, {15.0f, 400.0f});

    SetTargetFPS(60); // Set game to run at 60 fps
    int framesCounter = 0;
    bool isPaused; // Allow game to pause

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
            if (!isPaused)
                mainMenu.Update();
            break;
        case 1:
            lvl1.RenderBackground();
            lvl1.RenderItems();
            player1.Init(playerSelected);
            player1.Render();
            if (!isPaused)
            {
                player1.Update();
                lvl1.Update(player1);
            }
            break;
        case 2:
            lvl2.RenderBackground();
            lvl2.RenderItems();
            player1.Init(playerSelected);
            player1.Render();
            if (!isPaused)
            {
                player1.Update();
                lvl2.Update(player1);
            }
            break;
        case 3:
            lvl3.RenderBackground();
            lvl3.RenderItems();
            player1.Init(playerSelected);
            player1.Render();
            if (!isPaused)
            {
                player1.Update();
                lvl3.Update(player1);
            }
            break;
        case 4:
            lvlBoss.RenderBackground();
            lvlBoss.RenderItems();
            player1.Init(playerSelected);
            player1.Render();
            if (!isPaused)
            {
                player1.Update();
                lvlBoss.Update(player1);
            }
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

        // Mute/unmute music
        if (IsKeyPressed(KEY_M))
        {
            isMute = !isMute;
        }

        // Pause/unpause game
        if (IsKeyPressed(KEY_P))
        {
            PlaySound(gameSounds.checkpoint);
            isPaused = !isPaused;
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
    ending.Unload();
    UnloadAssets();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

static void LoadAssets(void)
{
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
    backgroundTextures.levelBoss = LoadTexture("resources/textures/background/level_boss.png");
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
    itemTextures.trampoline = {LoadTexture("resources/textures/items/trampoline.png"), 8};
    itemTextures.platform = {LoadTexture("resources/textures/items/platform.png"), 1};
    logo = LoadTexture("resources/textures/items/logo.png");

    // Sounds
    gameSounds.trampoline = LoadSound("resources/sounds/trampoline.wav");
    gameSounds.checkpoint = LoadSound("resources/sounds/checkpoint.wav");
    gameSounds.door = LoadSound("resources/sounds/door_open.wav");
    gameSounds.apple = LoadSound("resources/sounds/apple.wav");
    gameSounds.bombDrop = LoadSound("resources/sounds/bomb_drop.wav");
    gameSounds.bombExplode = LoadSound("resources/sounds/bomb_explode.wav");
    gameSounds.killEnemy = LoadSound("resources/sounds/kill_enemy.wav");
    gameSounds.gameOver = LoadSound("resources/sounds/gameover.wav");
    gameSounds.playerDied = LoadSound("resources/sounds/player_died.wav");
}

static void UnloadAssets(void)
{
    // Font
    UnloadFont(customFont);

    // Textures
    UnloadTexture(backgroundTextures.border);
    UnloadTexture(backgroundTextures.menu);
    UnloadTexture(backgroundTextures.level1);
    UnloadTexture(backgroundTextures.level2);
    UnloadTexture(backgroundTextures.level3);
    UnloadTexture(backgroundTextures.levelBoss);
    UnloadTexture(statusbarTextures.lifebar.texture);
    UnloadTexture(statusbarTextures.heart.texture);
    UnloadTexture(statusbarTextures.checkpointBar.texture);
    UnloadTexture(statusbarTextures.checkpointBarCollected.texture);
    UnloadTexture(playerTextures.frog.texture);
    UnloadTexture(playerTextures.blueGuy.texture);
    UnloadTexture(playerTextures.pinkGuy.texture);
    UnloadTexture(enemyTextures.pig.texture);
    UnloadTexture(enemyTextures.turtle.texture);
    UnloadTexture(enemyTextures.spikeHead.texture);
    UnloadTexture(enemyTextures.pigBoss.texture);
    UnloadTexture(itemTextures.apple.texture);
    UnloadTexture(itemTextures.collect.texture);
    UnloadTexture(itemTextures.bombOff.texture);
    UnloadTexture(itemTextures.bombOn.texture);
    UnloadTexture(itemTextures.bombExplosion.texture);
    UnloadTexture(itemTextures.doorClosed.texture);
    UnloadTexture(itemTextures.doorOpened.texture);
    UnloadTexture(itemTextures.checkpoint.texture);
    UnloadTexture(itemTextures.checkpointCollected.texture);
    UnloadTexture(itemTextures.platform.texture);
    UnloadTexture(itemTextures.trampoline.texture);
    UnloadTexture(logo);

    // Sounds
    UnloadSound(gameSounds.trampoline);
    UnloadSound(gameSounds.checkpoint);
    UnloadSound(gameSounds.door);
    UnloadSound(gameSounds.apple);
    UnloadSound(gameSounds.bombDrop);
    UnloadSound(gameSounds.bombExplode);
    UnloadSound(gameSounds.killEnemy);
    UnloadSound(gameSounds.gameOver);
    UnloadSound(gameSounds.playerDied);
}