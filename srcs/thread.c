/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:52:50 by eberger           #+#    #+#             */
/*   Updated: 2023/06/24 09:25:00 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	struct timeval	tv;
	char		*timestamp;
	
	gettimeofday(&tv, NULL);
	philo->start_eating = tv.tv_usec;
	timestamp = ft_itoa(tv.tv_usec);
	msg_eat(timestamp, philo->id);
	free(timestamp);
	usleep(philo->time_to_eat);
}

t_fork	*get_fork(int id, t_fork *fork)
{
	struct timeval	tv;
	char		*timestamp;

	pthread_mutex_lock(&fork->fork_mutex);
	gettimeofday(&tv, NULL);
	timestamp = ft_itoa(tv.tv_usec);
	msg_taken_fork(timestamp, id);
	free(timestamp);
	return (fork);
}

t_fork	*get_fork_left(int id, t_fork **forks, int len)
{
	t_fork		*fork;

	if (id == 1)
		fork = forks[len - 1];
	else
		fork = forks[id - 1];
	return (get_fork(id, fork));
}

t_fork	*get_fork_right(int id, t_fork **forks, int len)
{
	t_fork		*fork;

	if (id == len)
		fork = forks[0];
	else
		fork = forks[id];
	return (get_fork(id, fork));
}

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

void	*thread_one_philo(void *arg)
{
	t_philo		*philo;
	t_fork		*left;
	t_fork		*right;
	
	philo = arg;
	printf("philo\n");
	while (philo->number_of_times_must_eat-- != 0)
	{
		left = get_fork_left(philo->id, philo->forks, philo->len);
		right = get_fork_right(philo->id, philo->forks, philo->len);
		eating(philo);
		pthread_mutex_unlock(&left->fork_mutex);
		pthread_mutex_unlock(&right->fork_mutex);
		sleeping(philo->id, philo->time_to_sleep);
		thinking(philo->id);
	}
	return ("ok");
}

pthread_t	lance_thread(t_philo *philo)
{
	pthread_t	id;
	pthread_attr_t	attr;
	int		res;

	res = pthread_create(&id, &attr, &thread_one_philo, philo);
	if (res != 0)
		return (NULL);
	return (id);
}

int	thread_philos(t_philo **philos)
{
	int		i;
	pthread_t	*id_threads;

	i = 0;
	id_threads = malloc(sizeof(pthread_t) * len);
	while (philos[i])
	{
		id_threads[i] = lance_thread(philos[i]);
		i++;
		if (!id_threads)
			ft_putendl_fd("erreur au lancement d'un thread", 2);
	}
	return (0);
}
