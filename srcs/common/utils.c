/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:16:35 by smanta            #+#    #+#             */
/*   Updated: 2020/02/18 13:16:37 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t			get_len_stack(t_lst *stack)
{
	size_t	len;
	t_node	*node;

	len = 0;
	node = stack->begin;
	while (node != NULL)
	{
		node = node->next;
		++len;
	}
	return (len);
}

int				print_error_and_exit(t_lst *stack_a, t_lst *stack_b,
		int32_t *nums_arr)
{
	write(2, "Error\n", 6);
	if (stack_a != NULL)
		free_stack(stack_a->begin);
	if (stack_b != NULL)
		free_stack(stack_b->begin);
	free(nums_arr);
	exit(1);
}

static t_node	*create_node(int32_t num, t_lst *stack, int32_t *nums_arr)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
	{
		free_stack(stack->begin);
		free(nums_arr);
		exit(1);
	}
	node->value = num;
	node->num_moves = INT_MAX;
	node->way_to_move = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void		fill_stack_up_bottom(t_lst *stack,
		int32_t *nums_arr, size_t num_nums)
{
	size_t	index;
	t_node	*node;

	index = 0;
	if (stack->begin == NULL && (index = 1))
	{
		stack->begin = create_node(nums_arr[0], stack, nums_arr);
		stack->end = stack->begin;
	}
	node = stack->end;
	while (index < num_nums)
	{
		node->next = create_node(nums_arr[index], stack, nums_arr);
		node->next->prev = node;
		node = node->next;
		++index;
	}
	stack->end = node;
}

void			init_stack_with_nums(t_lst *stack, size_t argc, char **argv)
{
	size_t	index;
	size_t	num_nums;
	int32_t	*nums_arr;

	index = 1;
	while (index < argc)
	{
		nums_arr = NULL;
		if (!(num_nums = letspars_argv(stack, argv[index++], &nums_arr)))
			print_error_and_exit(stack, NULL, NULL);
		fill_stack_up_bottom(stack, nums_arr, num_nums);
		stack->len += num_nums;
		free(nums_arr);
	}
}
