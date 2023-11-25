#include "raylib.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Platform.h"

#include "Level1.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game Name");

    Level1 lvl1;
    lvl1.Init();

    Texture2D disappearChar = LoadTexture("resources/textures/items/collected.png");

    Player player(LoadTexture("resources/textures/characters/frog_idle.png"), 11, {15.0f, 400.0f}, RAYWHITE, disappearChar);

    Enemy pig(LoadTexture("resources/textures/characters/pig_walking.png"), 16, {500.0f, 400.0f}, RAYWHITE, disappearChar);
    Enemy turtle(LoadTexture("resources/textures/characters/turtle_idle.png"), 14, {320.0f, 155.0f}, RAYWHITE, disappearChar);
    Enemy spikeHead(LoadTexture("resources/textures/characters/enemy_spike_head.png"), 4, {550.0f, 300.0f}, RAYWHITE, disappearChar);

    Item lifeBar(LoadTexture("resources/textures/items/life_bar.png"), 1, {20.0f, 20.0f}, RAYWHITE, disappearChar);
    Item life(LoadTexture("resources/textures/items/life.png"), 8, {28.0f, 30.0f}, RAYWHITE, disappearChar);
    Item life2(LoadTexture("resources/textures/items/life.png"), 8, {42.0f, 30.0f}, RAYWHITE, disappearChar);
    Item life3(LoadTexture("resources/textures/items/life.png"), 8, {56.0f, 30.0f}, RAYWHITE, disappearChar);

    Item door(LoadTexture("resources/textures/items/door_closed.png"), 1, {530.0f, 245.0f}, RAYWHITE, LoadTexture("resources/textures/items/door_open.png"));

    Platform platform(LoadTexture("resources/textures/items/platform.png"), 1, {15.0f, 300.0f}, RAYWHITE);
    Platform platform2(LoadTexture("resources/textures/items/platform.png"), 1, {70.0f, 150.0f}, RAYWHITE);
    Platform platform3(LoadTexture("resources/textures/items/platform.png"), 1, {330.0f, 180.0f}, RAYWHITE);
    Platform platform4(LoadTexture("resources/textures/items/platform.png"), 1, {530.0f, 300.0f}, RAYWHITE);

    Platform trampoline(LoadTexture("resources/textures/items/trampoline.png"), 8, {290.0f, 400.0f}, RAYWHITE);
    Platform trampoline2(LoadTexture("resources/textures/items/trampoline.png"), 8, {25.0f, 275.0f}, RAYWHITE);

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

        turtle.Render();
        pig.Render();
        platform.Render();
        spikeHead.Render();
        trampoline.Render();
        trampoline2.Render();

        platform2.Render();
        platform3.Render();
        platform4.Render();
        door.Render();
        lifeBar.Render();
        life.Render();
        life2.Render();
        // life3.Render();

        player.Render();
        player.Update();
        spikeHead.Drop();
        pig.Move();

        // Plat 1
        if (CheckCollisionRecs(player.GetPositionRec(), platform.GetPositionRec()))
        {
            if (!player.GetIsPlayerOnPlatform())
            {
                if (player.GetPositionRec().y < platform.GetPositionRec().y)
                {
                    player.SetIsPlayerOnPlatform(true);
                    player.position.y = platform.GetPositionRec().y - platform.texture.height - 20;
                }
            }
        }
        // Plat2
        else if (CheckCollisionRecs(player.GetPositionRec(), platform2.GetPositionRec()))
        {
            if (!player.GetIsPlayerOnPlatform())
            {
                if (player.GetPositionRec().y < platform2.GetPositionRec().y)
                {
                    player.SetIsPlayerOnPlatform(true);
                    player.position.y = platform2.GetPositionRec().y - platform2.texture.height - 20;
                }
            }
        }
        // Plat3
        else if (CheckCollisionRecs(player.GetPositionRec(), platform3.GetPositionRec()))
        {
            if (!player.GetIsPlayerOnPlatform())
            {
                if (player.GetPositionRec().y < platform3.GetPositionRec().y)
                {
                    player.SetIsPlayerOnPlatform(true);
                    player.position.y = platform3.GetPositionRec().y - platform3.texture.height - 20;
                }
            }
        }
        // Plat4
        else if (CheckCollisionRecs(player.GetPositionRec(), platform4.GetPositionRec()))
        {
            if (!player.GetIsPlayerOnPlatform())
            {
                if (player.GetPositionRec().y < platform4.GetPositionRec().y)
                {
                    player.SetIsPlayerOnPlatform(true);
                    player.position.y = platform4.GetPositionRec().y - platform4.texture.height - 20;
                }
            }
        }
        else
        {
            if (player.GetIsPlayerOnPlatform())
            {
                player.SetIsPlayerOnPlatform(false);
            }
        }

        /*if (CheckCollisionRecs(player.GetPositionRec(), checkpoint.GetPositionRec()))
        {
            checkpoint.SetIsAlive(false);
            checkpoint.SetIsDisappear(false);
        }*/

        if (CheckCollisionRecs(player.GetPositionRec(), trampoline.GetPositionRec()))
        {
            player.JumpTrampoline(trampoline.GetPosition().y);
        }

        if (CheckCollisionRecs(player.GetPositionRec(), trampoline2.GetPositionRec()))
        {
            player.JumpTrampoline(trampoline2.GetPosition().y);
        }

        if (CheckCollisionRecs(player.GetPositionRec(), door.GetPositionRec()))
        {
            if (door.GetIsAlive())
            {
                player.UndoMove();
                // not allow go left
            }
            else
            {
                // move to next level
            }
            // door.SetIsAlive(false);
            // door.SetIsDisappear(false);
        }

        if (pig.GetIsAlive() && CheckCollisionRecs(player.GetPositionRec(), pig.GetPositionRec()))
        {
            if (player.GetPositionRec().y < pig.GetPositionRec().y)
            {
                pig.SetIsAlive(false);
            }
            else
            {
                // player.SetIsAlive(false);
                player.Die();
            }
        }

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