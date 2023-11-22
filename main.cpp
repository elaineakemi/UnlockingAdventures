#include "raylib.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Platform.h"

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

    Texture2D disappearChar = LoadTexture("resources/textures/items/collected.png");

    Player player(LoadTexture("resources/textures/characters/frog_idle.png"), 11, {15.0f, 400.0f}, RAYWHITE, disappearChar);

    Enemy pig(LoadTexture("resources/textures/characters/pig_walking.png"), 16, {500.0f, 400.0f}, RAYWHITE, disappearChar);
    Enemy turtle(LoadTexture("resources/textures/characters/turtle_idle.png"), 14, {550.0f, 280.0f}, RAYWHITE, disappearChar);
    Enemy spikeHead(LoadTexture("resources/textures/characters/enemy_spike_head.png"), 4, {550.0f, 300.0f}, RAYWHITE, disappearChar);

    Item apple(LoadTexture("resources/textures/items/apple.png"), 17, {300.0f, 280.0f}, RAYWHITE, disappearChar);

    Platform platform(LoadTexture("resources/textures/items/platform.png"), 1, {550.0f, 280.0f}, RAYWHITE);
    Platform trampoline(LoadTexture("resources/textures/items/trampoline.png"), 8, {350.0f, 400.0f}, RAYWHITE);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background1, 0, 0, WHITE); // Background
        DrawTexture(border, 0, 0, WHITE);      // Border

        apple.Render();
        player.Render();
        turtle.Render();
        pig.Render();
        platform.Render();
        spikeHead.Render();
        trampoline.Render();

        player.Update();
        spikeHead.Drop();
        pig.Move();

        if (CheckCollisionRecs(player.GetPositionRec(), apple.GetPositionRec()))
        {
            apple.setIsAlive(false);
        }

        if (CheckCollisionRecs(player.GetPositionRec(), trampoline.GetPositionRec()))
        {
            player.JumpTrampoline(trampoline.GetPosition().y);
        }

        if (pig.getIsAlive() && CheckCollisionRecs(player.GetPositionRec(), pig.GetPositionRec()))
        {
            if (player.GetPosition().y < pig.GetPosition().y)
            {
                pig.setIsAlive(false);
            }
            else
            {
                player.setIsAlive(false);
            }
        }

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