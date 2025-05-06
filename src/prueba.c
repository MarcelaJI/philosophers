#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*hola(void *unused)
{
	size_t		i;
	char	*msg;
    (void)unused;

	i = 0;
	msg = "Hola desde el hilo 1";
	while (i < ft_strlen(msg))
	{
		printf("%c", msg[i]);
		fflush(stdout);
		i++;
	}
	return (NULL);
}

void	*mundo(void *unused)
{
	size_t		i;
	char	*msg;

    (void)unused;
	i = 0;
	msg = "hola desde el hilo 2";
	while (i < ft_strlen(msg))
	{
		printf("%c", msg[i]);
		fflush(stdout);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t h1;
	pthread_t h2;


    (void)argc;
    (void)argv;
	pthread_create(&h1, NULL, hola, NULL);
    usleep(1000000);
	pthread_create(&h2, NULL, mundo, NULL);
    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
	printf("Fin\n");
	return (0);
}