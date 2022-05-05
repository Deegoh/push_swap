/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/05 18:47:12 by tpinto-m         ###   ########.fr       */
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
	ns.sizemax = tmp.sizemax;
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
	char	*best_op;
	int		limite;

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_list(init_stacks(ac, av));
	dup = dup_stack(stacks);
	if (check_sort(stacks))
	{
		if (stacks.size_a <= 5)
		{
			simple_sort(&stacks);
			join_op(&stacks, "");
			ft_remove_str(stacks.op, "pb\npa\n");
		}
		else
		{
			limite = 0;
			if (stacks.size_a >= 500)
				limite = 2;
			chunck = 3;
			while (chunck >= 1)
			{
				range = 150;
				while (range >= 0)
				{
					custom_sort(&stacks, chunck, range);
					join_op(&stacks, "");
					ft_remove_str(stacks.op, "pb\npa\n");
					if (!best_op)
						best_op = ft_strdup(stacks.op);
					if (count_char(stacks.op, '\n') < count_char(best_op, '\n'))
					{
						free(best_op);
						best_op = ft_strdup(stacks.op);
						// printf("op[%d] range[%d] chunck[%d] size[%d]\n", count_char(best_op, '\n'), range, chunck, stacks.size_a);
					}
					free_all(&stacks);
					stacks = dup_stack(dup);
					range--;
				}
				chunck--;
			}
			free(stacks.op);
			stacks.op = ft_strdup(best_op);
		}
	}
	// join_op(&stacks, "");
	// ft_remove_str(stacks.op, "pb\npa\n");
	ft_printf("%s", stacks.op);
	// print_stacks(stacks, 500);
	// print_stacks(dup, 500);
	free_all(&stacks);
	free_all(&dup);
	return (EXIT_SUCCESS);
}
