/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by martin.januario@epitech.eu,
*/

#include <stdlib.h>
#include <stdio.h>
#include "philosopher.h"
#include "extern.h"

static void setLastAction(philosopher *node, unsigned int idx)
{
	if (idx % 4 == 0) {
		node->lastact = SLEEP;
		node->llastact = EAT;
	} else if (idx % 3 == 0) {
		node->lastact = EAT;
		node->llastact = THINK;
	} else if (idx % 2 == 0) {
		node->lastact = THINK;
		node->llastact = SLEEP;
	} else {
		node->llastact = SLEEP;
		node->lastact = SLEEP;
	}
}

philosopher *philosopher_initialisation(unsigned int number, unsigned int eaten
)
{
	philosopher *philo = malloc(sizeof(philosopher) * number);
	pthread_barrier_t *bar = malloc(sizeof(pthread_barrier_t));

	pthread_barrier_init(bar, NULL, number);
	for (unsigned int i = 0; i < number; i++) {
		philo[i].id = i;
		philo[i].match = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		philo[i].eaten = 0;
		philo[i].bar = bar;
		philo[i].max_eaten = eaten;
		setLastAction(&philo[i], i);
		if (i == number - 1) {
			philo[i].next = &(philo[0]);
		} else {
			philo[i].next = &(philo[i + 1]);
		}
	}
	return philo;
}
