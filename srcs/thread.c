/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:52:50 by eberger           #+#    #+#             */
/*   Updated: 2023/06/26 15:43:29 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_one_philo(void *arg)
{
	t_philo		*philo;
	t_fork		*left;
	t_fork		*right;
	
	philo = arg;
	while (philo->number_of_times_must_eat != 0)
	{
		left = get_fork_left(philo->id, philo->forks, philo->len);
		right = get_fork_right(philo->id, philo->forks, philo->len);
		eating(philo);
		philo->number_of_times_must_eat--;
		pthread_mutex_unlock(&left->fork_mutex);
		pthread_mutex_unlock(&right->fork_mutex);
		sleeping(philo->id, philo->time_to_sleep);
		thinking(philo->id);
	}
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

void	wait_all_philos(pthread_t *id_threads)
{
	int		i;
	void	*ret;

	i = 0;
	ret = NULL;
	while (id_threads[i])
	{
		if (pthread_join(id_threads[i], ret))
			return ;
		i++;
	}
	return ;
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

int	thread_philos(t_philo **philos, int len)
{
	int		i;
	pthread_t	*id_threads;

	i = 0;
	id_threads = malloc(sizeof(pthread_t) * len + 1);
	while (philos[i])
	{
		if (i % 2)
			usleep(100);
		if (lance_thread(philos[i], id_threads + i))
			ft_putendl_fd("erreur au lancement d'un thread", 2);
		i++;
	}
	id_threads[i] = 0;
	check_death(philos);
	stop_philos(id_threads);
	return (0);
}
