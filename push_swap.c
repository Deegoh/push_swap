/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/01 23:21:12 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bool(int btn)
{
	if (!btn)
		return (1);
	else
		return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;
	int		count;

	i = 0;
	res = 0;
	sign = 1;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i++] - '0';
		count++;
	}
	if (count > 19 && sign == 1)
		return (sign * -1);
	if (count > 19 && sign == -1)
		return (0);
	return (res * sign);
}

char	*ft_remove_str(char *str, const char *sub)
{
	int		len;
	char	*p;

	len = ft_strlen(sub);
	if (len > 0)
	{
		p = ft_strnstr(str, sub, ft_strlen(str));
		while (p)
		{
			ft_memmove(p, p + len, ft_strlen(p + len) + 1);
			p = ft_strnstr(str, sub, ft_strlen(str));
		}
	}
	return (str);
}

int	main(int ac, char *av[])
{
	t_sck		stacks;

	if (ac == 1)
		return (EXIT_FAILURE);
	stacks = init_list(init_stacks(ac, av));
	stacks.op = ft_strdup("");
	stacks.l_op = ft_strdup("");
	if (check_sort(stacks))
	{
		if (stacks.size_a <= 5)
			simple_sort(&stacks);
		else
			custom_sort(&stacks);
	}
	join_op(&stacks, "");
	ft_remove_str(stacks.op, "pb\npa\n");
	ft_printf("%s", stacks.op);
	free(stacks.l_op);
	free(stacks.op);
	free_all_nodes(&stacks);
	return (EXIT_SUCCESS);
}
