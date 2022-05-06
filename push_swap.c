/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/06 13:56:53 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_c(char *str, char c)
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
	ns.btn = 0;
	return (ns);
}

char	*is_best_op(t_sck *stacks, char *op)
{
	if (!op)
		op = ft_strdup(stacks->op);
	if (count_c(stacks->op, '\n') < count_c(op, '\n'))
	{
		free(op);
		op = ft_strdup(stacks->op);
	}
	return (op);
}

void	multiverse(t_sck *stacks, int *chunck, int *range)
{
	char	*best_op;
	t_sck	dup;

	best_op = NULL;
	dup = dup_stack(*stacks);
	while (--*chunck >= 1)
	{
		*range = 41;
		while (--*range >= 1)
		{
			custom_sort(stacks, *chunck, *range);
			join_op(stacks, "");
			ft_remove_str(stacks->op, "pb\npa\n");
			best_op = is_best_op(stacks, best_op);
			free_all(stacks);
			*stacks = dup_stack(dup);
		}
	}
	free(stacks->op);
	stacks->op = ft_strdup(best_op);
	free(best_op);
	free_all(&dup);
}

int	main(int ac, char *av[])
{
	t_sck	stacks;
	int		range;
	int		chunck;

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_list(init_stacks(ac, av));
	if (check_sort(stacks))
	{
		if (stacks.size_a <= 5)
			simple_sort(&stacks);
		else
		{
			chunck = 4;
			range = 51;
			multiverse(&stacks, &chunck, &range);
		}
	}
	ft_printf("%s", stacks.op);
	free_all(&stacks);
	return (EXIT_SUCCESS);
}
