/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:17:50 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/10 12:35:40 by houaslam         ###   ########.fr       */
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
	int				nb;
	int				m_nb;
	struct t_data	*data;
	int				death;
	sem_t			rf;
	sem_t			lf;
	struct timeval	store;
	pid_t			id;
	int				d;
	int				k;
}				t_philo;

typedef struct t_data
{
	sem_t			*death;
	int				p_nb;
	pthread_t		t;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	sem_t			*print;
	struct timeval	start_time;
	int				nb_m;
	int				check1;
	sem_t			*sem;
	t_philo			*philo;
	sem_t			*eat;
	struct timeval	now;
}				t_data;

//initialize
t_data				*initialize_general_b(int ac, char **av);
void				initialize_childs_b(t_data *data);
void				initialize_process(t_data *data);

//check
void				*check_loop_b(void	*arg);
int					check_data(t_data *data, int ac);
int					check_arg(char **str);

//action
void				taking_fork_action_b(t_philo *philo);
void				general_action_b(t_philo *philo);
void				eating_action_b(t_philo *philo);
void				sleeping_action_b(t_philo *philo);

//time
int					now_time(void);
int					right_time(struct timeval time);

//outils
int					ft_atoi(const char *str);
void				ft_usleep(unsigned long time_2);
void				printf_msg(char *str, t_philo *philo);
void				ft_putstr_fd(char *s, int fd);
void				check_wait(t_data *data);

#endif