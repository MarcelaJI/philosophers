/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/13 11:34:04 by ingjimen         ###   ########.fr       */
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
	gettimeofday(&sim->begin_time, NULL);
	usleep(100);
	if (pthread_create(&monitor, NULL, monitor_func, sim) != 0)
		error_exit("Error: Failed to create monitor thread");
	start_threads(sim);
	i = 0;
	while (i < sim->num_of_philos)
		pthread_join(sim->philos[i++].thread, NULL);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < sim->num_of_philos)
		pthread_mutex_destroy(&sim->philos[i++].mutex);

	i = 0;
	while (i < sim->num_of_philos)
		pthread_mutex_destroy(&sim->forks[i++]);

	pthread_mutex_destroy(&sim->dead_lock);

	free(sim->philos);
	free(sim->forks);
	free(sim);

	return (EXIT_SUCCESS);
}
