// ������Ʈ
// �� ���ϱ� ����(Avoiding the Stars Game)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>

int main(void) {
	int w, x, y, z;	// ȭ�� ���� ����
	int player_x, player_y;	// �÷��̾� ��ġ ����
	int key;	// Ű���� ����Ű �Է� ����
	int star1_x, star1_y, star2_x, star2_y, star3_x, star3_y;	// �� 3�� ��ġ ����
	int avoid_star;	// ���� �� ���� ����

	// �÷��̾� �ʱ� ��ġ
	player_x = 5;
	player_y = 9;

	// �� x��ǥ �ʱ� ��ġ
	srand((unsigned)time(NULL));
	star1_x = rand() % 3;
	star2_x = rand() % 3 + 3;
	star3_x = rand() % 3 + 6;

	// �� y��ǥ �ʱ� ��ġ


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

	while (1) {
		// ���� ���� ȭ��

	/*
	// �÷��̾� �̵�
	char player[x][y] = { 0 };
	char input = getchar();
	if (input == 'a' || input == 'A') {
		//player[x]--;
	}
	*/

	// ���� ����
	// ���̶� �÷��̾�� �ε����� -> ���� ���� �� ���� ���� ���
		if ((player_x == star1_x && player_y == star1_y) || (player_x == star2_x && player_y == star2_y) || (player_x == star3_x && player_y == star3_y))
		{
			printf("���� ����! ������ ����Ǿ����ϴ�.\n");
			break;
		}
	}

	return 0;
}