/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:51:19 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/25 23:39:24 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	initialize_data(t_data *data, char **av, int ac)
{
	data->philo_nb = ft_atoi(av[1]);
	data->forks = malloc(sizeof(int) * data->philo_nb);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

void	forks(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->forks[i] = i;
		ft_lstadd_back(philo, ft_lstnew(i));
		if ((*philo)->nb == 0)
		{
			(*philo)->lf = 1;
			(*philo)->rf = 0;
		}
		else if ((*philo)->nb == data->philo_nb - 1)
		{
			(*philo)->lf = 0;
			(*philo)->rf = i;
		}
		else
		{
			(*philo)->lf = i + 1;
			(*philo)->rf = i;
		}
		i++;
		(*philo) = (*philo)->next;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;

	if (ac == 6 || ac == 5)
	{
		philo = NULL;
		initialize_data(&data, av, ac);
		forks(&data, &philo);
	}
	else
		write(2, "NUMBER OF ARGUMENTS IS INVALID\n", 31);
}
