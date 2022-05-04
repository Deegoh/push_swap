/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:03:09 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/04 17:12:46 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_node *root)
{
	int	i;

	i = 0;
	while (root)
	{
		root = root->next;
		i++;
	}
	return (i);
}

t_node	*count_until_index(t_node *root, int index, char c)
{
	t_node	*tmp;

	if (c == 'T')
		tmp = root;
	else
		tmp = last_node(root);
	if (!tmp)
		return (NULL);
	while (tmp && index--)
	{
		if (c == 'T')
			tmp = tmp->next;
		else
			tmp = tmp->prev;
	}
	return (tmp);
}

int	find_max(t_sck *stacks, char c)
{
	int		value;
	t_node	*tmp;

	if (c == 'A')
		tmp = stacks->a;
	else
		tmp = stacks->b;
	value = -1;
	while (tmp)
	{
		if (value < tmp->i)
			value = tmp->i;
		tmp = tmp->next;
	}
	tmp = first_node(tmp);
	return (value);
}

int	find_min(t_sck *stacks, char c)
{
	int		value;
	t_node	*tmp;

	if (c == 'A')
		tmp = stacks->a;
	else
		tmp = stacks->b;
	value = INT_MAX;
	while (tmp)
	{
		if (value > tmp->i)
			value = tmp->i;
		tmp = tmp->next;
	}
	tmp = first_node(tmp);
	return (value);
}

t_node	*first_node(t_node *root)
{
	while (root && root->prev)
		root = root->prev;
	return (root);
}
