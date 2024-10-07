# 2024-JFS-Problemset
2024.11.09. ARGOS JFS CTF

# How to upload
1. Make a challenge
2. test
3. Write how to run the challenge (including requirements)
4. Write challenge description (this will be shown to the CTF players)
5. Write challenge comments (what is this challenge? (for admins))
6. Upload exploit
7. Update below categories

# Directory requirements
```
[Subjects]
  |-- [Challenge Name]
        |-- src
        |-- deploy
        |-- publish
        |-- exploit
        |-- Writeup.pdf
        `-- README.md
```
## src/
* challenge 원본 소스
##  deploy/
* Docker Build 파일
* 가능한 shell script로 배포
##  exploit/
* 해당 문제 exploit code
## publish/
* 참가자에게 제공할 파일이 없다면 만들지 않을 것
## Writeup.pdf
* 파일 형식은 .pdf로만 제출
## README.md
```
# [{Subjects}] {Challenge Name}
## Summary
* {Challenge Summary}

## Description
* {Description for Deploy}
`FLAG 형식은 JFS{...} 입니다.`

## Solve
자세한 풀이는 `Writeup.pdf`를 참고 Flag : `JFS{___________}`
```
