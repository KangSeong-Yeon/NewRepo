// 프로젝트
// 별 피하기 게임(Avoiding the Stars Game)

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAX_STAR    90  // 별이 떨어질 수 있는 최대 개수
#define LEVEL_COUNT    3  // 난이도 상승시 별의 출력 개수 증가량
#define LEVEL_SPEED    15  // 난이도 상승시 별의 떨어지는 속도 증가량

// 별 구조체
typedef struct {
    int x;
    int y;
    int wait;
} STAR;

// 플레이어 구조체
typedef struct {
    int x;
    int y;
} PLAYER;

char name[50];  // 플레이어 이름 변수
char test[100];  // 한/영키 테스트 변수
int score = 0;  // 점수 변수

void start();  // 게임 시작 전 문구 출력 함수
int game(int);  // 게임 실행 함수

// 화면의 특정 위치로 커서를 이동시키는 함수
void gotoxy(int x, int y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void start() {
    printf("=============================================\n");
    printf("=  별 피하기 게임(Avoiding the Stars Game)  =\n");
    printf("=============================================\n");
    printf("\n");

    // 플레이어 이름 입력
    printf("플레이어의 이름을 입력해주세요. >> ");
    scanf_s("%s", name, 50);

    // 게임 안내 문구 출력
    printf("\n%s 님! 안녕하세요.\n", name);
    Sleep(1500);
    printf("이 게임은 하늘에서 떨어지는 별들을 부딪히지 않고 피하면 되는 게임입니다.\n");
    Sleep(1500);
    printf("일정 개수의 별을 피하게 되면 난이도가 상승하여 별의 개수가 늘어나고 떨어지는 속도가 빨라집니다.\n");
    Sleep(1500);
    printf("'a'키 또는 'A'키를 눌러 왼쪽으로 이동할 수 있으며, 'd'키 또는 'D'키를 눌러 오른쪽으로 이동할 수 있습니다.\n");
    Sleep(1500);
    printf("단, 한/영 입력키가 한글로 설정되어있을 시 게임 작동이 원활하게 진행되지 않을 수 있습니다.\n");
    Sleep(1500);
    printf("게임 시작 전 테스트를 통해 한글 입력 상태라면 한/영 입력키를 영어 입력 상태로 설정하여 주십시오.\n>> ");
    scanf_s("%s", test, 100);
    printf("\n좋습니다!\n");
    Sleep(1500);
    printf("그럼 게임을 시작하겠습니다.\n");
    Sleep(1500);
    printf("행운을 빕니다! GOOD LUCK!\n");
    Sleep(1000);

    system("cls");
}

int game(int level)
{
    STAR star[MAX_STAR];  // 별 위치 변수
    PLAYER player;  // 플레이어 위치 변수
    int key;  // 키보드 방향키 입력 변수
    int check = 1;  // 게임 진행 체크 변수
    int avoid_star = 0;  // 피한 별 개수 변수
    int speed = 200 - level * LEVEL_SPEED;  // 별 떨어지는 속도 변수
    int count = level * LEVEL_COUNT;  // 별 출력 개수 변수

    // 난이도 상승에 필요한 별의 개수
    int levelup = 20 + level * 20;  // 난이도 상승 변수

    // 별의 출력 개수가 최댓값을 넘지 않도록 조정
    if (count >= MAX_STAR) {
        count = MAX_STAR - 1;
    }

    // 별의 속도의 최솟값이 10보다 작지 않도록 조정
    if (speed < 10) {
        speed = 10;
    }

    // 플레이어 시작 위치
    player.x = 9;
    player.y = 10;

    // 별 위치 초기화
    for (int i = 0; i < count; i++)
    {
        star[i].x = rand() % 19;
        star[i].y = 1;
        star[i].wait = rand() % 10;
    }

    // 게임 루프
    while (check)
    {
        // 별이 떨어지는 속도에 따른 지연
        Sleep(speed);

        system("cls");

        // 게임 환경 출력
        printf("= 별 피하기 게임   LEVEL %d =", level);

        // 방향키 입력
        while (_kbhit())
        {
            do {
                key = _getch();
            } while (key == 224);
            switch (key) {
            case 'a':
                player.x--;
                if (player.x < 0) {
                    player.x = 0;
                    break;
                }
                else {
                    continue;
                }
            case 'A':
                player.x--;
                if (player.x < 0) {
                    player.x = 0;
                    break;
                }
                else {
                    continue;
                }
            case 'd':
                player.x++;
                if (player.x > 19) {
                    player.x = 19;
                    break;
                }
                else {
                    continue;
                }
            case 'D':
                player.x++;
                if (player.x > 19) {
                    player.x = 19;
                    break;
                }
                else {
                    continue;
                }
            }
        }

        // 플레이어 출력
        gotoxy(player.x, player.y);
        printf("○");

        // 별 떨어짐 처리
        for (int i = 0; i < count; i++)
        {
            // 별이 떨어지기 전에 기다리기
            if (star[i].wait > 0) {
                star[i].wait--;
            }
            else {
                star[i].y++;

                // 별이 바닥과 닿았을 때 처리
                if (star[i].y > 10)
                {
                    star[i].x = rand() % 19;
                    star[i].y = 1;
                    avoid_star++;
                    score++;
                }

                // 현재 점수 출력
                gotoxy(0, 12);
                printf("현재 점수 : %d\n", score);

                // 별 출력
                gotoxy(star[i].x, star[i].y);
                printf("★");

                // 충돌 체크
                if (star[i].x == player.x && star[i].y == player.y)
                {
                    check = 0;
                }
            }
        }
        gotoxy(0, 11);
        printf("#####################");

        // 난이도 상승
        if (avoid_star >= levelup) {
            return 1;
        }
    }

    return 0;
}

int main(void) {
    srand((unsigned)time(NULL));
    int level = 1;
    start();

    while (1)
    {
        system("cls");

        // 게임 시작 전 난이도 출력
        gotoxy(0, 0);
        printf("=============================================\n");
        gotoxy(0, 1);
        printf("=                                           =\n");
        gotoxy(0, 2);
        printf("=  별 피하기 게임(Avoiding the Stars Game)  =\n");
        gotoxy(0, 3);
        printf("=                                           =\n");
        gotoxy(0, 4);
        printf("=                 LEVEL : %d                 =\n", level);
        gotoxy(0, 5);
        printf("=                                           =\n");
        gotoxy(0, 6);
        printf("=============================================\n");

        Sleep(1500);

        // 게임 시작
        if (game(level++) == 0)
        {
            gotoxy(0, 13);
            printf("\n=====================================\n");
            printf("= 게임 오버! 게임이 종료되었습니다. =\n");
            printf("===================================\n");
            break;
        }
    }

    printf("\n%s 님께서 획득하신 최종 점수는 %d점 입니다.\n", name, score);

    return 0;
}