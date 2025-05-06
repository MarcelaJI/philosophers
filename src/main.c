/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/06 09:05:22 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo_sim *table;

	if (argc < 5 || argc > 6)
		return (error_argv(), EXIT_FAILURE);
	table = malloc(sizeof(t_philo_sim));
	if (!table)
		return (EXIT_FAILURE);
	parse_data(argv, table);
	free(table);
	return (EXIT_SUCCESS);
}