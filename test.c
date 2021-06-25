
#include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc < 2 && argc > 2)
		return (0);
	printf("MAX INT %d\n", INT_MIN);
	printf("MIN INT %d\n\n", INT_MAX);

	printf("MAX LONG %ld\n", LONG_MIN);
	printf("MIN LONG %ld\n", LONG_MAX);
	return (0);
}

