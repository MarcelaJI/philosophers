/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:07:23 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 10:32:29 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long get_time_in_ms(t_sim *sim)
{
	struct timeval	now;
	
	gettimeofday(&now, NULL);
	return ((now.tv_sec - sim->begin_time.tv_sec) * 1000
		+ (now.tv_usec - sim->begin_time.tv_usec) / 1000);
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






