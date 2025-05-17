# [PWNABLE] 홀짝게임

## Summary
1. srand() 시드를 time(null) 로 설정했을 때 발생할 수 있는 취약점

## Description
```
로또 한번만 됐으면 좋겠다.
```

## Solve
- do while 문으로 첫 회에는 srand() 1회, 두 번째 부터는 srand()를 두번 씩 사용하므로 이에 맞춰 Ctypes 모듈로 익스를 작성하면 된다.
- FLAG : `JFS{u_g0t_4_t!me_m4ch!neeeee_eeee}`