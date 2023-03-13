/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:51 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/13 15:16:43 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct t_philo
{
	int				nb;
	int				m_nb;
	int				d;
	int				death;
	pthread_t		t;
	struct t_data	*data;
	unsigned long	store;
	struct timeval	d2;
	struct timeval	d1;
	pthread_mutex_t	*rf;
	pthread_mutex_t	*lf;
}				t_philo;

typedef struct t_data
{
	int				p_nb;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				nb_m;
	int				check1;
	t_philo			*philo;
	struct timeval	now;
	struct timeval	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	time;
	pthread_mutex_t	meals;
	pthread_mutex_t	death;
}				t_data;

//check 
void				check_loop(t_data *data);
int					check_arg(char **string);
int					check_data(t_data *data, int ac);

//initialize
void				initialize_forks(t_data *data);
void				initialize_philo(t_data *data);
void				initialize_mutex(t_data *data);
void				initialize_threads(t_data *data);
t_data				*initialize_general(int ac, char **av);

//actions
void				eating_action(t_philo *philo);
void				*globale_action(void	*ptr);
void				sleeping_action(t_philo *philo);
void				taking_fork_action(t_philo *philo);

//utils
int					ft_atoi(char *str);
void				ft_usleep(unsigned long time_2);
void				printf_msg(char *str, t_philo *philo, int i);

//time
unsigned long		now_time(void);
unsigned long		right_time(struct timeval time);

#endif