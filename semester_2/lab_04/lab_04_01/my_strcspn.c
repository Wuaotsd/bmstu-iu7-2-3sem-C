#include <stddef.h>
#include "my_strcspn.h"

size_t my_strcspn(const char *str, const char *sym)
{
	size_t i = 0, j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (sym[j] != '\0')
		{
			if (sym[j] == str[i])
				return i;
			j++;
		}
		i++;
	}
	return i;
}