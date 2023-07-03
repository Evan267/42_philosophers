/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:35:35 by eberger           #+#    #+#             */
/*   Updated: 2023/07/03 14:57:55 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all_philos(t_philo **philos, int len)
{
	int	i;

	i = 0;
	free_all_forks(philos[0]->forks, len);
	while (i < len)
		free(philos[i++]);
	free(philos);
}

static t_philo *create_one_philo(int argc, char **argv, t_fork **forks, unsigned int id)
{
	t_philo		*philo;
	
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->time_to_die = (int)ft_atoi(argv[2]);
	philo->time_to_eat = (int)ft_atoi(argv[3]);
	philo->time_to_sleep = (int)ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_must_eat = ft_atoi(argv[5]);
	else
		philo->number_of_times_must_eat = -1;
	philo->start_eating = get_ms_now();
	philo->len = ft_atoi(argv[1]);
	philo->forks = forks;
	philo->end = 0;
	pthread_mutex_init(&philo->eat_mutex, NULL);
	pthread_mutex_init(&philo->number_mutex, NULL);
	pthread_mutex_init(&philo->end_mutex, NULL);
	return (philo);
}

t_philo	**create_all_philos(int argc, char **argv)
{
	t_fork	**forks;
	t_philo	**philos;
	int	nb_philos;
	int	i;

	i = 0;
	nb_philos = ft_atoi(argv[1]);
	forks = create_all_forks(nb_philos);;
	if (!forks)
		return (NULL);
	philos = malloc(sizeof(t_philo *) * (nb_philos + 1));
	if (!philos)
		return (NULL);
	while (i < nb_philos)
	{
		philos[i] = create_one_philo(argc, argv, forks, i + 1);
		if (!(philos[i]))
		{
			while (i--)
				free(philos[i]);
			free(philos);
			return (NULL);
		}
		philos[i]->philos = philos;
		i++;
	}
	philos[i] = NULL;
	return (philos);
}
