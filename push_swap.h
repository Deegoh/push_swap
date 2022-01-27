/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:56:53 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/27 07:10:12 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stacks
{
	int	sizemax;
	int	size_a;
	int	size_b;
	int	*a;
	int	*b;
}	t_stack;

void	swap(int **stack, char *print);
void	push_b(t_stack *stacks);
void	push_a(t_stack *stacks);
void	rotate(int **stack, char *print);
void	r_rotate(int **stack, char *print);

#endif