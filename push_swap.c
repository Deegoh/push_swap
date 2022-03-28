/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/03/28 18:49:10 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (1);
}

void	print_stacks(t_stacks stacks)
{
	int		i;

	i = 0;
	printf("\nstacks\n");
	printf("s_a:%d s_b:%d\n", stacks.a.size, stacks.b.size);
	printf("sizemax:%d\n", stacks.sizemax);
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
		return(1);
	}
	print_stacks(stacks);
	exit(EXIT_SUCCESS);
}

//TODO gerer le 0
void bubbleSort(t_stacks *stacks)
{
	// while(check_sort(*stacks))
	// {

	// }
	(void)stacks;
	return;
}

void sort3(t_stacks *stacks)
{
	if (stacks->a.value[0] > stacks->a.value[1])
		swap(&stacks->a, "sa\n");
	check_sort(*stacks);
	if (stacks->a.value[0] < stacks->a.value[1])
		push_b(stacks);
	else
	{
		swap(&stacks->a, "sa\n");
		push_b(stacks);
	}
	check_sort(*stacks);
	swap(&stacks->a, "sa\n");
	push_a(stacks);
	check_sort(*stacks);
	if (stacks->a.value[0] > stacks->a.value[1])
		swap(&stacks->a, "sa\n");
	check_sort(*stacks);
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (ac == 1)
		error_exit();
	stacks = init_stacks(ac, av);
	check_sort(stacks);
	if (stacks.sizemax <= 3)
		sort3(&stacks);

	// print stacks
	// print_stacks(stacks);
	return(0);
}
