/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/03 23:32:18 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_sck		stacks;

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_list(init_stacks(ac, av));
	if (check_sort(stacks))
	{
		if (stacks.size_a <= 5)
		{
			simple_sort(&stacks);
		}
		else
		{
			if (stacks.size_a <= 100)
				custom_sort(&stacks, 1, 1);
			else
				custom_sort(&stacks, 2, 8);
		}
	}
	join_op(&stacks, "");
	ft_remove_str(stacks.op, "pb\npa\n");
	// print_stacks(stacks, 500);
	ft_printf("%s", stacks.op);
	free_all(&stacks);
	return (EXIT_SUCCESS);
}
