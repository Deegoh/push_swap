/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:41:59 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/27 07:38:30 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
swap the first 2 elements at the top of a stack.
Do nothing if there is only one or no elements).
*/

void	swap(int **stack, char *print)
{
	int	tmp;

	if (stack[0][1])
	{
		tmp = stack[0][0];
		stack[0][0] = stack[0][1];
		stack[0][1] = tmp;
		if (print)
			ft_putstr_fd(print, 1);
	}
}
/*
pa : push a - take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
 */

void	push_a(t_stack *stacks)
{
	int	i;

	if (stacks->b[0])
	{
		stacks->size_a++;
		i = stacks->size_a;
		while (--i)
			stacks->a[i] = stacks->a[i - 1];
		stacks->a[0] = stacks->b[0];
		i = -1;
		while (++i < stacks->size_b)
			stacks->b[i] = stacks->b[i + 1];
		stacks->b[i] = 0;
		stacks->size_b--;
		ft_putstr_fd("pa\n", 1);
	}
}
/*
pb : push b - take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
 */

void	push_b(t_stack *stacks)
{
	int	i;

	if (stacks->a[0])
	{
		stacks->size_b++;
		i = stacks->size_b;
		while (--i)
			stacks->b[i] = stacks->b[i - 1];
		stacks->b[0] = stacks->a[0];
		i = -1;
		while (++i < stacks->size_a)
			stacks->a[i] = stacks->a[i + 1];
		stacks->a[i] = 0;
		stacks->size_a--;
		ft_putstr_fd("pb\n", 1);
	}
}

void	rotate(int **stack, char *print)
{
	(void)stack;
	if (print)
		ft_putstr_fd(print, 1);
}

void	r_rotate(int **stack, char *print)
{
	(void)stack;
	if (print)
		ft_putstr_fd(print, 1);
}
