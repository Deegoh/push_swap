/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:41:59 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/26 20:38:45 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int **stack, char *print)
{
	int	tmp;

	tmp = stack[0][0];
	stack[0][0] = stack[0][1];
	stack[0][1] = tmp;
	if (print)
		ft_putstr_fd(print, 1);
}

//TODO add len and change stack
void	push(int **stack_a, int **stack_b, int len, char *print)
{
	int	tmp_b;
	int	i;

	if (!stack_b[0][0])
		return ;
	i = -1;
	tmp_b = stack_b[0][0];
	while (++i < len)
		stack_b[0][i - 1] = stack_b[0][i];
	i = -1;
	while (++i < len)
	{
		stack_a[0][i + 1] = stack_a[0][i];
	}
	stack_a[0][0] = tmp_b;
	stack_b[0][i - 1] = 0;
	if (print)
		ft_putstr_fd(print, 1);
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
