/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 09:21:27 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_sim		*sim;
	pthread_t	monitor;
	int			i;

	if (argc < 5 || argc > 6)
		error_exit("Error: Number of incorrect arguments\n");
	sim = malloc(sizeof(t_sim));
	if (!sim)
		return (EXIT_FAILURE);
	parse_data(argv, sim);
	init_forks(sim);
	init_philos(sim);
	pthread_mutex_init(&sim->start_mutex, NULL);
	sim->start_sim = false;
	gettimeofday(&sim->begin_time, NULL);
	printf("\U0001F7E2 begin_time set at: %ld.%06ld\n", sim->begin_time.tv_sec,
		sim->begin_time.tv_usec);

	start_threads(sim);
	if (pthread_create(&monitor, NULL, monitor_func, sim) != 0)
		error_exit("Error: Failed to create monitor thread");

	pthread_mutex_lock(&sim->start_mutex);
	sim->start_sim = true;
	pthread_mutex_unlock(&sim->start_mutex);

	for (i = 0; i < sim->num_of_philos; i++)
		pthread_join(sim->philos[i].thread, NULL);
	pthread_join(monitor, NULL);

	for (i = 0; i < sim->num_of_philos; i++)
		pthread_mutex_destroy(&sim->forks[i]);
	pthread_mutex_destroy(&sim->start_mutex);
	pthread_mutex_destroy(&sim->dead_lock);
	free(sim->philos);
	free(sim->forks);
	free(sim);
	return (EXIT_SUCCESS);
}
