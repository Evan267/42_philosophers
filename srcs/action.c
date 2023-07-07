/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:53:12 by eberger           #+#    #+#             */
/*   Updated: 2023/07/07 15:14:24 by eberger/Deskt    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->end_mutex);
	if (!philo->end && all_meal_ok(philo->philos))
	{
		msg_sleep(philo->id);
		pthread_mutex_unlock(&philo->end_mutex);
		ft_msleep(philo->time_to_sleep);
	}
	else
		pthread_mutex_unlock(&philo->end_mutex);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->end_mutex);
	if (!philo->end && all_meal_ok(philo->philos))
		msg_think(philo->id);
	pthread_mutex_unlock(&philo->end_mutex);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->end_mutex);
	if (!philo->end && all_meal_ok(philo->philos))
	{
		pthread_mutex_lock(&philo->eat_mutex);
		philo->start_eating = get_ms_now();
		pthread_mutex_unlock(&philo->eat_mutex);
		msg_eat(philo->id);
		ft_msleep(philo->time_to_eat);
		pthread_mutex_lock(&philo->number_mutex);
		philo->number_of_times_must_eat--;
		pthread_mutex_unlock(&philo->number_mutex);
	}
	pthread_mutex_unlock(&philo->end_mutex);
}
