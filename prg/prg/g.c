// 프로젝트
// 별 피하기 게임(Avoiding the Stars Game)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>

int game_x, game_y;  // 화면 구성 변수
char name[50];  // 플레이어 이름 변수
int player_x, player_y;  // 플레이어 위치 변수
int key;  // 키보드 방향키 입력 변수
int star1_x, star1_y, star2_x, star2_y, star3_x, star3_y, star4_x, star4_y, star5_x, star5_y;  // 별 위치 변수
int avoid_star;  // 피한 별 개수 변수

void start();  // 게임 시작 전 문구 출력 함수
void initialize();  // 변수 초기화 함수
void display();  // 게임판 출력 함수
void falling_star();  // 별 떨어짐 출력 함수

void start() {
	printf("===========================================\n");
	printf("  별 피하기 게임(Avoiding the Stars Game)  \n");
	printf("===========================================\n");
	printf("\n");

	// 플레이어 이름 입력
	printf("플레이어 이름을 입력하세요>> ");
	scanf_s("%s", name, 50);

	// 게임 안내 문구 출력
	printf("\n%s 님! 안녕하세요.\n", name);
	Sleep(1500);
	printf("이 게임은 하늘에서 떨어지는 별들을 피하면 되는 게임입니다.\n");
	Sleep(1500);
	printf("그럼 5초 후 게임을 시작하겠습니다.\n");
	Sleep(1000);
	printf("\n");

	// 게임 시작 카운트 다운 표시
	for (int i = 5; i > 0; i--) {
		printf("%d\n", i);
		Sleep(900);
	}

	system("cls");
}

void initialize() {
	// 플레이어 초기 위치
	player_x = 4;
	player_y = 8;

	// 별 x좌표 초기 위치
	star1_x = rand() % 3 + 1;
	star2_x = rand() % 3 + 4;
	star3_x = rand() % 3 + 7;
	star4_x = rand() % 3 + 2;
	star5_x = rand() % 3 + 5;

	// 별 y좌표 초기 위치
	star1_y = (rand() % 3) - 3;
	star2_y = (rand() % 3) - 3;
	star3_y = (rand() % 3) - 3;
	star4_y = (rand() % 3) - 3;
	star5_y = (rand() % 3) - 3;

	// 피한 별 개수 초기화
	avoid_star = 0;
}

void display() {
	// 게임판 출력
	for (game_y = 0; game_y < 10; game_y++) {
		for (game_x = 0; game_x < 11; game_x++) {
			// 게임판 벽 출력
			if (game_x == 0 || game_x == 10) {
				printf("#");
			}
			else if (game_y == 9) {
				printf("##");
			}

			// 별 출력
			else if (game_x == star1_x && game_y == star1_y) {
				printf("★");
			}
			else if (game_x == star2_x && game_y == star2_y) {
				printf("★");
			}
			else if (game_x == star3_x && game_y == star3_y) {
				printf("★");
			}
			else if (game_x == star4_x && game_y == star4_y) {
				printf("★");
			}
			else if (game_x == star5_x && game_y == star5_y) {
				printf("★");
			}

			// 플레이어 출력
			else if (game_x == player_x && game_y == player_y) {
				printf("○");
			}

			// 게임판 공백 출력
			else {
				printf("  ");
			}
		}
		putchar('\n');
	}
}

void falling_star() {
	// 별 떨어짐 출력
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

	// 게임 화면
	while (1) {
		system("cls");
		display();
		falling_star();

		// 현재 점수 출력
		printf("현재 점수 : %d\n", avoid_star);

		// 방향키 입력
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

		// 별이랑 플레이어랑 부딪히면 게임 종료
		if ((player_x == star1_x && player_y == star1_y)
			|| (player_x == star2_x && player_y == star2_y)
			|| (player_x == star3_x && player_y == star3_y)
			|| (player_x == star4_x && player_y == star4_y)
			|| (player_x == star5_x && player_y == star5_y))
		{
			printf("\n===================================\n");
			printf(" 게임 오버! 게임이 종료되었습니다. \n");
			printf("===================================\n");
			break;
		}
	}

	printf("\n%s 님께서 획득하신 최종 점수는 %d점 입니다.\n", name, avoid_star);

	return 0;
}