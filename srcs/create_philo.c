/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:35:35 by eberger           #+#    #+#             */
/*   Updated: 2023/06/20 22:36:28 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all_philos(t_philo **philos, int len)
{
	int	i;

	i = 0;
	free_all_fourchettes(philos[0]->fourchettes, len);
	while (i < len)
		free(philos[i++]);
	free(philos);
}

static t_philo *create_one_philosopher(int argc, char **argv, t_fourchette **fourchettes, unsigned int id)
{
	t_philo	*philo;
	struct timeval	time_value;
	
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->time_to_die = (unsigned int)ft_atoi(argv[2]);
	philo->time_to_eat = (unsigned int)ft_atoi(argv[3]);
	philo->time_to_sleep = (unsigned int)ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_must_eat = ft_atoi(argv[5]);
	else
		philo->number_of_times_must_eat = -1;
	if (gettimeofday(&time_value, NULL) == -1)
		return (free(philo), NULL);
	philo->start_eating = time_value.tv_usec;
	philo->fourchettes = fourchettes;
	return (philo);
}

t_philo	**create_all_philosophers(int argc, char **argv)
{
	t_fourchette	**fourchettes;
	t_philo		**philos;
	int		nb_philos;
	int		i;

	i = 0;
	nb_philos = ft_atoi(argv[1]);
	fourchettes = create_all_fourchettes(nb_philos);;
	if (!fourchettes)
		return (NULL);
	philos = malloc(sizeof(t_philo *) * (nb_philos + 1));
	if (!philos)
		return (NULL);
	while (i < nb_philos)
	{
		printf("philo %i\n", i);
		philos[i] = create_one_philosopher(argc, argv, fourchettes, i + 1);
		if (!(philos[i]))
		{
			while (i--)
				free(philos[i]);
			free(philos);
			return (NULL);
		}
		i++;
	}
	philos[i] = NULL;
	return (philos);
}
