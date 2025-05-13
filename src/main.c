/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/13 10:31:21 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_sim *sim;
	pthread_t monitor;
	int		i;

	if (argc < 5 || argc > 6)
		error_exit("Error: Number of incorrect arguments\n");
	sim = malloc(sizeof(t_sim));
	if (!sim)
		return (EXIT_FAILURE);
	parse_data(argv, sim);
	init_forks(sim);
	init_philos(sim);
	gettimeofday(&sim->begin_time, NULL);
	pthread_create(&monitor, NULL, monitor_func, sim);
	print_status(&sim->philos[0], "is testing print_status", YELLOW);
	printf(YELLOW "Forks initialized successfully!\n" RESET);
	printf(GREEN "Philosophers initialized successfully!\n" RESET);
	start_threads(sim);
	i = 0;
	while (i < sim->num_of_philos)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	free(sim);
	return (EXIT_SUCCESS);
}