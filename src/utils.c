/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:06:53 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/22 11:44:38 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	long		sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 &&
				-result < INT_MIN))
			return (-1);
		i++;
	}
	return ((int)(result * sign));
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *status, char *color)
{
	long	timestamp;

	pthread_mutex_lock(&philo->sim->write_lock);
	if (!philo_has_died(philo) || ft_strncmp(status, "died 💀", 7) == 0)
	{
		timestamp = get_current_time_ms() - philo->sim->start_time;
		printf("%ld %d %s%s%s\n", timestamp, philo->id, color, status, RESET);
	}
	pthread_mutex_unlock(&philo->sim->write_lock);
}


void	ft_usleep(size_t time_in_ms)
{
	size_t	start;

	start = get_current_time_ms();
	while ((get_current_time_ms() - start) < time_in_ms)
		usleep(500);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

