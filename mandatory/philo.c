/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:15 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/12 17:54:08 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 5 || ac == 6)
		data = initialize_general(ac, av);
	else
		return (1);
	if (!data)
		return (1);
	initialize_threads(data);
	check_loop(data);
	free(data->philo);
	free(data->forks);
	free(data);
	return (0);
}
