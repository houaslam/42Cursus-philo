# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 16:48:53 by houaslam          #+#    #+#              #
#    Updated: 2023/03/10 16:05:53 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS = philo_bonus
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3

SRCS = mandatory/philo.c \
	   mandatory/outil.c \
	   mandatory/initialize.c \
	   mandatory/actions.c \
	   mandatory/check.c

SRCS_B = bonus/philo_b.c \
	     bonus/outil_b.c \
	     bonus/initialize_b.c \
	     bonus/actions_b.c \
	     bonus/check_b.c 


all : ${NAME}
bonus : ${BONUS}

OBJ = ${SRCS:.c=.o}
OBJ_B = ${SRCS_B:.c=.o}

${NAME} : ${OBJ}
	cc $(CFLAGS) ${OBJ} -o ${NAME}

${BONUS} : ${OBJ_B}
	cc $(CFLAGS) ${OBJ_B} -o ${BONUS}

push :
	git add .
	git commit -m philo
	git push

clean :
	rm -f ${OBJ_B}
	rm -f ${OBJ}

fclean : clean
	rm -f ${BONUS}
	rm -f $(NAME)
re: fclean all