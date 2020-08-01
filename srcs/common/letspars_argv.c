/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letspars_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:48:48 by smanta            #+#    #+#             */
/*   Updated: 2020/02/17 14:48:49 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static size_t	get_num_words(const char *str)
{
	size_t	num;
	size_t	index;
	size_t	flag;

	num = 0;
	index = 0;
	while (str[index] != '\0' && !(flag = 0))
	{
		while (ft_isspace(str[index]))
			++index;
		if (str[index] == '\0')
			break ;
		if (str[index] == '-' || str[index] == '+')
			++index;
		if (!(str[index] > 47 && str[index] < 58))
			return (0);
		while (str[index] > 47 && str[index] < 58 && (flag = 1))
			++index;
		if (str[index] != '\0' && !ft_isspace(str[index]))
			return (0);
		num = flag ? num + 1 : num;
	}
	return (num);
}

static size_t	get_nums(char *str, int32_t **nums, size_t count, size_t start)
{
	size_t				index;
	int32_t				sign;
	unsigned long long	num;

	num = 0;
	index = start;
	while (ft_isspace(str[index]))
		++index;
	sign = str[index] == '-' && (++index) ? -1 : 1;
	index = str[index] == '+' ? index + 1 : index;
	while (str[index] > 47 && str[index] < 58)
	{
		num = num * 10 + (str[index++] - 48);
		if ((sign == 1 && num >= 2147483648)
		|| (sign == -1 && num >= 2147483649))
			print_error_and_exit(NULL, NULL, NULL);
	}
	(*nums)[count] = (int32_t)(num * sign);
	return (index);
}

int				letspars_argv(t_lst *stack, char *arg, int32_t **nums_arr)
{
	size_t	len;
	size_t	num_words;
	size_t	count;
	size_t	index;

	len = ft_strlen(arg);
	if (!(num_words = get_num_words(arg)))
		return (0);
	if (!(*nums_arr = (int32_t *)malloc(sizeof(int32_t) * num_words)))
	{
		if (stack != NULL)
			free_stack(stack->begin);
		exit(1);
	}
	index = 0;
	count = 0;
	while (index < len && count < num_words)
	{
		index = get_nums(arg, nums_arr, count, index);
		++count;
	}
	return (num_words);
}
