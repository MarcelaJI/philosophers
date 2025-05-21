/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:17:53 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/21 21:25:27 by ingjimen         ###   ########.fr       */
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
# include <stdbool.h>

# define PHILO_MAX 200

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

typedef struct s_sim t_sim;

typedef struct s_philo
{
	int             id;
	int             meals_eaten;
	int				eating;
	size_t          last_meal;
	pthread_t       thread;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	t_sim           *sim;
	pthread_mutex_t	mutex;
}	t_philo;

// Estructura general de la simulación
typedef struct s_sim {
	int             num_of_philos;
	int             time_to_die;
	int             time_to_eat;
	int             time_to_sleep;
	int             number_of_times_each_philosopher_must_eat;
	int             someone_died;
	size_t          start_time;
	pthread_mutex_t write_lock;
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t *forks;
	t_philo         *philos;
	struct timeval  begin_time;
} t_sim;


// error
void	ft_error_parsing(t_sim *sim);
void	error_exit(const char *msg);

// clean
void	clean_up(t_sim *sim);
void	clean_up_all(char *str, t_sim *sim);

// parse_data
bool    ft_isspace(char c);
bool    ft_is_digit(char c);
int	    ft_atoi(const char *str);
void     parse_data(char **argv, t_sim *table);

// init_simulation
void       init_forks(t_sim *sim);
void	init_philos(t_sim *sim);
void	assign_forks(t_philo *philo, int index, t_sim *sim);
void	start_threads(t_sim *sim);
void *philo_routine(void *arg);
long get_current_time_ms(void);
void print_status(t_philo *philo, char *message, char *color);
void philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void philo_think(t_philo *philo);
int	philo_died(t_philo *philo, size_t time);
int	check_death(t_sim *sim);
void	*monitor_func(void *arg);
int	philo_has_died(t_philo *philo);
void release_forks(t_philo *philo);
void ft_usleep(size_t time_in_ms);
int	ft_strlen(char *str);
int	check_if_all_ate(t_sim *philos);
void    taken_forks(t_philo *philo);

#endif