/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 23:46:35 by jacarpio          #+#    #+#             */
/*   Updated: 2026/03/22 19:16:28 by jamie_ubunt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

char *ft_join_args(int argc, char **argv)
{
    char    *tmp;
    char    *result;
    int     i;

    result = ft_strdup("");
    i = 1;
    while (i < argc)
    {
        tmp = result;
        result = ft_strjoin(result, argv[i]);
        free(tmp);

        tmp = result;
        result = ft_strjoin(result, " ");
        free(tmp);

        i++;
    }
    return (result);
}
