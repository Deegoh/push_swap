/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:47:55 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/25 19:56:36 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rule(t_sck *stacks, char *str)
{
	if (!ft_strncmp(str, "PA", ft_strlen(str)))
		push_ab(stacks, 'A');
	else if (!ft_strncmp(str, "PB", ft_strlen(str)))
		push_ab(stacks, 'B');
	else if (!ft_strncmp(str, "SA", ft_strlen(str)))
		swap(stacks, 'A');
	else if (!ft_strncmp(str, "SB", ft_strlen(str)))
		swap(stacks, 'B');
	else if (!ft_strncmp(str, "RA", ft_strlen(str)))
		rotate(stacks, "RA");
	else if (!ft_strncmp(str, "RB", ft_strlen(str)))
		rotate(stacks, "RB");
	else if (!ft_strncmp(str, "RRA", ft_strlen(str)))
		rotate(stacks, "RRA");
	else if (!ft_strncmp(str, "RRB", ft_strlen(str)))
		rotate(stacks, "RRB");
}

void	do_rule_nb(t_sck *stacks, char *str, int nb)
{
	if (nb < 0)
		nb = -nb;
	while (nb--)
		check_rule(stacks, str);
}

void	opti_rot(t_sck *stacks, int value, char c)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = NULL;
	if (c == 'A')
		tmp = stacks->a;
	else if (c == 'B')
		tmp = stacks->b;
	while (tmp && value != tmp->data)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 0)
		return ;
	if (c == 'A' && i < i - stacks->size_a)
		do_rule_nb(stacks, "RA", i);
	else if (c == 'A' && i > i - stacks->size_a)
		do_rule_nb(stacks, "RRA", i - stacks->size_a);
	else if (c == 'B' && i < i - stacks->size_a)
		do_rule_nb(stacks, "RB", i);
	else if (c == 'B' && i > i - stacks->size_b)
		do_rule_nb(stacks, "RRB", i - stacks->size_b);
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
