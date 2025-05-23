/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:00:56 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/23 10:27:28 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	ft_check_argument(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	if (!ft_is_digit(str[i]))
		return (false);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	ft_init_sim(t_sim *sim, char **argv)
{
	sim->num_of_philos = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat = ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		sim->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		sim->number_of_times_each_philosopher_must_eat = -1;
	sim->someone_died = 0;
	sim->full_philos = 0;
	pthread_mutex_init(&sim->write_lock, NULL);
	pthread_mutex_init(&sim->dead_lock, NULL);
	pthread_mutex_init(&sim->meal_lock, NULL);
	pthread_mutex_init(&sim->full_lock, NULL);
}

int parse_data(char **argv, t_sim *table)
{
    int i;

	i = 1;
    while (argv[i])
    {
        if (!ft_check_argument(argv[i]))
            return (1);
        i++;
    }
    ft_init_sim(table, argv);
    if (table->num_of_philos < 1 || table->num_of_philos > PHILO_MAX
        || table->time_to_die <= 0 || table->time_to_eat <= 0
        || table->time_to_sleep <= 0)
        return (1);
    table->start_time = get_current_time_ms();
    return (0);
}

