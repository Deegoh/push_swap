/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/28 17:37:31 by tpinto-m         ###   ########.fr       */
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

int	is_between_value(int value, int a, int z)
{
	if (value >= a && value <= z)
		return (1);
	return (0);
}

int	find_opti_top(t_sck *stacks, int a, int z, char c)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (c == 'A')
		tmp = stacks->a;
	else
		tmp = stacks->b;
	while (tmp)
	{
		if (is_between_value(tmp->data, a, z))
			break ;
		tmp = tmp->next;
		i++;
	}
	tmp = first_node(tmp);
	return (i);
}

int	find_opti_bot(t_sck *stacks, int a, int z, char c)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (c == 'A')
		tmp = last_node(stacks->a);
	else
		tmp = last_node(stacks->b);
	while (tmp)
	{
		if (is_between_value(tmp->data, a, z))
			break ;
		tmp = tmp->prev;
		i++;
	}
	tmp = first_node(tmp);
	return (i);
}

int	find_value_between(t_sck *stacks, int a, int z, char c)
{
	int		i;
	int		j;

	i = find_opti_top(stacks, a, z, c);
	j = find_opti_bot(stacks, a, z, c);
	stacks->a = first_node(stacks->a);
	if (i < j)
		return (count_until_index(stacks->a, i, 'T')->data);
	return (count_until_index(stacks->a, j, 'B')->data);
}

void	customsort(t_sck *stacks)
{
	int		a;
	int		z;
	int		count;

	a = 0;
	z = 1;
	count = 0;
	while (stacks->size_a)
	{
		while (count < 10)
		{
			opti_rot(stacks, find_value_between(stacks, a * 10, z * 10, 'A'), 'A');
			push_ab(stacks, 'B');
			count++;
		}
		count = 0;
		a++;
		z++;
	}
	// print_stacks(*stacks, 100);
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
			customsort(&stacks);
		}
	}
	// print_stacks(stacks, 100);
	// ft_printf("%s", stacks.op);
	return (EXIT_SUCCESS);
}
