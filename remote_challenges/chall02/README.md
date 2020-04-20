<h1 align="center"><code>Chall02 / String to Morse</code></h1>


---

### Instructions
<sub>**Turn-in directory:** `chall02/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.py`</sub><br />
<sub>**Language:** `Python 3.x`</sub>

<sub>**Deadline:** 21.04.2020 - 13:42pm</sub>
<br /><br />

### Subject

<p align="center">
  <img width="350" height="350" src="https://miro.medium.com/max/2326/0*ILDRyFYvSxy7Wmse.jpg">
</p>


For the purpose of this challenge, Morse code represents every letter as a sequence of 1-4 characters, each of which is either `.` (dot) or `-` (dash). The code for the letter `a` is `.-`, for `b` is `-...`, etc. 

The codes for each letter from a through z are:
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

You have to submit a **python3 executable script** to encode a string to morse.
<br /><br />
### Examples

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
### Reward

 - You must write a detailed description in English. If the description is not written in English and not detailed the PR will be refused
 - The first one to submit a working solution will earn `10` or `420` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `3` or `126` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `2` or `84` points for their coalition.
 
<br /><br />
Good luck!
