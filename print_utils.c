/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:21:16 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/03 23:19:12 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

void	print_index(t_node *a, t_node *b)
{
	int	j;

	if (a)
	{
		j = ft_nbrlen(a->i);
		ft_printf("a:");
		while (j++ < 4)
			ft_printf(" ");
		ft_printf("%d b:", a->i);
	}
	else
		ft_printf("a:     b:");
	if (b)
	{
		j = ft_nbrlen(b->i);
		while (j++ < 4)
			ft_printf(" ");
		ft_printf("%d\n", b->i);
	}
	else
		ft_printf("\n");
}

void	print_nodes(t_node *a, t_node *b)
{
	int	j;

	if (a)
	{
		j = ft_nbrlen(a->data);
		ft_printf("a:");
		while (j++ < 4)
			ft_printf(" ");
		ft_printf("%d b:", a->data);
	}
	else
		ft_printf("a:     b:");
	if (b)
	{
		j = ft_nbrlen(b->data);
		while (j++ < 4)
			ft_printf(" ");
		ft_printf("%d  |  ", b->data);
	}
	else
		ft_printf("  |  ");
}

void	print_stacks(t_sck s, int nbr)
{
	while ((s.a || s.b) && nbr--)
	{
		print_nodes(s.a, s.b);
		print_index(s.a, s.b);
		if (s.a)
			s.a = s.a->next;
		if (s.b)
			s.b = s.b->next;
	}
	ft_printf("\n");
}
