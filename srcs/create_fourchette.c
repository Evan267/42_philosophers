/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fourchette.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:41:50 by eberger           #+#    #+#             */
/*   Updated: 2023/07/07 14:36:49 by eberger/Deskt    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all_forks(t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i])
		free(forks[i++]);
	free(forks);
}

static t_fork	*create_one_fork(void)
{
	t_fork	*one_fork;

	one_fork = malloc(sizeof(t_fork));
	if (!one_fork)
		return (NULL);
	pthread_mutex_init(&one_fork->fork_mutex, NULL);
	return (one_fork);
}

t_fork	**create_all_forks(int len)
{
	int		i;
	t_fork	**forks;

	i = 0;
	forks = malloc(sizeof(t_fork *) * (len + 1));
	if (!forks)
		return (NULL);
	while (i < len)
	{
		forks[i] = create_one_fork();
		if (!(forks[i]))
			return (free_all_forks(forks), NULL);
		i++;
	}
	forks[i] = NULL;
	return (forks);
}
