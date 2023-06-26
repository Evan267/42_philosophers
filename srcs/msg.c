/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:14:51 by eberger           #+#    #+#             */
/*   Updated: 2023/06/26 10:06:39 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msg_die(char *timestamp, int id)
{
	printf("%s %i died\n", timestamp, id);
}

void	msg_think(char *timestamp, int id)
{
	printf("%s %i is thinking\n", timestamp, id);
}

void	msg_sleep(char *timestamp, int id)
{
	printf("%s %i is sleeping\n", timestamp, id);
}

void	msg_eat(char *timestamp, int id)
{
	printf("%s %i is eating\n", timestamp, id);
}

void	msg_taken_fork(char *timestamp, int id)
{
	printf("%s %i has taken a fork\n", timestamp, id);
}

