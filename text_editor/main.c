#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

// 1. 사용자가 텍스트를 입력
// 2. 입력한 텍스트를 배열에 저장
// 3. 특정 위치의 문자를 삽입, 삭제, 종료 할 수 있도록 편집 기능 제공
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

// 텍스트 편집기
void edit_text(TextEditor *editor)
{
    printf("editor 개발중");
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