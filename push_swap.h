/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:56:53 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/25 20:05:06 by tpinto-m         ###   ########.fr       */
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
	int		size_a;
	int		size_b;
	int		max;
	int		min;
	t_node	*a;
	t_node	*b;
	t_node	*top_a;
	t_node	*end_a;
	t_node	*top_b;
	t_node	*end_b;
}			t_sck;

typedef struct s_stack
{
	int	size;
	int	*value;
}			t_stack;

typedef struct s_stacks
{
	int		sizemax;
	char	*op;
	t_node	*pivot;
	int		nbr;
	int		max;
	int		min;
	t_stack	a;
	t_stack	b;
}			t_stacks;

t_stacks	init_stacks(int ac, char *av[]);
void		set_min_max(t_sck *stacks);

void		check_rule(t_sck *stacks, char *str);
void		do_rule_nb(t_sck *stacks, char *str, int nb);
void		opti_rot(t_sck *stacks, int value, char c);
long		ft_atol(const char *str);

void		sort2(t_sck *stacks);
void		sort3(t_sck *stacks);
void		sort4(t_sck *stacks);
void		sort5(t_sck *stacks);
void		simple_sort(t_sck *stacks);

void		error_exit(void);
void		print_arr(int arr[], int n);
void		print_stacks(t_sck stacks);
int			check_sort(t_sck	stacks);
void		print_list(t_node *node);

void		append(t_node **head_ref, int new_data);
void		insert_after(t_node *prev_node, int new_data);
void		push(t_node **head_ref, int new_data);
void		delete_node(t_node **head_ref, t_node *del);
t_node		*last_node(t_node *root);

void		swap(t_sck *stacks, char c);
void		rotate(t_sck *stacks, char *str);
void		push_ab(t_sck *stacks, char c);

int			count_nodes(t_node *root);
int			count_until(t_node *root, int value);

#endif