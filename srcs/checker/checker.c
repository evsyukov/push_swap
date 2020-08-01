/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:02:51 by smanta            #+#    #+#             */
/*   Updated: 2020/07/31 19:02:54 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	stack_a;
	t_lst	stack_b;

	if (argc == 1)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	init_stack_with_nums(&stack_a, argc, argv);
	check_doubled_nums(&stack_a);
	if (handle_instr(&stack_a, &stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a.begin);
	free_stack(stack_b.begin);
	return (0);
}
