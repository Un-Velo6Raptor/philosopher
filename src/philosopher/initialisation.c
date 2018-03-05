/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <stdlib.h>
#include "philosopher.h"

philosopher *philosopher_initialisation(unsigned int number,
	unsigned int eaten)
{
	philosopher *philo = malloc(sizeof(philosopher) * number);

	for (unsigned int i = 0; i < number; i++) {
		philo[i].match = PTHREAD_MUTEX_INITIALIZER;
		philo[i].eaten = 0;
		philo[i].max_eaten = eaten;
		if (i == number - 1) {
			philo[i].next = &(philo[i]);
		} else {
			philo[i].next = &(philo[i + 1]);
		}
	}
	return philo;
}

void *philosophe(void *philo) {
	philosopher *me = (philosopher *)philo;

	while (me->eaten < me->max_eaten) {

	}
}

pthread_t *philosopher_thread(unsigned int number, philosopher *philos)
{
	pthread_t *thread = malloc(sizeof(pthread_t) * (number));

	for (unsigned int i = 0; i < number; i++) {
		pthread_create(&thread[i], NULL, &philosophe, &(philos[i]));
	}
	return thread;
}