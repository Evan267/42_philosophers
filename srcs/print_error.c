/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger/Desktop <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:20:49 by eberger/Deskt     #+#    #+#             */
/*   Updated: 2023/07/07 15:21:33 by eberger/Deskt    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error_red(char *str)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd("Erreur : ", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[0m", 2);
}
