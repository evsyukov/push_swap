/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:06:26 by smanta            #+#    #+#             */
/*   Updated: 2020/07/31 19:06:30 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	repeat_actions_support(t_lst *stack_a, t_lst *stack_b,
		size_t num_oper)
{
	if (num_oper == 6)
		exec_rx(stack_b);
	else if (num_oper == 7)
	{
		exec_rx(stack_a);
		exec_rx(stack_b);
	}
	else if (num_oper == 8)
		exec_rrx(stack_a);
	else if (num_oper == 9)
		exec_rrx(stack_b);
	else if (num_oper == 10)
	{
		exec_rrx(stack_a);
		exec_rrx(stack_b);
	}
}

static void	repeat_actions(t_stacks *stacks, size_t num_oper, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count)
	{
		if (num_oper == 0)
			exec_sx(stacks->a);
		else if (num_oper == 1)
			exec_sx(stacks->b);
		else if (num_oper == 2)
		{
			exec_sx(stacks->a);
			exec_sx(stacks->b);
		}
		else if (num_oper == 3)
			exec_px(stacks->a, stacks->b);
		else if (num_oper == 4)
			exec_px(stacks->b, stacks->a);
		else if (num_oper == 5)
			exec_rx(stacks->a);
		else
			repeat_actions_support(stacks->a, stacks->b, num_oper);
		lst_push_back(stacks, num_oper);
		++index;
	}
}

static void	do_case_up_up(t_stacks *stacks)
{
	size_t	num_moves;
	size_t	index_a;
	size_t	index_b;

	num_moves = stacks->a->best_index <= stacks->b->best_index ?
			stacks->a->best_index : stacks->b->best_index;
	index_a = stacks->a->best_index - num_moves;
	index_b = stacks->b->best_index - num_moves;
	repeat_actions(stacks, 7, num_moves);
	if (index_a != 0)
		repeat_actions(stacks, 5, index_a);
	if (index_b != 0)
		repeat_actions(stacks, 6, index_b);
}

static void	do_case_down_down(t_stacks *stacks)
{
	size_t	num_moves;
	size_t	index_a;
	size_t	index_b;

	num_moves = stacks->a->len - stacks->a->best_index <=
			stacks->b->len - stacks->b->best_index ?
			stacks->a->len - stacks->a->best_index :
			stacks->b->len - stacks->b->best_index;
	index_a = stacks->a->best_index + num_moves;
	index_b = stacks->b->best_index + num_moves;
	repeat_actions(stacks, 10, num_moves);
	if (index_a != 0)
		repeat_actions(stacks, 8, stacks->a->len - index_a);
	if (index_b != 0)
		repeat_actions(stacks, 9, stacks->b->len - index_b);
}

void		do_optimize_main(t_stacks *stacks)
{
	size_t	way_to_move;

	way_to_move = stacks->b->way_to_move;
	if (way_to_move == 1)
		do_case_up_up(stacks);
	if (way_to_move == 2)
		do_case_down_down(stacks);
	if (way_to_move == 3)
	{
		repeat_actions(stacks, 5, stacks->a->best_index);
		repeat_actions(stacks, 9, stacks->b->len - stacks->b->best_index);
	}
	if (way_to_move == 4)
	{
		repeat_actions(stacks, 8, stacks->a->len - stacks->a->best_index);
		repeat_actions(stacks, 6, stacks->b->best_index);
	}
}
