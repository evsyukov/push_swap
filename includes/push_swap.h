/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:09:11 by smanta            #+#    #+#             */
/*   Updated: 2020/02/19 19:10:10 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_node
{
	int32_t			value;
	size_t			num_moves;
	size_t			way_to_move;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_lst
{
	size_t	len;
	size_t	best_index;
	size_t	way_to_move;
	t_node	*begin;
	t_node	*end;
}				t_lst;

typedef struct	s_stacks
{
	t_lst	*a;
	t_lst	*b;
	t_lst	*result;
}				t_stacks;

# define C const char
# define A ((C*[]){"sa","sb","ss","pa","pb","ra","rb","rr","rra","rrb","rrr"})

int				handle_instr(t_lst *stack_a, t_lst *stack_b);
void			exec_px(t_lst *stack_first, t_lst *stack_sec);
void			exec_sx(t_lst *stack);
void			exec_rx(t_lst *stack);
void			exec_rrx(t_lst *stack);
void			exec_instr(t_lst *stack_a, t_lst *stack_b, char	*buff);
void			init_arr(int32_t *arr, size_t len);
void			free_stack(t_node *node);
void			init_stack(t_lst *stack);
void			init_stacks(t_stacks *stacks, t_lst *a,
		t_lst *b, t_lst *result);
void			delete_stacks(t_stacks *stacks);
int				letspars_argv(t_lst *stack, char *arg, int32_t **nums_arr);
int				check_result_sort(t_lst *stack_a, t_lst *stack_b);
void			check_doubled_nums(t_lst *stack);
size_t			get_len_stack(t_lst *stack);
int				print_error_and_exit(t_lst *stack_a,
		t_lst *stack_b, int32_t *nums_arr);
void			init_stack_with_nums(t_lst *stack, size_t argc, char **argv);
void			lst_push_back(t_stacks *stacks, int32_t n);
void			main_job(t_stacks *stacks);
void			fix_result_list(t_stacks *stacks);
void			find_mis(t_stacks *stacks);
size_t			get_best_moves(t_stacks *stacks, size_t index_a,
		size_t index_b, t_node *node);
void			do_optimize_main(t_stacks *stacks);
size_t			sort_three_main(t_stacks *stacks);
#endif
