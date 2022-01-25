/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/25 20:45:55 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (1);
}

void	find_dup(char	**stack_a)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (stack_a[++i])
	{
		j = i;
		while (stack_a[++j])
		{
			if (ft_strlen(stack_a[i]) < ft_strlen(stack_a[j]))
				len = ft_strlen(stack_a[j]);
			else
				len = ft_strlen(stack_a[i]);
			if (ft_strncmp(stack_a[i], stack_a[j], len) == 0)
				error_exit();
		}
	}
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

int	main(int ac, char *av[])
{
	char	*arg;
	char	**stack_a;
	char	**stack_b;
	int		i;

	if (ac == 1)
		error_exit();
	arg = merge_arg(av, ac);
	stack_a = ft_split(arg, ' ');
	find_dup(stack_a);
	swap(&stack_a, "");
	push(&stack_a, &stack_b, "");
	i = 0;
	while (stack_a[i])
		if (stack_a[i])
			ft_printf("%s\n", (stack_a[i++]));
	printf(":)\n");
	return (0);
}
