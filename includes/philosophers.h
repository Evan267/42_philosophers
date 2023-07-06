/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:02:05 by eberger           #+#    #+#             */
/*   Updated: 2023/07/06 16:27:14 by eberger          ###   ########.fr       */
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
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	number_mutex;
	int				number_of_times_must_eat;
	pthread_mutex_t	eat_mutex;
	long int		start_eating;
	int				len;
	t_fork			**forks;
	pthread_mutex_t	end_mutex;
	int				end;
	struct s_philo	**philos;
}	t_philo;

/*Message*/
void		msg_die(int id);
void		msg_think(int id);
void		msg_sleep(int id);
void		msg_eat(int id);
void		msg_taken_fork(int id);

/*Action*/
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		eating(t_philo *philo);

/*Get fork*/
t_fork		*get_fork_left(t_philo *philo, t_fork **forks);
t_fork		*get_fork_right(t_philo *philo, t_fork **forks);
void		drop_forks(t_fork *left, t_fork *right, t_philo *philo);

/*Error*/
void		print_error_red(char *str);
int			error(int argc, char **argv);

/*Initialisation*/
t_fork		**create_all_forks(int len);
t_philo		**create_all_philos(int argc, char **argv);

void		free_all_philos(t_philo **philos, int len);
void		free_all_forks(t_fork **forks, int len);

/*Thread*/
int			thread_philos(t_philo **philos, int len);

/*Death*/
int			all_meal_ok(t_philo **philos);
int			check_death(t_philo **philos);

/*Utils*/
int			ft_msleep(long int msec);
int			ft_usleep(long int usec);
long int	get_ms_now(void);

#endif
