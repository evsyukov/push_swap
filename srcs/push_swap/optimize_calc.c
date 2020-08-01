/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:05:58 by smanta            #+#    #+#             */
/*   Updated: 2020/07/31 19:06:02 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	case_up_up(size_t index_a, size_t index_b)
{
	size_t	num_moves;

	num_moves = index_a <= index_b ? index_a : index_b;
	num_moves += index_a - num_moves + index_b - num_moves;
	return (num_moves);
}

static size_t	case_down_down(size_t len_a, size_t index_a,
		size_t len_b, size_t index_b)
{
	size_t	num_moves;

	num_moves = len_a - index_a <= len_b - index_b ?
			len_a - index_a : len_b - index_b;
	num_moves += len_a - (index_a + num_moves) + len_b - (index_b + num_moves);
	return (num_moves);
}

size_t			get_best_moves(t_stacks *stacks, size_t index_a,
		size_t index_b, t_node *node)
{
	size_t	num_moves[4];
	size_t	index;
	size_t	num;

	num_moves[0] = case_up_up(index_a, index_b);
	num_moves[1] = case_down_down(stacks->a->len, index_a,
			stacks->b->len, index_b);
	num_moves[2] = index_a + stacks->b->len - index_b;
	num_moves[3] = stacks->a->len - index_a + index_b;
	index = 0;
	num = INT_MAX;
	while (index < 4)
	{
		if (num_moves[index] < num)
		{
			num = num_moves[index];
			node->way_to_move = index + 1;
		}
		++index;
	}
	return (num);
}
