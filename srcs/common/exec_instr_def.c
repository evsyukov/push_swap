/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr_def.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:39:41 by smanta            #+#    #+#             */
/*   Updated: 2020/07/31 13:39:43 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_px(t_lst *stack_first, t_lst *stack_sec)
{
	t_node	*node_first;
	t_node	*node_second;

	if (stack_first->begin == NULL)
		return ;
	node_first = stack_first->begin;
	stack_first->begin = node_first->next;
	node_second = stack_sec->begin;
	stack_sec->begin = node_first;
	if (node_first->next != NULL)
		node_first->next->prev = NULL;
	node_first->next = node_second;
	node_first->prev = NULL;
	if (node_second != NULL)
		node_second->prev = node_first;
	stack_first->end = stack_sec->begin == NULL ? NULL : stack_first->end;
	stack_sec->end = stack_sec->end == NULL ? node_first : stack_sec->end;
}

void	exec_sx(t_lst *stack)
{
	t_node	*node_first;
	t_node	*node_second;

	if (stack->begin == NULL || stack->begin == stack->end)
		return ;
	node_first = stack->begin;
	node_second = stack->begin->next;
	if (node_second->next != NULL)
		node_second->next->prev = node_first;
	node_first->next = node_second->next;
	node_first->prev = node_second;
	node_second->next = node_first;
	node_second->prev = NULL;
	stack->begin = node_second;
	stack->end = stack->end == node_second ? node_first : stack->end;
}

void	exec_rx(t_lst *stack)
{
	t_node	*node_first;
	t_node	*node_second;

	if (stack->begin == NULL || stack->begin == stack->end)
		return ;
	node_first = stack->begin;
	node_second = stack->end;
	if (node_first->next == stack->end)
	{
		exec_sx(stack);
		return ;
	}
	stack->begin = node_first->next;
	stack->begin->prev = NULL;
	stack->end = node_first;
	node_second->next = node_first;
	node_first->next = NULL;
	node_first->prev = node_second;
}

void	exec_rrx(t_lst *stack)
{
	t_node	*node_first;
	t_node	*node_second;

	if (stack->begin == NULL || stack->begin == stack->end)
		return ;
	node_first = stack->end;
	node_second = stack->begin;
	if (node_first->prev == node_second)
	{
		exec_sx(stack);
		return ;
	}
	stack->end = node_first->prev;
	stack->end->next = NULL;
	stack->begin = node_first;
	node_second->prev = node_first;
	node_first->prev = NULL;
	node_first->next = node_second;
}
