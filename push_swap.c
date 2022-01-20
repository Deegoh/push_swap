/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/20 20:38:14 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char	*a;
	char	*tmp;
	int		i;

	i = 0;
	if (ac == 1)
	{
		ft_putstr_fd("usage: ./push_swap [arg]\n", 1);
		return (1);
	}
	a = ft_calloc(1, sizeof(char));
	while (++i < ac)
	{
		tmp = a;
		a = ft_strjoin(a, av[i]);
		free(tmp);
		tmp = a;
		a = ft_strjoin(a, " ");
		free(tmp);
	}
	return (0);
}
