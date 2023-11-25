#ifndef PLATFORM_H
#define PLATFORM_H

#include "raylib.h"
#include "Scenario.h"

// Platform interfere in player position and cannot be collected or disappear (for now)

class Platform : public Scenario
{

public:
    Platform(Texture2D txtr, int numFrames, Vector2 pos, Color c);
};

#endif