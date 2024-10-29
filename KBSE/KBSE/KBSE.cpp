
#include <iostream>
#include "raylib.h"
#include "Checkforinputs.h"
#include "Saving_Load.h"



using namespace std;

Checkforinputs mInputs;
Saving_Load SaveLoad;
bool StartEffect = false;
int DarkModeState = 2;

#define MaxSoundChannels 10
Sound soundArray[MaxSoundChannels] = { 0 };
int currentSound;


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1500;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "KBSE - [KeyBoard Sound Effects]");
    InitAudioDevice();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    

    Texture2D KeyBoard = LoadTexture("Textures/Keyboard.png");
    soundArray[0] = LoadSound("Sounds/ClickSound.wav");

    for (int i = 1; i < MaxSoundChannels; i++) {
        soundArray[i] = LoadSoundAlias(soundArray[0]);
    }
    currentSound = 0;


    Color DarkBlueGrey;
    DarkBlueGrey.a = 255;
    DarkBlueGrey.r = 27;
    DarkBlueGrey.g = 52;
    DarkBlueGrey.b = 68;
 
    Color Mercury;
    Mercury.a = 255;
    Mercury.r = 222;
    Mercury.g = 231;
    Mercury.b = 230;

    Color Mirage;
    Mirage.a = 255;
    Mirage.r = 15;
    Mirage.g = 26;
    Mirage.b = 34;


    DarkModeState = SaveLoad.DarkMode;

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //---------------------------------------------------------------------------------

        // DEBUG ZONE
        if (IsKeyPressed(KeyboardKey::KEY_TAB)) {
            StartEffect = true; // Starts the Effect Of Noise That the Keyboard Will Do 
        }

        if (IsKeyPressed(KeyboardKey::KEY_CAPS_LOCK)) {
            
            DarkModeState++;
            if (DarkModeState >= 3) {
                DarkModeState = 1; 
            }
        }


        // CODE RUN ZONE
        if (StartEffect == true) {
          mInputs.pressDown(); // Check To See if a keyboard key is press 
        }
       
       
        if (mInputs.inputindex == 1) {

            if (mInputs.SoundPlayRate == true) {
                PlaySound(soundArray[currentSound]);
                currentSound++;
                if (currentSound >= MaxSoundChannels) {
                    currentSound = 0;
                }
                mInputs.SoundPlayRate = false;
            }
           
        }
      

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        if (DarkModeState >= 2)
        {
            ClearBackground(Mercury);
        }
        else
        {
            ClearBackground(Mirage);
        }
       
     

        DrawRectangle(0, 0, screenWidth/6, screenHeight, DarkBlueGrey);
        DrawText("KBSE", 15, 25, 80, LIGHTGRAY);
        DrawText("KeyBoard Sound Effects", 15, 100, 15, LIGHTGRAY); // name one for the app
        DrawText("KeyBoard Settings Engine", 15, 120, 15, LIGHTGRAY); // name one for the app



        DrawLine(250, 440, 1500, 440, DARKGRAY);
        DrawLine(250, 240, 1500, 240, DARKGRAY);
        DrawTexture(KeyBoard, 480, 480, WHITE);

       
       SaveLoad.SaveDarkMode(DarkModeState);
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    for (int i = 1; i < MaxSoundChannels; i++) {
        UnloadSoundAlias(soundArray[i]);
    }
    UnloadSound(soundArray[0]);

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;



  
}




   



