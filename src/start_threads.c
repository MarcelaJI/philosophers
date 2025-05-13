/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:07:23 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/13 12:14:38 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long get_elapsed_ms(t_sim *sim)
{
	struct timeval now;
	gettimeofday(&now, NULL);

	printf("📏 now = %ld.%06ld, begin_time = %ld.%06ld\n",
		now.tv_sec, now.tv_usec,
		sim->begin_time.tv_sec, sim->begin_time.tv_usec);

	// calcula diferencia
	long ms = (now.tv_sec - sim->begin_time.tv_sec) * 1000;
	ms += (now.tv_usec - sim->begin_time.tv_usec) / 1000;
	return ms;
}


void	start_threads(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		sim->philos[i].last_meal = get_elapsed_ms(sim);
		printf("🕒 SET last_meal for philo %d = %ld\n", sim->philos[i].id, sim->philos[i].last_meal);
		if (pthread_create(&sim->philos[i].thread, NULL, philo_routine, &sim->philos[i]) != 0)
			error_exit("Error: Failed to create thread\n");
		i++;
	}
}



