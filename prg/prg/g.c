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
// �� ��ġ ����
int star1_x, star1_y, star2_x, star2_y, star3_x, star3_y;
int star4_x, star4_y, star5_x, star5_y;
int star6_x, star6_y, star7_x, star7_y, star8_x, star8_y, star9_x, star9_y, star10_x, star10_y;
int avoid_star;  // ���� �� ���� ����
char test[100];  // ��/��Ű �׽�Ʈ ����

void start();  // ���� ���� �� ���� ��� �Լ�
void initialize();  // ���� �ʱ�ȭ �Լ�
void display();  // ������ ��� �Լ�
void level_easy();  // ���� ���̵� ���� �Լ�
void level_normal();  // �߰� ���̵� ���� �Լ�
void level_hard();  // ����� ���̵� ���� �Լ�
void easy_falling_star();  // ���� ���̵� �� ������ �Լ�
void normal_falling_star();  // �߰� ���̵� �� ������ �Լ�
void hard_falling_star();  // ����� ���̵� �� ������ �Լ�

void start() {
	printf("===========================================\n");
	printf("  �� ���ϱ� ����(Avoiding the Stars Game)  \n");
	printf("===========================================\n");
	printf("\n");

	// �÷��̾� �̸� �Է�
	printf("�÷��̾� �̸��� �Է��ϼ���. >> ");
	scanf_s("%s", name, 50);

	// ���� �ȳ� ���� ���
	printf("\n%s ��! �ȳ��ϼ���.\n", name);
	Sleep(1500);
	printf("�� ������ �ϴÿ��� �������� ������ ���ϸ� �Ǵ� �����Դϴ�.\n");
	Sleep(1500);
	printf("���� ������ �����ϰ� �Ǹ� ���̵��� ����Ͽ� ���� ������ �þ�� �������� �ӵ��� �������ϴ�.\n");
	Sleep(1500);
	printf("'a'Ű �Ǵ� 'A'Ű�� ���� �������� �̵��� �� ������, 'd'Ű �Ǵ� 'D'Ű�� ���� ���������� �̵��� �� �ֽ��ϴ�.\n");
	Sleep(1500);
	printf("��, ��/�� �Է�Ű�� �ѱ۷� �����Ǿ����� �� ���� �۵��� ��Ȱ�ϰ� ������� ���� �� �ֽ��ϴ�.\n");
	Sleep(1500);
	printf("���� ���� �� �׽�Ʈ�� ���� �ѱ� �Է� ���¶�� ��/�� �Է�Ű�� ����� �����Ͽ� �ֽʽÿ�.\n>> ");
	scanf_s("%s", test, 100);
	printf("\n�����ϴ�!\n");
	Sleep(1500);
	printf("�׷� 5���� ī��Ʈ �� ������ �����ϰڽ��ϴ�.\n");
	Sleep(1500);
	printf("����� ���ϴ�! GOOD LUCK!\n");
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
	player_x = 5;
	player_y = 8;

	// �� x��ǥ �ʱ� ��ġ
	star1_x = rand() % 3 + 1;
	star2_x = rand() % 3 + 4;
	star3_x = rand() % 3 + 7;
	star4_x = rand() % 5 + 1;
	star5_x = rand() % 5 + 5;
	star6_x = rand() % 4 + 1;
	star7_x = rand() % 4 + 6;
	star8_x = rand() % 5 + 3;
	star9_x = rand() % 2 + 1;
	star10_x = rand() % 2 + 8;

	// �� y��ǥ �ʱ� ��ġ
	star1_y = (rand() % 3) - 4;
	star2_y = (rand() % 3) - 4;
	star3_y = (rand() % 3) - 4;
	star4_y = (rand() % 3) - 4;
	star5_y = (rand() % 3) - 4;
	star6_y = (rand() % 3) - 4;
	star7_y = (rand() % 3) - 4;
	star8_y = (rand() % 3) - 4;
	star9_y = (rand() % 3) - 4;
	star10_y = (rand() % 3) - 4;

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
			else if (game_x == star6_x && game_y == star6_y) {
				printf("��");
			}
			else if (game_x == star7_x && game_y == star7_y) {
				printf("��");
			}
			else if (game_x == star8_x && game_y == star8_y) {
				printf("��");
			}
			else if (game_x == star9_x && game_y == star9_y) {
				printf("��");
			}
			else if (game_x == star10_x && game_y == star10_y) {
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

void easy_falling_star() {
	star1_y++;
	Sleep(20);
	if (star1_y > 8) {
		star1_x = rand() % 3 + 1;
		star1_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star2_y++;
	Sleep(20);
	if (star2_y > 8) {
		star2_x = rand() % 3 + 4;
		star2_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star3_y++;
	Sleep(20);
	if (star3_y > 8) {
		star3_x = rand() % 3 + 7;
		star3_y = (rand() % 3) - 4;
		avoid_star++;
	}
}

void normal_falling_star() {
	star1_y++;
	Sleep(8);
	if (star1_y > 8) {
		star1_x = rand() % 3 + 1;
		star1_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star2_y++;
	Sleep(8);
	if (star2_y > 8) {
		star2_x = rand() % 3 + 4;
		star2_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star3_y++;
	Sleep(8);
	if (star3_y > 8) {
		star3_x = rand() % 3 + 7;
		star3_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star4_y++;
	Sleep(8);
	if (star4_y > 8) {
		star4_x = rand() % 5 + 1;
		star4_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star5_y++;
	Sleep(8);
	if (star5_y > 8) {
		star5_x = rand() % 5 + 5;
		star5_y = (rand() % 3) - 4;
		avoid_star++;
	}
}

void hard_falling_star() {
	star1_y++;
	Sleep(1);
	if (star1_y > 8) {
		star1_x = rand() % 3 + 1;
		star1_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star2_y++;
	Sleep(1);
	if (star2_y > 8) {
		star2_x = rand() % 3 + 4;
		star2_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star3_y++;
	Sleep(1);
	if (star3_y > 8) {
		star3_x = rand() % 3 + 7;
		star3_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star4_y++;
	Sleep(1);
	if (star4_y > 8) {
		star4_x = rand() % 5 + 1;
		star4_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star5_y++;
	Sleep(1);
	if (star5_y > 8) {
		star5_x = rand() % 5 + 5;
		star5_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star6_y++;
	Sleep(1);
	if (star6_y > 8) {
		star6_x = rand() % 4 + 1;
		star6_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star7_y++;
	Sleep(1);
	if (star7_y > 8) {
		star7_x = rand() % 4 + 6;
		star7_y = (rand() % 3) - 4;
		avoid_star++;
	}

	star8_y++;
	Sleep(1);
	if (star8_y > 8) {
		star8_x = rand() % 5 + 3;
		star8_y = (rand() % 3) - 4;
	}

	star9_y++;
	Sleep(1);
	if (star8_y > 8) {
		star8_x = rand() % 2 + 1;
		star8_y = (rand() % 3) - 4;
	}

	star10_y++;
	Sleep(1);
	if (star8_y > 8) {
		star8_x = rand() % 2 + 8;
		star8_y = (rand() % 3) - 4;
	}
}

void level_easy() {
	easy_falling_star();
}

void level_normal() {
	normal_falling_star();
}

void level_hard() {
	hard_falling_star();
}

int main(void) {
	srand((unsigned)time(NULL));
	initialize();
	start();

	// ���� ȭ��
	while (1) {
		system("cls");
		display();

		if (avoid_star < 50) {
			level_easy();
		}
		else if (avoid_star < 150) {
			level_normal();
		}
		else {
			level_hard();
		}

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
			|| (player_x == star5_x && player_y == star5_y)
			|| (player_x == star6_x && player_y == star6_y)
			|| (player_x == star7_x && player_y == star7_y)
			|| (player_x == star8_x && player_y == star8_y)
			|| (player_x == star9_x && player_y == star9_y)
			|| (player_x == star10_x && player_y == star10_y))
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