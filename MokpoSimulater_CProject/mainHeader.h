#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include"sourceHeader.h"
#include"exitHeader.h"
#include"mapHeader.h"

#define gX 35
#define gY 15
void init();
void gotoXY(int, int);
void maindraw();
void textcolore(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}
int main() {
	maindraw();
}

void maindraw() {
	textcolore(YELLOW);
	init();

	int botton = 0;
	Sleep(1000);

	while (1) {
		gotoXY(gX, gY);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		gotoXY(gX, gY + 1);
		printf("                                                                                                                \n");
		gotoXY(gX, gY + 2);
		printf("                                                                                                                \n");
		gotoXY(gX, gY + 3);
		printf("                                                ■■■■■■■■■■___  ┌───────────────────────────┐           \n");
		gotoXY(gX, gY + 4);
		printf("                                                ■▒▒▒▒■▒▒  ■▒▒▒ ■  ■ │ ▩▩▩▩  지도보기  ▩▩▩│           \n");
		gotoXY(gX, gY + 5);
		printf("                                                ■▒  ");
		textcolor(SkyBlue);
		printf(" 랭킹 보기 ");
		textcolor(YELLOW);
		printf("▒ ■  ■ │   ▩▩▩          ▩▩▩  │           \n");
		gotoXY(gX, gY + 6);
		printf("                                                ■■■■■■■■■■  ■ │    ▩▩▩  ,.   ▩▩▩▩▩│           \n");
		gotoXY(gX, gY + 7);
		printf("                                                ■▒▒▒▒■▒▒▒▒■▒▒▒▒■  ■ │ ▩▩▩        ▩▩▩      │           \n");
		gotoXY(gX, gY + 8);
		printf("                                                ■▒   게임 설명  ▒■  ■ └───────────────────────────┘	         \n");
		gotoXY(gX, gY + 9);
		printf("        ┌──────────────────────┐    ___________ ■■■■■■■■■■  ■_________________________________       \n");
		gotoXY(gX, gY + 10);
		printf("        ├      꾀병부리기      ┤   /          /|■  ▒▒■  ▒▒■▒▒▒▒■   /         ┌──────┐               /■      \n");
		gotoXY(gX, gY + 11);
		printf("        ├──────________────────┤  ┌──────────  |■  ▒▒■  ▒▒■▒▒▒▒■  ■■■■■■|      |■■■■■■■ ■      \n");
		gotoXY(gX, gY + 12);
		printf("        /      /       /       |  ├──────-───┤ |■■■■■■■■■■  ■          |      |/           ■ ■     \n");
		gotoXY(gX, gY + 13);
		printf("_______/=_=-~~└=======┘ /- = -/|__├─────-────┤ |■▒▒▒▒■  ▒▒■▒▒▒▒■  ■________ ├──────┤  |__________■ ■     \n");
		gotoXY(gX, gY + 14);
		printf("      /                      //|  ├────────-─┤ /■▒▒▒▒■  ▒▒■▒▒▒▒■  ■          |'     | '          ■ ■     \n");
		gotoXY(gX, gY + 15);
		printf("     /                      // /  │__________│/ ■■■■■■■■■■ /'           |      |            ■ /     \n");
		gotoXY(gX, gY + 16);
		printf("    /                      // /                                                                                 \n");
		gotoXY(gX, gY + 17);
		printf("   /                      // /                                                                                  \n");
		gotoXY(gX, gY + 18);
		printf("  ├=====================┤/  /                                                                                   \n");
		gotoXY(gX, gY + 19);
		printf("  ├─_-──--_──_──────── ─┼  /                                                                                    \n");
		gotoXY(gX, gY + 20);
		printf("  └─ ───────────────────┴                                                                                      \n");
		gotoXY(gX, gY + 21);
		printf("\n");
		gotoXY(gX, gY + 22);
		printf("\n");
		gotoXY(gX, gY + 23);
		printf("\n");
		gotoXY(gX, gY + 24);
		printf("\n");
		gotoXY(gX, gY + 25);
		printf("\n");
		gotoXY(gX, gY + 26);
		printf("\n");
		gotoXY(gX, gY + 27);
		printf("\n");
		gotoXY(gX, gY + 28);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

		gotoXY(gX + 12, gY + 10);
		printf("▷");
		gotoXY(gX + 83, gY + 4);
		printf("▷");

		if (botton) {
			gotoXY(gX + 12, gY + 10);
			printf("▷");
			gotoXY(gX + 83, gY + 4);
			printf("▶");
		}
		else {
			gotoXY(gX + 83, gY + 4);
			printf("▷");
			gotoXY(gX + 12, gY + 10);
			printf("▶");
		}
		if (Getkeydown(VK_LEFT) && botton) {
			botton = 0;
		}
		else if (Getkeydown(VK_RIGHT) && !botton) {
			botton = 1;
		}

		if (Getkeydown(VK_SPACE) && botton) {
			map();
		}
		else if (Getkeydown(VK_SPACE) && !botton) {
			ending();
		}
		Sleep(60);
	}
}

void init() {
	system("mode con cols=200 lines=50 | title  목포 시뮬레이터");
}

