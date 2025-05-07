/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/07 09:57:09 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_sim *sim;

	if (argc < 5 || argc > 6)
		error_exit("Error: Number of incorrect arguments\n");
	sim = malloc(sizeof(t_sim));
	if (!sim)
		return (EXIT_FAILURE);
	parse_data(argv, sim);
	init_forks(sim);
	init_philos(sim);
	printf(YELLOW "Forks initialized successfully!\n" RESET);
	printf(GREEN "Philosophers initialized successfully!\n" RESET);

	free(sim);
	return (EXIT_SUCCESS);
}