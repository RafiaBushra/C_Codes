#include "iGraphics.h"

int lineAxis[10][4] = { {290,553,758,553},{290,495,698,495},{698,495,698,136},{758,553,758,197},{698,136,1100,136},{758,197,1160,197},{1100,136,1100,34},{1160,197,1160,95},{1160,95,1250,95},{1100,34,1310,34} };
int roadAxis[5][2] = { {450,549},{602,549},{701,344},{751,192},{1055,192} };
int roadPosition[5][2] = { {50,150},{50,-150},{-150,-50},{50,150},{50,150} };
int roadDirection[5] = { 1,3,4,1,1 };
int times = 0, timerY = 0, count = 0, s=0, enter=0, car=0;
int carAxis[4] = { 1265,50,40,34 };

void iDraw()
{

	iClear();
	if (enter == 0) {
		iPauseTimer(0);
		iShowBMP(0, 0, "Pictures\\start.bmp");
	}
	else {
		iResumeTimer(0);
		iClear();
		iShowBMP(0, 0, "Pictures\\FINAL.bmp");

		iSetColor(100, 100, 100);
		iFilledRectangle(roadAxis[0][0], roadAxis[0][1], roadPosition[0][0], roadPosition[0][1]);
		iFilledRectangle(roadAxis[1][0], roadAxis[1][1], roadPosition[1][0], roadPosition[1][1]);
		iFilledRectangle(roadAxis[2][0], roadAxis[2][1], roadPosition[2][0], roadPosition[2][1]);
		iFilledRectangle(roadAxis[3][0], roadAxis[3][1], roadPosition[3][0], roadPosition[3][1]);
		iFilledRectangle(roadAxis[4][0], roadAxis[4][1], roadPosition[4][0], roadPosition[4][1]);
		
		iSetColor(255, 0, 0);
		iFilledCircle(150, 150, 100);
		iSetColor(255, 255, 255);
		iFilledCircle(150, 150, timerY);
		for (int i = 0; i < 5; i++) {
			if (roadDirection[i] == 5) {
				count++;
			}
			else count = 0;
		}
		if (count == 0) {
			if (timerY >= 80) {
				iPauseTimer(0);
				iPauseTimer(1);
				times = 1;
				iShowBMP(0, 0, "Pictures\\game_over.bmp");
				for (int i = 0; i < 5; i++) {
					roadDirection[i] = 0;
				}
			}
		}
		else if (count != 0 && count != 1) {
			if (timerY <= 80) {
				iPauseTimer(0);
				times = 1;
				iShowBMP(0, 0, "Pictures\\FINAL1.bmp"); 
				iSetColor(160, 82, 45);
				iLine(lineAxis[0][0], lineAxis[0][1], lineAxis[0][2], lineAxis[0][3]);
				iLine(lineAxis[1][0], lineAxis[1][1], lineAxis[1][2], lineAxis[1][3]);
				iLine(lineAxis[2][0], lineAxis[2][1], lineAxis[2][2], lineAxis[2][3]);
				iLine(lineAxis[3][0], lineAxis[3][1], lineAxis[3][2], lineAxis[3][3]);
				iLine(lineAxis[4][0], lineAxis[4][1], lineAxis[4][2], lineAxis[4][3]);
				iLine(lineAxis[5][0], lineAxis[5][1], lineAxis[5][2], lineAxis[5][3]);
				iLine(lineAxis[6][0], lineAxis[6][1], lineAxis[6][2], lineAxis[6][3]);
				iLine(lineAxis[7][0], lineAxis[7][1], lineAxis[7][2], lineAxis[7][3]);
				iLine(lineAxis[8][0], lineAxis[8][1], lineAxis[8][2], lineAxis[8][3]);
				iLine(lineAxis[9][0], lineAxis[9][1], lineAxis[9][2], lineAxis[9][3]);
				iSetColor( 205,38,38);
				iFilledRectangle(carAxis[0], carAxis[1], carAxis[2], carAxis[3]);

				if (s % 2 == 0) {
					iSetColor(139,0,0);
					iFilledRectangle(carAxis[0] + 8, carAxis[1] + 12, 25, 25);
					iSetColor(0, 0, 0);
					iFilledCircle(carAxis[0] + 8, carAxis[1], 5);
					iFilledCircle(carAxis[0] + 32, carAxis[1], 5);

				}
				else {
					iSetColor(140,0,0);
					iFilledRectangle(carAxis[0] + 5, carAxis[1] + 8, 25, 25);
				}
				count = 1;
			}
		}
		if (enter == 2) {
			iShowBMP(0, 0, "Pictures\\finish.bmp");
		}

	}
	if(car==1){
		iShowBMP(3,2,"Pictures\\car.bmp");
	}
}

