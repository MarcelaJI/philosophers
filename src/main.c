/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/30 12:52:36 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int   is_only_digits(char *argv)
{
    int i;

    i = 0;
    if (!argv || argv[0] == '\0')
        return (0);
    while (argv[i] != '\0')
    {
        if (argv[i] < '0' || argv[i] > '9')
            return (0); // No es dígito
        i++;
    }
    return (1);
}

int     main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    printf("1: %d\n", is_only_digits("123")); 
    printf("1: %d\n", is_only_digits("123a")); 
    printf("1: %d\n", is_only_digits(""));

    printf("Hello\n");
    return (0);
}