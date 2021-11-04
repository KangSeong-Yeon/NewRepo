// 프로젝트
// 별 피하기 게임(Avoiding the Stars Game)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>

int main(void) {
	int w, x, y, z;	// 화면 구성 변수
	int player_x, player_y;	// 플레이어 위치 변수
	int key;	// 키보드 방향키 입력 변수
	int star1_x, star1_y, star2_x, star2_y, star3_x, star3_y;	// 별 3개 위치 변수
	int avoid_star;	// 피한 별 개수 변수

	// 플레이어 초기 위치
	player_x = 5;
	player_y = 9;

	// 별 x좌표 초기 위치
	srand((unsigned)time(NULL));
	star1_x = rand() % 3;
	star2_x = rand() % 3 + 3;
	star3_x = rand() % 3 + 6;

	// 별 y좌표 초기 위치


	// 게임 시작
	printf("===== 별 피하기 게임 (Avoiding the Stars Game) =====\n");
	printf("\n");

	// 플레이어 이름 입력
	char name[50];
	printf("플레이어 이름을 입력하세요>> ");
	scanf_s("%s", name, sizeof(name));

	// 게임 안내 문구 출력
	printf("\n%s님! 안녕하세요.\n", name);
	Sleep(1500);	// 다음 문구 출력까지 잠시 기다리기
	printf("이 게임은 하늘에서 떨어지는 별들을 최대한 오래, 많이 피하면 되는 게임입니다.\n");
	Sleep(1500);	// 다음 문구 출력까지 잠시 기다리기
	printf("그럼 게임을 시작합니다.\n");
	Sleep(1000);	// 다음 문구 출력까지 잠시 기다리기

	// 게임 시작 카운트 다운 표시
	for (int i = 5; i > 0; i--) {
		printf("%d\n", i);
		Sleep(900);
	}

	printf("===게임 시작===");	// 게임 시작 문구 출력
	Sleep(1000);	// 게임판 출력 전까지 잠시 기다리기
	system("cls");	// 게임판 출력하기 위해 화면 지움

	while (1) {
		// 게임 시작 화면

	/*
	// 플레이어 이동
	char player[x][y] = { 0 };
	char input = getchar();
	if (input == 'a' || input == 'A') {
		//player[x]--;
	}
	*/

	// 게임 종료
	// 별이랑 플레이어랑 부딪히면 -> 게임 오버 후 게임 종료 출력
		if ((player_x == star1_x && player_y == star1_y) || (player_x == star2_x && player_y == star2_y) || (player_x == star3_x && player_y == star3_y))
		{
			printf("게임 오버! 게임이 종료되었습니다.\n");
			break;
		}
	}

	return 0;
}