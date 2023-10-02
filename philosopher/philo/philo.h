/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:05 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/10/02 10:27:23 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // Pour write, fork, usleep
#include <sys/types.h>  // Pour getpid, fork, kill, waitpid
#include <signal.h>     // Pour kill
#include <sys/time.h>   // Pour gettimeofday
#include <pthread.h>    // Pour pthread_create, pthread_detach, pthread_join
#include <sys/wait.h>   // Pour waitpid
#include <semaphore.h>

#endif
