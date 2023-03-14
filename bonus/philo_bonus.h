/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:17:50 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/13 17:23:10 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>
# include <semaphore.h>
# include <stdatomic.h>

typedef struct t_philo
{
	int				d;
	int				k;
	int				nb;
	int				m_nb;
	int				death;
	pid_t			id;
	sem_t			rf;
	sem_t			lf;
	struct t_data	*data;
	struct timeval	store;
}				t_philo;

typedef struct t_data
{
	int				nb_m;
	int				p_nb;
	int				t_die;
	int				t_eat;
	int				check1;
	int				t_sleep;
	sem_t			*eat;
	sem_t			*sem;
	sem_t			*death;
	sem_t			*print;
	t_philo			*philo;
	pthread_t		t;
	struct timeval	now;
	struct timeval	start_time;
}				t_data;

//initialize
void				initialize_process(t_data *data);
void				initialize_childs_b(t_data *data);
t_data				*initialize_general_b(int ac, char **av);

//check
void				*check_loop_b(void	*arg);
void				check_arg(char **str);
void				check_data(t_data *data, int ac);

//action
void				taking_fork_action_b(t_philo *philo);
void				general_action_b(t_philo *philo);
void				eating_action_b(t_philo *philo);
void				sleeping_action_b(t_philo *philo);

//time
int					now_time(void);
int					right_time(struct timeval time);

//outils
int					ft_atoi(char *str);
void				ft_usleep(unsigned long time_2);
void				printf_msg(char *str, t_philo *philo);
void				ft_putstr_fd(char *s, int fd);
void				check_wait(t_data *data);

#endif