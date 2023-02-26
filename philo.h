/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:43:36 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/26 20:42:43 by houaslam         ###   ########.fr       */
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

typedef struct t_philo{
	pthread_t			t;
	int					nb;
	int					lf;
	int					rf;
	struct	t_philo		next;
}				t_philo;

typedef struct t_data{
	int		*tab;
	int		philo_nb;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	int		*forks;
	t_philo	*philo;
}				t_data;

int		ft_atoi(const char *str);
void	initialize_data(t_data *data, char **av, int ac);
void	forks(t_data *data);
int		philo_took_fork(t_data *data, int lf, int rf);

#endif