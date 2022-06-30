#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include"boosterHeader.h"

enum ColorType {
	BLACK,  	//0
	darkBLUE,	//1
	DarkGreen,	//2
	darkSkyBlue,    //3
	DarkRed,  	//4
	DarkPurple,	//5
	DarkYellow,	//6
	GRAY,		//7
	DarkGray,	//8
	BLUE,		//9
	GREEN,		//10
	SkyBlue,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE		//15
} COLOR;

#define WHALE_BOTTOM_Y 26
#define FISH_BOTTOM_Y 36
#define FISH_BOTTOM_X 85
#define SQUID_BOTTOM_Y 24
#define SQUID_BOTTOM_X 85
#define SEAGULL_BOTTOM_Y 10
#define SEAGULL_BOTTOM_X 85
#define CRAB_BOTTOM_Y 46
#define CRAB_BOTTOM_X 85
#define BOOSTER_BOTTOM_Y 46
#define BOOSTER_BOTTOM_X 85

void consolesize();
int isCollision(const int boosterX, const int crabX, const int seaGullX, const int squidX, const int fishX, const int whaleY);
void drawgameover(int score);
void GotXY(int x, int y);
void drawwhale(int whaleY);
void background();
void fishdraw(int fishX);
void squiddraw(int squidX);
void seaGulldraw(int);
void boosterDraw(int);
void crabDraw(int);
void itemBox();
void gotoXY(int, int);
int Getkeydown(int vkey) {
	if (GetAsyncKeyState(vkey) & 0x8000) {
		return true;
	}
	return false;
}
void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}
void play() {
	isUp = false;
	isDown = false;

	isJumping = false;
	isBottom = true;

	isDiving = false;
	isTop = true;

	ownBooster = false;

	whaleY = WHALE_BOTTOM_Y;
	fishX = FISH_BOTTOM_X;
	squidX = 35;
	seaGullX = SEAGULL_BOTTOM_X;
	crabX = SEAGULL_BOTTOM_X;
	boosterX = BOOSTER_BOTTOM_X;
	score = 0;
	keycontrol = 0;

	sfmt_t sfmt;
	sfmt_init_gen_rand(&sfmt, time(NULL));

	consolesize();
	srand(time(NULL));

	int fishspd = 4;
	int squidspd = 4;
	int seaGullspd = 4;
	int crabspd = 4;
	int boosterspd = 4;
	trapvalue = 0;
	const int gravity = 2;

	clock_t start, curr;
	start = clock();

	while (true) {
		gotoXY(0, 0);
		background();
		if (isCollision(boosterX, crabX, seaGullX, squidX, fishX, whaleY))
			break;

		if (Getkeydown(VK_SPACE) && ownBooster == true) {
			keycontrol++;
			ownBooster = false;
			booster();
			fishspd = 4;
			squidspd = 4;
			seaGullspd = 4;
			crabspd = 4;
		}

		if (Getkeydown(VK_UP) && isUp == false && whaleY > 14 && whaleY == 26 && isDown == false && isDiving != true)
		{
			keycontrol++;
			isUp = true;
		}
		else if (Getkeydown(VK_DOWN) && whaleY < 26)
		{
			keycontrol++;
			isDown = true;
		}

		if (whaleY <= 14) {
			if (Getkeydown(VK_UP) && whaleY == 14 && !isJumping) {
				keycontrol++;
				isJumping = true;
				isBottom = false;
			}
			if (isJumping)
			{
				whaleY -= gravity;
			}
			else if (whaleY < 14 && !isJumping)
			{
				whaleY += gravity;
			}
		}
		if (whaleY <= 0) {
			isJumping = false;
			isBottom = true;
		}

		if (whaleY >= 26) {
			if (Getkeydown(VK_DOWN) && whaleY == 26) {
				keycontrol++;
				isDiving = true;
				isTop = false;
			}
			if (isDiving) {
				whaleY += gravity;
			}
			else if (whaleY > 26 && !isDiving) {
				whaleY -= gravity;
			}
		}
		if (whaleY >= 36) {
			isDiving = false;
			isTop = true;
		}

		if (isUp)
			whaleY -= gravity;
		else if (isDown)
			whaleY += gravity;

		if (whaleY >= WHALE_BOTTOM_Y && isDown)
		{
			whaleY = WHALE_BOTTOM_Y;
			isDown = false;
		}

		if (whaleY <= 14)
			isUp = false;
		fishX -= fishspd;;
		if (fishX <= -1) {
			fishspd = sfmt_genrand_uint32(&sfmt) % 5 + 4;
			fishX = FISH_BOTTOM_X;
		}

		squidX -= squidspd;
		if (squidX <= -1) {
			squidspd = sfmt_genrand_uint32(&sfmt) % 5 + 4;
			squidX = SQUID_BOTTOM_X;
		}

		seaGullX -= seaGullspd;
		if (seaGullX <= -1) {
			seaGullspd = sfmt_genrand_uint32(&sfmt) % 5 + 4;
			seaGullX = SEAGULL_BOTTOM_X;
		}

		itemBox();
		drawwhale(whaleY);
		fishdraw(fishX);
		squiddraw(squidX);
		seaGulldraw(seaGullX);

		if (trapvalue == 0 && ownBooster == false) {
			boosterDraw(boosterX);
			boosterX -= boosterspd;
			if (boosterX <= -1 || ownBooster == 1) {
				boosterX = BOOSTER_BOTTOM_X;
				crabX = CRAB_BOTTOM_X;
				trapvalue = sfmt_genrand_uint32(&sfmt) % 20;
			}
		}
		else {
			crabDraw(crabX);
			crabX -= crabspd;
			if (crabX <= -1) {
				crabspd = sfmt_genrand_uint32(&sfmt) % 5 + 4;
				crabX = CRAB_BOTTOM_X;
				boosterX = BOOSTER_BOTTOM_X;
				trapvalue = sfmt_genrand_uint32(&sfmt) % 20;
			}
		}

		curr = clock();
		if (((curr - start) / CLOCKS_PER_SEC) >= 0) {
			score++;
			start = clock();
		}
		Sleep(60);
		system("cls");

		GotXY(10, 0);
		printf("Score : %d, keyClick : %d", score, keycontrol);
	}

	drawgameover(score);
}
int isCollision(const int boosterX, const int crabX, const int seaGullX, const int squidX, const int fishX, const int whaleY) {
	if (boosterX <= 20 && boosterX >= 0 && whaleY >= 34)
		ownBooster = true;
	if (crabX <= 16 && crabX >= 0 && whaleY >= 34)
		return true;
	if (seaGullX <= 16 && seaGullX >= 0 && whaleY <= 3)
		return true;
	if (fishX <= 20 && fishX >= 0 && whaleY == 26)
		return true;
	if (squidX <= 20 && squidX >= 0 && whaleY == 14)
		return true;
	return false;
}

