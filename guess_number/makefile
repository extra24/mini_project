# 컴파일러 설정
CC = gcc

# 컴파일 옵션
CFLAGS = -Wall -Wextra -std=c11

# 소스 및 실행 파일
SRCS = main.c game_logic.c
OBJS = $(SRCS:.c=.o)
TARGET = main

# 빌드 규칙
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	del $(OBJS) $(TARGET).exe

# 추가 규칙
.PHONY: all clean