/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_ultils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:03:09 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/25 20:04:43 by tpinto-m         ###   ########.fr       */
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

int	count_until(t_node *root, int value)
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