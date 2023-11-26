#include "Level3.h"

Level3::Level3() {}

void Level3::Init()
{
    PlayMusicStream(backgroundMusic);
}

void Level3::RenderBackground()
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(backgroundBorder, 0, 0, WHITE);
}

void Level3::RenderItems()
{
    //----------------------------------------------------------------------------------
    // Render Elements
    //----------------------------------------------------------------------------------
    status.Render(checkpointsRemaining);
    door.Render();

    for (auto enemy : enemies)
    {
        enemy->Render();
    }

    for (auto apple : apples)
    {
        apple->Render();
    }

    for (auto checkpoint : checkpoints)
    {
        checkpoint->Render();
    }

    for (auto platform : platforms)
    {
        platform->Render();
    }
}

void Level3::Update(Player &player)
{
    UpdateMusicStream(backgroundMusic);

    //----------------------------------------------------------------------------------
    // Enemies Move
    //----------------------------------------------------------------------------------
    pig1.Move();
    pig2.Move();
    pig3.Move();
    spikeHead.Drop();

    //----------------------------------------------------------------------------------
    // Enemies Collisions
    //----------------------------------------------------------------------------------

    for (auto enemy : enemies)
    {
        if (enemy->GetIsAlive() && CheckCollisionRecs(player.GetPositionRec(), enemy->GetPositionRec()))
        {
            // If enemy can be killed check if colision comes from top
            if (enemy->GetCanBeKilled())
            {
                if (player.GetPositionRec().y < enemy->GetPositionRec().y)
                {
                    enemy->Kill();
                }
                else
                {
                    player.Die();
                }
            }
            else
            {
                player.Die();
            }
        }
    }

    //----------------------------------------------------------------------------------
    // Apples Collisions
    //----------------------------------------------------------------------------------
    for (auto apple : apples)
    {
        if (CheckCollisionRecs(player.GetPositionRec(), apple->GetPositionRec()))
        {
            apple->Collect();
        }
    }

    //----------------------------------------------------------------------------------
    // Checkpoint Collisions
    //----------------------------------------------------------------------------------
    for (auto checkpoint : checkpoints)
    {
        if (CheckCollisionRecs(player.GetPositionRec(), checkpoint->GetPositionRec()))
        {
            if (checkpoint->GetIsAlive())
            {
                // Collect checkpoint
                checkpointsRemaining--;
                PlaySound(checkpointSound);
            }
            checkpoint->SetIsAlive(false);
            checkpoint->SetIsDisappearAfterCollect(false);
        }
    }

     //----------------------------------------------------------------------------------
    // Door Collision
    //----------------------------------------------------------------------------------
    if (checkpointsRemaining == 0)
    {
        if (door.GetIsAlive())
        {
            PlaySound(doorSound);
        }
        door.SetIsAlive(false);
        door.SetIsDisappearAfterCollect(false);
    }
    if (CheckCollisionRecs(player.GetPositionRec(), door.GetPositionRec()))
    {
        if (door.GetIsAlive())
        {
            // Not allow go past the door
            player.UndoMove();
        }
        else
        {
            player.ResetPosition();
            currentScreen++;
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

void Level3::Unload()
{
    UnloadTexture(background);
    UnloadTexture(backgroundBorder);
    UnloadTexture(disappearTexture);
    UnloadTexture(appleTexture);
    UnloadTexture(checkpointTexture);
    UnloadTexture(checkpointCollectedTexture);
    UnloadTexture(trampolineTexture);
    UnloadTexture(platformTexture);
    UnloadTexture(doorOpenTexture);
    UnloadTexture(doorClosedTexture);
    UnloadTexture(pigTexture);
    UnloadTexture(spikeHeadTexture);
    UnloadTexture(turtleTexture);

    UnloadMusicStream(backgroundMusic);
    UnloadSound(trampolineSound);
    UnloadSound(checkpointSound);
    UnloadSound(doorSound);
}
