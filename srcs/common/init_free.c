/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:39:19 by smanta            #+#    #+#             */
/*   Updated: 2020/07/31 13:39:24 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_arr(int32_t *arr, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
		arr[index++] = 0;
}

void	free_stack(t_node *node)
{
	t_node	*del_node;

	if (node == NULL)
		return ;
	while (node != NULL)
	{
		del_node = node;
		node = node->next;
		free(del_node);
	}
}

void	init_stack(t_lst *stack)
{
	stack->len = 0;
	stack->best_index = 0;
	stack->way_to_move = 0;
	stack->begin = NULL;
	stack->end = NULL;
}

void	init_stacks(t_stacks *stacks, t_lst *a, t_lst *b, t_lst *result)
{
	stacks->a = a;
	stacks->b = b;
	stacks->result = result;
}

void	delete_stacks(t_stacks *stacks)
{
	if (stacks->a != NULL)
		free_stack(stacks->a->begin);
	if (stacks->b != NULL)
		free_stack(stacks->b->begin);
	if (stacks->result != NULL)
		free_stack(stacks->result->begin);
}
