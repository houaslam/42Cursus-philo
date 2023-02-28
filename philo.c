/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:15:23 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/28 19:27:28 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//./philo [1]philo_nb [2]time_to_die [3]time_to_eat 
//[4]time_to_sleep [5]nb_of_philosophers_meals

void	*routine(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		pthread_mutex_lock(philo->rf);
		pthread_mutex_lock(philo->lf);
		printf("%d took a fork\n", philo->nb);
		usleep(philo->data->t_eat * 1000);
		printf("%d is eating\n", philo->nb);
		philo->m_nb++;
		pthread_mutex_unlock(philo->rf);
		pthread_mutex_unlock(philo->lf);
		printf("%d is sleeping\n", philo->nb);
		usleep(philo->data->t_sleep * 1000);
		printf("%d is thinking\n", philo->nb);
		if (philo->m_nb == philo->data->m_nb)
			philo->data->meals++;
	}
	return (NULL);
}

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

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	initialize_data(&data, av, ac);
	philo_fork(data);
	while (i < data->p_nb)
	{
		pthread_create(&data->philo[i].t, NULL, routine, &data->philo[i]);
		i++;
	}
	while (1)
	{
		if (ac == 6 && data->meals == data->p_nb)
			return (0);
	}
}
