/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:02:05 by eberger           #+#    #+#             */
/*   Updated: 2023/06/24 09:19:49 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct	s_fork
{
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct	s_philo
{
	unsigned int	id;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int		number_of_times_must_eat;
	pthread_mutex_t	eat_mutex;
	unsigned long	start_eating;
	int		len;
	t_fork		**forks;
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
t_fork	**create_all_forks(int len);
t_philo	**create_all_philos(int argc, char **argv);

void	free_all_philos(t_philo **philos, int len);
void	free_all_forks(t_fork **forks, int len);

/*Thread*/
int	thread_philos(t_philo **philos, int len);

#endif
