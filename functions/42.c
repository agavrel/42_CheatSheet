n=0,m,i;f(){int a[13]={0x7f1fe07,0x7e1f803,0x7c1f1f1,0x781f1f1,0x711f1f1,0x631ffc3,0x471ff0f,0xf1fc3f,0x78ff,0x71ff,0x7f1f1f8,0x7f1f000,a[11]};for(int i=0;i<13;i++){m=1<<27;while(m>>=1)putchar(!(a[i]&m)?"theanswertolifetheuniverseandeverything"[n++%38]:32);putchar(10);}}

int main(void) {
    f();
    return 0;
}
// gcc -w 42.c && ./a.out
/*

       the        answer
      toli      fetheuniv
     ersea     nde     ver
    ythint     hea     nsw
   ert oli     fet     heu
  niv  ers           eand
 eve   ryt         hint
hea    nsw       erto
lifetheunive    rse
andeverythin   the
       ans     wer      to
       ife     theuniverse
       nde     verythinthe

*/