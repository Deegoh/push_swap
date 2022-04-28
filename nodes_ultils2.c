/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_ultils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:03:09 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/28 17:35:07 by tpinto-m         ###   ########.fr       */
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

int	count_until_value(t_node *root, int value)
{
	int	i;

	i = 0;
	while (root)
	{
		i++;
		if (root->data == value)
			return (i);
		root = root->next;
	}
	return (i);
}

t_node	*count_until_index(t_node *root, int index, char c)
{
	int		i;
	t_node	*tmp;

	if (c == 'T')
		tmp = root;
	else
		tmp = last_node(root);
	i = 0;
	while (tmp && index--)
	{
		if (c == 'T')
			tmp = tmp->next;
		else
			tmp = tmp->prev;
	}
	return (tmp);
}

t_node	*first_node(t_node *root)
{
	while (root && root->prev)
		root = root->prev;
	return (root);
}
