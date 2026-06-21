<h1 align="center"><code>Chall00 / Collier (목걸이)</code></h1>

---

### 지시 사항

<sub>**제출 폴더:** `chall00/`</sub><br />
<sub>**제출 파일:** `<xlogin>.c`</sub><br />
<sub>**언어:** `C`</sub><br />
<sub>**프로토타입:** `int   ft_necklace(char *s1, char *s2);`</sub>

<sub>**마감:** 2020-04-07 13:42 (당시 원격 챌린지 일정)</sub>

> **참고:** 이 문서는 **2020년 42 원격 챌린지** 스냅샷입니다. 현재 캠퍼스 공식 과제·마감과는 다릅니다.

<br /><br />
### 주제

<p align="center">
  <img width="350" height="350" src="https://www.craftkitsandsupplies.com/images/Beads/Alpha_Beads/Wood_Alphabet_Beads_26217.jpg">
</p>

각인된 구슬이 줄 위를 미끄러지듯 움직일 수 있는 **목걸이**를 떠올려 보세요. 위 그림처럼, `NICOLE`에서 `N`을 떼서 반대쪽 끝으로 내면 `ICOLEN`이 됩니다. 같은 짓을 반복하면 `COLENI` 같은 식으로 이어지죠.

챌린지가 끝날 때쯤이면 `"nicole"`, `"icolen"`, `"coleni"` 같은 문자열이 **같은 목걸이**를 묘사한다고 말할 수 있게 됩니다.

<br /><br />
### 예시

```
ft_necklace("nicole", "icolen") == 1
ft_necklace("nicole", "lenico") == 1
ft_necklace("nicole", "coneli") == 0
ft_necklace("aabaaaaabaab", "aabaabaabaaa") == 1
ft_necklace("abc", "cba") == 0
ft_necklace("xxyyy", "xxxyy") == 0
ft_necklace("xyxxz", "xxyxz") == 0
ft_necklace("x", "x") == 1
ft_necklace("x", "xx") == 0
ft_necklace("x", "") == 0
ft_necklace("", "") == 1
```
<br /><br />
### 보상

 - 가장 먼저 정답을 낸 사람은 새 cursus 기준 `420` coalition 점, 구 cursus 기준 `10` 점을 받습니다.
 - 기한 안에 **유효한 제출**을 한 사람은 각각 `126` 또는 `3` 점.
 - 시도했고 솔루션을 올린 다른 참가자는 `84` 또는 `2` 점.


<br /><br />
행운을 빌어요!
