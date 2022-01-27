/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/27 11:56:23 by tpinto-m         ###   ########.fr       */
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
	char	*arg;
	char	**split;
	t_stacks	stacks;

	if (ac == 1)
		error_exit();
	// init stack
	arg = merge_arg(av, ac);
	split = ft_split(arg, ' ');
	stacks.sizemax = arrlen(split);
	stacks.a.value = split_to_arr(split, stacks.sizemax);
	stacks.a.size = stacks.sizemax;
	find_dup(stacks.a.value, stacks.a.size);
	stacks.b.value = ft_calloc(sizeof(stacks.b), stacks.sizemax);
	stacks.b.size = 0;
	// solve (test)
//	print_stacks(stacks);
	return (0);
}
