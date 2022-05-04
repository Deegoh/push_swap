/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/04 18:24:14 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

t_sck	dup_stack(t_sck old)
{
	t_sck	ns;
	t_sck	tmp;

	tmp = old;
	ns.a = NULL;
	ns.b = NULL;
	while (tmp.a)
	{
		append(&ns.a, tmp.a->data, tmp.a->i);
		tmp.a = tmp.a->next;
	}
	ns.size_a = tmp.size_a;
	ns.size_b = tmp.size_b;
	ns.max = tmp.max;
	ns.min = tmp.min;
	ns.op = ft_strdup("");
	ns.l_op = ft_strdup("");
	ns.range = 0;
	// ns.btn = 0;
	// ns.count = 0;
	// ns.z = 0;
	return (ns);
}

int	main(int ac, char *av[])
{
	t_sck	stacks;
	t_sck	dup;
	int		range;
	int		chunck;

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_list(init_stacks(ac, av));
	dup = dup_stack(stacks);
	if (check_sort(stacks))
	{
		if (stacks.size_a <= 5)
		{
			simple_sort(&stacks);
		}
		else
		{
			if (stacks.size_a <= 100)
			{
				// print_stacks(stacks, 500);
				// split_by_chunck(&stacks, 2, 0);
				// print_stacks(stacks, 500);
				custom_sort(&stacks, 1, 5);
			}
			else
			{
				chunck = 3;
				// while (chunck <= 250)
				// {
					range = 30;
					// while (range <= 250)
					// {
						split_by_chunck(&stacks, chunck);
						// custom_sort(&stacks, chunck, range);
						join_op(&stacks, "");
						ft_remove_str(stacks.op, "pb\npa\n");
						// if (10000 >= count_char(stacks.op, '\n'))
						// printf("op[%d] range[%d] chunck[%d]\n", count_char(stacks.op, '\n'), range, chunck);
						// free_all(&stacks);
						// stacks = dup_stack(dup);
						// range++;
					// }
					// chunck++;
					// printf("new chunck %d\n", chunck);
				// }

			}
		}
	}
	// join_op(&stacks, "");
	// ft_remove_str(stacks.op, "pb\npa\n");
	ft_printf("%s", stacks.op);
	// print_stacks(stacks, 500);
	// print_stacks(dup, 500);
	(void)range;
	free_all(&stacks);
	return (EXIT_SUCCESS);
}
