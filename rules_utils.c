/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:47:55 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/13 14:04:01 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rule(t_stacks *stacks, char *str)
{
	if (!ft_strncmp(str, "PA", ft_strlen(str)))
		push_a(stacks);
	else if (!ft_strncmp(str, "PB", ft_strlen(str)))
		push_b(stacks);
	else if (!ft_strncmp(str, "SA", ft_strlen(str)))
		swap(&stacks->a, "sa\n");
	else if (!ft_strncmp(str, "SB", ft_strlen(str)))
		swap(&stacks->b, "sb\n");
	else if (!ft_strncmp(str, "RA", ft_strlen(str)))
		rotate(&stacks->a, "ra\n");
	else if (!ft_strncmp(str, "RB", ft_strlen(str)))
		rotate(&stacks->b, "rb\n");
	else if (!ft_strncmp(str, "RRA", ft_strlen(str)))
		r_rotate(&stacks->a, "rra\n");
	else if (!ft_strncmp(str, "RRB", ft_strlen(str)))
		r_rotate(&stacks->b, "rrb\n");
	else if (!ft_strncmp(str, "SS", ft_strlen(str)))
		d_swap(stacks);
	else if (!ft_strncmp(str, "RR", ft_strlen(str)))
		d_rotate(stacks);
	else if (!ft_strncmp(str, "RRR", ft_strlen(str)))
		d_r_rotate(stacks);
}

void	do_rule_nb(t_stacks *stacks, char *str, int nb)
{
	while (nb--)
		check_rule(stacks, str);
}

void	opti_rot(t_stacks *stacks, t_stack *stack, int value, char c)
{
	int	i;
	int	j;

	i = 0;
	j = stack->size - 1;
	if (stack->size == 0)
		return ;
	while (value != stack->value[i] && i < stack->size - 1)
		i++;
	while (value != stack->value[j] && j > 0)
		j--;
	if (i == 0 && j == 0)
		return ;
	if (c == 'A')
	{
		if (i < stack->size - j)
			do_rule_nb(stacks, "RA", i);
		else
			do_rule_nb(stacks, "RRA", stack->size - j);
	}
	if (c == 'B')
	{
		if (i < stack->size - j)
			do_rule_nb(stacks, "RB", i);
		else
			do_rule_nb(stacks, "RRB", stack->size - j);
	}
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;
	int		count;

	i = 0;
	res = 0;
	sign = 1;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i++] - '0';
		count++;
	}
	if (count > 19 && sign == 1)
		return (sign * -1);
	if (count > 19 && sign == -1)
		return (0);
	return (res * sign);
}
