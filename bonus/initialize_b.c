/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:15:34 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/12 22:42:42 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	initialize_childs(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_nb)
	{
		data->philo[i].nb = i + 1;
		data->philo[i].data = data;
		data->philo[i].m_nb = 0;
		data->philo[i].death = 0;
		gettimeofday(&data->philo[i].store, NULL);
		i++;
	}
}

void	initialize_semaphore(t_data *data)
{
	sem_unlink("/sem");
	sem_unlink("/print");
	sem_unlink("/eat");
	sem_unlink("/die");
	data->sem = sem_open("/sem", O_CREAT | O_EXCL, 0644, data->p_nb);
	data->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	data->eat = sem_open("/eat", O_CREAT | O_EXCL, 0644, 1);
	data->death = sem_open("/die", O_CREAT | O_EXCL, 0644, 1);
}

t_data	*initialize_general_b(int ac, char **av)
{
	t_data	*data;

	check_arg(av);
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->p_nb = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_m = ft_atoi(av[5]);
	check_data(data, ac);
	data->philo = malloc(sizeof(t_philo) * data->p_nb);
	initialize_childs(data);
	initialize_semaphore(data);
	data->check1 = 0;
	if (!data->philo)
		return (NULL);
	return (data);
}

void	initialize_process(t_data *data)
{
	int		i;
	int		*tab;

	i = 0;
	tab = malloc(sizeof(pid_t) * data->p_nb);
	gettimeofday(&data->start_time, NULL);
	while (i < data->p_nb)
	{
		data->philo[i].id = fork();
		if (data->philo[i].id == 0)
			general_action_b(&data->philo[i]);
		else if (data->philo[i].id < 0)
			ft_putstr_fd("fork fail\n", 2);
		i++;
	}
}
