// TESTING HOW TO WORK WITH A 3D CAMERA

#include "raylib.h"

int main(void)
{
    const int wWidth = 800;
    const int wHeight = 450;
    
    SetTargetFPS(60);
    
    InitWindow(wWidth, wHeight, "Game Window");
    
    //Vector3 bettercube = {40.f, 40.f, 40.f};
    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
    
    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 20.0f, 20.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f}; //what is upwards for the camera, in this case it is positive y
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    Vector3 cylinderPositions[3] = 
    {
        (Vector3){-3.0f, 0.0f, 3.0f},
        (Vector3){3.0f, 0.0f, 0.0f},
        (Vector3){-3.0, 0.0f, -3.0}
    };
    
    while(!WindowShouldClose())
    {       
        if(cubePosition.x > -10 + 1)
            if(IsKeyDown(KEY_A)) cubePosition.x -= 0.2f;
        if(cubePosition.x < 10 - 1)
            if(IsKeyDown(KEY_D)) cubePosition.x += 0.2f;
        if(cubePosition.z < 10 - 1)
            if(IsKeyDown(KEY_S)) cubePosition.z += 0.2f;
        if(cubePosition.z > -10 + 1)
            if(IsKeyDown(KEY_W)) cubePosition.z -= 0.2f;
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Welcome to 3D!", 20, 20, 20, DARKGRAY);
            
            BeginMode3D(camera);
                DrawCube(cubePosition, 2, 2, 2, RED);
                DrawCylinder(cylinderPositions[0], 0.2f, 0.2f, 2.0f, 10, PURPLE);
                DrawCylinder(cylinderPositions[1], 0.2f, 0.2f, 2.0f, 10, PURPLE);
                DrawCylinder(cylinderPositions[2], 0.2f, 0.2f, 2.0f, 10, PURPLE);
                DrawGrid(20, 1.0f);
            
            EndMode3D();
            
        EndDrawing();
        
    }
    
    CloseWindow();
    
    return 0;
    
    
}