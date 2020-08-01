/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:03:53 by smanta            #+#    #+#             */
/*   Updated: 2020/07/31 19:03:55 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_instr_support(t_lst *stack_a, t_lst *stack_b, char *buff)
{
	if (ft_strnequ(buff, "ra", 2))
		exec_rx(stack_a);
	else if (ft_strnequ(buff, "rb", 2))
		exec_rx(stack_b);
	else if (ft_strnequ(buff, "rrr", 3))
	{
		exec_rrx(stack_a);
		exec_rrx(stack_b);
	}
	else if (ft_strnequ(buff, "rra", 3))
		exec_rrx(stack_a);
	else if (ft_strnequ(buff, "rrb", 3))
		exec_rrx(stack_b);
}

void		exec_instr(t_lst *stack_a, t_lst *stack_b, char *buff)
{
	if (ft_strnequ(buff, "ss", 2))
	{
		exec_sx(stack_a);
		exec_sx(stack_b);
	}
	else if (ft_strnequ(buff, "sa", 2))
		exec_sx(stack_a);
	else if (ft_strnequ(buff, "sb", 2))
		exec_sx(stack_b);
	else if (ft_strnequ(buff, "pa", 2))
		exec_px(stack_b, stack_a);
	else if (ft_strnequ(buff, "pb", 2))
		exec_px(stack_a, stack_b);
	else if (ft_strnequ(buff, "rr", 3))
	{
		exec_rx(stack_a);
		exec_rx(stack_b);
	}
	else
		exec_instr_support(stack_a, stack_b, buff);
}
