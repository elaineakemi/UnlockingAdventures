#include "Level1.h"

Level1::Level1() {}

void Level1::Init()
{
    // Background Music
    PlayMusicStream(backgroundMusic);

    // Initialize items that needs to be restarted if new game is started
    apple1 = Item(appleTexture, 17, {75.0f, 250.0f}, RAYWHITE, disappearTexture);
    apple2 = Item(appleTexture, 17, {100.0f, 280.0f}, RAYWHITE, disappearTexture);
    apple3 = Item(appleTexture, 17, {125.0f, 250.0f}, RAYWHITE, disappearTexture);
    apple4 = Item(appleTexture, 17, {150.0f, 280.0f}, RAYWHITE, disappearTexture);
    apple5 = Item(appleTexture, 17, {175.0f, 250.0f}, RAYWHITE, disappearTexture);

    checkpoint1 = Item(checkpointTexture, 10, {700.0f, 370.0f}, RAYWHITE, checkpointCollectedTexture);
    checkpoint2 = Item(checkpointTexture, 10, {200.0f, 88.0f}, RAYWHITE, checkpointCollectedTexture);
    checkpoint3 = Item(checkpointTexture, 10, {730.0f, 237.0f}, RAYWHITE, checkpointCollectedTexture);

    pig = Enemy(pigTexture, 16, {550.0f, 400.0f}, RAYWHITE, disappearTexture, true);
    spikeHead = Enemy(spikeHeadTexture, 4, {550.0f, 305.0f}, RAYWHITE, disappearTexture, false);
    turtle = Enemy(turtleTexture, 14, {305.0f, 165.0f}, RAYWHITE, disappearTexture, false);

    door = Item(doorClosedTexture, 1, {530.0f, 245.0f}, RAYWHITE, doorOpenTexture);
    checkpointsRemaining = 3;
}

void Level1::RenderBackground()
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(backgroundBorder, 0, 0, WHITE);
}

void Level1::RenderItems()
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
    UpdateMusicStream(backgroundMusic);

    //----------------------------------------------------------------------------------
    // Enemies Move
    //----------------------------------------------------------------------------------
    pig.Move();
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
    // Trampolines Collisions
    //----------------------------------------------------------------------------------

    for (auto trampoline : trampolines)
    {
        if (CheckCollisionRecs(player.GetPositionRec(), trampoline->GetPositionRec()))
        {
            player.JumpTrampoline(trampoline->GetPosition().y);
            PlaySound(trampolineSound);
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
