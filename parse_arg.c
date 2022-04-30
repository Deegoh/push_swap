/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:15:21 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/30 15:21:14 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_dup(int	*stack_a, int len)
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

static int	arrlen(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

static char	*merge_arg(char **arg, int ac)
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

static int	*split_to_arr(char **split, int len)
{
	int	*stack;
	int	i;

	stack = calloc(sizeof(int *), len);
	i = -1;
	while (++i < len)
	{
		if (ft_atol(split[i]) > INT_MAX || ft_atol(split[i]) < INT_MIN)
			error_exit();
		stack[i] = ft_atoi(split[i]);
		free(split[i]);
	}
	free(split);
	return (stack);
}

t_stacks	init_stacks(int ac, char **av)
{
	char		*arg;
	char		**split;
	t_stacks	stacks;

	arg = merge_arg(av, ac);
	split = ft_split(arg, ' ');
	free(arg);
	stacks.sizemax = arrlen(split);
	stacks.a.value = split_to_arr(split, stacks.sizemax);
	stacks.a.size = stacks.sizemax;
	find_dup(stacks.a.value, stacks.a.size);
	return (stacks);
}
