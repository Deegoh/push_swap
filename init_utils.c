/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:50:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/02 18:06:15 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_sck *stacks)
{
	while (stacks->a && stacks->a->next)
	{
		stacks->a = stacks->a->next;
		free(stacks->a->prev);
	}
	free(stacks->a);
	while (stacks->b && stacks->b->next)
	{
		stacks->b = stacks->b->next;
		free(stacks->b->prev);
	}
	free(stacks->b);
	free(stacks->l_op);
	free(stacks->op);
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
	sck.op = ft_strdup("");
	sck.l_op = ft_strdup("");
	return (sck);
}

t_stacks	init_stacks(int ac, char **av)
{
	char		*arg;
	char		**split;
	t_stacks	stacks;

	arg = merge_arg(av, ac);
	split = ft_split(arg, ' ');
	free(arg);
	stacks.sizemax = arr_len(split);
	stacks.a.value = split_to_arr(split, stacks.sizemax);
	stacks.a.size = stacks.sizemax;
	find_dup(stacks.a.value, stacks.a.size);
	return (stacks);
}
