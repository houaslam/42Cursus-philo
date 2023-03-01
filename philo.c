/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:15:23 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/01 21:29:29 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//./philo [1]philo_nb [2]time_to_die [3]time_to_eat 
//[4]time_to_sleep [5]nb_of_philosophers_meals

void	philo_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_nb)
	{		
		if (i + 1 == data->p_nb)
		{
			data->philo[i].lf = &data->forks[0];
			data->philo[i].rf = &data->forks[i];
			return ;
		}
		data->philo[i].lf = &data->forks[i + 1];
		data->philo[i].rf = &data->forks[i];
		i++;
	}
}

unsigned long	time_for_action(t_philo *philo)
{
	gettimeofday(&philo->data->now, NULL);
	philo->data->res = (philo->data->now.tv_sec - philo->data->start.tv_sec) \
	*1000000 + philo->data->now.tv_usec - philo->data->start.tv_usec;
	return (philo->data->res / 1000);
}

void	*routine(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		pthread_mutex_lock(philo->rf);
		pthread_mutex_lock(philo->lf);
		printf("%lu ms %d took a fork\n", time_for_action(philo), philo->nb);
		usleep(philo->data->t_eat * 1000);
		gettimeofday(&philo->t1, NULL);
		printf("%lu ms %d is eating\n", time_for_action(philo), philo->nb);
		philo->m_nb++;
		pthread_mutex_unlock(philo->rf);
		pthread_mutex_unlock(philo->lf);
		usleep(philo->data->t_sleep * 1000);
		printf("%lu ms %d is sleeping\n", time_for_action(philo), philo->nb);
		printf("%lu ms %d is thinking\n", time_for_action(philo), philo->nb);
		if (philo->m_nb == philo->data->m_nb)
			philo->data->meals++;
		gettimeofday(&philo->t2, NULL);
		philo->rt = philo->t2.tv_sec * 1000 - philo->t1.tv_sec * \
		1000 + philo->t2.tv_usec / 1000 - philo->t1.tv_usec / 1000;
	}
	return (NULL);
}

int	the_infinite_loop(t_data *data, int ac)
{
	int	i;

	i = 0;
	while (i < data->p_nb)
	{
		if (ac == 6 && data->meals == data->p_nb)
			return (0);
		if (data->philo[i].rt > (unsigned long)data->t_die)
		{
			printf("philo %d died\n", i + 1);
			return (0);
		}
		i++;
		if (i == data->p_nb)
			i = 0;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (check_int(av) == 0)
		return (1);
	initialize_data(&data, av, ac);
	if (check_value(data) == 0)
		return (1);
	philo_fork(data);
	gettimeofday(&data->start, NULL);
	while (i < data->p_nb)
	{
		pthread_create(&data->philo[i].t, NULL, routine, &data->philo[i]);
		i++;
	}
	if (the_infinite_loop(data, ac) == 0)
		return (0);
}
