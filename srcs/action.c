/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:53:12 by eberger           #+#    #+#             */
/*   Updated: 2023/06/26 12:07:04 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(int id, unsigned int time_to_sleep)
{
	struct timeval	tv;
	char		*timestamp;

	gettimeofday(&tv, NULL);
	timestamp = ft_itoa(tv.tv_usec);
	msg_sleep(timestamp, id);
	free(timestamp);
	usleep(time_to_sleep);
}

void	thinking(int id)
{
	struct timeval	tv;
	char		*timestamp;

	gettimeofday(&tv, NULL);
	timestamp = ft_itoa(tv.tv_usec);
	msg_think(timestamp, id);
	free(timestamp);
}

void	eating(t_philo *philo)
{
	struct timeval	tv;
	char		*timestamp;
	
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->start_eating = tv.tv_usec;
	pthread_mutex_unlock(&philo->eat_mutex);
	timestamp = ft_itoa(tv.tv_usec);
	msg_eat(timestamp, philo->id);
	free(timestamp);
	usleep(philo->time_to_eat);
}
