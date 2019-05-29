# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 16:02:00 by tberthie          #+#    #+#              #
#    Updated: 2019/05/29 15:35:40 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(addsuffix .o, $(addprefix objs/, main operators file tools \
	   parsing resolve output free rules tokens ))

NAME = expert_system

all: $(NAME)

$(NAME): objs $(OBJS)
	gcc -o $(NAME) $(OBJS)

objs:
	mkdir objs

objs/%.o: srcs/%.c
	gcc -o $@ -c $< -I includes -g -Weverything \
		-Wno-pointer-arith -Wno-missing-noreturn -Wno-padded
	

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all
