/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:14:51 by eberger           #+#    #+#             */
/*   Updated: 2023/06/27 11:30:52 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msg_die(int id)
{
	printf("%li %i died\n", get_ms_now(), id);
}

void	msg_think(int id)
{
	printf("%li %i is thinking\n", get_ms_now(), id);
}

void	msg_sleep(int id)
{
	printf("%li %i is sleeping\n", get_ms_now(), id);
}

void	msg_eat(int id)
{
	printf("%li %i is eating\n", get_ms_now(), id);
}

void	msg_taken_fork(int id)
{
	printf("%li %i has taken a fork\n", get_ms_now(), id);
}

