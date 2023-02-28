/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:51:19 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/28 11:53:48 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	initialize_data(t_data *data, char **av, int ac)
{
	int	i;

	i = 0;
	data->philo_nb = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	data->philo = malloc(sizeof(t_philo) * data->philo_nb);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	while (i < data->philo_nb)
	{
		data->philo[i].nb = i + 1;
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	data->i = 0;
	// gettimeofday(&data->e_time, NULL);
}

void	philo_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{		
		if (i + 1 == data->philo_nb)
		{
			data->philo[i].lf = &data->fork[0];
			data->philo[i].rf = &data->fork[i];
			return ;
		}
		data->philo[i].lf = &data->fork[i + 1];
		data->philo[i].rf = &data->fork[i];
		i++;
	}
}

void	*routine(void	*ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while (1)
	{
		printf("data.i = %d\n", data->i);
		pthread_mutex_lock(data->philo[data->i].lf);
		pthread_mutex_lock(data->philo[data->i].rf);
		printf("%d took a fork\n", data->philo[data->i].nb);
		usleep(data->time_to_eat * 1000);
		printf("%d is eating\n", data->philo[data->i].nb);
		pthread_mutex_unlock(data->philo[data->i].lf);
		pthread_mutex_unlock(data->philo[data->i].rf);
		data->meal_nb ++;
		printf("%d is sleeping\n", data->philo[data->i].nb);
		usleep(data->time_to_sleep * 1000);
		printf("%d is thinking\n", data->philo[data->i].nb);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac == 6 || ac == 5)
	{
		initialize_data(&data, av, ac);
		philo_fork(&data);
		printf("test |%d|\n", data.philo_nb);
		data.i = 0;
		while (data.i < data.philo_nb)
		{	
			pthread_create(&data.philo[data.i++].t, NULL, routine, &data);
		}
		// while (1)
		// {
		// 	if (time(data.c_time, data.e_time) >= data.time_to_die * 1000)
		// 	{
		// 		printf(" %d ms %d died\n", );
				
		// 	}
		// 	else if (ac == 6 || data.meal_nb == )
		// 		return ;
		// }
	}
	else
		write(2, "NUMBER OF ARGUMENTS IS INVALID\n", 31);
}

