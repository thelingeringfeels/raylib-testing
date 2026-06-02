#include "include/raylib.h"
#include <math.h>

typedef struct{
	double posX;
	double posY;
} Pos;

void changePos(Pos *pos);

int main(void)
{
	const int screenWidth = 900;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "New Window");

	Pos pos;
	pos.posX = 0;
	pos.posY = 0;
	
	SetTargetFPS(60);
	
	while(!WindowShouldClose())
	{
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			pos.posX = 0;
			pos.posY = 300;
		}
		
		changePos(&pos);

		BeginDrawing();
			ClearBackground(LIGHTGRAY);

			DrawRectangle(pos.posX, pos.posY, 10, 10, BLACK);
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}

void changePos(Pos *pos){
	pos->posX+=GetFrameTime()*150;
	if(pos->posX > 900){
		pos->posX=-10;
	}

	pos->posY = sin(pos->posX/50)*100 + 300;
}