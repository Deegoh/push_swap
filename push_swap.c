/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/02/01 13:01:23 by tpinto-m         ###   ########.fr       */
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

void	check_sort(t_stacks	stacks)
{
	int	i;

	i = 0;
	while (++i < stacks.sizemax - 1)
	{
		if (stacks.a.value[i - 1] < stacks.a.value[i])
			i++;
		else
			return ;
		if (i == stacks.sizemax - 2)
		{
			printf("fini\n");
			exit(0);
		}
	}
}

//TODO gerer le 0

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	int			i;
	int			t;

	if (ac == 1)
		error_exit();
	stacks = init_stacks(ac, av);
	// solve (test)
	i = -1;
	while (++i < stacks.sizemax)
	{
		check_sort(stacks);
		if (i % 2 == 0)
		{
			while (stacks.a.size != 0)
			{
				t = stacks.a.value[0];
				if (stacks.b.size == 0)
				{
					push_b(&stacks);
				}
				else
				{
					if (stacks.b.value[0] > t)
					{
						push_b(&stacks);
						swap(&stacks.b, "sb\n");
					}
					else
					{
						push_b(&stacks);
					}
				}
			}
		}
		else
		{
			while (!stacks.b.size)
			{
				t = stacks.b.value[0];
				if (stacks.a.size == 0)
				{
					push_a(&stacks);
				}
				else
				{
					if (stacks.a.value[0] > t)
					{
						push_a(&stacks);
						swap(&stacks.a, "sa\n");
					}
					else
					{
						push_a(&stacks);
					}
				}
			}
		}
		check_sort(stacks);
	}
	i = 0;
	while (i++ < stacks.sizemax)
		push_a(&stacks);
	check_sort(stacks);
	// print stacks
	print_stacks(stacks);
	return (0);
}
