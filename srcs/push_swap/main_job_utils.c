/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_job_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:40:10 by smanta            #+#    #+#             */
/*   Updated: 2020/07/31 13:40:12 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_up_in_stack(t_stacks *stacks, size_t num_stack)
{
	int32_t	flag;
	size_t	moves;
	int32_t	type_moving;
	size_t	index;

	moves = stacks->a->best_index <= stacks->a->len / 2 ?
			stacks->a->best_index : stacks->a->len - stacks->a->best_index;
	flag = stacks->a->best_index <= stacks->a->len / 2 ? 1 : -1;
	index = 0;
	while (index < moves)
	{
		type_moving = flag > 0 ? 5 + num_stack : 8 + num_stack;
		if (flag > 0)
			exec_rx(stacks->a);
		else
			exec_rrx(stacks->a);
		lst_push_back(stacks, type_moving);
		++index;
	}
}

void		fix_result_list(t_stacks *stacks)
{
	t_node	*node;
	int32_t	min_value;
	size_t	index;
	size_t	index_min_value;

	node = stacks->a->begin;
	min_value = INT_MAX;
	index = 0;
	index_min_value = 0;
	while (node != NULL)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			index_min_value = index;
		}
		node = node->next;
		++index;
	}
	stacks->a->best_index = index_min_value;
	do_up_in_stack(stacks, 0);
}
