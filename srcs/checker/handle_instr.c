/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_instr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:24:07 by smanta            #+#    #+#             */
/*   Updated: 2020/02/17 15:24:10 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_valid_instr(char *str, size_t len)
{
	size_t	res;

	res = 0;
	if (len == 3
	&& (ft_strnequ("rra", str, len) || ft_strnequ("rrb", str, len)
		|| ft_strnequ("rrr", str, len)))
		res = 1;
	if (len == 2
	&& (ft_strnequ("ra", str, len) || ft_strnequ("rb", str, len)
		|| ft_strnequ("rr", str, len) || ft_strnequ("sa", str, len)
		|| ft_strnequ("sb", str, len) || ft_strnequ("ss", str, len)
		|| ft_strnequ("pa", str, len) || ft_strnequ("pb", str, len)))
		res = 1;
	return (res);
}

static void	read_all_remains_and_exit(t_lst *stack_a, t_lst *stack_b)
{
	int		ret;
	char	buff_one[2];

	ft_bzero(buff_one, 2);
	ret = 1;
	while (ret > 0 && buff_one[0] != '\n')
		ret = read(0, buff_one, 1);
	print_error_and_exit(stack_a, stack_b, NULL);
}

int			handle_instr(t_lst *stack_a, t_lst *stack_b)
{
	int		index;
	int		ret;
	char	buff[4];
	char	buff_one[2];

	index = 0;
	ft_bzero(buff, 4);
	while ((ret = read(0, buff_one, 1)) > 0)
	{
		if (buff_one[0] == '\n')
		{
			buff[index] = '\0';
			if (!(check_valid_instr(buff, ft_strlen(buff))))
				print_error_and_exit(stack_a, stack_b, NULL);
			exec_instr(stack_a, stack_b, buff);
			index = 0;
		}
		else
			buff[index++] = buff_one[0];
		if (index >= 4)
			read_all_remains_and_exit(stack_a, stack_b);
	}
	if (index > 0)
		print_error_and_exit(stack_a, stack_b, NULL);
	return (check_result_sort(stack_a, stack_b));
}
