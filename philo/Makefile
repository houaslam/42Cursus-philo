# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 16:48:53 by houaslam          #+#    #+#              #
#    Updated: 2023/06/22 22:18:24 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
SRCS = philo.c \
	   outil.c \
	   initialize.c \
	   actions.c \
	   check.c


all : ${NAME}

OBJ = ${SRCS:.c=.o}

${NAME} : ${OBJ}
	cc $(CFLAGS) ${OBJ} -o ${NAME}


clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)
re: fclean all