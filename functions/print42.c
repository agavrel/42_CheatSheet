#include <unistd.h> // write

int	    ft_strlen(char const *s)
{
    int i = 0;
    while (s[i++] != '\0') ;
    return i;
}

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

int     main(void) {
    int asciiArt[13] = {
        0b111111100011111111000000111, // 28 chars with \n
        0b111111000011111100000000011,
        0b111110000011111000111110001,
        0b111100000011111000111110001,
        0b111000100011111000111110001,
        0b110001100011111111111000011,
        0b100011100011111111100001111,
        0b000111100011111110000111111,
        0b000000000000111100011111111,
        0b000000000000111000111111111,
        0b111111100011111000111111000,
        0b111111100011111000000000000,
        0b111111100011111000000000000,
    };
    char answer[39] = "theanswertolifetheuniverseandeverything";
    char buffer[28 * 13 + 1]; // don't forget the '\0'!
    int n = 0;
    int i = 0;

    while (i < 13) {
        int mask = 0b1000000000000000000000000000; // 1 more bit since we shift mask at loop begin
        while (mask >>= 1)
            buffer[(i * 27) + (26 - __builtin_ctz(mask))] = !(asciiArt[i] & mask) ? answer[n++ % 38] : ' ';
        buffer[i++ * 27 + 26] = '\n';
    }
    buffer[28 * 13] = '\0'; // NB index 28 * 13 is the ((28 * 13) + 1)ᵗʰ element
    ft_putstr(buffer); // better to print all at once to reduce i/o, improves the runtime
    return 0;
}

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