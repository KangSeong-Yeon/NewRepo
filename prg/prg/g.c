// ������Ʈ
// �� ���ϱ� ����(Avoiding the Stars Game)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>

// star_x : '��' �迭�� x��ǥ ��ġ
// star_y : '��' �迭�� y��ǥ ��ġ
// player[x][y] : �÷��̾� ��ġ
// player_x : �÷��̾� �迭�� x��ǥ ��ġ
// player_y : �÷��̾� �迭�� y��ǥ ��ġ

int main(void) {
	// ���� ����
	printf("===== �� ���ϱ� ���� (Avoiding the Stars Game) =====\n");
	printf("\n");

	// �÷��̾� �̸� �Է�
	char name[50];
	printf("�÷��̾� �̸��� �Է��ϼ���>> ");
	scanf_s("%s", name, sizeof(name));

	// ���� �ȳ� ���� ���
	printf("\n%s��! �ȳ��ϼ���.\n", name);
	Sleep(1500);	// ���� ���� ��±��� ��� ��ٸ���
	printf("�� ������ �ϴÿ��� �������� ������ �ִ��� ����, ���� ���ϸ� �Ǵ� �����Դϴ�.\n");
	Sleep(1500);	// ���� ���� ��±��� ��� ��ٸ���
	printf("�׷� ������ �����մϴ�.\n");
	Sleep(1000);	// ���� ���� ��±��� ��� ��ٸ���

	// ���� ���� ī��Ʈ �ٿ� ǥ��
	for (int i = 5; i > 0; i--) {
		printf("%d\n", i);
		Sleep(900);
	}

	printf("===���� ����===");	// ���� ���� ���� ���
	Sleep(1000);	// ������ ��� ������ ��� ��ٸ���
	system("cls");	// ������ ����ϱ� ���� ȭ�� ����

	/*
	// �� ���� ��ġ ����
	char star[50];
	srand((unsigned)time(NULL));
	int star_1 = rand() % 50 + 1;
	int star_2 = rand() % 50 + 1;
	int star_3 = rand() % 50 + 1;
	for (int i = 0; i < 3; i++) {
		star[i]=("��");
	}
	printf("%s\n", star);

	// �÷��̾� �̵�
	char player[x][y] = { 0 };
	char input = getchar();
	if (input == 'a' || input == 'A') {
		//player[x]--;
	}
	*/

	// ���� ����
	// ���̶� �÷��̾�� �ε����� -> ���� ���� �� ���� ���� ���
	//if (star == player) {
	//	printf("���� ����! ������ ����Ǿ����ϴ�.\n");
	//}

	return 0;
}