/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:05 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/09 11:26:10 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define DEAD 1
# define ALIVE 0


typedef struct s_philo
{
	pthread_t		tid;
// Variable utilise
	int				*wait;
	int				tt[4];
	int				num;
	int				state;
	int				last_eat;
	int				fork;
	long			*itime;
// Pointeur sur les prochains philos
	struct s_philo	*n_philo;
	struct s_philo	*p_philo;
// Mutex Lock
	pthread_mutex_t	*wait_lock;
	pthread_mutex_t	*time_lock;
	pthread_mutex_t	fork_lock;
}	t_philo;

typedef struct s_var
{
	int				wait;
	int				n_philo;
	int				tt[4];
	long			time;
	t_philo			*f_philo;
	t_philo			*p;
	pthread_mutex_t	lock;
	pthread_mutex_t	time_lock;
}	t_var;

long int	ft_atoi(const char *str);
void		ft_free(t_var *var);
void		init_philo(t_var *var);
void		ft_readarg(int argc, char **argv, t_var *var);
void		*ft_start_routine();

// Text colors
# define COLOR_BLACK   "\033[30m"
# define COLOR_RED     "\033[31m"
# define COLOR_GREEN   "\033[32m"
# define COLOR_YELLOW  "\033[33m"
# define COLOR_BLUE    "\033[34m"
# define COLOR_MAGENTA "\033[35m"
# define COLOR_CYAN    "\033[36m"
# define COLOR_WHITE   "\033[37m"

// Background colors
# define BG_BLACK   "\033[40m"
# define BG_RED     "\033[41m"
# define BG_GREEN   "\033[42m"
# define BG_YELLOW  "\033[43m"
# define BG_BLUE    "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN    "\033[46m"
# define BG_WHITE   "\033[47m"

// Text attributes
# define RESET     "\033[0m"
# define BOLD      "\033[1m"
# define DIM       "\033[2m"
# define UNDERLINE "\033[4m"
# define BLINK     "\033[5m"
# define REVERSE   "\033[7m"
# define HIDDEN    "\033[8m"

#endif
