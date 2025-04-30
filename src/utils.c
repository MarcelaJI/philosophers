/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:00:47 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/30 13:17:02 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int     ft_strlen(char *str)
{
    int i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int     ft_atoi(char *str)
{
    int     i;
    int     sign;
    int     result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] <= 32)
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10;
        result = result + str[i] - '0';
        i++;
    }
    return (result * sign);
}
