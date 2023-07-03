/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:07:12 by eberger           #+#    #+#             */
/*   Updated: 2023/07/03 12:41:56 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo		**philos;
	int	len;

	if (error(argc, argv))
		return (1);
	philos = create_all_philos(argc, argv);
	if (!philos)
		return (print_error_red("Création des philosophes a échoué"), 1);
	len = ft_atoi(argv[1]);
	thread_philos(philos, len);
	free_all_philos(philos, len);
	//system("leaks philo");
	return (0);
}
