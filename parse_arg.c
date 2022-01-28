/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:15:21 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/28 13:32:17 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stacks	init_stacks(int ac, char *av[])
{
	char	*arg;
	char	**split;
	t_stacks	stacks;
	int		i;

	arg = merge_arg(av, ac);
	split = ft_split(arg, ' ');
	stacks.sizemax = arrlen(split);
	stacks.a.value = split_to_arr(split, stacks.sizemax);
	free(arg);
	i = 0;
	while (i < stacks.sizemax)
		free(split[i++]);
	free(split);
	stacks.a.size = stacks.sizemax;
	find_dup(stacks.a.value, stacks.a.size);
	stacks.b.value = ft_calloc(sizeof(stacks.b), stacks.sizemax);
	stacks.b.size = 0;
	return (stacks);
}
