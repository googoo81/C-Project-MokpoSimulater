#include<stdio.h>
#include<Windows.h>
#include<stdbool.h>
void gotoXY(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
int Getkeydown(int vkey);

void map() {

	system("cls");

	int num = 1;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("					    �ҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢ�\n");
	printf("					\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("					\t@@@@@@@@@@@@@@@@@@@@@@;@@@,.,,@@@@@@@@@@@@@@@@@@@@	   �ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�\n");
	printf("					\t@@@@@@@@@@@@@@@@@@@@..........,,@@@@@@@@@@@@@@@@@@         ��          ����(��Ű�Ͻ�Ƽ)        ��\n");
	printf("					\t@@@@@@@@@@@@@@@@@@@,............@@@@@@@@@@@@@@@@@@         ��               �ȳ���             ��\n");
	printf("					\t@@@@@@@@@@@@@@@@@,,...............,., @@@@@@@@@@@@	   �ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�\n");
	printf("					\t@@@@@@@@@@@@@@,.......................@@@@@@@@@@@@\n");
	printf("					\t@@@@@@@@@@@@@@........................,@@@@@@@@@@@\n");
	printf("					\t@@@@@@@@@@@@@...........................@@@@@@@@@@\n");
	printf("					\t@@@@@@@@@@@@@..........................,@@@@@@@@@@\n");
	printf("					\t@@@@@@@@@@@@,.,,.......................,@@@@@@@@@@\n");
	printf("					\t@@@@@@@@@@,............................~@@@@@@@@@@\n");
	printf("					\t@@@@@@@@@..............,.,.............@@@@@@@@@@@\n");
	printf("					\t@@@@@@@@,...............,..............@@@@@@@@@@@\n");
	printf("					\t@@@@@@@@...............................@@@@@@@@@@@\n");
	printf("					\t@@@@@@~................................,, , @@@@@@\n");
	printf("					\t@@@@@@,......            ...................,-@@@@\n");
	printf("					\t@@@@@@.......  ��ϱ�  ......................@@@\n");
	printf("					\t@@@@@,.......            ..,....................@@\n");
	printf("					\t@@@@............�١١�..........................@@\n");
	printf("					\t@@@.....,.....,..,......            ............@@\n");
	printf("					\t@@,,...................,   ������   ..,..........@\n");
	printf("					\t@-......................            .............,\n");
	printf("					\t@;............,..........,.......................,\n");
	printf("					\t@@,...............................................\n");
	printf("					\t@@.........................................,@@@@@@\n");
	printf("					\t@@,.........,..........................., @@@@@@@@\n");
	printf("					\t            ....................................., \n");
	printf("					\t  �����ϱ�  ,.......,.............................\n");
	printf("					\t            ...,.......................,,.........\n");
	printf("					\t...�ڡڡ�........,.........,..........,@@@........\n");
	printf("					\t....................................,@@@@,........\n");
	printf("					\t,......................,.. .....,@@@@@@@@@.....,-@\n");
	printf("					\t,....,....................@@-,,@@@@@@@@@@@,,@@@@@@\n");
	printf("					\t@,,..........,.........,.@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("					\t@@@........,..........,@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("					\t@@@..�١ڡ�..........,@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("					\t..            ......,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("					\t@.  �����ϱ�  .,....,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("					\t@@            ,..,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("					\t@@@@@---,,, @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("					    �ҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢҢ�\n");
		printf("�� �� ����Ű�� ������ �� ����. �����̽��ķ� ��� ���ð���. ���� ������ ���̵��� ��Ÿ��.\n");

	Sleep(300);

	while (1) {
		if (Getkeydown(VK_DOWN) && num != 3) {
			num++;
		}
		else if (Getkeydown(VK_UP) && num != 0)
			num--;

		if (num == 0) {
			gotoXY(61, 21);
			printf("�ڡڡڡڡڡ�");
			gotoXY(61, 22);
			printf("��");
			gotoXY(71, 22);
			printf("��");
			gotoXY(61, 23);
			printf("�ڡڡڡڡڡ�");
		}
		else {
			gotoXY(61, 21);
			printf("            ");
			gotoXY(61, 22);
			printf("  ");
			gotoXY(71, 22);
			printf("  ");
			gotoXY(61, 23);
			printf("            ");
		}

		if (num == 1) {
			gotoXY(72, 25);
			printf("�ڡڡڡڡڡ�");
			gotoXY(72, 26);
			printf("��");
			gotoXY(82, 26);
			printf("��");
			gotoXY(72, 27);
			printf("�ڡڡڡڡڡ�");
		}
		else {
			gotoXY(72, 25);
			printf("            ");
			gotoXY(72, 26);
			printf("  ");
			gotoXY(82, 26);
			printf("  ");
			gotoXY(72, 27);
			printf("            ");
		}

		if (num == 2) {
			gotoXY(48, 32);
			printf("�ڡڡڡڡڡ�");
			gotoXY(48, 33);
			printf("��");
			gotoXY(58, 33);
			printf("��");
			gotoXY(48, 34);
			printf("�ڡڡڡڡڡ�");
		}
		else {
			gotoXY(48, 32);
			printf("            ");
			gotoXY(48, 33);
			printf("  ");
			gotoXY(58, 33);
			printf("  ");
			gotoXY(48, 34);
			printf("            ");
		}

		if (num == 3) {
			gotoXY(50, 42);
			printf("�ڡڡڡڡڡ�");
			gotoXY(50, 43);
			printf("��");
			gotoXY(60, 43);
			printf("��");
			gotoXY(50, 44);
			printf("�ڡڡڡڡڡ�");
		}
		else {
			gotoXY(50, 42);
			printf("            ");
			gotoXY(50, 43);
			printf("  ");
			gotoXY(60, 43);
			printf("  ");
			gotoXY(50, 44);
			printf("            ");
		}

		if (num == 0 && Getkeydown(VK_SPACE)) {
			PlaySound(TEXT("AHN_YEEUN_____Sailing____Violin_Cover"), NULL, SND_ASYNC | SND_LOOP);
			easynormalhard = 0;
			play();
			break;
		}
		else if (num == 1 && Getkeydown(VK_SPACE)) {
			system("cls");
			break;
		}
		else if (num == 2 && Getkeydown(VK_SPACE)) {
			PlaySound(TEXT("AHN_YEEUN_____Sailing____Violin_Cover"), NULL, SND_ASYNC | SND_LOOP);
			easynormalhard = 2;
			play();
			break;
		}
		else if (num == 3 && Getkeydown(VK_SPACE)) {
			PlaySound(TEXT("AHN_YEEUN_____Sailing____Violin_Cover"), NULL, SND_ASYNC | SND_LOOP);
			easynormalhard = 1;
			play();
			break;
		}
		Sleep(100);
	}
	return;
}