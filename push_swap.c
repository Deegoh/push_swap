/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/27 07:41:57 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (1);
}

void	find_dup(int	*stack_a, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
			if (stack_a[i] == stack_a[j])
				error_exit();
	}
}

int	arrlen(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

char	*merge_arg(char **arg, int ac)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = ft_calloc(1, sizeof(char));
	while (++i < ac)
	{
		if (!ft_isdigit(arg[i][ft_strlen(arg[i]) - 1]))
			error_exit();
		tmp = ret;
		ret = ft_strjoin(ret, arg[i]);
		free(tmp);
		tmp = ret;
		ret = ft_strjoin(ret, " ");
		free(tmp);
	}
	return (ret);
}

int	*split_to_arr(char **split, int len)
{
	int	*stack;
	int	i;

	stack = ft_calloc(sizeof(stack), len);
	i = -1;
	while (++i < len)
		stack[i] = ft_atoi(split[i]);
	return (stack);
}

int	main(int ac, char *av[])
{
	char	*arg;
	char	**split;
	int		i;
	t_stack	stacks;

	if (ac == 1)
		error_exit();
	// init stack
	arg = merge_arg(av, ac);
	split = ft_split(arg, ' ');
	stacks.sizemax = arrlen(split);
	stacks.a = split_to_arr(split, stacks.sizemax);
	stacks.size_a = stacks.sizemax;
	find_dup(stacks.a, stacks.size_a);
	stacks.b = ft_calloc(sizeof(stacks.b), stacks.sizemax);
	stacks.size_b = 0;
	// solve (test)
//	push_b(&stacks);
//	push_b(&stacks);
//	swap(&stacks.b, "sb\n");
//	push_a(&stacks);
	// print stacks (test)
	i = 0;
	printf("\nstacks\n");
	while (i < stacks.sizemax)
	{
		if (i < stacks.size_a)
			ft_printf("a:%d ", stacks.a[i]);
		else
			ft_printf("a:  ");
		if (i < stacks.size_b)
			ft_printf("b:%d\n", stacks.b[i]);
		else
			ft_printf("b:  \n");
		i++;
	}
	return (0);
}
