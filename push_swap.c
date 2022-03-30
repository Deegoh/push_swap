/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/03/30 14:24:37 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

void	print_stacks(t_stacks stacks)
{
	int		i;

	i = 0;
	printf("\nstacks\n");
	printf("sizemax:%d\n", stacks.sizemax);
	printf("s_a:%d s_b:%d\n", stacks.a.size, stacks.b.size);
	while (i < stacks.sizemax)
	{
		if (i < stacks.a.size)
			ft_printf("a:%d ", stacks.a.value[i]);
		else
			ft_printf("a:  ");
		if (i < stacks.b.size)
			ft_printf("b:%d\n", stacks.b.value[i]);
		else
			ft_printf("b:\n");
		i++;
	}
}

int	check_sort(t_stacks	stacks)
{
	int	i;

	i = 0;
	while (++i < stacks.sizemax)
	{
		if (stacks.a.value[i - 1] < stacks.a.value[i])
			continue ;
		return (1);
	}
	// print_stacks(stacks);
	exit(EXIT_SUCCESS);
}
//TODO gerer intmax
int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (ac == 1)
		error_exit();
	stacks = init_stacks(ac, av);
	check_sort(stacks);
	if (stacks.sizemax == 2)
		sort2(&stacks.a);
	else if (stacks.sizemax == 3)
		sort3(&stacks.a);
	else if (stacks.sizemax <= 5)
		sort5(&stacks);

	// print stacks
	// print_stacks(stacks);
	return (0);
}
