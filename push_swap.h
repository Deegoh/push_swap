/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:56:53 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/02 18:05:27 by tpinto-m         ###   ########.fr       */
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
	int		z;
	int		count;
	int		range;
	int		btn;
	char	*op;
	char	*l_op;
	t_node	*a;
	t_node	*b;
}			t_sck;

typedef struct s_stack
{
	int	size;
	int	*value;
}			t_stack;

typedef struct s_stacks
{
	int		sizemax;
	int		max;
	int		min;
	t_stack	a;
}			t_stacks;

long		ft_atol(const char *str);
int			ft_bool(int btn);
char		*ft_remove_str(char *str, const char *sub);

void		sort2(t_sck *stacks);
void		sort3(t_sck *stacks);
void		sort4(t_sck *stacks);
void		sort5(t_sck *stacks);
void		simple_sort(t_sck *stacks);

void		swap(t_sck *stacks, char c);
void		rotate(t_sck *stacks, char *str);
void		push_ab(t_sck *stacks, char c);
void		check_rule(t_sck *stacks, char *str);
int			do_rule_nb(t_sck *stacks, char *str, int nb);

void		print_nodes(t_node *a, t_node *b);
void		print_stacks(t_sck s, int nbr);
void		error_exit(void);

void		find_dup(int *stack_a, int len);
int			arr_len(char **arr);
char		*merge_arg(char **arg, int ac);
int			*split_to_arr(char **split, int len);
int			check_sort(t_sck	stacks);

void		join_op(t_sck *stacks, char *op);
int			opti_rot(t_sck *stacks, int value, char c);
int			find_opti_top(t_sck *stacks, int a, int z, char c);
int			find_opti_bot(t_sck *stacks, int a, int z, char c);
int			is_between_value(int value, int a, int z);

int			count_nodes(t_node *root);
t_node		*count_until_index(t_node *root, int index, char c);
int			find_max(t_sck *stacks, char c);
int			find_min(t_sck *stacks, char c);
t_node		*first_node(t_node *root);

void		push(t_node **head_ref, int new_data);
void		insert_after(t_node *prev_node, int new_data);
void		append(t_node **head_ref, int new_data);
void		delete_node(t_node **head_ref, t_node *del);
t_node		*last_node(t_node *root);

void		free_all(t_sck *stacks);
t_sck		init_list(t_stacks	stacks);
t_stacks	init_stacks(int ac, char *av[]);

int			get_mean(t_sck	*stacks, char c);
void		split_by_chunck(t_sck *s, int chunck);
int			data_in_range(t_sck *stacks, int a, int z, char c);
void		custom_sort(t_sck *s, int chunck, int range);

#endif