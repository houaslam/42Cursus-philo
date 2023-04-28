/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:26:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/04/28 14:53:48 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_fork_action(t_philo *philo)
{
	pthread_mutex_lock(philo->rf);
	printf_msg("took right fork", philo, 0);
	pthread_mutex_lock(philo->lf);
	printf_msg("took left fork", philo, 0);
}

void	ft_usleep(unsigned long time_2)
{
	unsigned long	time;

	time = now_time();
	while ((now_time() - time) < time_2)
		usleep(100);
}

void	eating_action(t_philo *philo)
{
	philo->store = now_time();
	printf_msg("is eating", philo, 0);
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(philo->rf);
	pthread_mutex_unlock(philo->lf);
	pthread_mutex_lock(&philo->data->death);
	pthread_mutex_unlock(&philo->data->death);
	pthread_mutex_lock(&philo->data->meals);
	philo->m_nb++;
	pthread_mutex_unlock(&philo->data->meals);
	if (philo->m_nb == philo->data->nb_m)
	{
		pthread_mutex_lock(&philo->data->meals);
		philo->data->check1++;
		pthread_mutex_unlock(&philo->data->meals);
	}
}

void	sleeping_action(t_philo *philo)
{
	printf_msg("is sleeping", philo, 0);
	ft_usleep(philo->data->t_sleep);
	printf_msg("is thinking", philo, 0);
}

void	*globale_action(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		taking_fork_action(philo);
		eating_action(philo);
		sleeping_action(philo);
	}
	return (NULL);
}
