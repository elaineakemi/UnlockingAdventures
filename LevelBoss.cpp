#include "LevelBoss.h"

LevelBoss::LevelBoss() {}

void LevelBoss::Init()
{
    PlayMusicStream(backgroundMusic);
}

void LevelBoss::RenderBackground()
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(backgroundBorder, 0, 0, WHITE);
}

void LevelBoss::RenderItems()
{
    DrawText(TextFormat("Boss: %d %", bossHealth * 10), 650, 20, 20, BLACK);
    //----------------------------------------------------------------------------------
    // Render Elements
    //----------------------------------------------------------------------------------
    // Render status bar without flags and with instructions for boss level
    status.Render(-1);

    pigBoss.Render();

    for (auto enemy : enemies)
    {
        enemy->Render();
    }

    for (auto platform : platforms)
    {
        platform->Render();
    }
}

void LevelBoss::Update(Player &player)
{
    UpdateMusicStream(backgroundMusic);

    //----------------------------------------------------------------------------------
    // Enemies Move
    //----------------------------------------------------------------------------------
    pigBoss.MoveBossLevel(true);
    pig1.MoveBossLevel(false);
    pig2.MoveBossLevel(false);
    pig3.MoveBossLevel(false);

    //----------------------------------------------------------------------------------
    // Enemies Collisions
    //----------------------------------------------------------------------------------

    /*if (CheckCollisionRecs(player.GetPositionRec(), pigBoss.GetPositionRec()))
 { // Check if colision comes from top
     if (player.GetPositionRec().y < 375)
     {
         bossHealth--;
         pigBoss.Hit(bossHealth);
     }
     else
     {
         player.Die();
     }
 }
*/
    if (intervalHit == 0)
    {
        if (CheckCollisionRecs(player.GetPositionRec(), pigBoss.GetPositionRec()))
        { // Check if colision comes from top
            if (player.GetPositionRec().y < 375)
            {
                bossHealth--;
            }
            else
            {
                player.Die();
            }
        }
        intervalHit = 50;
    }
    else
    {
        intervalHit--;
    }
    for (auto enemy : enemies)
    {
        if (enemy->GetIsAlive() && CheckCollisionRecs(player.GetPositionRec(), enemy->GetPositionRec()))
        {
            // Check if colision comes from top
            if (player.GetPositionRec().y < enemy->GetPositionRec().y)
            {
                enemy->Kill();
            }
            else
            {
                player.Die();
            }
        }
    }

    //----------------------------------------------------------------------------------
    // Platform Collisions
    //----------------------------------------------------------------------------------
    bool isOnPlatform = false;
    for (auto platform : platforms)
    {
        if (CheckCollisionRecs(player.GetPositionRec(), platform->GetPositionRec()))
        {
            if (player.GetPositionRec().y < platform->GetPositionRec().y)
            {
                player.SetIsPlayerOnPlatform(true);
                isOnPlatform = true;
                player.position.y = platform->GetPositionRec().y - platform->texture.height - 20;
            }
            // Player can only collide with one platform at the time
            // No need to check other platforms if already collided
            break;
        }
    }

    // If no collisions happened this turn, reset isPlayerOnPlatform
    // so player can fall if walk to outside platform
    if (!isOnPlatform)
    {
        if (player.GetIsPlayerOnPlatform())
        {
            player.SetIsPlayerOnPlatform(false);
        }
    }
}

void LevelBoss::Unload()
{
    UnloadTexture(background);
    UnloadTexture(backgroundBorder);
    UnloadTexture(disappearTexture);
    UnloadTexture(platformTexture);
    UnloadTexture(pigTexture);

    UnloadMusicStream(backgroundMusic);
}
