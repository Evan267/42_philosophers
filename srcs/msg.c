/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:14:51 by eberger           #+#    #+#             */
/*   Updated: 2023/06/17 11:59:08 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msg_die(char *timestamp, int id)
{
	printf("%s %i died", timestamp, id);
}

void	msg_think(char *timestamp, int id)
{
	printf("%s %i is thinking", timestamp, id);
}

void	msg_sleep(char *timestamp, int id)
{
	printf("%s %i is sleeping", timestamp, id);
}

void	msg_eat(char *timestamp, int id)
{
	printf("%s %i is eating", timestamp, id);
}

void	msg_taken_fork(char *timestamp, int id)
{
	printf("%s %i has taken a fork", timestamp, id);
}

