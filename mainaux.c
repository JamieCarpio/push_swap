/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <jacarpio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:42:21 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/23 20:16:37 by jacarpio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_flag(char *arg)
{
	return (
		strcmp(arg, "--simple") == 0
		|| strcmp(arg, "--medium") == 0
		|| strcmp(arg, "--complex") == 0
		|| strcmp(arg, "--adaptive") == 0
		|| strcmp(arg, "--bench") == 0
	);
}

void	detect_flags(int argc, char **argv,
	const char **strategy_flag, int *bench_mode)
{
	int	i;
	int	flag_set;

	i = 1;
	flag_set = 0;
	while (i < argc)
	{
		if (strcmp(argv[i], "--simple") == 0
			|| strcmp(argv[i], "--medium") == 0
			|| strcmp(argv[i], "--complex") == 0
			|| strcmp(argv[i], "--adaptive") == 0)
		{
			if (flag_set)
				ft_error();
			*strategy_flag = argv[i];
			flag_set = 1;
		}
		else if (strcmp(argv[i], "--bench") == 0)
			*bench_mode = 1;
		i++;
	}
}

char	*join_and_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

char	**build_numbers(int argc, char **argv)
{
	char	*joined;
	char	**numbers;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		ft_error();
	i = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
		{
			joined = join_and_free(joined, argv[i]);
			joined = join_and_free(joined, " ");
		}
		i++;
	}
	numbers = ft_split(joined, ' ');
	free(joined);
	if (!numbers || !numbers[0])
		ft_error();
	return (numbers);
}

int	count_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	return (i);
}
