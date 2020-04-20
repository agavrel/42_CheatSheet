<h1 align="center"><code>Chall00 / Collier</code></h1>

---

### Instructions

<sub>**Dossier de rendu:** `chall00/`</sub><br />
<sub>**Fichier à rendre:** `<xlogin>.c`</sub><br />
<sub>**Language:** `C`</sub><br />
<sub>**Prototype:** `int   ft_necklace(char *s1, char *s2);`</sub>

<sub>**Deadline:** 07.04.2020 - 13:42am</sub>
<br /><br />
### Sujet

<p align="center">
  <img width="350" height="350" src="https://www.craftkitsandsupplies.com/images/Beads/Alpha_Beads/Wood_Alphabet_Beads_26217.jpg">
</p>

Imaginez un collier avec des perles gravées qui peuvent glisser le long d'une chaine. Regardez l'exemple ci-dessus, vous pouvez retirer le N de NICOLE et le faire glisser à l'autre extrémité pour créer ICOLEN. Recommencez pour obtenir COLENI, etc.

A la fin du défi, nous pourrons dire que les chaines "nicole", "icolen" et "coleni" décrivent le même collier.

<br /><br />
### Exemples:

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
### Récompenses

 - Le premier à trouver la bonne solution gagnera `420` points de coalition si il est dans le nouveau cursus et `10` si il est dans l'ancien.
 - Toute personne ayant proposé une solution valide dans le temps imparti gagnera `126` ou `3` points selon son cursus.
 - Tous autre participant qui a tenté de résoudre le défi et a proposé une solution gagnera `84` points ou `2` points selon son cursus.


<br /><br />
Bonne chance !
