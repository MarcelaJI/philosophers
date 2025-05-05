/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:32:32 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/05 09:48:21 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int     ft_isspace(const char c)
{
    if ((c == 32) || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int     ft_isdigit(const char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int     ft_check_argument(char *argv)
{
    int     count;

    count = 0;
    while (ft_isspace(argv[count]))
        count++;
    if (ft_isdigit(argv[count]) || argv[count] == '+')
        count++;
    else
        return (EXIT_FAILURE);
    while (argv[count])
    {
        if (!ft_isdigit(argv[count]))
            return (EXIT_FAILURE);
        count++;
    }
    return (EXIT_SUCCESS);
}
