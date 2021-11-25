// ������Ʈ
// �� ���ϱ� ����(Avoiding the Stars Game)

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAX_STAR    90  // ���� ������ �� �ִ� �ִ� ����
#define LEVEL_COUNT    3  // ���̵� ��½� ���� ��� ���� ������
#define LEVEL_SPEED    15  // ���̵� ��½� ���� �������� �ӵ� ������

// �� ����ü
typedef struct {
    int x;
    int y;
    int wait;
} STAR;

// �÷��̾� ����ü
typedef struct {
    int x;
    int y;
} PLAYER;

char name[50];  // �÷��̾� �̸� ����
char test[100];  // ��/��Ű �׽�Ʈ ����
int score = 0;  // ���� ����

void start();  // ���� ���� �� ���� ��� �Լ�
int game(int);  // ���� ���� �Լ�

// ȭ���� Ư�� ��ġ�� Ŀ���� �̵���Ű�� �Լ�
void gotoxy(int x, int y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void start() {
    printf("=============================================\n");
    printf("=  �� ���ϱ� ����(Avoiding the Stars Game)  =\n");
    printf("=============================================\n");
    printf("\n");

    // �÷��̾� �̸� �Է�
    printf("�÷��̾��� �̸��� �Է����ּ���. >> ");
    scanf_s("%s", name, 50);

    // ���� �ȳ� ���� ���
    printf("\n%s ��! �ȳ��ϼ���.\n", name);
    Sleep(1500);
    printf("�� ������ �ϴÿ��� �������� ������ �ε����� �ʰ� ���ϸ� �Ǵ� �����Դϴ�.\n");
    Sleep(1500);
    printf("���� ������ ���� ���ϰ� �Ǹ� ���̵��� ����Ͽ� ���� ������ �þ�� �������� �ӵ��� �������ϴ�.\n");
    Sleep(1500);
    printf("'a'Ű �Ǵ� 'A'Ű�� ���� �������� �̵��� �� ������, 'd'Ű �Ǵ� 'D'Ű�� ���� ���������� �̵��� �� �ֽ��ϴ�.\n");
    Sleep(1500);
    printf("��, ��/�� �Է�Ű�� �ѱ۷� �����Ǿ����� �� ���� �۵��� ��Ȱ�ϰ� ������� ���� �� �ֽ��ϴ�.\n");
    Sleep(1500);
    printf("���� ���� �� �׽�Ʈ�� ���� �ѱ� �Է� ���¶�� ��/�� �Է�Ű�� ���� �Է� ���·� �����Ͽ� �ֽʽÿ�.\n>> ");
    scanf_s("%s", test, 100);
    printf("\n�����ϴ�!\n");
    Sleep(1500);
    printf("�׷� ������ �����ϰڽ��ϴ�.\n");
    Sleep(1500);
    printf("����� ���ϴ�! GOOD LUCK!\n");
    Sleep(1000);

    system("cls");
}

int game(int level)
{
    STAR star[MAX_STAR];  // �� ��ġ ����
    PLAYER player;  // �÷��̾� ��ġ ����
    int key;  // Ű���� ����Ű �Է� ����
    int check = 1;  // ���� ���� üũ ����
    int avoid_star = 0;  // ���� �� ���� ����
    int speed = 200 - level * LEVEL_SPEED;  // �� �������� �ӵ� ����
    int count = level * LEVEL_COUNT;  // �� ��� ���� ����

    // ���̵� ��¿� �ʿ��� ���� ����
    int levelup = 20 + level * 20;  // ���̵� ��� ����

    // ���� ��� ������ �ִ��� ���� �ʵ��� ����
    if (count >= MAX_STAR) {
        count = MAX_STAR - 1;
    }

    // ���� �ӵ��� �ּڰ��� 10���� ���� �ʵ��� ����
    if (speed < 10) {
        speed = 10;
    }

    // �÷��̾� ���� ��ġ
    player.x = 9;
    player.y = 10;

    // �� ��ġ �ʱ�ȭ
    for (int i = 0; i < count; i++)
    {
        star[i].x = rand() % 19;
        star[i].y = 1;
        star[i].wait = rand() % 10;
    }

    // ���� ����
    while (check)
    {
        // ���� �������� �ӵ��� ���� ����
        Sleep(speed);

        system("cls");

        // ���� ȯ�� ���
        printf("= �� ���ϱ� ����   LEVEL %d =", level);

        // ����Ű �Է�
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

        // �÷��̾� ���
        gotoxy(player.x, player.y);
        printf("��");

        // �� ������ ó��
        for (int i = 0; i < count; i++)
        {
            // ���� �������� ���� ��ٸ���
            if (star[i].wait > 0) {
                star[i].wait--;
            }
            else {
                star[i].y++;

                // ���� �ٴڰ� ����� �� ó��
                if (star[i].y > 10)
                {
                    star[i].x = rand() % 19;
                    star[i].y = 1;
                    avoid_star++;
                    score++;
                }

                // ���� ���� ���
                gotoxy(0, 12);
                printf("���� ���� : %d\n", score);

                // �� ���
                gotoxy(star[i].x, star[i].y);
                printf("��");

                // �浹 üũ
                if (star[i].x == player.x && star[i].y == player.y)
                {
                    check = 0;
                }
            }
        }
        gotoxy(0, 11);
        printf("#####################");

        // ���̵� ���
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

        // ���� ���� �� ���̵� ���
        gotoxy(0, 0);
        printf("=============================================\n");
        gotoxy(0, 1);
        printf("=                                           =\n");
        gotoxy(0, 2);
        printf("=  �� ���ϱ� ����(Avoiding the Stars Game)  =\n");
        gotoxy(0, 3);
        printf("=                                           =\n");
        gotoxy(0, 4);
        printf("=                 LEVEL : %d                 =\n", level);
        gotoxy(0, 5);
        printf("=                                           =\n");
        gotoxy(0, 6);
        printf("=============================================\n");

        Sleep(1500);

        // ���� ����
        if (game(level++) == 0)
        {
            gotoxy(0, 13);
            printf("\n=====================================\n");
            printf("= ���� ����! ������ ����Ǿ����ϴ�. =\n");
            printf("===================================\n");
            break;
        }
    }

    printf("\n%s �Բ��� ȹ���Ͻ� ���� ������ %d�� �Դϴ�.\n", name, score);

    return 0;
}