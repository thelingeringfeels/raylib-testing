#include "include/raylib.h"
#include <math.h>

int main(void)
{
	const int screenWidth = 900;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "New Window");

	double posX = 0;
	int posY = 0;
	
	SetTargetFPS(60);
	
	while(!WindowShouldClose())
	{
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			posX = 0;
			posY = 300;
		}
		
		posX+=GetFrameTime()*150;
		if(posX > 900){
			posX=-10;
		}

		posY = sin(posX/50)*100 + 300;

		BeginDrawing();
			ClearBackground(LIGHTGRAY);

			DrawRectangle(posX, posY, 10, 10, BLACK);
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}