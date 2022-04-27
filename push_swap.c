/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/27 23:44:52 by tpinto-m         ###   ########.fr       */
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
	set_min_max(&sck);
	return (sck);
}

void	customsort(t_stacks *stacks)
{
	(void)stacks;
}

void	set_min_max(t_sck *stacks)
{
	t_node	*tmp;
	int		min;
	int		max;

	tmp = stacks->a;
	max = tmp->data;
	min = tmp->data;
	while (tmp)
	{
		if (max < tmp->data)
			max = tmp->data;
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	stacks->max = max;
	stacks->min = min;
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
			// customsort(&stacks);
		}
	}
	// print_stacks(stacks);
	ft_printf("%s", stacks.op);
	return (EXIT_SUCCESS);
}
