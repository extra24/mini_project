#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

/** 텍스트 편집기 */

// 텍스트 편집기 초기화 (포인터* 안의 변수 불러오기: ->)
void init_editor(TextEditor *editor)
{
    editor->buffer = NULL;
    editor->buffer_size = 0;
}

// 텍스트 저장
// malloc : 메모리 동적 할당 함수
void save_text(TextEditor *editor, const char *input)
{
    size_t length = strlen(input);
    // *input과 같은 동적 메모리 공간을 할당시켜줌
    editor->buffer = (char *)malloc((length + 1) * sizeof(char)); 
    if (editor->buffer == NULL) 
    {   
        // 할당 오류 메시지 출력
        perror("Failed to allocate memory\n");
        exit(1);
    }
    // buffer에 input 값 복사
    strcpy(editor->buffer, input);
    editor->buffer_size = length;   
}

// 텍스트 삽입
void insert_character(TextEditor *editor, char character, size_t position)
{
    // 텍스트를 삽입하려는 위치가 텍스트 길이 보다 크면 return
    if (position > editor->buffer_size)
    {
        printf("Invalid Position\n");
        return;
    }
    editor->buffer = (char *)realloc(editor->buffer, (editor->buffer_size + 2) * sizeof(char));
    if (editor->buffer == NULL) 
    {   
        // 재할당 오류 메시지 출력
        perror("Failed to reallocate memory\n");
        exit(1);
    }
    // memmove 함수에 char의 주소값을 넣기 위해 & 사용 
    memmove(&editor->buffer[position + 1], &editor->buffer[position], editor->buffer_size - position + 1);
    editor->buffer[position] = character;
    editor->buffer_size++;
}

// 텍스트 삭제
void delete_character(TextEditor *editor, size_t position)
{
    if (position >= editor->buffer_size)
    {
        printf("Invalid position\n");
        return;
    }
     memmove(&editor->buffer[position], &editor->buffer[position + 1], editor->buffer_size - position);
     editor->buffer_size--;
     editor->buffer =  (char *)realloc(editor->buffer, (editor->buffer_size + 1) * sizeof(char));
}

// 텍스트 출력 
void print_text(const TextEditor *editor)
{
    if (editor->buffer == NULL)
    {
        printf("입력된 텍스트가 없습니다.\n");
        return;
    }
    printf("현재 텍스트: %s\n", editor->buffer);
}

// 텍스트 편집기 메모리 해제
void free_editor(TextEditor *editor)
{
    free(editor->buffer);
    editor->buffer = NULL;
    editor->buffer_size = 0;
}