void roadMovements(int i) {
	if (i == 0 || i == 3 || i == 4) {
		if (roadDirection[i] == 1) {
			roadPosition[i][0] += 100;
			roadPosition[i][1] -= 200;
			roadDirection[i] = 2;
		}
		else if (roadDirection[i] == 2) {
			roadPosition[i][0] -= 200;
			roadPosition[i][1] -= 100;
			roadDirection[i] = 3;
		}
		else if (roadDirection[i] == 3) {
			roadPosition[i][0] -= 100;
			roadPosition[i][1] += 200;
			roadDirection[i] = 4;
		}
		else if (roadDirection[i] == 4) {
			roadPosition[i][0] += 200;
			roadPosition[i][1] += 100;
			roadDirection[i] = 1;
		}
	}
	else {
		if (roadDirection[i] == 1) {
			roadPosition[i][0] += 200;
			roadPosition[i][1] -= 100;
			roadDirection[i] = 2;
		}
		else if (roadDirection[i] == 2) {
			roadPosition[i][0] -= 100;
			roadPosition[i][1] -= 200;
			roadDirection[i] = 3;
		}
		else if (roadDirection[i] == 3) {
			roadPosition[i][0] -= 200;
			roadPosition[i][1] += 100;
			roadDirection[i] = 4;
		}
		else if (roadDirection[i] == 4) {
			roadPosition[i][0] += 100;
			roadPosition[i][1] += 200;
			roadDirection[i] = 1;
		}
	}
}

void iMouseMove(int mx, int my)
{
		if (mx >= roadAxis[1][0] && mx <= roadAxis[1][0] + 150) {
			if (roadDirection[1] == 2) {
				roadAxis[1][1] = my;
				if (roadAxis[1][1] >= 480 && roadAxis[1][1] <= 550) {
					roadAxis[1][1] = 499;
				}
			}
		}
		if (roadAxis[1][1] == 499) {
			roadDirection[1] = 5;
		}
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= roadAxis[0][0] && mx <= roadAxis[0][0] + 150 && my >= roadAxis[0][1] - 50 && my <= roadAxis[0][1]) {
			roadMovements(0);
			if (roadDirection[0] == 2) {
				roadDirection[0] = 5;
			}
		}
		if (mx >= roadAxis[1][0]  && mx <= roadAxis[1][0] + 150 && my >= roadAxis[1][1] - 50 && my <= roadAxis[1][1] ) {
			roadMovements(1);
		}
		if (mx >= roadAxis[3][0] - 50 && mx <= roadAxis[3][0] + 100 && my >= roadAxis[3][1] - 50 && my <= roadAxis[3][1]) {
			roadMovements(3);
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= roadAxis[2][0] && mx <= roadAxis[2][0] + 50 && my >= roadAxis[2][1] - 150 && my <= roadAxis[2][1]) {
			roadMovements(2);
			if (roadDirection[2] == 3) {
				roadDirection[2] = 5;
			}
		}
		if (mx >= roadAxis[4][0] - 50 && mx <= roadAxis[4][0] + 100 && my >= roadAxis[4][1] - 50 && my <= roadAxis[4][1]) {
			roadMovements(4);
		}
	}
}

void iKeyboard(unsigned char key) {

	if (roadAxis[3][0] == 701 && roadDirection[4] == 2 && key == ',') {
		roadAxis[4][0] -= 50;
		roadDirection[4] = 5;
	}
	if (key == 's') {
		int temp = carAxis[2];
		carAxis[2] = carAxis[3];
		carAxis[3] = temp;
		s++;
	}
}
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_LEFT) {
		if (count != 1 && roadDirection[0] == 5 && roadDirection[1] == 5 && roadDirection[2] == 5 && roadDirection[3] == 2) {
			roadAxis[3][0] -= 5;
			if (roadAxis[3][0] >= 700 && roadAxis[3][0] <= 705) {
				roadAxis[3][0] = 701;
				roadDirection[3] = 5;
			}
		}
	}
	if (key == GLUT_KEY_HOME) {
		enter = 1;
	}
	
}
void timer0() {
	timerY += 10;
}
void timer1() {
	if (times == 1) {
		if (carAxis[2] > carAxis[3]) {
			carAxis[0] -= 1;
		}
		else {
			carAxis[1] += 1;
		}
	}
	if (carAxis[0] >= 300 && carAxis[0] <= 320 && carAxis[1] >= 500 && carAxis[1] <= 520) {
		iPauseTimer(1);
		enter = 2;
	}
	if (carAxis[1] + carAxis[3] == lineAxis[8][1] && carAxis[0] >= lineAxis[8][0]) {
		iPauseTimer(1);
		car=1;
	}
	if (carAxis[0] == lineAxis[6][2] && carAxis[1] >= lineAxis[6][3] && carAxis[1] <= lineAxis[6][1]) {
		iPauseTimer(1);
		car=1;
	}
	if (carAxis[1] + carAxis[3] == lineAxis[5][1] && carAxis[0] >= lineAxis[5][0]) {
		iPauseTimer(1);
		car=1;
	}
	if (carAxis[0] == lineAxis[2][2] && carAxis[1] >= lineAxis[2][3] && carAxis[1] <= lineAxis[2][1]) {
		iPauseTimer(1);
		car=1;
	}
	if (carAxis[1] + carAxis[3] == lineAxis[0][1] && carAxis[0] >= lineAxis[0][0]) {
		iPauseTimer(1);
		car=1;
	}
}

int main()
{
	iSetTimer(2000, timer0);
	iSetTimer(1, timer1);
	iInitialize(1350, 700, "Save The Animals!");
	return 0;
}	