/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:14:44 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/22 08:19:59 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_up_all(char *str, t_sim *sim)
{
	int	i;

	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&sim->write_lock);
	pthread_mutex_destroy(&sim->meal_lock);
	pthread_mutex_destroy(&sim->dead_lock);
	if (sim->forks)
	{
		i = 0;
		while (i < sim->num_of_philos)
			pthread_mutex_destroy(&sim->forks[i++]);
		free(sim->forks);
	}
	if (sim->philos)
	{
		i = 0;
		while (i < sim->num_of_philos)
			pthread_mutex_destroy(&sim->philos[i++].mutex);
		free(sim->philos);
	}
}
