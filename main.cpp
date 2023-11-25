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
int life = 3;

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

    Enemy pig(LoadTexture("resources/textures/characters/pig_walking.png"), 16, {500.0f, 400.0f}, RAYWHITE, disappearChar);
    Enemy turtle(LoadTexture("resources/textures/characters/turtle_idle.png"), 14, {320.0f, 155.0f}, RAYWHITE, disappearChar);
    Enemy spikeHead(LoadTexture("resources/textures/characters/enemy_spike_head.png"), 4, {550.0f, 300.0f}, RAYWHITE, disappearChar);

    Item lifeBar(LoadTexture("resources/textures/items/life_bar.png"), 1, {20.0f, 20.0f}, RAYWHITE, disappearChar);
    Item life(LoadTexture("resources/textures/items/life.png"), 8, {28.0f, 30.0f}, RAYWHITE, disappearChar);
    Item life2(LoadTexture("resources/textures/items/life.png"), 8, {42.0f, 30.0f}, RAYWHITE, disappearChar);
    Item life3(LoadTexture("resources/textures/items/life.png"), 8, {56.0f, 30.0f}, RAYWHITE, disappearChar);

    Item door(LoadTexture("resources/textures/items/door_closed.png"), 1, {530.0f, 245.0f}, RAYWHITE, LoadTexture("resources/textures/items/door_open.png"));

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
        turtle.Render();
        pig.Render();

        spikeHead.Render();

        door.Render();
        lifeBar.Render();
        life.Render();
        life2.Render();
        // life3.Render();

        player1.Update();
        spikeHead.Drop();
        pig.Move();

        /*


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
        */
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