# Mini Projects

## Guess Number (숫자 추측 게임)

이 프로젝트는 **C 언어** 로 작성된 숫자 추측 게임입니다. 사용자는 1부터 100 사이의 숫자를 추측하고, 컴퓨터가 선택한 숫자를 맞출 때까지 반복해 시도할 수 있습니다.

### 프로젝트 설명

- 사용자에게 1부터 100 사이의 숫자를 입력받고, 컴퓨터가 랜덤으로 생성한 숫자를 추측하는 게임입니다.
- 각 시도 후 사용자가 입력한 숫자와 컴퓨터의 숫자 비교 결과를 알려줍니다.
- 게임은 사용자가 올바른 숫자를 맞출 때까지 반복됩니다.
- 사용자가 숫자가 아닌 값을 입력하면, 적절한 에러 메시지가 출력되고 재입력을 요구합니다.

### 개발 환경

- 언어 : C
- 컴파일러 : GCC (GNU Compiler Collection)
- 운영체제 : Windows (MinGW 사용)

### 시연 예시

<div style="border:1px solid #ddd; padding: 16px; border-radius: 8px; background-color: black; color: white;">

```plaintext
Guess Number 게임에 온 것을 환영합니다
1부터 100 사이의 숫자를 맞춰보세요!
숫자를 맞춰보세요: d
정수만 입력해주세요.
숫자를 맞춰보세요: 333
1에서 100 사이의 숫자를 입력해주세요.
숫자를 맞춰보세요: 21
입력하신 숫자보다 높습니다!
숫자를 맞춰보세요: 문자여러개
정수만 입력해주세요.
숫자를 맞춰보세요: 60
입력하신 숫자보다 낮습니다!
숫자를 맞춰보세요: 50
입력하신 숫자보다 높습니다!
숫자를 맞춰보세요: 53
입력하신 숫자보다 낮습니다!
숫자를 맞춰보세요: 51
정답을 맞추셨습니다! 정답은 51 였습니다. 총 5 번의 시도를 하셨습니다!
```

</div>

### 사용 방법

1. 컴파일

   - 이 프로젝트는 **C 언어** 로 작성되었으므로, 아래 명령어로 컴파일합니다. (Window MinGW 설치 후 사용 가능)

   ```bash
   minGW32-make
   ```

2. 실행

   - 컴파일 후 아래 명령어로 게임을 실행할 수 있습니다.
     '''
     ./main
     '''

### 구조 및 설계

<div style="border:1px solid #ddd; padding: 16px; border-radius: 8px; background-color: #f9f9f9;">

```plaintext
guess_number
├── game_logic.c        # 게임 로직
├── game_logic.h        # game_logic.c 함수 선언
└── main.c              # 게임 실행
└── makefile            # 프로젝트 빌드 및 컴파일 자동화
```

</div>
