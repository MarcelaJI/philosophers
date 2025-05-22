/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:18:40 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/22 08:16:12 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (argc != 5 && argc != 6)
		error_exit("Wrong argument count\n");
	parse_data(argv, &sim);
	init_forks(&sim);
	init_philos(&sim);
	start_threads(&sim);
	clean_up_all(NULL, &sim);
	return (EXIT_SUCCESS);
}