// ������Ʈ
// �� ���ϱ� ����(Avoiding the Stars Game)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>

int game_x, game_y;  // ȭ�� ���� ����
char name[50];  // �÷��̾� �̸� ����
int player_x, player_y;  // �÷��̾� ��ġ ����
int key;  // Ű���� ����Ű �Է� ����
int star1_x, star1_y, star2_x, star2_y, star3_x, star3_y;  // �� 3�� ��ġ ����
int avoid_star;  // ���� �� ���� ����

void start();  // ���� ���� �� ���� ��� �Լ�
void initialize();  // ���� �ʱ�ȭ �Լ�

void start() {
	printf("===== �� ���ϱ� ���� (Avoiding the Stars Game) =====\n");
	printf("\n");

	// �÷��̾� �̸� �Է�
	printf("�÷��̾� �̸��� �Է��ϼ���>> ");
	scanf_s("%s", name, 50);

	// ���� �ȳ� ���� ���
	printf("\n%s��! �ȳ��ϼ���.\n", name);
	Sleep(1500);
	printf("�� ������ �ϴÿ��� �������� ������ ���ϸ� �Ǵ� �����Դϴ�.\n");
	Sleep(1500);
	printf("�׷� ������ �����մϴ�.\n");
	Sleep(1000);
	printf("\n");

	// ���� ���� ī��Ʈ �ٿ� ǥ��
	for (int i = 5; i > 0; i--) {
		printf("%d\n", i);
		Sleep(900);
	}

	printf("\n===== ���� ���� (Game Start) =====");
	Sleep(1000);
	system("cls");
}

void initialize() {
	// �÷��̾� �ʱ� ��ġ
	player_x = 4;
	player_y = 8;

	// �� x��ǥ �ʱ� ��ġ
	// ������ ���� 3���� ������ �ڸ����� �����.
	srand((unsigned)time(NULL));
	star1_x = rand() % 3;
	star2_x = rand() % 3 + 3;
	star3_x = rand() % 3 + 6;

	// �� y��ǥ �ʱ� ��ġ
	// ���� �׻� �ٸ��� �������� �� ǥ���ϱ� ���� ���� �������� ��ġ : -2~0���� �������� ����
	star1_y = (rand() % 3) - 3;
	star2_y = (rand() % 3) - 3;
	star3_y = (rand() % 3) - 3;

	// ���� �� ���� �ʱ�ȭ
	avoid_star = 0;
}

int main(void) {
	initialize();
	start();

	// ���� ���� ȭ��
	while (1) {
		system("cls");

		// ������ ���
		for (game_y = 0; game_y < 9; game_y++) {
			for (game_x = 0; game_x < 9; game_x++) {
				// �� ���
				if (game_x == star1_x && game_y == star1_y) {
					printf("��");
				}
				else if (game_x == star2_x && game_y == star2_y) {
					printf("��");
				}
				else if (game_x == star3_x && game_y == star3_y) {
					printf("��");
				}

				// �÷��̾� ���
				else if (game_x == player_x && game_y == player_y) {
					printf("@");
				}

				// ������ ���� ���
				else {
					printf("*");
				}
			}
			putchar('\n');
		}

		// �� ������ ���
		star1_y++;
		Sleep(100);
		if (star1_y > 8) {
			star1_x = rand() % 3;
			star1_y = (rand() % 3) - 3;
			avoid_star++;
		}

		star2_y++;
		Sleep(100);
		if (star2_y > 8) {
			star2_x = rand() % 3 + 3;
			star2_y = (rand() % 3) - 3;
			avoid_star++;
		}

		star3_y++;
		Sleep(100);
		if (star3_y > 8) {
			star3_x = rand() % 3 + 6;
			star3_y = (rand() % 3) - 3;
			avoid_star++;
		}

		// ����Ű �Է�
		if (_kbhit()) {
			key = _getch();

			switch (key) {
			case 'a':
				player_x--;
				if (player_x < 0) {
					player_x = 0;
					break;
				}
				else {
					continue;
				}
			case 'A':
				player_x--;
				if (player_x < 0) {
					player_x = 0;
					break;
				}
				else {
					continue;
				}
			case 'd':
				player_x++;
				if (player_x > 8) {
					player_x = 8;
					break;
				}
				else {
					continue;
				}
			case 'D':
				player_x++;
				if (player_x > 8) {
					player_x = 8;
					break;
				}
				else {
					continue;
				}
			}
		}

		// ���̶� �÷��̾�� �ε����� ���� ����
		if ((player_x == star1_x && player_y == star1_y) || (player_x == star2_x && player_y == star2_y) || (player_x == star3_x && player_y == star3_y))
		{
			printf("���� ����! ������ ����Ǿ����ϴ�.\n");
			break;
		}
	}

	printf("\n%s���� ������ %d�� �Դϴ�.\n", name, avoid_star);

	return 0;
}