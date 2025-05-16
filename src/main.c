/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 09:57:57 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (argc != 5 && argc != 6)
		return (error_exit("Invalid number of arguments\n"), 1);
	parse_data(argv, &sim);
	init_forks(&sim);
	init_philos(&sim);

	gettimeofday(&sim.begin_time, NULL);
	printf("🟢 begin_time set at: %ld.%06ld\n",
		sim.begin_time.tv_sec, sim.begin_time.tv_usec);

	init_last_meals(&sim);

	start_threads(&sim);
	wait_for_threads(&sim);
	cleanup(&sim);
	return (0);
}

