/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:21:16 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/05 12:12:23 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

void	print_index(t_node *a, t_node *b, int i, int j)
{
	int	k;

	if (a)
	{
		k = ft_nbrlen(i);
		while (k++ < 4)
			ft_printf(" ");
		ft_printf("%i", i);
		ft_printf("|");
		k = ft_nbrlen(a->i);
		while (k++ < 4)
			ft_printf(" ");
		ft_printf("%d:a b:", a->i);
	}
	else
		ft_printf(":a b:");
	if (b)
	{
		k = ft_nbrlen(b->i);
		while (k++ < 4)
			ft_printf(" ");
		ft_printf("%d|", b->i);
	}
	else
		ft_printf("    |");
	ft_printf("%d\n", j);
	(void)i;
}

void	print_nodes(t_node *a, t_node *b, int i)
{
	int	j;

	if (a)
	{
		j = ft_nbrlen(i);
		while (j++ < 4)
			ft_printf(" ");
		ft_printf("%i", i);
		ft_printf("|a:");
		j = ft_nbrlen(a->data);
		while (j++ < 7)
			ft_printf(" ");
		ft_printf("%d b:", a->data);
	}
	else
		ft_printf("%i a:     b:", i);
	if (b)
	{
		j = ft_nbrlen(b->data);
		while (j++ < 7)
			ft_printf(" ");
		ft_printf("%d!  ", b->data);
	}
	else
		ft_printf("       !  ");
}

void	print_stacks(t_sck s, int nbr)
{
	int	i;
	int	j;

	i = 1;
	j = s.size_a;
	if (j < s.size_b)
		j = s.size_b;
	if (j > nbr)
		j = nbr;
	while ((s.a || s.b) && nbr--)
	{
		// print_nodes(s.a, s.b, i++);
		print_index(s.a, s.b,i++, j--);
		if (s.a)
			s.a = s.a->next;
		if (s.b)
			s.b = s.b->next;
	}
	ft_printf("\n");
}
