/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:15:19 by eberger           #+#    #+#             */
/*   Updated: 2023/07/06 16:44:19 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	isdied(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	if (get_ms_now() > philo->time_to_die + philo->start_eating)
		return (pthread_mutex_unlock(&philo->eat_mutex), 1);
	return (pthread_mutex_unlock(&philo->eat_mutex), 0);
}

static int	check_all_alive(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		if (isdied(philos[i]))
			return (i + 1);
		i++;
	}
	return (0);
}

int	all_meal_ok(t_philo **philos)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (philos[i])
	{
		pthread_mutex_lock(&philos[i]->number_mutex);
		if (philos[i]->number_of_times_must_eat != 0)
			ret = 1;
		pthread_mutex_unlock(&philos[i]->number_mutex);
		i++;
	}
	return (ret);
}

void	end_philos(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		pthread_mutex_lock(&philos[i]->end_mutex);
		i++;
	}
	i = 0;
	while (philos[i])
	{
		philos[i]->end = 1;
		pthread_mutex_unlock(&philos[i]->end_mutex);
		i++;
	}
}

void	*all_alive(void *arg)
{
	t_philo	**philos;
	int		death;
	int		meal;

	philos = (t_philo **)arg;
	death = 0;
	meal = 1;
	while (!death && meal)
	{
		death = check_all_alive(philos);
		meal = all_meal_ok(philos);
		if (!meal || death)
			end_philos(philos);
	}
	if (!meal)
		printf("%li all meal OK !\n", get_ms_now());
	if (death)
		printf("%li %i is died\n", get_ms_now(), death);
	return (NULL);
}

int	check_death(t_philo **philos)
{
	pthread_t	id;
	void		*arg;

	arg = (void *)philos;
	pthread_create(&id, NULL, all_alive, arg);
	pthread_join(id, NULL);
	return (1);
}
