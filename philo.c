/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:51:19 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/28 11:28:37 by houaslam         ###   ########.fr       */
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

	// printf("++++%d\n", data->philo[data->i].nb);

	// printf("----------------------------------|%d|----------------------------------", data->i);
	// printf("check |%p|\n", data->philo[0].rf);
	// printf("check |%p|\n", data->philo[1].rf);
	// printf("check |%p|\n", data->philo[2].rf);
	// printf("check |%p|\n", data->philo[3].rf);
	// printf("check |%p|\n", data->philo[4].rf);
	// printf("check |%p|\n", data->philo[5].rf);
	// printf("check |%p|\n", data->philo[6].rf);
	// printf("check |%p|\n", data->philo[7].rf);
	int i = 0;
	while (1)
	{
			pthread_mutex_lock(data->philo[data->i].lf);
			pthread_mutex_lock(data->philo[data->i].rf);
			
			printf("%d took a fork\n", data->philo[data->i].nb);
			usleep(data->time_to_eat);
			printf("%d is eating\n", data->philo[data->i].nb);
			slee9;
			
			pthread_mutex_unlock(data->philo[data->i].lf);
			pthread_mutex_unlock(data->philo[data->i].rf);


			time_to_last =;
			eat ++;
			
			printf("%d is sleeping\n", data->philo[data->i].nb);
			
			
			if (i == data->time_to_eat)
				return NULL;
			
			usleep(data->time_to_sleep * 1000);
			prit
			printf("=====%d done\n", data->philo[data->i].nb);
	}
	return (NULL);
}

# include <string.h>

int	main(int ac, char **av)
{
	t_data		data;

	
	if (ac == 6 || ac == 5)
	{
		// memset(&data, 0, sizeof(t_data));÷
		initialize_data(&data, av, ac);
		philo_fork(&data);
		printf("test |%d|\n", data.philo_nb);
		data.i = 0;
		while (data.i < data.philo_nb - 1)
			pthread_create(&data.philo[data.i++].t, NULL, routine, &data);
		
		//pthread_mutex_lock(data.philo[6].lf);
		
		// unsigned long long o = 0;
		while (1)
		{
			if (tmie to die)
				print;
			else if (argv == valide ==)
				return ;
		}
		
	}
	else
		write(2, "NUMBER OF ARGUMENTS IS INVALID\n", 31);
}

