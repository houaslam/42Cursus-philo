/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:29:16 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/14 21:56:27 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_wait(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->p_nb)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < data->p_nb)
				kill(data->philo[i++].id, SIGKILL);
			sem_close(data->sem);
			free(data);
			free(data->philo);
			exit(0);
		}
		i++;
	}
}

void	*check_loop_b(void *arg)
{
	t_philo			*philo;
	int				res;

	philo = (t_philo *)arg;
	while (1)
	{
		res = now_time() - right_time(philo->store);
		if (res > philo->data->t_die)
		{
			printf_msg("is dead", philo);
			exit(EXIT_FAILURE);
		}	
	}
}

void	check_arg(char **str)
{
	int		i;
	int		j;

	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '+' || str[j][i] == ' ')
				i++;
			if (!((str[j][i] >= '0' && str[j][i] <= '9') || str[j][i] == ' '))
			{
				printf("Error\n");
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	check_data(t_data *data, int ac)
{
	if (data->p_nb <= 0 || data->t_die <= 0)
		ft_putstr_fd("ERROR\n", 2);
	if (data->t_sleep <= 0 || data->t_eat <= 0)
		ft_putstr_fd("ERROR\n", 2);
	if (ac == 6 && data->nb_m <= 0)
		ft_putstr_fd("ERROR\n", 2);
}

int	now_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (right_time(now));
}
