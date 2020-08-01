/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:47:55 by smanta            #+#    #+#             */
/*   Updated: 2020/07/28 15:47:58 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	make_compare(t_node *node, t_node *node_b,
		size_t index_a, size_t index)
{
	if (node->prev == NULL && node_b->value < node->value)
		index_a = index;
	if (node->prev != NULL
		&& node_b->value > node->prev->value && node_b->value < node->value)
		index_a = index;
	if (node->prev != NULL
		&& node_b->value > node->prev->value && node_b->value > node->value
		&& node->value < node->prev->value)
		index_a = index;
	if (node->prev != NULL
		&& node_b->value < node->prev->value && node_b->value < node->value
		&& node->value < node->prev->value)
		index_a = index;
	return (index_a);
}

static size_t	find_place_to_push(t_stacks *stacks,
		size_t index_b, t_node *node_b)
{
	size_t	num;
	t_node	*node;
	size_t	index;
	size_t	index_a;

	num = 0;
	node = stacks->a->begin;
	index = 0;
	index_a = 0;
	while (node != NULL)
	{
		index_a = make_compare(node, node_b, index_a, index);
		node = node->next;
		++index;
	}
	num = get_best_moves(stacks, index_a, index_b, node_b);
	node_b->num_moves = num + 1;
	return (index_a);
}

static void		move_from_b_to_a(t_stacks *stacks)
{
	do_optimize_main(stacks);
	exec_px(stacks->b, stacks->a);
	lst_push_back(stacks, 3);
	++(stacks->a->len);
	--(stacks->b->len);
}

void			main_job(t_stacks *stacks)
{
	int32_t	index;
	t_node	*node;
	size_t	index_a;
	size_t	best_num_moves;

	while (stacks->b->len > 0 && (index = -1) == -1)
	{
		node = stacks->b->begin;
		best_num_moves = INT_MAX;
		while (node != NULL)
		{
			index_a = find_place_to_push(stacks, ++index, node);
			if (node->num_moves < best_num_moves)
			{
				best_num_moves = node->num_moves;
				stacks->b->best_index = index;
				stacks->b->way_to_move = node->way_to_move;
				stacks->a->best_index = index_a;
			}
			node = node->next;
		}
		move_from_b_to_a(stacks);
	}
	fix_result_list(stacks);
	stacks->result->len = get_len_stack(stacks->result);
}
