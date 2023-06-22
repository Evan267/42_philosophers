/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:52:50 by eberger           #+#    #+#             */
/*   Updated: 2023/06/20 23:34:43 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	isalive(t_philo *philo)
{
	struct timeval	time_value;
	unsigned int	limit;

	gettimeofday(&time_value, NULL);
	limit = philo->start_eating + philo->time_to_eat;
	if (limit <= time_value.tv_usec)
		//TOBEDONE
}

void	eat(t_philo *philo)
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

int	taken_fork(t_philo *philo, t_fourchette *gauche, t_fourchette *droite)
{
	struct timeval	tv;
	char		*timestamp;
	int		fourchettes;

	if (gauche->fourchette == 1)
	{
		gettimeofday(&tv, NULL);
		timestamp = ft_itoa(tv.usec);
		fourchettes += gauche->fourchette;
		gauche->fourchette -= 1;
		msg_taken_fork(timestamp, philo->id);
	}
	if (droite->fourchette == 1)
	{
		gettimeofday(&tv, NULL);
		timestamp = ft_itoa(tv.usec);
		fourchettes += droite->fourchette;
		droite->fourchette -= 1;
		msg_taken_fork(timestamp, philo->id);
	}
	return (fourchettes);
}

void	*thread_one_philo(void *arg)
{
	t_philo		*philo;
	t_fourchette	*gauche;
	t_fourchette	*droite;
	int		fourchettes;
	
	philo = arg;
	def_frcht(gauche, droite, philo);
	while (philo->number_of_times_must_eat-- != 0)
	{
		if (gauche && droite
			&& gauche->fourchette && droite->fourchette)
		{
			pthread_mutex_lock(gauche->fourchette_mutex);
			pthread_mutex_lock(droite->fourchette_mutex);
			fourchettes = taken_fork(philo, gauche, droite)
			if (fourchettes == 2)
				eat(philo);
			pthread_mutex_unlock(gauche->fourchette_mutex);
			pthread_mutex_unlock(droite->fourchette_mutex);
		}
	}
}
