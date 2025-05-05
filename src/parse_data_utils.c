/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:32:32 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/05 08:48:10 by ingjimen         ###   ########.fr       */
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
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

// static int   is_only_digits(char *argv)
// {
//     int i;

//     i = 0;
//     if (!argv || argv[0] == '\0')
//         return (0);
//     while (argv[i] != '\0')
//     {
//         if (argv[i] < '0' || argv[i] > '9')
//             return (0);
//         i++;
//     }
//     return (1);
// }
