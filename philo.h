/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:43:36 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/01 17:34:23 by houaslam         ###   ########.fr       */
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
	int					m_nb;
	struct t_data		*data;
	struct timeval		lm_t;
	pthread_mutex_t		*rf;
	pthread_mutex_t		*lf;
	struct timeval		t2;
	struct timeval		t1;
	unsigned long		rt;
}				t_philo;

typedef struct t_data{
	struct timeval	start;
	struct timeval	now;
	int				res;
	int				p_nb;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				m_nb;
	int				meals;
	t_philo			*philo;
	int				r_time;
	pthread_mutex_t	*forks;
}	t_data;

int		ft_atoi(const char *str);
void	initialize_data(t_data **data, char **av, int ac);
int		count_meals(t_data data);
int		check_int(char **str);
int		check_value(t_data *data);

#endif