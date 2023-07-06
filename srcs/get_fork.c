/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:55:37 by eberger           #+#    #+#             */
/*   Updated: 2023/07/06 16:42:36 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_fork	*get_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&philo->end_mutex);
	if (!philo->end && all_meal_ok(philo->philos))
	{
		pthread_mutex_unlock(&philo->end_mutex);
		pthread_mutex_lock(&(fork->fork_mutex));
		msg_taken_fork(philo->id);
		return (fork);
	}
	pthread_mutex_unlock(&philo->end_mutex);
	return (NULL);
}

t_fork	*get_fork_left(t_philo *philo, t_fork **forks)
{
	t_fork		*fork;

	fork = forks[philo->id - 1];
	return (get_fork(philo, fork));
}

t_fork	*get_fork_right(t_philo *philo, t_fork **forks)
{
	t_fork		*fork;

	if (philo->id == philo->len)
		fork = forks[0];
	else
		fork = forks[philo->id];
	return (get_fork(philo, fork));
}

void	drop_forks(t_fork *left, t_fork *right, t_philo *philo)
{
	pthread_mutex_lock(&philo->end_mutex);
	if (!philo->end && all_meal_ok(philo->philos))
	{
		pthread_mutex_unlock(&philo->end_mutex);
		pthread_mutex_unlock(&(left->fork_mutex));
		pthread_mutex_unlock(&(right->fork_mutex));
		return ;
	}
	pthread_mutex_unlock(&philo->end_mutex);
}
