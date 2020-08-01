/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:29:14 by smanta            #+#    #+#             */
/*   Updated: 2020/02/19 19:29:20 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	output(t_lst *result_list)
{
	t_node	*node;

	node = result_list->begin;
	while (node != NULL)
	{
		ft_putstr(A[node->value]);
		write(1, "\n", 1);
		node = node->next;
	}
}

static void	do_main_job(t_stacks *stacks)
{
	find_mis(stacks);
	main_job(stacks);
}

int			main(int argc, char **argv)
{
	t_lst		stack_a;
	t_lst		stack_b;
	t_lst		result_list;
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	init_stack(&result_list);
	init_stacks(&stacks, &stack_a, &stack_b, &result_list);
	init_stack_with_nums(&stack_a, argc, argv);
	check_doubled_nums(&stack_a);
	do_main_job(&stacks);
	output(&result_list);
	delete_stacks(&stacks);
	return (0);
}
