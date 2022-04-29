/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/29 21:03:07 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bool(int btn)
{
	if (!btn)
		return (1);
	else
		return (0);
}

void	custom_sort(t_sck *s)
{
	split_by_chunck(s, s->size_a / 150);
	s->count = 0;
	s->range = 5 + (s->size_a / 100);
	s->min = s->min - 1;
	s->z = s->min + 1;
	s->btn = 0;
	while (s->size_a)
	{
		while (s->count < s->range && s->size_a)
		{
			opti_rot(s, data_in_range(s, s->min, s->z + s->range, 'A'), 'A');
			push_ab(s, 'B');
			if (s->btn)
				rotate(s, "RB");
			s->count++;
			s->z++;
		}
		s->count = 0;
		s->btn = ft_bool(s->btn);
	}
	while (s->size_b)
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
			custom_sort(&stacks);
	}
	ft_printf("%s", stacks.op);
	return (EXIT_SUCCESS);
}
