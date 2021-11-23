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
int star1_x, star1_y, star2_x, star2_y, star3_x, star3_y, star4_x, star4_y, star5_x, star5_y;  // �� ��ġ ����
int avoid_star;  // ���� �� ���� ����

void start();  // ���� ���� �� ���� ��� �Լ�
void initialize();  // ���� �ʱ�ȭ �Լ�
void display();  // ������ ��� �Լ�
void falling_star();  // �� ������ ��� �Լ�

void start() {
	printf("===========================================\n");
	printf("  �� ���ϱ� ����(Avoiding the Stars Game)  \n");
	printf("===========================================\n");
	printf("\n");

	// �÷��̾� �̸� �Է�
	printf("�÷��̾� �̸��� �Է��ϼ���>> ");
	scanf_s("%s", name, 50);

	// ���� �ȳ� ���� ���
	printf("\n%s ��! �ȳ��ϼ���.\n", name);
	Sleep(1500);
	printf("�� ������ �ϴÿ��� �������� ������ ���ϸ� �Ǵ� �����Դϴ�.\n");
	Sleep(1500);
	printf("�׷� 5�� �� ������ �����ϰڽ��ϴ�.\n");
	Sleep(1000);
	printf("\n");

	// ���� ���� ī��Ʈ �ٿ� ǥ��
	for (int i = 5; i > 0; i--) {
		printf("%d\n", i);
		Sleep(900);
	}

	system("cls");
}

void initialize() {
	// �÷��̾� �ʱ� ��ġ
	player_x = 4;
	player_y = 8;

	// �� x��ǥ �ʱ� ��ġ
	star1_x = rand() % 3 + 1;
	star2_x = rand() % 3 + 4;
	star3_x = rand() % 3 + 7;
	star4_x = rand() % 3 + 2;
	star5_x = rand() % 3 + 5;

	// �� y��ǥ �ʱ� ��ġ
	star1_y = (rand() % 3) - 3;
	star2_y = (rand() % 3) - 3;
	star3_y = (rand() % 3) - 3;
	star4_y = (rand() % 3) - 3;
	star5_y = (rand() % 3) - 3;

	// ���� �� ���� �ʱ�ȭ
	avoid_star = 0;
}

void display() {
	// ������ ���
	for (game_y = 0; game_y < 10; game_y++) {
		for (game_x = 0; game_x < 11; game_x++) {
			// ������ �� ���
			if (game_x == 0 || game_x == 10) {
				printf("#");
			}
			else if (game_y == 9) {
				printf("##");
			}

			// �� ���
			else if (game_x == star1_x && game_y == star1_y) {
				printf("��");
			}
			else if (game_x == star2_x && game_y == star2_y) {
				printf("��");
			}
			else if (game_x == star3_x && game_y == star3_y) {
				printf("��");
			}
			else if (game_x == star4_x && game_y == star4_y) {
				printf("��");
			}
			else if (game_x == star5_x && game_y == star5_y) {
				printf("��");
			}

			// �÷��̾� ���
			else if (game_x == player_x && game_y == player_y) {
				printf("��");
			}

			// ������ ���� ���
			else {
				printf("  ");
			}
		}
		putchar('\n');
	}
}

void falling_star() {
	// �� ������ ���
	star1_y++;
	Sleep(1);
	if (star1_y > 8) {
		star1_x = rand() % 3 + 1;
		star1_y = (rand() % 3) - 3;
		avoid_star++;
	}

	star2_y++;
	Sleep(1);
	if (star2_y > 8) {
		star2_x = rand() % 3 + 4;
		star2_y = (rand() % 3) - 3;
		avoid_star++;
	}

	star3_y++;
	Sleep(1);
	if (star3_y > 8) {
		star3_x = rand() % 3 + 7;
		star3_y = (rand() % 3) - 3;
		avoid_star++;
	}

	star4_y++;
	Sleep(1);
	if (star4_y > 8) {
		star4_x = rand() % 3 + 2;
		star4_y = (rand() % 3) - 3;
		avoid_star++;
	}

	star5_y++;
	Sleep(1);
	if (star5_y > 8) {
		star5_x = rand() % 3 + 5;
		star5_y = (rand() % 3) - 3;
		avoid_star++;
	}
}

int main(void) {
	srand((unsigned)time(NULL));

	initialize();
	start();

	// ���� ȭ��
	while (1) {
		system("cls");
		display();
		falling_star();

		// ���� ���� ���
		printf("���� ���� : %d\n", avoid_star);

		// ����Ű �Է�
		if (_kbhit()) {
			key = _getch();

			switch (key) {
			case 'a':
				player_x--;
				if (player_x < 1) {
					player_x = 1;
					break;
				}
				else {
					continue;
				}
			case 'A':
				player_x--;
				if (player_x < 1) {
					player_x = 1;
					break;
				}
				else {
					continue;
				}
			case 'd':
				player_x++;
				if (player_x > 9) {
					player_x = 9;
					break;
				}
				else {
					continue;
				}
			case 'D':
				player_x++;
				if (player_x > 9) {
					player_x = 9;
					break;
				}
				else {
					continue;
				}
			}
		}

		// ���̶� �÷��̾�� �ε����� ���� ����
		if ((player_x == star1_x && player_y == star1_y)
			|| (player_x == star2_x && player_y == star2_y)
			|| (player_x == star3_x && player_y == star3_y)
			|| (player_x == star4_x && player_y == star4_y)
			|| (player_x == star5_x && player_y == star5_y))
		{
			printf("\n===================================\n");
			printf(" ���� ����! ������ ����Ǿ����ϴ�. \n");
			printf("===================================\n");
			break;
		}
	}

	printf("\n%s �Բ��� ȹ���Ͻ� ���� ������ %d�� �Դϴ�.\n", name, avoid_star);

	return 0;
}