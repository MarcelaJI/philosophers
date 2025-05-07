/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:48:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/07 09:55:20 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 250

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

// Declaración directa
typedef struct s_sim t_sim;
// Estructura para cada filósofo
typedef struct s_philo
{
	int             id;
	int             meals_eaten;
	size_t          last_meal;
	pthread_t       thread;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	t_sim           *sim;          // referencia a los datos globales
	pthread_mutex_t	mutex;  // Protege el acceso a last_meal, meals_eaten, etc.
}	t_philo;


// Estructura general de la simulación
typedef struct s_sim
{
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_to_eat;
	int		dead;
	size_t	start_time;
	pthread_mutex_t write_lock;
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t *forks;        // array de mutexes
	t_philo         *philos;       // array de filósofos
}	t_sim;


void				error_exit(char *msg);
void				error_parsing(t_sim *table);
int					ft_atoi(const char *str);
int					ft_strlen(char *str);
int					ft_isspace(char c);
int					ft_isdigit(char c);
int					ft_check_argument(char *argv);
void				parse_data(char **argv, t_sim *table);
void    			init_forks(t_sim *sim);

#endif