/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/28 16:26:37 by tpinto-m         ###   ########.fr       */
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
	printf("s_a:%d s_b:%d\n\n", stacks.a.size, stacks.b.size);
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

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (ac == 1)
		error_exit();
	stacks = init_stacks(ac, av);
	// solve (test)
	int	i;

	i = -1;
	while (++i < stacks.sizemax)
	{
		if (i % 2 == 0)
		{
			while (!stacks.a.size)
			{
				int t = s1.top();
				s1.pop();
				if (s2.empty())
				{
					s2.push(t);
				}
				else
				{
					// Swapping
					if (s2.top() > t)
					{
						int temp = s2.top();
						s2.pop();
						s2.push(t);
						s2.push(temp);
					}
					else
					{
						s2.push(t);
					}
				}
			}
			// Tricky step
			a[n - 1 - i] = s2.top();
			s2.pop();
		}
		else
		{
			while (!s2.empty())
			{
				int t = s2.top();
				s2.pop();
				if (s1.empty())
				{
					s1.push(t);
				}
				else
				{
					if (s1.top() > t)
					{
						int temp = s1.top();
						s1.pop();
						s1.push(t);
						s1.push(temp);
					}
					else
					{
						s1.push(t);
					}
				}
			}
			// Tricky step
			a[n - 1 - i] = s1.top();
			s1.pop();
		}
	}
	// print stacks
	print_stacks(stacks);
	return (0);
}
