# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 15:55:18 by houaslam          #+#    #+#              #
#    Updated: 2023/02/28 14:31:58 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread

SRCS = philo.c \
	  atoi.c


all : ${NAME}

OBJ = ${SRCS:.c=.o}

${NAME} : ${OBJ}
	cc $(CFLAGS) ${OBJ} -o ${NAME}

push :
	git add .
	git commit -m philo
	git push

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)
re: fclean all