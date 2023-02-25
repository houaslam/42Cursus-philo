/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   still-learning_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:42:18 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/25 21:03:40 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo.h"

// unsigned int INT = 1000;
// int i = 0;
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// void	*myturn(void *arg)
// {
// 	int j = 0;
// 	while (j < INT)
// 	{
// 		pthread_mutex_lock(&lock);
// 		j++;
// 		i++;
// 		pthread_mutex_unlock(&lock);
// 	}
// 	return NULL;
// }

// int main()
// {
// 	pthread_t	thread;
// 	int	*ret;

// 	pthread_create(&thread, NULL, myturn, NULL);
// 	myturn(NULL);
// 	pthread_join(thread, NULL);
// 	printf("res = %d\n", i);
// }
