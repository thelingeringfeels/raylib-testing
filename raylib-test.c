#include "include/raylib.h"
#include <math.h>

int main(void)
{
	Texture2D sprite;

	const int screenWidth = 900;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "New Window");

	sprite = LoadTexture("junk/israfel.png");
	float spriteX = 0.0f;
	float spriteY = 0.0f;
	float theta = 0.0f;
	int r = 150;
	
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(RAYWHITE);

			spriteX = r * cos(theta) + 300;
			spriteY = r * sin(theta) + 300;

			theta -= GetFrameTime() * 5;
			
			DrawTexture(sprite, spriteX, spriteY, WHITE);

		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}