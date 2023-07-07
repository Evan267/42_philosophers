/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:26:20 by eberger           #+#    #+#             */
/*   Updated: 2023/07/07 15:21:06 by eberger/Deskt    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	argv_are_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) < 1 || ft_strlen(argv[i]) > 11)
			return (0);
		i++;
	}
	return (1);
}

static void	example(void)
{
	ft_putendl_fd("Pour que le programme fonctionne, procédé comme cela:", 1);
	ft_putstr_fd("./philo number_of_philosophers time_to_die time_to_eat", 1);
	ft_putstr_fd(" time_to_sleep ", 1);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat]", 1);
	ft_putendl_fd("Exemple:", 1);
	ft_putendl_fd("\t./philo 2 800 200 200 7", 1);
}

static int	error_argv_are_int(int argc, char **argv)
{
	if (argv_are_num(argc, argv))
		return (0);
	print_error_red("Certains arguments ne sont pas des int positifs");
	example();
	return (1);
}

static int	error_nb_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			print_error_red("Spécifiez plus d'arguments");
		else if (argc > 6)
			print_error_red("Spécifiez moins d'arguments");
		example();
		return (1);
	}
	return (0);
}

int	error(int argc, char **argv)
{
	if (error_nb_args(argc))
		return (1);
	if (error_argv_are_int(argc, argv))
		return (1);
	return (0);
}
