/// try to change pa and pb

//#include "push_swap.h"

int	pa(t_swap *s)
{
	int	i;

	i = s->count.len_b + 1;
	while (--i > 0)
		s->b[i] = s->b[i - 1];
	s->count.len_b++;
	s->b[0] = s->a[0];
	i = -1;
	s->count.len_a--;
	while (++i < s->count.len_a)
		s->a[i] = s->a[i + 1];
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_swap *s)
{
	int	i;

	i = s->count.len_a + 1;
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->count.len_a++;
	s->a[0] = s->b[0];
	i = -1;
	s->count.len_b--;
	while (++i < s->count.len_b)
		s->b[i] = s->b[i + 1];
	ft_putstr_fd("pb\n", 1);
	return (0);
}

void	parse(t_swap *swap, char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < swap->count.len_a)
	{
		swap->a[i] = ft_atoi(s[j]);
		i++;
		j++;
	}
}

int	prepare_list(t_swap *swap, char **s)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	swap->a = malloc(sizeof(int *) * swap->count.len_a);
	swap->b = malloc(sizeof(int *) * swap->count.len_a);
	if (!swap->a || !swap->b)
		return (0);
	if (swap->type == 'S')
	{
		while (s[1][i] && pos <= swap->count.len_a)
		{
			swap->a[pos] = ft_atoi(&s[1][i]);
			while (ft_isdigit(s[1][i]))
				i++;
			while (!ft_isdigit(s[1][i]))
				i++;
			pos++;
		}
	}
	else
		parse(swap, s);
	return (1);
}

int	ft_same_int(int j, char **av)
{
	int	i;

	i = 1;
	while (av[j])
	{
		while (av[i])
		{
			//printf("verif %s != %s || %d \n",av[j], av[i], ft_strcmp(av[i], av[j]));
			if (ft_strcmp(av[i], av[j]) == 0 && i != j)
				return (1);
			i++;
		}
		j++;
		i = 1;
	}
	return (0);
}

/*
int	veirf_size_int(char *s)
{
	ft_strncmp(s, "2147483647", ft_strlen(s));
	ft_strncmp(s, "-2147483648", ft_strlen(s));
}
*/

int	verif_digit(char *s, int len, t_swap *swap)
{
	while (len > 0)
	{
		if (!ft_isdigit(s[len - 1]) && s[len - 1] != ' ')
			return (0);
		if (ft_isdigit(s[len - 1]) && !ft_isdigit(s[len - 2]))
			swap->count.len_a++;
		len--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		tmp;
	t_swap	swap;

	tmp = argc;
	init_struct(&swap);
	if (argc < 2)
		return (0);
//	ft_same_int(1, argv);// dangers more than 25 line
	while (--tmp >= 1)
	{
		if (!verif_digit(argv[tmp], ft_strlen(argv[tmp]), &swap) || ft_same_int(1, argv))// || verif_size_int(argv[tmp]))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
	}
	if (argc < swap.count.len_a)
		swap.type = 'S';
	if (!prepare_list(&swap, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}

	printf("%d \n", swap.count.len_a);
	ft_print(swap.a, 'A', swap.count.len_a);
	pa(&swap);
	ft_print(swap.b, 'B', swap.count.len_b);
	ft_print(swap.a, 'A', swap.count.len_a);
	pa(&swap);
	ft_print(swap.b, 'B', swap.count.len_b);
	ft_print(swap.a, 'A', swap.count.len_a);
	pa(&swap);
	ft_print(swap.b, 'B', swap.count.len_b);
	ft_print(swap.a, 'A', swap.count.len_a);
	printf("----------------------------------------------------\n");
	pb(&swap);
	ft_print(swap.b, 'B', swap.count.len_b);
	ft_print(swap.a, 'A', swap.count.len_a);
	pb(&swap);
	ft_print(swap.b, 'B', swap.count.len_b);
	ft_print(swap.a, 'A', swap.count.len_a);
	pb(&swap);
	ft_print(swap.a, 'A', swap.count.len_a);
	//ft_print(swap.a, 'A', swap.count.len_a);
	return (0);
}

