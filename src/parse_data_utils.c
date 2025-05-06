/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:32:32 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/06 09:05:51 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isspace(char c)
{
	return ((c == 32) || (c >= 9 && c <= 13));
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_check_argument(char *argv)
{
	int	i;

	i = 0;
	while (ft_isspace(argv[i]))
		i++;
	if (argv[i] == '+')
		i++;
	if (!argv[i] || !ft_isdigit(argv[i]))
		return (EXIT_FAILURE);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
