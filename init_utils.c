/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:50:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/30 15:23:21 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

// void	print_stacks(t_sck stacks, int nbr)
// {
// 	t_sck	tmp;
// 	int		j;

// 	tmp = stacks;
// 	ft_printf("min[%d] max[%d]\n", stacks.min, stacks.max);
// 	ft_printf("A size[%d] B size[%d]\n", stacks.size_a, stacks.size_b);
// 	while ((tmp.a || tmp.b) && nbr--)
// 	{
// 		if (tmp.a)
// 		{
// 			j = ft_nbrlen(tmp.a->data);
// 			ft_printf("a:");
// 			while (j++ < 4)
// 				ft_printf(" ");
// 			ft_printf("%d ", tmp.a->data);
// 			tmp.a = tmp.a->next;
// 		}
// 		else
// 			ft_printf("a:     ");
// 		if (tmp.b)
// 		{
// 			j = ft_nbrlen(tmp.b->data);
// 			ft_printf("b:");
// 			while (j++ < 4)
// 				ft_printf(" ");
// 			ft_printf("%d\n", tmp.b->data);
// 			tmp.b = tmp.b->next;
// 		}
// 		else
// 			ft_printf("b:\n");
// 	}
// }

int	check_sort(t_sck stacks)
{
	stacks.a = stacks.a->next;
	while (stacks.a && stacks.a->prev)
	{
		if (stacks.a->prev->data < stacks.a->data)
		{
			stacks.a = stacks.a->next;
			continue ;
		}
		return (1);
	}
	return (0);
}

t_sck	init_list(t_stacks	stacks)
{
	t_sck	sck;
	int		i;

	i = -1;
	sck.a = NULL;
	sck.b = NULL;
	while (++i < stacks.a.size)
		append(&sck.a, stacks.a.value[i]);
	free(stacks.a.value);
	sck.size_a = count_nodes(sck.a);
	sck.size_b = 0;
	sck.max = find_max(&sck, 'A');
	sck.min = find_min(&sck, 'A');
	return (sck);
}
