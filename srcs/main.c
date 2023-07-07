/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:07:12 by eberger           #+#    #+#             */
/*   Updated: 2023/07/07 15:23:09 by eberger/Deskt    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	**philos;
	t_fork	**forks;
	int		len;

	if (error(argc, argv))
		return (1);
	len = ft_atoi(argv[1]);
	forks = create_all_forks(len);
	if (!forks)
		return (print_error_red("Création des fourchettes a échoué"), 1);
	philos = create_all_philos(argc, argv, forks);
	if (!philos)
		return (print_error_red("Création des philosophes a échoué"), 1);
	thread_philos(philos, len);
	return (0);
}
