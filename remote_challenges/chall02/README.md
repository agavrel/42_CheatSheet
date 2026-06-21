<h1 align="center"><code>Chall02 / String to Morse</code></h1>


---

### 지시 사항
<sub>**제출 폴더:** `chall02/`</sub><br />
<sub>**제출 파일:** `<xlogin>.py`</sub><br />
<sub>**언어:** `Python 3.x`</sub>

<sub>**마감:** 2020-04-21 13:42 (당시 원격 챌린지)</sub>

> **참고:** 2020년 원격 챌린지입니다. 아래 `usage:` 줄과 예시 출력은 **스펙**이므로 영어 그대로 두었습니다.

<br /><br />

### 주제

<p align="center">
  <img width="350" height="350" src="https://miro.medium.com/max/2326/0*ILDRyFYvSxy7Wmse.jpg">
</p>


이 챌린지에서 Morse code는 각 알파벳을 **1~4개**의 문자 시퀀스로 표현하고, 각 문자는 `.`(dot) 또는 `-`(dash)입니다. `a`는 `.-`, `b`는 `-...` 식이죠.

`a`부터 `z`까지의 표는 다음과 같습니다.
```
.-
-... 
-.-. 
-.. 
. 
..-. 
--. 
.... 
.. 
.--- 
-.- 
.-.. 
-- 
-. 
--- 
.--. 
--.- 
.-. 
... 
- 
..- 
...- 
.-- 
-..- 
-.-- 
--..
```

**python3로 실행 가능한 스크립트**를 제출해, 문자열을 Morse로 인코딩해야 합니다.
<br /><br />
### 예시

```
[salty@42.fr ~ ]$ ./xlogin.py
usage: ./xlogin.py <a-zA-Z string>
```
```
[salty@42.fr ~ ]$ ./xlogin.py ""
usage: ./xlogin.py <a-zA-Z string>
```
```
[salty@42.fr ~ ]$ ./xlogin.py "firstArg" "secondArg"
usage: ./xlogin.py <a-zA-Z string>
```
```
[salty@42.fr ~ ]$ ./xlogin.py "sos daily##@"
usage: ./xlogin.py <a-zA-Z string>
```
```
[salty@42.fr ~ ]$ ./xlogin.py "soS"
...---...
```
```
[salty@42.fr ~ ]$ ./xlogin.py "daily"
-...-...-..-.--
```
```
[salty@42.fr ~ ]$ ./xlogin.py "proGRammer"
.--..-.-----..-..-----..-.
```
```
[salty@42.fr ~ ]$ ./xlogin.py "bits"
-.....-...
```
```
[salty@42.fr ~ ]$ ./xlogin.py "sos daily" | cat -e
...---... -...-...-..-.--$
```
<br /><br />
### 보상

 - **상세 설명은 영어로** 작성해야 합니다. 영어가 아니거나 빈약하면 PR이 거절됩니다.
 - 가장 먼저 정답을 낸 사람은 coalition에 `10` 또는 `420` 점.
 - 그 외 **아직 제출되지 않은** 정답은 `3` 또는 `126` 점.
 - 시도했고 솔루션을 push한 참가자는 `2` 또는 `84` 점.
 
<br /><br />
행운을 빌어요!
