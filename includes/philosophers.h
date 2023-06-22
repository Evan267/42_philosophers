/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:02:05 by eberger           #+#    #+#             */
/*   Updated: 2023/06/19 23:14:58 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct	s_fourchette
{
	pthread_mutex_t	fourchette_mutex;
	unsigned int	fourchette;
}	t_fourchette;

typedef struct	s_philo
{
	unsigned int	id;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int		number_of_times_must_eat;
	unsigned long	start_eating;
	t_fourchette	**fourchettes;
}	t_philo;

/*Message*/
void	msg_die(char *timestamp, int id);
void	msg_think(char *timestamp, int id);
void	msg_sleep(char *timestamp, int id);
void	msg_eat(char *timestamp, int id);
void	msg_taken_fork(char *timestamp, int id);

/*Error*/
void	print_error_red(char *str);
int	error(int argc, char **argv);

/*Initialisation*/
t_fourchette	**create_all_fourchettes(int len);
t_philo		**create_all_philosophers(int argc, char **argv);

void	free_all_philos(t_philo **philos, int len);
void	free_all_fourchettes(t_fourchette **fourchettes, int len);

#endif
