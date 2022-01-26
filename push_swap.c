/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/26 20:42:34 by tpinto-m         ###   ########.fr       */
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
	int		len;
	char	**split;
	int		*stack_a;
	int		*stack_b;
	int		i;

	if (ac == 1)
		error_exit();
	arg = merge_arg(av, ac);
	split = ft_split(arg, ' ');
	len = arrlen(split);
	stack_a = split_to_arr(split, len);
	find_dup(stack_a, len);
	stack_b = ft_calloc(sizeof(stack_b), len);
	swap(&stack_a, "sa\n");
	push(&stack_b, &stack_a, len, "pb\n");
	push(&stack_b, &stack_a, len, "pb\n");
//	push(&split, &stack_b, "");
	i = 0;
	printf("len:%d\n", len);
	while (i < len)
	{
		ft_printf("i:%d a:%d ", i, (stack_a[i]));
		ft_printf("b:%d\n", (stack_b[i++]));
	}
//	printf(":)\n");
	return (0);
}
