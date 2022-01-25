/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:41:59 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/25 20:47:26 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char ***stack, char *print)
{
	char	*tmp;

	tmp = stack[0][0];
	stack[0][0] = stack[0][1];
	stack[0][1] = tmp;
	if (print)
		ft_putstr_fd(print, 1);
}

void	push(char ***stack_a, char ***stack_b, char *print)
{
	char	*tmp_b;
	int		i;

	if (!stack_b)
		return ;
	i = 0;
	tmp_b = stack_b[0][0];
	while (stack_a[0][i])
		i++;
	while (stack_a[0][i])
	{
		stack_a[0][i + 1] = stack_a[0][i];
		i--;
	}
	stack_a[0][0] = tmp_b;
	if (print)
		ft_putstr_fd(print, 1);
}

void	rotate(char ***stack, char *print)
{
	(void)stack;
	if (print)
		ft_putstr_fd(print, 1);
}

void	r_rotate(char ***stack, char *print)
{
	(void)stack;
	if (print)
		ft_putstr_fd(print, 1);
}
