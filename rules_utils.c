/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:47:55 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/11 13:45:19 by tpinto-m         ###   ########.fr       */
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
		rotate(&stacks->a, "RA");
	else if (!ft_strncmp(str, "RB", ft_strlen(str)))
		rotate(&stacks->b, "RB");
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

void	opti_rot(t_stacks *stacks, int value)
{
	int	i;
	int	j;

	i = 0;
	j = stacks->a.size - 1;
	while (value != stacks->a.value[i])
		i++;
	while (value != stacks->a.value[j])
		j--;
	if (i < j)
		do_rule_nb(stacks, "RA", i);
	else
		do_rule_nb(stacks, "RRA", stacks->a.size - j);
}
