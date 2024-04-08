#include <stdio.h>
#include <time.h>
#include "raylib.h"

// The entry point.
int main(int argc, char* argv[])
{
  // Set up anti-aliasing.
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  // Initialize the window.
  InitWindow(800, 450, "Random Reference Generator");
  SetTargetFPS(60);

  // Initialize the random number generator.
  SetRandomSeed(time(NULL));

  // Initialize cube parameters.
  Vector3 CubePosition = { 0.0f, 0.0f, 0.0f };
  float CubeWidth = (float)GetRandomValue(1, 5);
  float CubeHeight = (float)GetRandomValue(1, 5);
  float CubeLength = (float)GetRandomValue(1, 5);

  // Initialize the camera.
  Camera MainCamera = { 0 };
  MainCamera.position = (Vector3) { 10.0f, (float)GetRandomValue(-10, 10), 10.0f };
  MainCamera.target = CubePosition;
  MainCamera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
  MainCamera.fovy = 45.0f;
  MainCamera.projection = CAMERA_PERSPECTIVE;

  // Enter rendering loop.
  while (!WindowShouldClose())
  {
    // Draw white background.
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    // Draw text.
    DrawText("Press space to generate a new reference.", GetScreenWidth() / 2 - MeasureText("Press space to generate a new reference.", 20) / 2, GetScreenHeight() - 30, 20, GRAY);

    // Draw cube.
    BeginMode3D(MainCamera);
    DrawCube(CubePosition, CubeWidth, CubeHeight, CubeLength, BLUE);
    DrawCubeWires(CubePosition, CubeWidth, CubeHeight, CubeLength, BLACK);
    EndMode3D();
    EndDrawing();

    // Process input.
    if (IsKeyPressed(KEY_SPACE))
    {
      CubeWidth = (float)GetRandomValue(1, 5);
      CubeHeight = (float)GetRandomValue(1, 5);
      CubeLength = (float)GetRandomValue(1, 5);
      MainCamera.position = (Vector3) { 10.0f, (float)GetRandomValue(-10, 10), 10.0f };
    }
  }

  // Close window and exit.
  CloseWindow();
  return 0;
}
