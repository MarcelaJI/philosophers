/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:00:47 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/09 11:01:55 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (-1);
		i++;
	}
	return ((int)(result * sign));
}

void	print_status(t_philo *philo, char *message, char *color)
{
	long	timestamp;

	pthread_mutex_lock(&philo->sim->write_lock);
	timestamp = get_elapsed_ms(philo->sim);
	printf("%s%ld %d %s%s\n", color, timestamp, philo->id, message, RESET);
	pthread_mutex_unlock(&philo->sim->write_lock);
}
