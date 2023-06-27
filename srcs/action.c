/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:53:12 by eberger           #+#    #+#             */
/*   Updated: 2023/06/27 12:43:05 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(int id, unsigned int time_to_sleep)
{
	msg_sleep(id);
	ft_msleep(time_to_sleep);
}

void	thinking(int id)
{
	msg_think(id);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	philo->start_eating = get_ms_now();
	pthread_mutex_unlock(&philo->eat_mutex);
	msg_eat(philo->id);
	ft_msleep(philo->time_to_eat);
}
