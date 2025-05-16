/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:07:23 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 09:24:35 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long get_elapsed_ms(t_sim *sim)
{
	struct timeval current;
	long sec;
	long usec;

	gettimeofday(&current, NULL);
	sec = current.tv_sec - sim->begin_time.tv_sec;
	usec = current.tv_usec - sim->begin_time.tv_usec;
	if (usec < 0)
	{
		sec -= 1;
		usec += 1000000;
	}
	return sec * 1000 + usec / 1000;
}


void	wait_all_threads(t_sim *sim)
{
	while (1)
	{
		pthread_mutex_lock(&sim->start_mutex);
		if (sim->start_sim)
		{
			pthread_mutex_unlock(&sim->start_mutex);
			break ;
		}
		pthread_mutex_unlock(&sim->start_mutex);
		usleep(100); // para evitar busy waiting
	}
}

void	start_threads(t_sim *sim)
{
    int		i;
    t_philo	*philo;

    i = 0;
    while (i < sim->num_of_philos)
    {
        philo = &sim->philos[i];
        if (pthread_create(&philo->thread, NULL, philo_routine, philo) != 0)
            error_exit("Error: Failed to create thread\n");
        usleep(100);
        i++;
    }
}






