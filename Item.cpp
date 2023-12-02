#include "Item.h"

Item::Item(ItemType type)
    : Character(GetTexture(type), {0, 0}, GetKillTexture(type)) {}

Item::Item(TextureFrames txtr, Vector2 pos, TextureFrames collecttx)
    : Character(txtr, pos, collecttx) {}

Item::Item(TextureFrames txtr, Vector2 pos)
    : Character(txtr, pos) {}

TextureFrames Item::GetTexture(ItemType type)
{
    switch (type)
    {
    case APPLE:
        return itemTextures.apple;
        break;
    case CHECKPOINT:
        return itemTextures.checkpoint;
    case DOOR:
        return itemTextures.doorClosed;

    default:
        break;
    }
}

TextureFrames Item::GetKillTexture(ItemType type)
{
    switch (type)
    {
    case APPLE:
        return itemTextures.collect;
        break;
    case CHECKPOINT:
        return itemTextures.checkpointCollected;
    case DOOR:
        return itemTextures.doorOpened;
    default:
        break;
    }
}

// When collect item, play sound then disappear
void Item::Collect()
{
    if (GetIsAlive())
    {
        score += 100;
        PlaySound(gameSounds.apple);
    }
    SetIsAlive(false);
}

// Bombs are used in the boss level only
void Item::RenderBomb()
{
    if (GetIsAlive())
    {
        if (isActive)
        {
            // Drop item to ground
            float dt = GetFrameTime() * GetFPS();
            if (!isOnGround)
            {
                // Drop until reaches ground, then set isOnGround true
                if (position.y < GetScreenHeight() - 10 - textureWithFramesNumber.texture.height)
                {
                    position.y += dt * 5;
                }
                else
                {
                    isOnGround = true;
                }
            }
            else
            {
                waitFramesExplosion++;
                if (waitFramesExplosion == 120) // Explode
                {
                    // Update texture and numframes to explosion
                    SetTextureFrames(itemTextures.bombExplosion);
                    PlaySound(gameSounds.bombExplode);
                    isExploding = true;
                }

                if (waitFramesExplosion == 200) // Respawn
                {
                    // Reset status
                    isActive = false;
                    isExploding = false;
                    isOnGround = false;
                    waitFramesExplosion = 0;

                    // Reset texture and numframes to initial state
                    SetTextureFrames(itemTextures.bombOff);

                    // Random position
                    position = GetRandomPosition();
                }
            }
        }
        Render();
    }
}

void Item::Restart(Vector2 position)
{
    SetPosition(position);
    SetIsAlive(true);
}

// Used only for bombs
// This is needed to change texture of the bomb
void Item::ActivateBomb()
{
    // Update texture and numframes to active
    SetTextureFrames(itemTextures.bombOn);
    isActive = true;
    PlaySound(gameSounds.bombDrop);
}

// Generate a random position for bombs
Vector2 Item::GetRandomPosition()
{
    // Get which platform will spawn
    int platform = GetRandomValue(1, 3);

    // Generate random position - range and height manually calculated
    // Platform 1 - X between (10-240) Y=250
    // Platform 2 - X between (290-520) Y=320
    // Platform 3 - X between (300-530) Y=190
    switch (platform)
    {
    case 1:
        return {(float)GetRandomValue(10, 240), 250.0f};
    case 2:
        return {(float)GetRandomValue(290, 520), 320.0f};
    case 3:
        return {(float)GetRandomValue(300, 530), 190.0f};
    default: // Default return platform 1
        return {(float)GetRandomValue(10, 240), 250.0f};
    }
    return {530.0f, 190.0f};
}