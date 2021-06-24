
#include <stdio.h>

int	world_len(char *s, char c, int *i)
{
	int len;

	len = 0;
	while (s[*i] != c && s[*i])
	{
		*i += 1;
		len++;
	}
	return (len);
}


int	count_word(char *str, char sep)
{
	int	i;
	int	count;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 0;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[++i])
		if (str[i] != sep && str[i - 1] == sep)
			count++;
	return (count);
}

int	main(int argc, char **argv)
{
	int		tmp;
	int		i;
	int		word;
	int		last;

	if (argc < 2 && argc > 2)
		return (0);
	i = 0;
	tmp = argc;
	word = count_word(argv[1], ' ');
	printf("Il existe %d mots dans %s \n", word, argv[1]);
	while (word > 0)
	{
		printf("le mot \"%s\" = %d \n\n\n", &argv[1][last], world_len(argv[1], ' ', &i));
		i++;
		word--;
		last = i;
	}
	return (0);
}

