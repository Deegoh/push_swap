/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:41:59 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/27 08:17:52 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
sa/sb : swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements).
*/

void	swap(t_stack *stack, char *print)
{
	int	tmp;

	if (stack->value[1])
	{
		tmp = stack->value[0];
		stack->value[0] = stack->value[1];
		stack->value[1] = tmp;
		if (print)
			ft_putstr_fd(print, 1);
	}
}
/*
pa : push a - take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
 */

void	push_a(t_stacks *stacks)
{
	int	i;

	if (stacks->b.value[0])
	{
		stacks->a.size++;
		i = stacks->a.size;
		while (--i)
			stacks->a.value[i] = stacks->a.value[i - 1];
		stacks->a.value[0] = stacks->b.value[0];
		i = -1;
		while (++i < stacks->b.size)
			stacks->b.value[i] = stacks->b.value[i + 1];
		stacks->b.value[i] = 0;
		stacks->b.size--;
		ft_putstr_fd("pa\n", 1);
	}
}
/*
pb : push b - take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
 */

void	push_b(t_stacks *stacks)
{
	int	i;

	if (stacks->a.value[0])
	{
		stacks->b.size++;
		i = stacks->b.size;
		while (--i)
			stacks->b.value[i] = stacks->b.value[i - 1];
		stacks->b.value[0] = stacks->a.value[0];
		i = -1;
		while (++i < stacks->a.size)
			stacks->a.value[i] = stacks->a.value[i + 1];
		stacks->a.value[i] = 0;
		stacks->a.size--;
		ft_putstr_fd("pb\n", 1);
	}
}
/*
rotate a/b - shift up all elements of stack by 1.
The first element becomes the last one.
 */

void	rotate(t_stack *stacks, char *print)
{
	(void)stacks;
	if (print)
		ft_putstr_fd(print, 1);
//	int	tmp;
//	int	i;
//
//	if (stack[0][0])
//	{
//		i = -1;
//		tmp = stack[0][0];
//		while (++i < s)
//		stack[0][0] = stack[0][1];
//		stack[0][1] = tmp;
//		if (print)
//			ft_putstr_fd(print, 1);
//	}
}

void	r_rotate(int **stack, char *print)
{
	(void)stack;
	if (print)
		ft_putstr_fd(print, 1);
}
