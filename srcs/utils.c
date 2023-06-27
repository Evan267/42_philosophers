/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:39:32 by eberger           #+#    #+#             */
/*   Updated: 2023/06/27 13:19:08 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	get_ms_now(void)
{
	struct timeval	tv;
	long int		ms;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

int	ft_msleep(long int msec)
{
	long int	ms;
	long int	end;

	ms = get_ms_now();
	if (ms == -1)
		return (-1);
	end = ms + msec;
	while (ms < end)
	{
		usleep(100);
		ms = get_ms_now();
		if (ms == -1)
			return (-1);
	}
	return (0);
}

int	ft_usleep(long int usec)
{
	struct timeval	tv;
	long int		end;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	end = tv.tv_usec + usec;
	while (tv.tv_usec < end)
	{
		usleep(1);
		if (gettimeofday(&tv, NULL) == -1)
			return (-1);
	}
	return (0);
}
