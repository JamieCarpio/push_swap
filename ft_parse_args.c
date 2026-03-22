/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:02:48 by sbouzian          #+#    #+#             */
/*   Updated: 2026/03/22 19:17:13 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	count_words(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void	copy_words(char **dst, char **src, int *k)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[*k] = ft_strdup(src[i]);
		(*k)++;
		i++;
	}
}
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**parse_args(int argc, char **argv)
{
	char	**result;
	char	**split;
	int		total;
	int		i;
	int		k;

	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		total += count_words(split);
		ft_free_split(split);
		i++;
	}
	result = malloc(sizeof(char *) * (total + 1));
	if (!result)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		copy_words(result, split, &k);
		ft_free_split(split);
		i++;
	}
	result[k] = NULL;
	return (result);
}
