/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:44:12 by smanta            #+#    #+#             */
/*   Updated: 2020/07/28 14:44:20 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_max(t_lst *stack_a, int32_t *arr, int32_t *pos)
{
	size_t	index;
	int32_t	res;
	t_node	*node;
	t_node	*node_end;

	index = 0;
	res = arr[0];
	node = stack_a->begin;
	*pos = -1;
	while (index < stack_a->len)
	{
		if (arr[index] > res)
		{
			res = arr[index];
			*pos = index;
			node_end = node;
		}
		++index;
		node = node->next;
	}
	return (node_end);
}

static size_t	do_mark_mis(t_node *node, int32_t *anc,
		int32_t pos, int32_t *arr)
{
	size_t	num_sorted;
	size_t	move_len;

	num_sorted = 0;
	while (pos != -1)
	{
		arr[pos] = 1;
		++num_sorted;
		move_len = pos - anc[pos];
		while (move_len--)
			node = node->prev;
		pos = anc[pos];
	}
	return (num_sorted);
}

static void		move_to_another_stack(t_stacks *stacks,
		int32_t *arr, size_t num_sorted)
{
	size_t	index;
	size_t	start_len;
	size_t	num_non_sorted;
	size_t	adding_moving;

	index = 0;
	start_len = stacks->a->len;
	num_non_sorted = start_len - num_sorted;
	while (index < start_len && num_non_sorted > 0 && stacks->a->len > 3)
	{
		if (arr[index] == 1)
			exec_rx(stacks->a);
		else
		{
			exec_px(stacks->a, stacks->b);
			++(stacks->b->len);
			--(stacks->a->len);
			--(num_non_sorted);
		}
		lst_push_back(stacks, 4 + arr[index]);
		++index;
	}
	if ((adding_moving = 0) == 0 && num_non_sorted > 0)
		adding_moving = sort_three_main(stacks);
	stacks->result->len = index + adding_moving;
}

static void		main_job_find_mis(t_stacks *stacks, int32_t *arr, int32_t *anc)
{
	int32_t	ind_left;
	int32_t	ind_right;
	t_node	*left;
	t_node	*right;

	ind_right = -1;
	right = stacks->a->begin;
	while (++ind_right < (int32_t)stacks->a->len)
	{
		arr[ind_right] = 1;
		anc[ind_right] = -1;
		ind_left = -1;
		left = stacks->a->begin;
		while (++ind_left < (int32_t)ind_right)
		{
			if (left->value < right->value
			&& arr[ind_left] + 1 > arr[ind_right])
			{
				arr[ind_right] = arr[ind_left] + 1;
				anc[ind_right] = ind_left;
			}
			left = left->next;
		}
		right = right->next;
	}
}

void			find_mis(t_stacks *stacks)
{
	int32_t	*arr;
	int32_t	*anc;
	int32_t	pos;
	t_node	*node_end;
	size_t	num_sorted;

	if (!(arr = (int32_t*)malloc(sizeof(int32_t) * stacks->a->len))
	|| !(anc = (int32_t*)malloc(sizeof(int32_t) * stacks->a->len)))
	{
		free(arr);
		delete_stacks(stacks);
		exit(1);
	}
	main_job_find_mis(stacks, arr, anc);
	node_end = get_max(stacks->a, arr, &pos);
	init_arr(arr, stacks->a->len);
	num_sorted = do_mark_mis(node_end, anc, pos, arr);
	free(anc);
	move_to_another_stack(stacks, arr, num_sorted);
	free(arr);
}
