/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:40:24 by smanta            #+#    #+#             */
/*   Updated: 2020/07/31 13:40:26 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	sort_three_support(t_stacks *stacks, int32_t *digits)
{
	size_t	adding_moving;

	adding_moving = 0;
	if (digits[2] < digits[0] && digits[0] < digits[1])
	{
		exec_rrx(stacks->a);
		lst_push_back(stacks, 8);
		++adding_moving;
	}
	else if (digits[1] < digits[2] && digits[2] < digits[0])
	{
		exec_rx(stacks->a);
		lst_push_back(stacks, 5);
		++adding_moving;
	}
	else if (digits[2] < digits[1] && digits[1] < digits[0])
	{
		exec_sx(stacks->a);
		exec_rrx(stacks->a);
		lst_push_back(stacks, 0);
		lst_push_back(stacks, 8);
		adding_moving += 2;
	}
	return (adding_moving);
}

static size_t	sort_three_actions(t_stacks *stacks, int32_t *digits)
{
	size_t	adding_moving;

	adding_moving = 0;
	if (digits[1] < digits[0] && digits[0] < digits[2])
	{
		exec_sx(stacks->a);
		lst_push_back(stacks, 0);
		++adding_moving;
	}
	else if (digits[0] < digits[2] && digits[2] < digits[1])
	{
		exec_sx(stacks->a);
		exec_rx(stacks->a);
		lst_push_back(stacks, 0);
		lst_push_back(stacks, 5);
		adding_moving += 2;
	}
	else
		adding_moving = sort_three_support(stacks, digits);
	return (adding_moving);
}

size_t			sort_three_main(t_stacks *stacks)
{
	size_t	adding_moving;
	int32_t	three_digits[3];
	t_node	*node;

	if (stacks->a->len != 3)
		return (0);
	adding_moving = 0;
	node = stacks->a->begin->next;
	three_digits[0] = node->prev->value;
	three_digits[1] = node->value;
	three_digits[2] = node->next->value;
	adding_moving = sort_three_actions(stacks, three_digits);
	return (adding_moving);
}
