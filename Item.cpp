#include "Item.h"

Item::Item(Texture2D txtr, int numFrames, Vector2 pos, Color c, Texture2D disappearChar)
    : Character(txtr, numFrames, pos, c, disappearChar)
{
}

Item::Item() {}

void Item::Collect()
{
    if (GetIsAlive())
    {
        score += 100;
        PlaySound(appleSound);
    }
    SetIsAlive(false);
}