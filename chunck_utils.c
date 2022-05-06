/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:27:29 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/06 11:40:50 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_split(t_sck *s, int chunck)
{
	int	len;
	int	max;

	if (chunck == 3)
		len = s->size_a - s->size_a / 3;
	else
		len = get_mean(s, 'A');
	max = len;
	while (max--)
	{
		opti_rot(s, in_range(s, 1, len, 'A'), 'A');
		push_ab(s, 'B');
	}
}

void	split_by_3(t_sck *s)
{
	int	len;
	int	max;
	int	mean;
	int	count;

	len = s->size_b / 2;
	max = s->size_b;
	mean = len;
	count = -1;
	while (len--)
	{
		opti_rot(s, in_range(s, mean, max, 'B'), 'B');
		push_ab(s, 'A');
		if (--count < len)
			rotate(s, "RA");
	}
	count = s->size_b;
	while (s->size_b)
	{
		push_ab(s, 'A');
		if ((count / 2) <= s->size_b)
			rotate(s, "RA");
	}
}

void	split_by_chunck(t_sck *s, int chunck)
{
	if (chunck == 2)
	{
		first_split(s, chunck);
		do_rule_nb(s, "PA", s->size_b);
	}
	else if (chunck == 3)
	{
		first_split(s, chunck);
		split_by_3(s);
	}
}
