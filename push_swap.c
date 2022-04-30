/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/30 20:02:44 by tpinto-m         ###   ########.fr       */
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

void	print_stacks(t_sck s, int nbr)
{
	int		j;

	while ((s.a || s.b) && nbr--)
	{
		if (s.a)
		{
			j = ft_nbrlen(s.a->data);
			ft_printf("a:");
			while (j++ < 4)
				ft_printf(" ");
			ft_printf("%d b:", s.a->data);
			s.a = s.a->next;
		}
		else
			ft_printf("a:     b:");
		if (s.b)
		{
			j = ft_nbrlen(s.b->data);
			while (j++ < 4)
				ft_printf(" ");
			ft_printf("%d", s.b->data);
			s.b = s.b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	join_op(t_sck *stacks, char *op)
{
	char	*tmp;

	tmp = stacks->op;
	stacks->op = ft_strjoin(stacks->op, op);
	free(tmp);
}

void	free_all_nodes(t_sck *stacks)
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
}

char	*opti_op(char *op)
{
	int		i;
	int		j;
	char	*new_op;

	i = -1;
	j = -1;
	new_op = calloc(sizeof(char), ft_strlen(op));
	while (++i < ft_strlen(op))
	{
		if ((op[i] == 'r' && op[i + 1] == 'a' && op[i + 2] == '\n' && op[i + 3] == 'r' && op[i + 4] == 'b' && op[i + 5] == '\n') ||
			(op[i] == 'r' && op[i + 1] == 'b' && op[i + 2] == '\n' && op[i + 3] == 'r' && op[i + 4] == 'a' && op[i + 5] == '\n'))
		{
			new_op[++j] = 'r';
			new_op[++j] = 'r';
			new_op[++j] = '\n';
			i += 5;
		}
		else if ((op[i] == 'r' && op[i + 1] == 'r' && op[i + 2] == 'b' && op[i + 3] == '\n' && op[i + 4] == 'r' && op[i + 5] == 'r' && op[i + 6] == 'a' && op[i + 7] == '\n') ||
			(op[i] == 'r' && op[i + 1] == 'r' && op[i + 2] == 'a' && op[i + 3] == '\n' && op[i + 4] == 'r' && op[i + 5] == 'r' && op[i + 6] == 'b' && op[i + 7] == '\n'))
		{
			new_op[++j] = 'r';
			new_op[++j] = 'r';
			new_op[++j] = 'r';
			new_op[++j] = '\n';
			i += 7;
		}
		else 
			new_op[++j] = op[i];
	}
	free(op);
	return (new_op);
}

int	find_closest(t_sck *s, int value, char c)
{
	t_node	*tmp;
	int		delta;
	int		res;

	if (c == 'A')
		tmp = s->a;
	else
		tmp = s->b;
	delta = INT_MAX;
	while (tmp)
	{
		if (delta > abs(value - tmp->data))
		{
			res = tmp->data;
			delta = abs(value - tmp->data);
		}
		tmp = tmp->next;
	}
	return (res);
}

void	video_sort(t_sck *s)
{
	int	a;
	int	b;
	int	topA;
	int	topB;
	int	botA;
	int	botB;
	do_rule_nb(s, "PB", 3);
	// while (s->size_a)
	// {
		b = find_closest(s, s->b->data, 'A');
		a = find_closest(s, s->a->data, 'B');
		topA = find_opti_top(s, a, a, 'B');
		topB = find_opti_top(s, b, b, 'A');
		botA = find_opti_bot(s, a, a, 'B');
		botB = find_opti_bot(s, b, b, 'A');
		ft_printf("data[%d] a[%d] topA[%d] endA[%d]\ndata[%d] b[%d] topB[%d] endB[%d]\n",
		 s->a->data, a, find_opti_top(s, a, a, 'B'), find_opti_bot(s, a, a, 'B'),
		 s->b->data, b, find_opti_top(s, b, b, 'A'), find_opti_bot(s, b, b, 'A'));
		// if (find_opti_top(s, find_closest(s, s->a->data, 'B'), 'B') == opti_rot(s, find_closest(s, s->b->data, 'A'), 'A'))
		// 	{
		// 		push_ab(s, 'B');
				// continue ;
			// }
	// }
		// if (opti_rot(s, find_closest(s, s->a->data, 'B'), 'B') < opti_rot(s, find_closest(s, s->b->data, 'A'), 'A'))
		// 	opti_rot(s, find_closest(s, s->b->data, 'A'), 'A');
		// else
		// 	opti_rot(s, find_closest(s, s->a->data, 'B'), 'B');
		// push_ab(s, 'B');
	// ft_printf("a[%d] opti[%d] close[%d] b[%d] opti[%d] close[%d]\n",
	// 	s->a->data, opti_rot(s, find_closest(s, s->a->data, 'B'), 'B'), find_closest(s, s->a->data, 'B'),
	// 	s->b->data, opti_rot(s, find_closest(s, s->b->data, 'A'), 'A'), find_closest(s, s->b->data, 'A'));
	// }
	// while (s->size_b)
	// {
	// 	opti_rot(s, find_max(s, 'B'), 'B');
	// 	push_ab(s, 'A');
	// }
}

void	custom_sort(t_sck *s)
{
	split_by_chunck(s, s->size_a / 150);
	s->count = 0;
	s->range = 5 + (s->size_a / 100);
	s->min = s->min - 1;
	s->z = s->min + 1;
	s->btn = 0;
	while (s->size_a > 1)
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
			// custom_sort(&stacks);
			video_sort(&stacks);
	}
	print_stacks(stacks, 500);
	// ft_printf("%s", (stacks.op));
	// ft_printf("%s", opti_op(stacks.op));
	free_all_nodes(&stacks);
	return (EXIT_SUCCESS);
}
