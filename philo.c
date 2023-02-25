/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:51:19 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/25 21:16:36 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		data;

	if (ac == 6 || ac == 5)
	{
		initialize_data(&data, av, ac);
	}
	else
		write(2, "NUMBER OF ARGUMENTS IS INVALID\n", 31);
}

void	initialize_data(t_data *data, char **av, int ac)
{
	data->philo_nb = ft_atoi(av[1]);
	data->forks = malloc(sizeof(int) * data->philo_nb);
	forks(data);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[5]);
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	data->philo->lf = data->philo->nb - 1;
}

void	forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->forks[i] = i;
		i++;
	}
}