void drawgameover(int score) {
	system("cls");
	int x = 31;
	int y = 18;
	int botton = 0;
	while (true) {
		GotXY(x, y);
		printf("\t  \t\t===========================");
		GotXY(x, y + 1);
		printf("\t  \t\t======G A M E O V E R======");
		GotXY(x, y + 2);
		printf("\t  \t\t===========================");
		GotXY(x, y + 5);
		printf("\t  \t\t\tSCORE : %d\n\n\n", score);
		printf("\t\t\t\t\t\t\t\t\t\t다시시작           돌아가기");
		printf("\n\n\n\n\n\n\n\n\n");

		gotoXY(76, 26);
		printf("▷");
		gotoXY(96, 26);
		printf("▷");

		if (botton) {
			gotoXY(76, 26);
			printf("▷");
			gotoXY(96, 26);
			printf("▶");
		}
		else {
			gotoXY(96, 26);
			printf("▷");
			gotoXY(76, 26);
			printf("▶");
		}
		if (Getkeydown(VK_LEFT) && botton) {
			botton = 0;
		}
		else if (Getkeydown(VK_RIGHT) && !botton) {
			botton = 1;
		}

		if (Getkeydown(VK_SPACE) && botton) {
			break;
		}
		else if (Getkeydown(VK_SPACE) && !botton) {
			play();
			break;
		}
		Sleep(100);
	}
	return;
}

void itemBox() {
	if (ownBooster == 1) {
		gotoXY(130, 0);
		printf("┌───────┐");
		gotoXY(130, 1);
		printf("│ 부스터│");
		gotoXY(130, 2);
		printf("└───────┘");
	}
	else {
		gotoXY(130, 0);
		printf("┌───────┐");
		gotoXY(130, 1);
		printf("│       │");
		gotoXY(130, 2);
		printf("└───────┘");
	}
}

