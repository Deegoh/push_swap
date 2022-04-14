/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:56:53 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/14 16:44:37 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_lst
{
	int		data;
	t_lst	*next;
	t_lst	*prev;
}			t_lst;

typedef struct s_sck
{
	int		top_a;
	int		end_a;
	int		top_b;
	int		end_b;
	int		size_a;
	int		size_b;
	t_lst	a;
	t_lst	b;
}			t_sck;

typedef struct s_stack
{
	int	size;
	int	*value;
}			t_stack;

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

void		check_rule(t_stacks *stacks, char *str);
void		do_rule_nb(t_stacks *stacks, char *str, int nb);
void		opti_rot(t_stacks *stacks, t_stack *stack, int value, char c);
long		ft_atol(const char *str);

int			check_sort(t_stacks	stacks);
void		sort2(t_stack *stack);
void		sort3(t_stack *stack);
void		sort4(t_stacks *stacks);
void		sort5(t_stacks *stacks);
void		simple_sort(t_stacks *stacks);

void		swapp(int *a, int *b);
int			partition_ite(t_stacks *stacks, int arr[], int l, int h);
void		quicksort_ite(t_stacks *stacks, int arr[], int l, int h);
void		swappp(t_stacks *stacks, int i, int j);

void		sort_stack(t_stacks *stacks);
void		sorted_insert(t_stacks *stacks, int x);

void		print_arr(int arr[], int n);
void		print_stacks(t_stacks stacks);

#endif