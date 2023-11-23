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
    Texture2D appleTexture = LoadTexture("resources/textures/items/apple.png");

    Player player(LoadTexture("resources/textures/characters/frog_idle.png"), 11, {15.0f, 400.0f}, RAYWHITE, disappearChar);

    Enemy pig(LoadTexture("resources/textures/characters/pig_walking.png"), 16, {500.0f, 400.0f}, RAYWHITE, disappearChar);
    Enemy turtle(LoadTexture("resources/textures/characters/turtle_idle.png"), 14, {320.0f, 155.0f}, RAYWHITE, disappearChar);
    Enemy spikeHead(LoadTexture("resources/textures/characters/enemy_spike_head.png"), 4, {550.0f, 300.0f}, RAYWHITE, disappearChar);

    Item apple(appleTexture, 17, {300.0f, 280.0f}, RAYWHITE, disappearChar);

    Item checkpoint(LoadTexture("resources/textures/items/checkpoint.png"), 10, {700.0f, 370.0f}, RAYWHITE, LoadTexture("resources/textures/items/checkpoint_collected.png"));
    Item checkpoint2(LoadTexture("resources/textures/items/checkpoint.png"), 10, {200.0f, 88.0f}, RAYWHITE, LoadTexture("resources/textures/items/checkpoint_collected.png"));
    Item checkpoint3(LoadTexture("resources/textures/items/checkpoint.png"), 10, {730.0f, 237.0f}, RAYWHITE, LoadTexture("resources/textures/items/checkpoint_collected.png"));

    Item apple2(appleTexture, 17, {200.0f, 280.0f}, RAYWHITE, disappearChar);

    Item lifeBar(LoadTexture("resources/textures/items/life_bar.png"), 1, {20.0f, 20.0f}, RAYWHITE, disappearChar);
    Item life(LoadTexture("resources/textures/items/life.png"), 8, {28.0f, 30.0f}, RAYWHITE, disappearChar);
    Item life2(LoadTexture("resources/textures/items/life.png"), 8, {42.0f, 30.0f}, RAYWHITE, disappearChar);
    Item life3(LoadTexture("resources/textures/items/life.png"), 8, {56.0f, 30.0f}, RAYWHITE, disappearChar);

    Item apples[5]{
        Item(appleTexture, 17, {75.0f, 250.0f}, RAYWHITE, disappearChar),
        Item{appleTexture, 17, {100.0f, 280.0f}, RAYWHITE, disappearChar},
        Item{appleTexture, 17, {125.0f, 250.0f}, RAYWHITE, disappearChar},
        Item{appleTexture, 17, {150.0f, 280.0f}, RAYWHITE, disappearChar},
        Item{appleTexture, 17, {175.0f, 250.0f}, RAYWHITE, disappearChar}

    };

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

        DrawTexture(background1, 0, 0, WHITE); // Background
        DrawTexture(border, 0, 0, WHITE);      // Border

        apple.Render();

        turtle.Render();
        pig.Render();
        platform.Render();
        spikeHead.Render();
        trampoline.Render();
        trampoline2.Render();
        checkpoint.Render();
        checkpoint2.Render();
        checkpoint3.Render();
        platform2.Render();
        platform3.Render();
        platform4.Render();
        door.Render();
        lifeBar.Render();
        life.Render();
        life2.Render();
        // life3.Render();

        for (Item item : apples)
        {
            item.Render();
        }

        apple2.Render();
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

        if (CheckCollisionRecs(player.GetPositionRec(), apple.GetPositionRec()))
        {
            apple.SetIsAlive(false);
        }

        if (CheckCollisionRecs(player.GetPositionRec(), checkpoint.GetPositionRec()))
        {
            checkpoint.SetIsAlive(false);
            checkpoint.SetIsDisappear(false);
        }

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
                // not allow go left
            }
            else
            {
                // move to next level
            }
            door.SetIsAlive(false);
            door.SetIsDisappear(false);
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
    UnloadTexture(background1);
    UnloadTexture(border);

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}