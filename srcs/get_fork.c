/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:55:37 by eberger           #+#    #+#             */
/*   Updated: 2023/06/27 13:05:21 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_fork	*get_fork(int id, t_fork *fork)
{
	pthread_mutex_lock(&(fork->fork_mutex));
	msg_taken_fork(id);
	return (fork);
}

t_fork	*get_fork_left(int id, t_fork **forks)
{
	t_fork		*fork;

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
