#include<stdio.h>
void 설명() {
    system("cls");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t게임 방법\n");
    printf("\t\t\t\t\t\t\t위방향키와 아래방향키로 플레이 할 수 있다.\n");
    printf("\t\t\t\t\t\t\t너무 물 밑이sk 위로 올라가면 다시 중앙으로 되돌아온다.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t이 게임은 목포사는 송현우가 어뜨케 학교 기숙사로 등교하는지 시뮬레이션하는 프로그램이다!\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t┌───┐\n");
    printf("\t\t\t\t\t\t\t│ №│\n");
    printf("\t\t\t\t\t\t\t└───┘\n");
    printf("\t\t\t\t\t\t\t부스트!\n");
    printf("\t\t\t\t\t\t\t먹으면 스페이스바를 누르는 것으로 사용가능하다. \n");
    printf("\t\t\t\t\t\t\t사용시 속도가 눈에띄게 빨라지며 모든 장애물을 파괴한다.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t  ─\n");
    printf("\t\t\t\t\t\t\t│ ★│\n");
    printf("\t\t\t\t\t\t\t  ─\n");
    printf("\t\t\t\t\t\t\t실드!\n");
    printf("\t\t\t\t\t\t\t먹으면 고래가 등에서 물을 뿜어 쉴드를 생성한다.\n");
    printf("\t\t\t\t\t\t\t장애물을 한번 무효로 만들 수 있으며 방어시 실드는 소멸한다.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t장애물\n\n");
    printf("\t\t\t\t\t\t\t☜(ㆍΘㆍ)э\n");
    printf("\t\t\t\t\t\t\t새다. 아무튼 새라고 한다.\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t＜コ：ミ\n");
    printf("\t\t\t\t\t\t\t오징어다. 플레이어를 닮은게 특징이다.(어쩌라고)\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t<º))))><\n");
    printf("\t\t\t\t\t\t\t물고기다. 회쳐먹으면 참 맛있겠다.\n");
    printf("\n");
    printf("\t\t\t\t\t\t\tミ('=')ミ\n");
    printf("\t\t\t\t\t\t\t게다. 술먹고 객기부리는 사람을 '개'라고 부르기로했다.\n");
    printf("\n");
    textcolor(BLACK);
    printf("\n");
    printf("\n");
    textcolor(WHITE);
    Sleep(30);
    printf("\t\t\t\t\t\t\t메인으로 돌아가려면 스페이스바를 눌러주세요");

    Sleep(1000);

    while (1) {
        if (Getkeydown(VK_SPACE)) {
            system("cls");
            textcolor(YELLOW);
            break;
        }
    }

    return;
}