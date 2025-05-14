/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:07:23 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/14 08:17:05 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long get_elapsed_ms(t_sim *sim)
{
	struct timeval now;
	long long ms;
	
	gettimeofday(&now, NULL);
	ms = (now.tv_sec - sim->begin_time.tv_sec) * 1000;
	ms += (now.tv_usec - sim->begin_time.tv_usec) / 100;
	return (ms);
}

void	ft_wait_all_threads(t_ *table)
{
	pthread_mutex_lock(&table->start_mutex);
	while (!table->all_threads_ready)
	{
		pthread_mutex_unlock(&table->start_mutex);
		usleep(100); // Evita consumir CPU excesivamente
		pthread_mutex_lock(&table->start_mutex);
	}
	gettimeofday(&table->start_simulator, NULL);
	pthread_mutex_unlock(&table->start_mutex);
}


void	start_threads(t_sim *sim)
{
	int	i;
	t_philo	*philo;

	i = 0;
	while (i < sim->num_of_philos)
	{
		philo = &sim->philos[i];
		pthread_mutex_lock(&philo->mutex);
		philo->last_meal = get_elapsed_ms(sim);
		pthread_mutex_unlock(&philo->mutex);
		printf("🕒 SET last_meal for philo %d = %ld\n", philo->id, philo->last_meal);
		if (pthread_create(&philo->thread, NULL, philo_routine, philo) != 0)
			error_exit("Error: Failed to create thread\n");
		i++;
	}
}





