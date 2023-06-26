/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fourchette.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:41:50 by eberger           #+#    #+#             */
/*   Updated: 2023/06/22 20:21:08 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all_forks(t_fork **forks, int len)
{
	int	i;

	i = 0;
	while (i < len)
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
	while (i < len)
	{
		forks[i] = create_one_fork();
		if (!(forks[i]))
		{
			while (i--)
				free(forks[i]);
			free(forks);
			return (NULL);
		}
		i++;
	}
	forks[i] = NULL;
	return (forks);
}
