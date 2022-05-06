/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:21:16 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/06 11:44:25 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

void	print_a(t_node *a, int i)
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
}

void	print_b(t_node *b, int j)
{
	int	k;

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
		print_a(s.a, i++);
		print_b(s.b, j--);
		if (s.a)
			s.a = s.a->next;
		if (s.b)
			s.b = s.b->next;
	}
	ft_printf("\n");
}
