/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:43:36 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/27 18:17:02 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct t_philo{
	pthread_t			t;
	int					nb;
	pthread_mutex_t		*lf;
	int					last_meal;
	pthread_mutex_t		*rf;
}				t_philo;

typedef struct t_data{
	int					i;
	int					*tab;
	int					philo_nb;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	struct timeval		c_time;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	struct timeval		e_time;
}				t_data;

int		ft_atoi(const char *str);
void	initialize_data(t_data *data, char **av, int ac);
void	forks(t_data *data);
void	*routine(void *ptr);

#endif