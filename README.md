myshell
========
시스템 프로그래밍 텀 프로젝트. 미완성으로 끝났지만 기본적인 설계나 참조 등을 적기로 함.

기본 파일 설명
--------------
Makefile : make할 수 있게 되어있음.
mybash.c : main 함수 존재. 내부적인 기능은 사실 상 없고 기본적인 틀만 가지고 있음.
mybash.h : 다른 c 파일들의 내용물을 받아서 mybash.c에 전달함.
promptprint.c : 지속적으로 터미널에 프롬프트를 출력함.
reader.c : 입력된 명령문을 읽고 버퍼에 저장함.
parser.c : 저장된 명령문을 parsing 함.
execute.c : parsing된 명령문을 실행함. 또한, built-in 함수들이 포함되어있음.

서론
-----------
이번 프로젝트를 하면서 아직은 절대 내가 만족할 수준의 쉘이 나오지 않음을 알게 되었다. shell의 기본적인 기능이나 pipeline, redirection에 대한 개념도 부족했고 해당 기능을 구현하는데 아직 실력이 부족했다. 그렇기에 이번에는 shell의 기본틀만 공부 후 구현하기로 했다.

Shell
-----------

## Shell의 개념
Shell이란 유저와 OS 간의 의사소통을 위한 도구라고 할 수 있다. 일반적인 GUI와 달리 우리가 만들 Shell은 CLI이며, 명령문을 읽고 수행하는 것이 본 목적이다.

## Shell의 기능
Shell은 기본적으로 크게 다음 세단계로 동작한다.

1. Initialize : 일반적으로 configuration을 읽어오고 지정된 환경을 불러들여 적용하는 단계이다.
2. Interpret : 실질적으로 입력된 명령문을 읽고 수행하게 된다.
3. Terminate : 종료 명령문을 받으면 종료한다.

위 기능들 중 Interpret가 실질적으로 Shell이 하는 기능을 담고 있다고 보면 된다.

## Interpret의 구성
Interpret는 다음과 같은 기능을 가지고 있다.

1. read : 명령문을 읽어들인다.
2. parse : 명령문을 parsing해서 단어로 분할한다.
3. execute : 명령문을 수행한다.

MyShell
---------
## 요약
내가 만든 Shell은 일반적인 Shell이 가진 아주 기초적인 기능만을 가지고 있다. 파이프라인 통신과 시그널의 기능도 가지고 있지 않으며, 그렇기에 아주 단순하다.

## 기능
### 프롬프트 출력
내가 만든 Shell은 현재 디렉토리를 읽어내고 반복적으로 출력하게 된다.

### 명령문 수행
위에서 설명한 단계대로 명령문을 read, parse, execute한다. Built in 되어있는 명령문은 별로 없기에 기본적으로는 시스템 내부에 선언되어있는 명령을 수행한다.

### Built in 명령문
* cd : 기존 cd와 동일한 기능을 한다.
* help : shell에 대한 정보와 built in 되어있는 명령문을 출력한다.
* exit : shell을 종료한다.


결론
--------
중간고사가 겹쳐서 설계가 제대로 되어있지 않은 것 같았고 Shell에 대한 정보나 pipeline, signal 동작에 대한 Shell의 작동을 결국 구현하지 못했다.
아직 시스템 함수들에 대해 익숙하지 않아서 기본적인 부분만 구현하고 이후 기회가 되면 pipeline, signal, redirection 등의 기능을 구현해야할 것으로 생각된다.
