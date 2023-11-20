#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
private:
    Texture2D playerTexture;
    int numberFrames; // Number of frames in the texture
    Vector2 position;
    Color color;

    // Used to change player frames within texture
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;
    int framesSpeed;

public:
    Player(Texture2D playertx, int numFrames, Vector2 pos, Color c);

    void Draw();

    void Move(Vector2 offset);

    Vector2 GetPosition() const;

    void Animate();
};

#endif