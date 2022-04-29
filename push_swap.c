/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/29 19:21:50 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sck	init_list(t_stacks	stacks)
{
	t_sck	sck;
	int		i;

	i = -1;
	sck.a = NULL;
	sck.b = NULL;
	while (++i < stacks.a.size)
		append(&sck.a, stacks.a.value[i]);
	sck.size_a = count_nodes(sck.a);
	sck.size_b = 0;
	sck.top_a = sck.a;
	sck.end_a = last_node(sck.a);
	sck.max = find_max(&sck, 'A');
	sck.min = find_min(&sck, 'A');
	return (sck);
}

void	customsort(t_sck *s)
{
	int	z;
	int	count;
	int	min;

	split_by_chunck(s, s->size_a / 250);
	z = 1;
	count = 0;
	min = s->min;
	while (s->size_a)
	{
		while (count < 10 && s->size_a)
		{
			opti_rot(s, find_value_between(s, min, min + z * 10 - 1, 'A'), 'A');
			push_ab(s, 'B');
			count++;
		}
		count = 0;
		z++;
	}
	while (s->size_b > 0)
	{
		opti_rot(s, find_max(s, 'B'), 'B');
		push_ab(s, 'A');
	}
}

int	main(int ac, char *av[])
{
	t_sck		stacks;

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_list(init_stacks(ac, av));
	stacks.op = ft_strdup("");
	if (check_sort(stacks))
	{
		if (stacks.size_a <= 5)
			simple_sort(&stacks);
		else
		{
			customsort(&stacks);
		}
	}
	ft_printf("%s", stacks.op);
	return (EXIT_SUCCESS);
}
