/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:08:56 by smanta            #+#    #+#             */
/*   Updated: 2020/07/28 17:08:58 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_push_back(t_stacks *stacks, int32_t n)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
	{
		delete_stacks(stacks);
		exit(1);
	}
	node->value = n;
	node->num_moves = INT_MAX;
	node->way_to_move = 0;
	if (stacks->result->begin == NULL)
	{
		stacks->result->begin = node;
		stacks->result->end = node;
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	stacks->result->end->next = node;
	node->next = NULL;
	node->prev = stacks->result->end;
	stacks->result->end = node;
}
