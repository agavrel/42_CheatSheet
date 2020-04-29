#include <stdbool.h>	// bool
#include <unistd.h>		// write
#include <stdlib.h>		// malloc
#include <string.h>		// strlen
#include<stdarg.h>		// va_list

bool	ft_error_va(char *errmsg, ...) {
	va_list		args;
	char		*arg = errmsg;

	write(2, errmsg, strlen(errmsg));
	va_start(args, errmsg);
	while (arg = va_arg(args, char*)) {
		write(2, arg, strlen(arg));
	}
	write(2, "\n", 1);
	va_end(args);
	return false;
}

char	*ft_itoa(int n);

bool	ft_error(char *errmsg, char *file, const char *function, int line) {
	 return ft_error_va(errmsg, "File: ", __FILE__,  ", in function ", \
	 (char *)function, ", line ", ft_itoa(line), NULL);
}


bool	dummy_function(void) {
	 if (3 != 2)
	 	return ft_error("Error with 3 != 2: ", __FILE__, __FUNCTION__, __LINE__);
}

int			main(void) {
	if (!dummy_function())
		return 1;
	return 0;
}

char	*ft_itoa(int n)
{
	char	*s;
	long	tmp;
	int		length;

	tmp = n;
	length = (n <= 0 ? 2 : 1);
	while (n && ++length)
		n /= 10;
	if (!(s = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	s[--length] = '\0';
	if (tmp <= 0)
		s[0] = (tmp < 0 ? '-' : '0');
	while (tmp)
	{
		s[--length] = (tmp < 0 ? -tmp : tmp) % 10 + '0';
		tmp /= 10;
	}
	return (s);
}
