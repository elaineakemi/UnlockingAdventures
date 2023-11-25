#include "Level1.h"

Level1::Level1() {}

void Level1::Init()
{
}

void Level1::RenderBackground()
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(backgroundBorder, 0, 0, WHITE);
}

void Level1::RenderItems()
{
    lifeBar.Render();
    door.Render();

    for (auto life : lives)
    {
        life->Render();
    }

    for (auto apple : apples)
    {
        apple->Render();
    }

    for (auto checkpoint : checkpoints)
    {
        checkpoint->Render();
    }

    for (auto trampoline : trampolines)
    {
        trampoline->Render();
    }

    for (auto platform : platforms)
    {
        platform->Render();
    }
}

void Level1::Update(Player &player)
{
    //----------------------------------------------------------------------------------
    // Apples Collisions
    //----------------------------------------------------------------------------------
    for (auto apple : apples)
    {
        if (CheckCollisionRecs(player.GetPositionRec(), apple->GetPositionRec()))
        {
            apple->SetIsAlive(false);
        }
    }

    //----------------------------------------------------------------------------------
    // Checkpoint Collisions
    //----------------------------------------------------------------------------------
    for (auto checkpoint : checkpoints)
    {
        if (CheckCollisionRecs(player.GetPositionRec(), checkpoint->GetPositionRec()))
        {
            checkpoint->SetIsAlive(false);
            checkpoint->SetIsDisappearAfterCollect(false);
        }
    }

    //----------------------------------------------------------------------------------
    // Trampolines Collisions
    //----------------------------------------------------------------------------------

    for (auto trampoline : trampolines)
    {
        if (CheckCollisionRecs(player.GetPositionRec(), trampoline->GetPositionRec()))
        {
            player.JumpTrampoline(trampoline->GetPosition().y);
        }
    }

    //----------------------------------------------------------------------------------
    // Door Collision
    //----------------------------------------------------------------------------------
    if (CheckCollisionRecs(player.GetPositionRec(), door.GetPositionRec()))
    {
        if (door.GetIsAlive())
        {
            // Not allow go past the door
            player.UndoMove();
        }
        else
        {
            // move to next level
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

void Level1::Unload()
{
    UnloadTexture(background);
    UnloadTexture(backgroundBorder);
    UnloadTexture(disappearTexture);
    UnloadTexture(appleTexture);
    UnloadTexture(checkpointTexture);
    UnloadTexture(checkpointCollectedTexture);
    UnloadTexture(trampolineTexture);
    UnloadTexture(platformTexture);
    UnloadTexture(lifebarTexture);
    UnloadTexture(heartTexture);
    UnloadTexture(doorOpenTexture);
    UnloadTexture(doorClosedTexture);
}
