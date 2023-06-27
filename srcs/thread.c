/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:52:50 by eberger           #+#    #+#             */
/*   Updated: 2023/06/27 15:36:13 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_one_philo(void *arg)
{
	t_philo		*philo;
	t_fork		*left;
	t_fork		*right;
	
	philo = arg;
	if (philo->id % 2 == 0)
		ft_usleep(100);
	pthread_mutex_lock(&philo->number_mutex);
	while (philo->number_of_times_must_eat != 0)
	{
		pthread_mutex_unlock(&philo->number_mutex);
		left = get_fork_left(philo->id, philo->forks);
		right = get_fork_right(philo->id, philo->forks, philo->len);
		eating(philo);
		pthread_mutex_unlock(&left->fork_mutex);
		pthread_mutex_unlock(&right->fork_mutex);
		pthread_mutex_lock(&philo->number_mutex);
		philo->number_of_times_must_eat--;
		if (philo->number_of_times_must_eat == 0)
			break ;
		pthread_mutex_unlock(&philo->number_mutex);
		sleeping(philo->id, philo->time_to_sleep);
		thinking(philo->id);
		pthread_mutex_lock(&philo->number_mutex);
	}
	pthread_mutex_unlock(&philo->number_mutex);
	return (philo);
}

int	lance_thread(t_philo *philo, pthread_t *id)
{
	int		res;

	res = pthread_create(id, NULL, thread_one_philo, philo);
	if (res != 0)
		return (1);
	return (0);
}

void	stop_philos(pthread_t *id_threads)
{
	int	i;

	i = 0;
	while (id_threads[i])
	{
		if (pthread_detach(id_threads[i]))
			return ;
		i++;
	}
}

void	stop_mutex(t_philo **philos, t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i])
	{
		pthread_mutex_destroy(&forks[i]->fork_mutex);
		i++;
	}
	i = 0;
	while (philos[i])
	{
		pthread_mutex_destroy(&philos[i]->number_mutex);
		pthread_mutex_destroy(&philos[i]->eat_mutex);
		i++;
	}
}

int	thread_philos(t_philo **philos, int len)
{
	int		i;
	pthread_t	*id_threads;
	int	end;

	i = 0;
	end = 0;
	id_threads = malloc(sizeof(pthread_t) * len + 1);
	while (philos[i])
	{
		if (lance_thread(philos[i], id_threads + i))
			ft_putendl_fd("erreur au lancement d'un thread", 2);
		i++;
	}
	id_threads[i] = 0;
	check_death(philos);
	stop_philos(id_threads);
	stop_mutex(philos, philos[0]->forks);
	return (0);
}
