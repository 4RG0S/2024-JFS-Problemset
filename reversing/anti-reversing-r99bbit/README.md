# [REVERSING] Anti Reversing

## Summary
1. UPX 언패킹 방지 기법 우회
2. UPX 섹션 이름을 XXX로 바꾸어 놓았음, 헥스에디터를 통해 해당 부분을 다시 UPX로 바꾸고 UPX Unpacking 하면 해결 가능

## Description
```
악성코드는 백신을 어떻게 피할까?
힌트 : Anti UPX Unpacking
Usage: ./anti-reversing.exe JFS{???}
```

## Solve
- do while 문으로 첫 회에는 srand() 1회, 두 번째 부터는 srand()를 두번 씩 사용하므로 이에 맞춰 Ctypes 모듈로 익스를 작성하면 된다.
- FLAG : `JFS{ant!_u9x_un9ack!ng@@}`