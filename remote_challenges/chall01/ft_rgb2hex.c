#include <stdio.h>
#include <string.h>

char		*ft_rgb2hex(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (NULL);

	char	hex[8];
	hex[0] = '#';
	sprintf(hex + 1, "%02x", r);
	sprintf(hex + 3, "%02x", g);
	sprintf(hex + 5, "%02x", b);
	hex[7] = '\0';
	return (hex);
}
