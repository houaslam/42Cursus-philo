/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:26:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/14 21:55:36 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	taking_fork_action_b(t_philo *philo)
{
	sem_wait(philo->data->sem);
	sem_wait(philo->data->sem);
	printf_msg("took right fork", philo);
	printf_msg("took left fork", philo);
}

void	eating_action_b(t_philo *philo)
{
	printf_msg("is eating", philo);
	gettimeofday(&philo->store, NULL);
	ft_usleep(philo->data->t_eat);
	sem_post(&philo->death);
	sem_wait(&philo->death);
	sem_wait(philo->data->eat);
	philo->m_nb++;
	sem_post(philo->data->eat);
	sem_post(philo->data->sem);
	sem_post(philo->data->sem);
	if (philo->m_nb == philo->data->nb_m)
		exit(EXIT_SUCCESS);
}

void	sleeping_action_b(t_philo *philo)
{
	printf_msg("is sleeping", philo);
	ft_usleep(philo->data->t_sleep);
	printf_msg("is thinking", philo);
}

void	general_action_b(t_philo *philo)
{
	pthread_create(&philo->data->t, NULL, check_loop_b, philo);
	gettimeofday(&philo->store, NULL);
	while (1)
	{
		taking_fork_action_b(philo);
		eating_action_b(philo);
		sleeping_action_b(philo);
	}
}
