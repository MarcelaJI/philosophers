/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/07 09:09:52 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_sim *sim;

	if (argc < 5 || argc > 6)
		return (error_argv(), EXIT_FAILURE);
	sim = malloc(sizeof(t_sim));
	if (!sim)
		return (EXIT_FAILURE);
	parse_data(argv, sim);
	init_forks(sim);
	printf(YELLOW "Forks initialized successfully!\n" RESET);
	free(sim);
	return (EXIT_SUCCESS);
}