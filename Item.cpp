#include "Item.h"

Item::Item(Texture2D txtr, int numFrames, Vector2 pos, Color c, Texture2D disappearChar)
    : Character(txtr, numFrames, pos, c, disappearChar)
{
}

Item::Item() {}