# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 16:48:53 by houaslam          #+#    #+#              #
#    Updated: 2023/04/04 13:15:25 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS = philo
CFLAGS = -Wall -Wextra -Werror
SRCS_B = philo_b.c \
	     outil_b.c \
	     initialize_b.c \
	     actions_b.c \
	     check_b.c 


all : ${BONUS}

OBJ_B = ${SRCS_B:.c=.o}

${BONUS} : ${OBJ_B}
	cc $(CFLAGS) ${OBJ_B} -o ${BONUS}

clean :
	rm -f ${OBJ_B}

fclean : clean
	rm -f ${BONUS}
re: fclean all