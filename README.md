# doorPi

20180147 김민           LED, NumPad, ...
20180405 문지혁         Nfc, Mutex, ...

# 프로젝트 구조설명

makefile을 이용하여 다중 파일 컴파일을 실행함
doorPi의 기본이 되는 main.c파일을 비롯한 소스코드 파일들은 src폴더에, 각 함수 및 헤더가 선언되어있는 헤더 파일은 include폴더에 작성되어있음
빌드할 시에 GitHub에는 올라가지 않는 build폴더를 이용하여 오브젝트 파일들을 생성, 다중 파일 컴파일을 실행함

# 실행방법

$ make

$ ./doorPi

# 옵션

-lwiringPi
WiringPi 라이브러리를 위한 옵션

-lnfc
nfc 라이브러리를 이용하기 위한 옵션

-I/usr/local/include/nfc

-L/usr/local/lib