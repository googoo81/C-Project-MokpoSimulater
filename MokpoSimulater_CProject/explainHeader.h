#include<stdio.h>
void 설명() {
    system("cls");
    printf("\t\t\t이 시뮬레이션은 총 세개의 엔딩으로 이루어져 있으니 숨겨진 조건을 잘 만족하여 모든 엔딩을 보시길 기원합니다(단, 등교하기에서만 볼 수 있음).\n");
    printf("\n");
    if (badEnding == 0)
        printf("\t\t\t\t\t\t\t\t\t?? ENDING : ????\n");
    else if (badEnding == 1)
        printf("\t\t\t\t\tBAD ENDING : 지각 (도착했습니다. 하지만 시계를 보니 8시 34분이에요. 아쉽군요)\n");
    if (happyEnding == 0)
        printf("\t\t\t\t\t\t\t\t\t??? : ???\n");
    else if (happyEnding == 1)
        printf("\t\t\tHAPPY ENDING : 해방 (부스터를 5개나 쓰셨군요. 속도를 주체못하고 벽에 박아버렸어요. 하지만 축하드립니다! 송현우를 삶의 굴래로부터 벗어나게 해주셨군요)\n");
    if (trueEnding == 0)
        printf("\t\t\t\t\t\t\t\t\t??? : ???\n");
    else if (trueEnding == 1)
        printf("\t\t\tTRUE ENDING : 수감 (안전모는 필수죠! 제시간에 도착하셨군요. 지옥에 재수감 되신 것을 축하드립니다.  하지만 과연 이게 좋은 선택이었슬까요....)\n");

    printf("\n\n");
    printf("\t\t\t\t\t\t\t게임 방법\n");
    printf("\t\t\t\t\t\t\t위방향키와 아래방향키로 플레이 할 수 있다.\n");
    printf("\t\t\t\t\t\t\t너무 물 밑이sk 위로 올라가면 다시 중앙으로 되돌아온다.\n");
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
    printf("\t\t\t\t\t\t\t  ─\n");
    printf("\t\t\t\t\t\t\t│ ★│\n");
    printf("\t\t\t\t\t\t\t  ─\n");
    printf("\t\t\t\t\t\t\t실드!\n");
    printf("\t\t\t\t\t\t\t먹으면 고래가 등에서 물을 뿜어 쉴드를 생성한다.\n");
    printf("\t\t\t\t\t\t\t장애물을 한번 무효로 만들 수 있으며 방어시 실드는 소멸한다.\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t장애물\n\n");
    printf("\t\t\t\t\t\t\t☜(ㆍΘㆍ)э\n");
    printf("\t\t\t\t\t\t\t새다. 아무튼 새다.\n");
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
    printf("\n");
    textcolor(WHITE);
    Sleep(30);
    printf("\t\t\t\t\t\t\t시작하려면 스페이스바를 눌러주세요");

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