#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

// 1. 사용자가 텍스트를 입력
// 2. 입력한 텍스트를 배열에 저장
// 3. 특정 위치의 문자를 추가, 삭제, 종료 할 수 있도록 편집 기능 제공
// 4. 삽입 또는 삭제하고자 하는 문자는 한 글자씩만 가능하도록 제약 걸어두기

// 텍스트 입력받기
void get_input(TextEditor *editor)
{
    char input[1000]; // 임시 배열
    printf("텍스트를 입력하세요: ");
    scanf("%[^\n]", input);     // 줄바꿈 전까지 입력받기
    getchar();  // 남아있는 '\n'을 제거

    save_text(editor, input);
}

// 텍스트 편집기 (추가, 삭제, 편집기 종료)
void edit_text(TextEditor *editor)
{
    int action;
    size_t position;
    char new_char;

    while(1)
    {
        printf("사용할 편집기능을 선택해주세요: \n1. 문자 추가\n2. 텍스트 삭제\n3. 편집기 종료\n");
        printf("입력: ");
        if (scanf("%d", &action) != 1 || action < 1 || action > 3 )
        {
            printf("1, 2, 3 숫자 중 하나만 입력해주세요.\n");
            while (getchar() != '\n'); // 버퍼 정리
            continue;
        }

        if (action == 1)
        {
            // 추가
            printf("추가하려는 문자의 위치를 입력해주세요 (0 ~ %zu): ", editor->buffer_size);
            scanf("%zu", &position);
            getchar(); 
            if (position > editor->buffer_size)
            {
                printf("위치를 잘못 입력하였습니다. 범위 내에서 입력해주세요.\n");
                while (getchar() != '\n'); // 버퍼 정리
                continue;
            }
            printf("추가하려는 문자를 입력해주세요: ");
            if (scanf("%c", &new_char) != 1 || getchar() != '\n') 
            {   
                printf("문자는 하나만 입력하셔야 합니다. \n");
                while (getchar() != '\n'); // 버퍼 정리
                continue;
            } 
            insert_character(editor, new_char, position);
            print_text(editor);
        }
        else if(action == 2)
        {
            // 삭제
            
        }
        else if(action == 3)
        {
            // 편집 종료
            break;  
        }
    }
    
}

int main()
{
    TextEditor editor;
    init_editor(&editor);

    // 사용자에게 텍스트 입력받기
    get_input(&editor);

    // 입력된 텍스트 보여주기
    print_text(&editor);

    // 텍스트 편집기 보여주기
    edit_text(&editor);

    // 메모리 해제
    free_editor(&editor);
    return 0;
}