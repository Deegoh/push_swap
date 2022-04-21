/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:56:53 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/21 15:47:02 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_sck
{
	int		top_a;
	int		end_a;
	int		top_b;
	int		end_b;
	int		size_a;
	int		size_b;
	t_node	a;
	t_node	b;
}			t_sck;

typedef struct s_stack
{
	int	size;
	int	*value;
}			t_stack;

typedef struct s_stacks
{
	int		sizemax;
	int		op;
	int		pivot;
	int		max;
	int		min;
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
void		swapppp(t_stacks *stacks, int *a, int *b);
int			partition_ite(t_stacks *stacks, int arr[], int l, int h);
void		quicksort(t_stacks *stacks, int arr[], int l, int h);
void		swappp(t_stacks *stacks, int i, int j);

void		sort_stack(t_stacks *stacks);
void		sorted_insert(t_stacks *stacks, int x);

void		print_arr(int arr[], int n);
void		print_stacks(t_stacks stacks);

void		print_list(t_node *node);
void		append(t_node **head_ref, int new_data);
void		insert_after(t_node *prev_node, int new_data);
void		push(t_node **head_ref, int new_data);

void		set_min_max(t_stacks *stacks);

#endif