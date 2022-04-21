/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:18:37 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/21 19:33:12 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **head_ref, int new_data)
{
	t_node	*new_node;

	/* 1. allocate node */
	new_node = (t_node *)malloc(sizeof(t_node));
	/* 2. put in the data  */
	new_node->data = new_data;
	/* 3. Make next of new node as head and previous as NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	/* 5. move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Given a node as prev_node, insert a new node after the
 * given node */
void	insert_after(t_node *prev_node, int new_data)
{
	t_node	*new_node;

	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return ;
	}
	/* 2. allocate new node */
	new_node = (t_node *)malloc(sizeof(t_node));
	/* 3. put in the data  */
	new_node->data = new_data;
	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;
	/* 5. Make the next of prev_node as new_node */
	prev_node->next = new_node;
	/* 6. Make prev_node as previous of new_node */
	new_node->prev = prev_node;
	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void	append(t_node **head_ref, int new_data)
{
	t_node	*new_node;
	t_node	*last;

	/* 1. allocate node */
	new_node = (t_node *)malloc(sizeof(t_node));
	/* 2. put in the data  */
	new_node->data = new_data;
	/* 3. This new node is going to be the last node, so make next of it as NULL*/
	new_node->next = NULL;
	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return ;
	}
	/* 5. Else traverse till the last node */
	last = *head_ref;
	while (last->next != NULL)
		last = last->next;
	/* 4. Change the next of last node */
	last->next = new_node;
	/* 7. Make last node as previous of new node */
	new_node->prev = last;
	return ;
}

// This function prints contents of linked list starting
// from the given node
void	print_list(t_node *node)
{
	t_node	*last;

	// printf("\nTraversal in forward direction \n");
	while (node != NULL)
	{
		ft_printf("%d ", node->data);
		last = node;
		node = node->next;
	}
	ft_printf("\n");
	(void)last;
	// printf("\nTraversal in reverse direction \n");
	// while (last != NULL)
	// {
	// 	printf(" %d ", last->data);
	// 	last = last->prev;
	// }
}

void	delete_node(t_node **head_ref, t_node *del)
{
	/* base case */
	if (*head_ref == NULL || del == NULL)
		return ;
	/* If node to be deleted is head node */
	if (*head_ref == del)
		*head_ref = del->next;
	/* Change next only if node to be deleted is NOT the last node */
	if (del->next != NULL)
		del->next->prev = del->prev;
	/* Change prev only if node to be deleted is NOT the first node */
	if (del->prev != NULL)
		del->prev->next = del->next;
	/* Finally, free the memory occupied by del*/
	free(del);
	return ;
}

t_node *last_node(t_node *root)
{
	while (root && root->next)
		root = root->next;
	return root;
}
