# 2024-JFS-Problemset
2024.11.09. ARGOS JFS CTF

# How to upload
1. 문제 제작
2. Git clone
3. {분야}-{문제_이름}-{출제자} branch 생성 (ex. pwnable-CNU_Board-semon)
4. {분야}/{문제_이름}-{출제자} directory 생성
5. 아래 요구사항에 해당하는 directory 및 file들을 commit
6. 모든 문제를 commit 후 Pull Reauest

# Requirements
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
* 가능한 shell script 배포 권장
##  exploit/
* 해당 문제 exploit code
## publish/
* 참가자에게 제공할 파일이 없다면 미생성
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
