/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:03:38 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/04/11 10:56:04 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

void	print_stacks(t_stacks stacks)
{
	int		i;

	i = 0;
	printf("\nstacks\n");
	printf("sizemax:%d\n", stacks.sizemax);
	printf("s_a:%d s_b:%d\n", stacks.a.size, stacks.b.size);
	while (i < stacks.sizemax)
	{
		if (i < stacks.a.size)
			ft_printf("a:%d ", stacks.a.value[i]);
		else
			ft_printf("a:  ");
		if (i < stacks.b.size)
			ft_printf("b:%d\n", stacks.b.value[i]);
		else
			ft_printf("b:\n");
		i++;
	}
}

int	check_sort(t_stacks	stacks)
{
	int	i;

	i = 0;
	while (++i < stacks.sizemax)
	{
		if (stacks.a.value[i - 1] < stacks.a.value[i])
			continue ;
		return (1);
	}
	// print_stacks(stacks);
	exit(EXIT_SUCCESS);
}
//TODO gerer intmax

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
    int i;
	
	i = -1;
    while (i++ < n)
	{
        printf("%d ", arr[i]);
	}
	printf("\n");
}

// A utility function to swap two elements
void swapp(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
	printf("swapp(%d, %d)\n", *a, *b);
}
 
/* This function is same in both iterative and recursive*/
int partition(int arr[], int l, int h, int maxarr)
{
    int x;
    int i;
	int j;

	x = arr[h];
	i = (l - 1);
	j = l;
    while (j <= h - 1)
	{
        if (arr[j] <= x) {
            i++;
			if (&arr[i] != &arr[j])
			{
				printf("avant:");
				printArr(arr, maxarr);
				swapp(&arr[i], &arr[j]);
				printf("apres:");
				printArr(arr, maxarr);
			}
        }
		j++;
    }
	if (&arr[i + 1] != &arr[h])
	{
		printf("avant:");
		printArr(arr, maxarr);
		swapp(&arr[i + 1], &arr[h]);
		printf("apres:");
		printArr(arr, maxarr);
		printf("%d[%d] = partition(l[%d], h[%d])\n", i + 1, arr[i + 1], l, h);
	}
    return (i + 1);
}
 
/* A[] --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */
void quickSortIterative(int arr[], int l, int h, int maxarr)
{
	printf("quick: l[%d] h[%d]\n      ", l, h);
	printArr(arr, h);
    // Create an auxiliary stack
    int stack[h - l + 1];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
 
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h, maxarr);
		printf("quick: p[%d]\n", p);
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
 
// Driver program to test above functions
// int main()
// {
//     int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
//     int n = sizeof(arr) / sizeof(*arr);
//     quickSortIterative(arr, 0, n - 1);
//     return 0;
// }

int	main(int ac, char *av[])
{
	t_stacks	stacks;

	if (ac == 1)
		error_exit();
	stacks = init_stacks(ac, av);
	check_sort(stacks);
	if (stacks.sizemax == 2)
		sort2(&stacks.a);
	else if (stacks.sizemax == 3)
		sort3(&stacks);
	// else if (stacks.sizemax <= 5)
	// 	algo5();
	// printArr(stacks.a.value, stacks.a.size - 1);
	quickSortIterative(stacks.a.value, 0, stacks.a.size - 1, stacks.a.size - 1);

	// print stacks
	print_stacks(stacks);
	return (0);
}
