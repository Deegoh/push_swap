/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:56:53 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/03/30 11:40:01 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	*value;
	//int	index;
}		t_stack;

typedef struct s_stacks
{
	int		sizemax;
	t_stack	a;
	t_stack	b;
}			t_stacks;

void		error_exit(void);
void		print_stacks(t_stacks stacks);

t_stacks	init_stacks(int ac, char *av[]);

void		swap(t_stack *stack, char *print);
void		push_b(t_stacks *stacks);
void		push_a(t_stacks *stacks);
void		rotate(t_stack *stack, char *print);
void		r_rotate(t_stack *stack, char *print);
void		d_swap(t_stacks *stacks);
void		d_rotate(t_stacks *stacks);
void		d_r_rotate(t_stacks *stacks);

int			check_sort(t_stacks	stacks);
void		sort2(t_stack *stack);
void		sort3(t_stack *stack);
void		sort5(t_stacks *stacks);

#endif