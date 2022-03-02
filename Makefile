# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 17:48:25 by modysseu          #+#    #+#              #
#    Updated: 2021/11/17 20:42:13 by modysseu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIST	=	ft_printf.c\
			ft_print_c.c\
			ft_print_s.c\
			ft_print_d_i.c\
			ft_print_u.c\
			ft_print_p.c\
			ft_print_lx.c\
			ft_print_ux.c

HEADER	=	ft_printf.h			
			
OBJ = $(LIST:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $? 

%.o : %.c $(HEADER) Makefile
	gcc $(FLAGS) -c $< -o $@ 
	
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re