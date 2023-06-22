/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fourchette.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:41:50 by eberger           #+#    #+#             */
/*   Updated: 2023/06/20 22:37:18 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all_fourchettes(t_fourchette **fourchettes, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(fourchettes[i++]);
	free(fourchettes);
}

static t_fourchette	*create_one_fourchette(void)
{
	t_fourchette	*fourchette;

	fourchette = malloc(sizeof(t_fourchette));
	if (!fourchette)
		return (NULL);
	pthread_mutex_init(&fourchette->fourchette_mutex, NULL);
	fourchette->fourchette = 1;
	return (fourchette);
}

t_fourchette	**create_all_fourchettes(int len)
{
	int		i;
	t_fourchette	**fourchettes;

	i = 0;
	fourchettes = malloc(sizeof(t_fourchette *) * (len + 1));
	while (i < len)
	{
		fourchettes[i] = create_one_fourchette();
		if (!(fourchettes[i]))
		{
			while (i--)
				free(fourchettes[i]);
			free(fourchettes);
			return (NULL);
		}
		i++;
	}
	fourchettes[i] = NULL;
	return (fourchettes);
}
