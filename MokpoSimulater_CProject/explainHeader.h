#include<stdio.h>
void ����() {
    system("cls");
    printf("\t\t\t�� �ùķ��̼��� �� ������ �������� �̷���� ������ ������ ������ �� �����Ͽ� ��� ������ ���ñ� ����մϴ�(��, ��ϱ⿡���� �� �� ����).\n");
    printf("\n");
    if (badEnding == 0)
        printf("\t\t\t\t\t\t\t\t\t?? ENDING : ????\n");
    else if (badEnding == 1)
        printf("\t\t\t\t\tBAD ENDING : ���� (�����߽��ϴ�. ������ �ð踦 ���� 8�� 34���̿���. �ƽ�����)\n");
    if (happyEnding == 0)
        printf("\t\t\t\t\t\t\t\t\t??? : ???\n");
    else if (happyEnding == 1)
        printf("\t\t\tHAPPY ENDING : �ع� (�ν��͸� 5���� ���̱���. �ӵ��� ��ü���ϰ� ���� �ھƹ��Ⱦ��. ������ ���ϵ帳�ϴ�! �����츦 ���� �����κ��� ����� ���ּ̱���)\n");
    if (trueEnding == 0)
        printf("\t\t\t\t\t\t\t\t\t??? : ???\n");
    else if (trueEnding == 1)
        printf("\t\t\tTRUE ENDING : ���� (������� �ʼ���! ���ð��� �����ϼ̱���. ������ ����� �ǽ� ���� ���ϵ帳�ϴ�.  ������ ���� �̰� ���� �����̾������....)\n");

    printf("\n\n");
    printf("\t\t\t\t\t\t\t���� ���\n");
    printf("\t\t\t\t\t\t\t������Ű�� �Ʒ�����Ű�� �÷��� �� �� �ִ�.\n");
    printf("\t\t\t\t\t\t\t�ʹ� �� ����sk ���� �ö󰡸� �ٽ� �߾����� �ǵ��ƿ´�.\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t�� ������ ������� �����찡 ����� �б� ������ ��ϴ��� �ùķ��̼��ϴ� ���α׷��̴�!\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t����������\n");
    printf("\t\t\t\t\t\t\t�� �ঢ\n");
    printf("\t\t\t\t\t\t\t����������\n");
    printf("\t\t\t\t\t\t\t�ν�Ʈ!\n");
    printf("\t\t\t\t\t\t\t������ �����̽��ٸ� ������ ������ ��밡���ϴ�. \n");
    printf("\t\t\t\t\t\t\t���� �ӵ��� ������� �������� ��� ��ֹ��� �ı��Ѵ�.\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t  ��\n");
    printf("\t\t\t\t\t\t\t�� �ڦ�\n");
    printf("\t\t\t\t\t\t\t  ��\n");
    printf("\t\t\t\t\t\t\t�ǵ�!\n");
    printf("\t\t\t\t\t\t\t������ ���� ��� ���� �վ� ���带 �����Ѵ�.\n");
    printf("\t\t\t\t\t\t\t��ֹ��� �ѹ� ��ȿ�� ���� �� ������ ���� �ǵ�� �Ҹ��Ѵ�.\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t��ֹ�\n\n");
    printf("\t\t\t\t\t\t\t��(���Ȥ�)��\n");
    printf("\t\t\t\t\t\t\t����. �ƹ�ư ����.\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t��������\n");
    printf("\t\t\t\t\t\t\t��¡���. �÷��̾ ������ Ư¡�̴�.(��¼���)\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t<��))))><\n");
    printf("\t\t\t\t\t\t\t������. ȸ�ĸ����� �� ���ְڴ�.\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t��('=')��\n");
    printf("\t\t\t\t\t\t\t�Դ�. ���԰� ����θ��� ����� '��'��� �θ�����ߴ�.\n");
    printf("\n");
    printf("\n");
    textcolor(WHITE);
    Sleep(30);
    printf("\t\t\t\t\t\t\t�����Ϸ��� �����̽��ٸ� �����ּ���");

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