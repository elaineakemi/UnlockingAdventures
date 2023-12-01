#include "Level1.h"

void Level1::Init()
{
    // Background Music
    PlayMusicStream(backgroundMusic);

    // Initialize items that needs to be restarted if new game is started
    apple1 = Item(itemTextures.apple, {75.0f, 250.0f}, itemTextures.collect);
    apple2 = Item(itemTextures.apple, {100.0f, 280.0f}, itemTextures.collect);
    apple3 = Item(itemTextures.apple, {125.0f, 250.0f}, itemTextures.collect);
    apple4 = Item(itemTextures.apple, {150.0f, 280.0f}, itemTextures.collect);
    apple5 = Item(itemTextures.apple, {175.0f, 250.0f}, itemTextures.collect);

    checkpoint1 = Item(itemTextures.checkpoint, {700.0f, 370.0f}, itemTextures.checkpointCollected);
    checkpoint2 = Item(itemTextures.checkpoint, {200.0f, 88.0f}, itemTextures.checkpointCollected);
    checkpoint3 = Item(itemTextures.checkpoint, {730.0f, 237.0f}, itemTextures.checkpointCollected);

    pig = Enemy(enemyTextures.pig, {550.0f, 400.0f}, itemTextures.collect, true);
    spikeHead = Enemy(enemyTextures.spikeHead, {550.0f, 305.0f}, itemTextures.collect, false);
    turtle = Enemy(enemyTextures.turtle, {305.0f, 165.0f}, itemTextures.collect, false);

    door = Item(itemTextures.doorClosed, {530.0f, 245.0f}, itemTextures.doorOpened);
    checkpointsRemaining = 3;
}

void Level1::RenderBackground()
{
    DrawTexture(backgroundTextures.level1, 0, 0, WHITE);
    DrawTexture(backgroundTextures.border, 0, 0, WHITE);
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
    if (!isMute)
    {
        PlayMusicStream(backgroundMusic);
        UpdateMusicStream(backgroundMusic);
    }
    else
    {
        StopMusicStream(backgroundMusic);
    }

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
                    enemy->Die();
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
                PlaySound(gameSounds.checkpoint);
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
            PlaySound(gameSounds.trampoline);
        }
    }

    //----------------------------------------------------------------------------------
    // Door Collision
    //----------------------------------------------------------------------------------
    if (checkpointsRemaining == 0)
    {
        if (door.GetIsAlive())
        {
            PlaySound(gameSounds.door);
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
                player.position.y = platform->GetPositionRec().y - platform->textureWithFramesNumber.texture.height - 20;
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
    UnloadMusicStream(backgroundMusic);
}
