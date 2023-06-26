/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:15:19 by eberger           #+#    #+#             */
/*   Updated: 2023/06/26 15:42:55 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	isalive(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&philo->eat_mutex);
	if (tv.tv_usec > philo->time_to_eat + philo->start_eating)
		return (pthread_mutex_unlock(&philo->eat_mutex), 0);
	return (pthread_mutex_unlock(&philo->eat_mutex), 1);
}

static int	check_all_alive(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		if (!isalive(philos[i]))
			return (i);
		i++;
	}
	return (0);
}

static int	all_meal_ok(t_philo **philos)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (philos[i])
	{
		if (philos[i]->number_of_times_must_eat != 0)
			ret = 1;
		i++;
	}
	return (ret);
}

void	*all_alive(void *arg)
{
	t_philo	**philos;
	int		alive;
	int		meal;
	struct timeval	tv;

	philos = arg;
	alive = 0;
	meal = 1;
	gettimeofday(&tv, NULL);
	while (!alive && meal)
	{
		alive = check_all_alive(philos);
		meal = all_meal_ok(philos);
	}
	if (!meal)
		printf("%i all meal OK !\n", tv.tv_usec);
	if (alive)
		printf("%i %i is died\n", tv.tv_usec, alive);
	return (0);
}

int	check_death(t_philo **philos)
{
	pthread_t	id;
	int			*ret;

	ret = NULL;
	pthread_create(&id, NULL, all_alive, philos);
	pthread_join(id, (void *)ret);
	return (1);
}
