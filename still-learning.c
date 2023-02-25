/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   still-learning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:42:18 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/25 21:03:43 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo.h"

// void	*myturn(void *arg)
// {
// 	int	*i = (int *)malloc(sizeof(int));

// 	(*i) = 0;
// 	while ((*i) < 10)
// 	{
// 		sleep(2);
// 		printf("me : hello\n");
// 		(*i)++;
// 	}
// 	return (i);
// }

// void	*urturn(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		sleep(1);
// 		printf("you : hii!\n");
// 		i++;
// 	}
// 	return (NULL);
// }

// int main()
// {
// 	pthread_t	thread;
// 	int	*ret;

// 	pthread_create(&thread, NULL, myturn, NULL);
// 	urturn();
// 	pthread_join(thread, &ret);
// 	printf("res = %d\n", *ret);
// }
