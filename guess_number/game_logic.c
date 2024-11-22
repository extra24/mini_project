#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h" // 함수 선언

// 숫자 생성, 사용자 입력, 힌트 제공 로직 구현
void start_game()
{
    int gNum = 0; // 사용자가 입력하는 숫자
    int cnt = 0; // 시도 횟수

    // 랜덤 숫자 생성
    srand(time(NULL));
    int randomNum = rand() % 100 + 1; // a~b 사이 범위 : rand() % (b - a + 1) + a

    // printf("힌트: %d\n", randomNum);

    // 게임 루프
    do 
    {
        printf("숫자를 맞춰보세요: ");
        if(scanf("%d", &gNum) != 1)
        {
            printf("정수만 입력해주세요.\n");
            while(getchar() != '\n'); // 버퍼 지우기
            continue;
        }
        else if(1 > gNum || 100 < gNum)
        {
            printf("1에서 100 사이의 숫자를 입력해주세요.\n");
            while(getchar() != '\n'); // 버퍼 지우기
            continue;
        }
        cnt++;

        if(gNum < randomNum) 
        {
            printf("입력하신 숫자보다 높습니다!\n");
        }
        else if(gNum > randomNum)
        {
            printf("입력하신 숫자보다 낮습니다!\n");
        }
        else
        {
            printf("정답을 맞추셨습니다! 정답은 %d 였습니다. 총 %d 번의 시도를 하셨습니다!\n", randomNum, cnt);
        }
    }
    while(gNum != randomNum);
}