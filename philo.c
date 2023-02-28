/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:15:23 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/28 16:45:43 by houaslam         ###   ########.fr       */
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
		pthread_mutex_lock(&philo->data->forks[philo->nb - 1]);
		pthread_mutex_lock(&philo->data->forks[philo->nb]);
		printf("%d took a fork\n", philo->nb);
		usleep(philo->data->t_eat * 1000);
		printf("%d is eating\n", philo->nb);
		philo->m_nb++;
		printf("\n\nphilo %d = |%d|\n\n", philo->nb, philo->m_nb);
		pthread_mutex_unlock(&philo->data->forks[philo->nb - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->nb]);
		printf("%d is sleeping\n", philo->nb);
		usleep(philo->data->t_sleep * 1000);
		printf("%d is thinking\n", philo->nb);
	}
	return (NULL);
}

int	count_meals(t_data data)
{
	int	i;

	i = 0;
	while (i < data.p_nb)
	{
		if (data.philo[i].m_nb != data.m_nb)
			return (0);
	}
	return (1);
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
	// data->p_nb = ft_atoi(av[1]);
	// data->t_die = ft_atoi(av[2]);
	// data->t_eat = ft_atoi(av[3]);
	// data->t_sleep = ft_atoi(av[4]);
	// if (ac == 6)
	// 	data->m_nb = ft_atoi(av[5]);
	// data->philo = malloc(sizeof(t_philo) * data->p_nb);
	// data->forks = malloc(sizeof(pthread_mutex_t) * data->p_nb);
	// while (i < data->p_nb)
	// {
	// 	data->philo[i].nb = i + 1;
	// 	data->philo[i].data = data;
	// 	data->philo[i].m_nb = 0;
	// 	pthread_mutex_init(&data->forks[i], NULL);
	// 	i++;
	// }
	// i = 0;
	initialize_data(&data, av ,ac);
	printf("******%d\n", data->p_nb);
	philo_fork(data);
	while (i < data->p_nb)
	{
		pthread_create(&data->philo[i].t, NULL, routine, &data->philo[i]);
		i++;
	}
	while (i < data->p_nb - 1)
	{
		pthread_join(data->philo[i].t, NULL);
		i++;
	}
	while (1)
	{
		if (ac == 6 && count_meals(*data) == 1)
			return (0);
	}
}
