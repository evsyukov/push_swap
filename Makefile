# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smanta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 19:03:38 by smanta            #+#    #+#              #
#    Updated: 2020/02/20 17:10:42 by smanta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_A = libft.a
CHECKER_BIN = checker
PUSH_SWAP_BIN = push_swap

FLAGS = -Wall -Wextra -Werror

HEADERS = -I./includes -I./libft

LIBFT_DIR = libft

SRCS_CHECKER_C = checker/checker.c checker/handle_instr.c
SRCS_PUSH_SWAP_C = push_swap/push_swap.c push_swap/mis.c push_swap/lst.c \
push_swap/main_job.c push_swap/main_job_utils.c push_swap/optimize_calc.c \
push_swap/optimize_do.c push_swap/sort_three.c
SRCS_COMMON_C = common/exec_instr_def.c common/exec_instr_parse.c \
common/init_free.c common/letspars_argv.c common/sort_utils.c common/utils.c
SRCS_DIR = srcs

OBJS_CHECKER = $(SRCS_CHECKER_C:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP_C:.c=.o)
OBJS_COMMON = $(SRCS_COMMON_C:.c=.o)
OBJS_DIR = objs

OBJS_CHECKER_PATH   = $(addprefix $(OBJS_DIR)/, $(OBJS_CHECKER))
OBJS_PUSH_SWAP_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS_PUSH_SWAP))
OBJS_COMMON_PATH    = $(addprefix $(OBJS_DIR)/, $(OBJS_COMMON))

.PHONY: clean fclean all re

all : make_libft_a $(OBJS_COMMON_PATH) $(CHECKER_BIN) $(PUSH_SWAP_BIN)

make_libft_a :
	make -C $(LIBFT_DIR)

$(CHECKER_BIN) : $(OBJS_CHECKER_PATH) $(OBJS_COMMON_PATH)
	gcc -o $@ $(OBJS_COMMON_PATH) $(OBJS_CHECKER_PATH) $(HEADERS) $(LIBFT_DIR)/$(LIBFT_A) -g

$(PUSH_SWAP_BIN) : $(OBJS_PUSH_SWAP_PATH) $(OBJS_COMMON_PATH)
	gcc -o $@ $(OBJS_COMMON_PATH) $(OBJS_PUSH_SWAP_PATH) $(HEADERS) $(LIBFT_DIR)/$(LIBFT_A) -g

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c includes/push_swap.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(dir $(OBJS_CHECKER_PATH))
	@mkdir -p $(dir $(OBJS_PUSH_SWAP_PATH))
	@mkdir -p $(dir $(OBJS_COMMON_PATH))
	gcc -o $@ -c $< $(HEADERS) $(FLAGS) -g

clean :
	$(RM) -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) -rf $(CHECKER_BIN) $(PUSH_SWAP_BIN)
	make fclean -C $(LIBFT_DIR)

re : fclean all
