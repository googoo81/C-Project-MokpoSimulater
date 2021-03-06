#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include"sourceHeader.h"
#include"exitHeader.h".h"
#include"mapHeader.h"
#include"explainHeader.h"

#define gX 35
#define gY 15
void init();
void gotoXY(int, int);
void maindraw();
void HideCursor(int hiding);
void textcolore(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}
void maindraw() {
	PlaySound(TEXT("Contaminated_Sea_____MapleStory.wav"), NULL, SND_ASYNC | SND_LOOP);
	system("cls");
	HideCursor(1);
	textcolore(YELLOW);
	init();

	int botton = 0;
	Sleep(300);

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
		printf("                                                ■▒▒▒▒■▒▒");
		printf("  ■▒▒▒▒■  ■ │   ▩▩▩          ▩▩▩  │           \n");
		gotoXY(gX, gY + 6);
		printf("                                                ■■■■■■■■■■  ■ │    ▩▩▩  ,.   ▩▩▩▩▩│           \n");
		gotoXY(gX, gY + 7);
		printf("                                                ■▒▒▒▒■▒▒▒▒■▒▒▒▒■  ■ │ ▩▩▩        ▩▩▩      │           \n");
		gotoXY(gX, gY + 8);
		printf("                                                ■▒   게임 설명 ▒▒■  ■ └───────────────────────────┘	         \n");
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
		gotoXY(gX + 52, gY + 8);
		printf("▷");

		if (botton == 0) {
			gotoXY(gX + 12, gY + 10);
			printf("▶");
			gotoXY(gX + 52, gY + 8);
			printf("▷");
			gotoXY(gX + 83, gY + 4);
			printf("▷");
		}
		else if (botton == 1) {
			gotoXY(gX + 83, gY + 4);
			printf("▷");
			gotoXY(gX + 52, gY + 8);
			printf("▶");
			gotoXY(gX + 12, gY + 10);
			printf("▷");
		}
		else if (botton == 2) {
			gotoXY(gX + 12, gY + 10);
			printf("▷");
			gotoXY(gX + 83, gY + 4);
			printf("▶");
			gotoXY(gX + 52, gY + 8);
			printf("▷");
		}

		if (Getkeydown(VK_LEFT) && botton != 0) {
			botton--;
		}
		else if (Getkeydown(VK_RIGHT) && botton != 2) {
			botton++;
		}

		if (Getkeydown(VK_SPACE) && botton == 2) {
			map();
		}
		else if (Getkeydown(VK_SPACE) && botton == 0) {
			ending();
		}
		else if (Getkeydown(VK_SPACE) && botton == 1) {
			설명();
		}
		Sleep(100);
	}
}

void init() {
	system("mode con cols=200 lines=50 | title  목포 시뮬레이터");
}