void crabDraw(int crabX) {
	GotXY(crabX, CRAB_BOTTOM_Y);
	textcolor(RED);
	printf("ミ('=')ミ\n");
	textcolor(YELLOW);
}

void seaGulldraw(int seaGullX) {
	GotXY(seaGullX, SEAGULL_BOTTOM_Y);
	textcolor(WHITE);
	printf("☜");
	textcolor(GRAY);;
	printf("(ㆍΘㆍ)");
	textcolor(WHITE);
	printf("э ≫\n");
	textcolor(YELLOW);
}
void squiddraw(int squidX) {
	GotXY(squidX, SQUID_BOTTOM_Y);
	textcolor(DarkYellow);
	printf("＜コ：ミ");
	textcolor(YELLOW);
}
void fishdraw(int fishX) {
	GotXY(fishX, FISH_BOTTOM_Y);
	textcolor(BLUE);
	printf("<º))))><");
	textcolor(YELLOW);
}

void boosterDraw(int boosterX) {
	GotXY(boosterX, BOOSTER_BOTTOM_Y);
	printf("┌───┐\n");
	GotXY(boosterX, BOOSTER_BOTTOM_Y + 1);
	printf("│ ");
	textcolor(RED);
	printf("№");
	textcolor(YELLOW);
	printf("│\n");
	GotXY(boosterX, BOOSTER_BOTTOM_Y + 2);
	printf("└───┘\n");
}

void drawwhale(int whaleY) {
	GotXY(0, whaleY);
	static int legFlag = 0;
	textcolor(WHITE);
	if (legFlag < 3) {
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                      ( ´--)/\n");
		legFlag++;
	}
	else if (legFlag < 5) {
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                   ><\n");
		printf("                   ㅣ( ´--)`\n");
		legFlag++;
	}
	else if (legFlag < 7) {
		printf("\n");
		printf("\n");
		printf("                  )  (\n");
		printf("                   ><\n");
		printf("                   ㅣ( ´--)`\n");
		legFlag++;
	}
	else if (legFlag < 9) {
		printf("\n");
		printf("             |ㅡ┐   ┌ㅡ|\n");
		printf("                  )  (\n");
		printf("                   ><\n");
		printf("                   ㅣ( ´--)`\n");
		legFlag++;
	}
	else
	{
		printf("      -  = ㅡ ┐  |||  ┌ ㅡ =  -\n");
		printf("             |ㅡ┐   ┌ㅡ|\n");
		printf("                  )  (\n");
		printf("                   ><\n");
		printf("                   ㅣ( ´--)`\n");
		legFlag = 0;
	}

	textcolor(SkyBlue);
	printf("                 ■■■■■■■\n");
	printf("    ■  ■     ■              ■\n");
	printf("    ㅁ ㅁ     ■                 ■\n");
	printf("      ■     ■              0    ■\n");
	printf("     ■     ■      ┌─────────────■\n");
	printf("~~~@~~~~■@~■┬┬─┬─┤ | | | | | | ■\n");
	printf("         ~  ~■^■~■^■@■~■~■/@@@/~~~ \n");
	textcolor(YELLOW);
}
void GotXY(int x, int y) {
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void consolesize() {
	system("mode con cols=200 lines=50");
	system("title Google Dinosaurs. By BlockDMask");
}
void background() {
	textcolor(BLUE);
	static int num = 0;
	if (num < 10) {
		gotoXY(0, 10);
		printf("\n");
		printf("      (***********(@┱__           (*********(@┱__            (********(@┱__      (***********(@┱__           (*********(@┱__            (********(@┱__           (*********(@┱__            (****\n");
		printf("~~~~~~~`             ``````~~~~~~~`           `````~~~~~~~~~~`          ````~~~~~~~`             ``````~~~~~~~`           `````~~~~~~~~~~`          ````~~~~~~~`           `````~~~~~~~~~~`          \n");
		num++;
	}
	else if (num >= 10) {
		gotoXY(0, 10);
		printf("\n");
		printf("~~~~~~~`             ``````~~~~~~~`           `````~~~~~~~~~~`          ````~~~~~~~`             ``````~~~~~~~`           `````~~~~~~~~~~`          ````~~~~~~~`           `````~~~~~~~~~~`          \n");
		printf("      (***********(@┱__           (*********(@┱__            (********(@┱__      (***********(@┱__           (*********(@┱__            (********(@┱__           (*********(@┱__            (****\n");
		num++;
	}
	if (num == 20)
		num = 0;
	textcolor(YELLOW);
}