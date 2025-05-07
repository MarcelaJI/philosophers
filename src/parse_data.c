/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:27:41 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/07 08:19:21 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_init_sim_table(t_sim *table, char **argv)
{
	table->num_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->num_times_to_eat = ft_atoi(argv[5]);
	else
		table->num_times_to_eat = -1;
}

void	parse_data(char **argv, t_sim *table)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_check_argument(argv[i]) == EXIT_FAILURE)
			return (error_parsing(table));
		i++;
	}
	ft_init_sim_table(table, argv);
	if (table->num_of_philos < 1 || table->num_of_philos > 250
		|| table->time_to_die <= 0 || table->time_to_eat <= 0
		|| table->time_to_sleep <= 0)
		return (error_parsing(table));
}
