/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:07:12 by eberger           #+#    #+#             */
/*   Updated: 2023/06/20 18:51:18 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	**philos;

	if (error(argc, argv))
		return (1);
	philos = create_all_philosophers(argc, argv);
	if (!philos)
		return (print_error_red("Création des philosophes a échoué"), 1);
	thread_philos(philos);
	free_all_philos(philos, ft_atoi(argv[1]));
	system("leaks philo");
	return (0);
}
