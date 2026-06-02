#include "include/raylib.h"
#include <math.h>

#define SWIDTH 900
#define SHEIGHT 600

#define SFPS 60

typedef struct{
	double posX;
	double posY;
} Pos;

void changePos(Pos *pos, Texture2D sprite);

int main(void)
{
	Texture2D sprite;
	Sound sound;
	Music music;
	
	InitWindow(SWIDTH, SHEIGHT, "New Window");
	
	InitAudioDevice();
	
	sprite = LoadTexture("junk/trngls.png");
	sound = LoadSound("junk/freesound_community-gunshot-37055.mp3");
	music = LoadMusicStream("junk/edelweiss.mp3");

	Pos pos;
	pos.posX = 0;
	pos.posY = 0;
	
	SetTargetFPS(SFPS);
	
	while(!WindowShouldClose())
	{
		UpdateMusicStream(music);
		
		changePos(&pos, sprite);
		
		if(IsKeyPressed(KEY_SPACE))
		{
			StopMusicStream(music);
			PlayMusicStream(music);
		}
		
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Rectangle spriteRect = {
			pos.posX,
			pos.posY,
			sprite.width,
			sprite.height
			};
			
			if(CheckCollisionPointRec(GetMousePosition(), spriteRect))
			{
				PlaySound(sound);	
			}
		}

		BeginDrawing();
			ClearBackground(LIGHTGRAY);

			DrawTexture(sprite, pos.posX, pos.posY, LIGHTGRAY);
		EndDrawing();
	}
	
	StopMusicStream(music);
	
	CloseAudioDevice();
	
	CloseWindow();
	
	return 0;
}

void changePos(Pos *pos, Texture2D sprite){
	pos->posX+=GetFrameTime()*150;
	if(pos->posX > 900){
		pos->posX=-sprite.width;
	}

	pos->posY = sin(pos->posX/50)*100 + 300;
}