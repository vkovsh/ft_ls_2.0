#include <string.h>

size_t		ft_strlen(const char *s)
{
	size_t	start;

	start = (size_t)s;
	while (*s++)
		;
	return ((size_t)s - start - 1);
}