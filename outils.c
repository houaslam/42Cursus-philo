/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:29:49 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/28 19:26:53 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > INT_MAX && sign > 0)
			return (-1);
		if (nb > INT_MAX && sign < 0)
			return (0);
		i++;
	}
	return (nb * sign);
}

void	initialize_data(t_data **data, char **av, int ac)
{
	int		i;

	i = 0;
	(*data) = malloc(sizeof(t_data));
	(*data)->p_nb = ft_atoi(av[1]);
	(*data)->t_die = ft_atoi(av[2]);
	(*data)->t_eat = ft_atoi(av[3]);
	(*data)->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->m_nb = ft_atoi(av[5]);
	(*data)->philo = malloc(sizeof(t_philo) * (*data)->p_nb);
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->p_nb);
	while (i < (*data)->p_nb)
	{
		(*data)->philo[i].nb = i + 1;
		(*data)->philo[i].data = *data;
		(*data)->philo[i].m_nb = 0;
		pthread_mutex_init(&(*data)->forks[i], NULL);
		i++;
	}
	(*data)->meals = 0;
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
