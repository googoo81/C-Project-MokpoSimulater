#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include"SFMT.h"

#define WHALE_BOTTOM_Y 26
#define FISH_BOTTOM_Y 36
#define FISH_BOTTOM_X 85
#define SQUID_BOTTOM_Y 24
#define SQUID_BOTTOM_X 85
#define SEAGULL_BOTTOM_Y 10
#define SEAGULL_BOTTOM_X 85
#define CRAB_BOTTOM_Y 10
#define CRAB_BOTTOM_X 85

bool isUp;
bool isDown;

bool isJumping;
bool isBottom;

bool isDiving;
bool isTop;

int whaleY;
int fishX;
int squidX;
int seaGullX;
int crabX;
int boosterX;
int shieldX;
int score;
int keycontrol;
int trapvalue;

int ownBooster = false;
int ownShield = false;

void consolesize();
int isCollision(const int seaGullX, const int squidX, const int fishX, const int dinoY);
void drawgameover(const int score);
void GotXY(int x, int y);
void background();
void drawInvinCibilityWhale(int whaleY);
void fishdraw(int fishX);
void squiddraw(int squidX);
void seaGulldraw(int seaGullX);
void crabDraw(int);
void itemBox();
int Getkeydown(int vkey);
void textcolor(int);

int booster() {
	sfmt_t sfmt;
	sfmt_init_gen_rand(&sfmt, time(NULL));
	clock_t old_time, cur_time;
	consolesize();
	srand(time(NULL));

	int fishspd = 4;
	int squidspd = 4;
	int seaGullspd = 4;
	int crabspd = 4;
	const int gravity = 2;

	clock_t start, curr;
	start = clock();

	old_time = clock();
	while (true) {
		background();

		if (Getkeydown(VK_UP) && isUp == false && whaleY != 14 && isDown == false)
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
			if (Getkeydown(VK_UP) && whaleY == 14) {
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
			fishX = FISH_BOTTOM_X;
			fishspd = rand() % 5 + 4;
		}

		squidX -= squidspd;
		if (squidX <= -1) {
			squidX = SQUID_BOTTOM_X;
			squidspd = rand() % 5 + 4;
		}

		seaGullX -= seaGullspd;
		if (seaGullX <= -1) {
			seaGullX = SEAGULL_BOTTOM_X;
			seaGullspd = rand() % 5 + 4;
		}

		crabX -= crabspd;
		if (crabX <= -1) {
			crabX = CRAB_BOTTOM_X;
			crabspd = rand() % 5 + 4;
		}

		fishdraw(fishX);
		squiddraw(squidX);
		seaGulldraw(seaGullX);
		crabDraw(crabX);
		itemBox();
		textcolor(sfmt_genrand_uint32(&sfmt) % 16);
		drawInvinCibilityWhale(whaleY);


		curr = clock();
		if (((curr - start) / CLOCKS_PER_SEC) >= 0) {
			score++;
			start = clock();
		}
		Sleep(10);
		system("cls");

		GotXY(10, 0);
		printf("Score : %d, keyClick : %d", score, keycontrol);

		cur_time = clock();

		if (((double)(cur_time - old_time) / CLOCKS_PER_SEC) > 3) {
			break;
		}
	}

	fishX = 85;
	squidX = 65;
	seaGullX = 85;
	return 0;
}
void drawInvinCibilityWhale(int dinoY) {
	GotXY(0, dinoY);
	static int legFlag = 0;
	if (legFlag < 3) {
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                      ( ╞--)/\n");
		legFlag++;
	}
	else if (legFlag < 5) {
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                   ><\n");
		printf("                   太( ╞--)`\n");
		legFlag++;
	}
	else if (legFlag < 7) {
		printf("\n");
		printf("\n");;
		printf("                  )  (\n");
		printf("                   ><\n");
		printf("                   太( ╞--)`\n");
		legFlag++;
	}
	else if (legFlag < 9) {
		printf("\n");
		printf("             |天忖   忙天|\n");
		printf("                  )  (\n");
		printf("                   ><\n");
		printf("                   太( ╞--)`\n");
		legFlag++;
	}
	else
	{
		printf("      -  = 天 忖  |||  忙 天 =  -\n");
		printf("             |天忖   忙天|\n");
		printf("                  )  (\n");
		printf("                   ><\n");
		printf("                   太( ╞--)`\n");
		legFlag = 0;
	}

	printf("                 =﹥﹥﹥﹥﹥﹥﹥﹥\n");
	printf("    ﹥  ﹥    _=﹥               ﹥\n");
	printf("     仃 仃  = ﹥                  ﹥\n");
	printf("       ﹥    ﹥              _0    ﹥\n");
	printf("       ﹥   ﹥      忙式式式式式式式式式式式式式﹥\n");
	printf("~~~@~~~~﹥@~﹥成成式成式扣 | | | | | | ﹥\n");
	printf("         ~  ~﹥^﹥~﹥^﹥@﹥~﹥~﹥~~~~/@@@/~~~~~ \n");
	textcolor(14);
}