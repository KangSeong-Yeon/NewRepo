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
// 별 위치 변수
int star1_x, star1_y, star2_x, star2_y, star3_x, star3_y;
int star4_x, star4_y, star5_x, star5_y;
int star6_x, star6_y, star7_x, star7_y, star8_x, star8_y, star9_x, star9_y, star10_x, star10_y;
int avoid_star;  // 피한 별 개수 변수
char test[100];  // 한/영키 테스트 변수

void start();  // 게임 시작 전 문구 출력 함수
void initialize();  // 변수 초기화 함수
void display();  // 게임판 출력 함수
void level_easy();  // 쉬움 난이도 실행 함수
void level_normal();  // 중간 난이도 실행 함수
void level_hard();  // 어려움 난이도 실행 함수
void easy_falling_star();  // 쉬움 난이도 별 떨어짐 함수
void normal_falling_star();  // 중간 난이도 별 떨어짐 함수
void hard_falling_star();  // 어려움 난이도 별 떨어짐 함수

void start() {
	printf("===========================================\n");
	printf("  별 피하기 게임(Avoiding the Stars Game)  \n");
	printf("===========================================\n");
	printf("\n");

	// 플레이어 이름 입력
	printf("플레이어 이름을 입력하세요. >> ");
	scanf_s("%s", name, 50);

	// 게임 안내 문구 출력
	printf("\n%s 님! 안녕하세요.\n", name);
	Sleep(1500);
	printf("이 게임은 하늘에서 떨어지는 별들을 피하면 되는 게임입니다.\n");
	Sleep(1500);
	printf("일정 점수에 도달하게 되면 난이도가 상승하여 별의 개수가 늘어나고 떨어지는 속도가 빨라집니다.\n");
	Sleep(1500);
	printf("'a'키 또는 'A'키를 눌러 왼쪽으로 이동할 수 있으며, 'd'키 또는 'D'키를 눌러 오른쪽으로 이동할 수 있습니다.\n");
	Sleep(1500);
	printf("단, 한/영 입력키가 한글로 설정되어있을 시 게임 작동이 원활하게 진행되지 않을 수 있습니다.\n");
	Sleep(1500);
	printf("게임 시작 전 테스트를 통해 한글 입력 상태라면 한/영 입력키를 영어로 설정하여 주십시오.\n>> ");
	scanf_s("%s", test, 100);
	printf("\n좋습니다!\n");
	Sleep(1500);
	printf("그럼 5초의 카운트 후 게임을 시작하겠습니다.\n");
	Sleep(1500);
	printf("행운을 빕니다! GOOD LUCK!\n");
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
	player_x = 5;
	player_y = 8;

	// 별 x좌표 초기 위치
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

	// 별 y좌표 초기 위치
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
			else if (game_x == star6_x && game_y == star6_y) {
				printf("★");
			}
			else if (game_x == star7_x && game_y == star7_y) {
				printf("★");
			}
			else if (game_x == star8_x && game_y == star8_y) {
				printf("★");
			}
			else if (game_x == star9_x && game_y == star9_y) {
				printf("★");
			}
			else if (game_x == star10_x && game_y == star10_y) {
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

	// 게임 화면
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
			|| (player_x == star5_x && player_y == star5_y)
			|| (player_x == star6_x && player_y == star6_y)
			|| (player_x == star7_x && player_y == star7_y)
			|| (player_x == star8_x && player_y == star8_y)
			|| (player_x == star9_x && player_y == star9_y)
			|| (player_x == star10_x && player_y == star10_y))
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