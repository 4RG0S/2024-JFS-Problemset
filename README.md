# 🛡️ 2024-JFS-Problemset

> ARGOS 정보보호 동아리에서 주최한 **2024 JFS(Just For Security) CTF**의 공식 문제 저장소입니다.

본 레포지토리는 2024년 ARGOS 주관으로 개최된 JFS(Just For Security) CTF에서 출제된 문제들을 아카이빙하고, 학습 및 복습을 위한 자료로 제공하기 위해 제작되었습니다.


## 📁 Repository Structure

```
2024-JFS-Problemset/
├── crypto/
│ ├── can_you_evolve_it-semon/
│ ├── digi_character-TimelessPersona/
│ └── secret_message-TimelessPersona/
│
├── forensic/
│ ├── akdongping-me0w2en/
│ ├── memoping-me0w2en/
│ └── zzoccomping-me0w2en/
│
├── misc/
│ ├── bbi_bbi_bbi_bbi-semon/
│ ├── ckr-donghyodong/
│ ├── discord_break-semon/
│ └── oh_what_is_this-semon/
│
├── reversing/
│ ├── anti_reversing-r99bbit/
│ ├── anti_baek-semon/
│ ├── basic_reversing-semon/
│ ├── black_and_white_bomb-semon/
│ └── our_dog_doesnt_byte-semon/
│
├── web/
│ ├── But_nothing_happened-smooroodina/
│ ├── pokeSearch-smooroodina/
│ ├── pokemon-collection-r99bbit/
│ └── pokemon-strength-r99bbit/
│
└── README.md
```

각 문제 디렉토리 안에는 다음과 같은 형식으로 문제 파일이 포함되어 있습니다.

- `README.md`: 문제 설명
- `src/`: challenge 원본 소스
- `deploy/`: Docker Build 파일
- `exploit/`: 해당 문제 exploit
- `publish/`: 문제 풀이에 필요한 파일 (바이너리, 이미지, 코드 등)
- `writeup.pdf`: 문제 풀이 및 플래그 설명 (경기 종료 후 공개)


## 📌 Usage

1. 원하는 문제로 이동합니다.
2. 문제 설명을 읽고, `publish/` 폴더의 파일을 이용해 문제를 풉니다.
3. 필요 시 `writeup.pdf`를 참고해 풀이 과정을 확인할 수 있습니다.


## 🤝 Contribution

- ARGOS 동아리의 내부적인 보안 교육, 스터디, 대회 준비용으로 활용 가능하며, 사용 시 각 문제 제작자에게 사전 연락 바랍니다.
- 오류, 오타, 개선사항 제안은 `Issue` 또는 `Pull Request`로 알려주세요.


## 📜 License

본 레포지토리 내 문제 및 자료의 저작권은 ARGOS 정보보호 동아리에 있으며, **비영리 목적의 학습 및 연구** 용도로 사용 가능합니다. 무단 상업적 이용 및 재배포를 금합니다.


## 🙌 Acknowledgements

- 주최 및 주관: 충남대학교 정보보호동아리 ARGOS, 충남대학교 융합보안연구센터, 충남대학교 소프트웨어중심대학사업단
- 일시: 2024년 11월 9일(토)
- 장소: 충남대학교 공과대학 5호관 410호
