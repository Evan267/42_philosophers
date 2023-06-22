/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:39:32 by eberger           #+#    #+#             */
/*   Updated: 2023/06/20 23:03:12 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_lenfourchette(t_fourchette **fourchettes)
{
	int	i;

	i = 0;
	while (fourchettes[i])
		i++;
	return (i);
}

void	def_frcht(t_fourchette *gauche, t_fourchette *droite, t_philo *philo)
{
	int	len;

	len = ft_lenfourchettes(philo->fourchettes);
	if (philo->id == len && len > 1)
	{
		droite = philo->fourchettes[id - 1];
		gauche = philo->fourchettes[0];
	}
	else if (len > 1)
	{
		droite = philo->fourchettes[id - 1];
		gauche = philo->fourchettes[id];
	}
	else
	{
		droite = NULL;
		gauche = NULL;
	}
}
