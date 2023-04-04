/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:52:58 by houaslam          #+#    #+#             */
/*   Updated: 2023/03/13 17:26:35 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(char *str)
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

int	right_time(struct timeval time)
{
	int			res;

	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}

void	printf_msg(char *str, t_philo *philo)
{
	sem_wait(philo->data->print);
	printf("%d ms philo %d %s\n", now_time() \
	- right_time(philo->data->start_time), philo->nb, str);
	sem_post(philo->data->print);
}

void	ft_usleep(unsigned long time_2)
{
	unsigned long	time;

	time = now_time();
	while ((now_time() - time) < time_2)
		usleep(100);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit(1);
}
