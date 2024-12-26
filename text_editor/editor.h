#ifndef EDITOR_H
#define EDITOR_H

#include <stddef.h>  // size_t를 사용하기 위해 필요

/** editor.c 함수 선언 */ 
// TextEditor struct 정의
typedef struct {
    char *buffer;           // 텍스트를 저장하는 동적 배열
    size_t buffer_size;     // 배열 크기
} TextEditor;

// 텍스트 편집기 초기화
void init_editor(TextEditor *editor);

// 텍스트 저장
void save_text(TextEditor *editor, const char *input);

// 텍스트 삽입
void insert_character(TextEditor *editor, char character, size_t position);

// 텍스트 삭제
void delete_character(TextEditor *editor, size_t position);

// 텍스트 출력
void print_text(const TextEditor *editor);

// 텍스트 편집기 메모리 해제
void free_editor(TextEditor *editor);

#endif // EDITOR_H 종료