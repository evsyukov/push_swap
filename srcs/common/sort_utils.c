/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:07:10 by smanta            #+#    #+#             */
/*   Updated: 2020/02/18 19:07:13 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		lets_insert_sort_arr(int32_t *arr, size_t len)
{
	int32_t	index_left;
	int32_t	index_right;
	int32_t	cache;

	if (arr == NULL || len == 0 || len == 1)
		return ;
	index_right = 1;
	while (index_right < (int32_t)len)
	{
		index_left = index_right - 1;
		while (index_left >= 0 && arr[index_left] > arr[index_left + 1])
		{
			cache = arr[index_left];
			arr[index_left] = arr[index_left + 1];
			arr[index_left + 1] = cache;
			--index_left;
		}
		++index_right;
	}
}

static int		check_double_sorted_values(const int32_t *arr, size_t len)
{
	size_t	index;

	if (len == 0 || len == 1 || arr == NULL)
		return (0);
	index = 1;
	while (index < len)
	{
		if (arr[index] == arr[index - 1])
			return (1);
		++index;
	}
	return (0);
}

static int32_t	*get_sorted_copy_stack(t_lst *stack)
{
	int32_t	*nums_arr;
	size_t	index;
	t_node	*node;

	if (!(nums_arr = (int32_t *)malloc(sizeof(int32_t) * stack->len)))
		return (NULL);
	index = 0;
	node = stack->begin;
	while (index < stack->len && node != NULL)
	{
		nums_arr[index] = node->value;
		node = node->next;
		++index;
	}
	lets_insert_sort_arr(nums_arr, stack->len);
	return (nums_arr);
}

int				check_result_sort(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*node;
	int32_t	prev;

	if (stack_b->begin != NULL)
		return (0);
	prev = stack_a->begin->value;
	node = stack_a->begin->next;
	while (node != NULL)
	{
		if (node->value <= prev)
			return (0);
		prev = node->value;
		node = node->next;
	}
	return (1);
}

void			check_doubled_nums(t_lst *stack)
{
	int32_t *nums_arr;

	if (!(nums_arr = get_sorted_copy_stack(stack)))
	{
		if (stack != NULL)
			free_stack(stack->begin);
		exit(1);
	}
	if (check_double_sorted_values(nums_arr, stack->len))
		print_error_and_exit(stack, NULL, nums_arr);
	free(nums_arr);
}
