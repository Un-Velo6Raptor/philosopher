/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philosopher.h"
#include "extern.h"

int ended(philosopher *me)
{
	int id = me->id;
	int first = 1;

	pthread_barrier_wait(me->bar);
	for (; me->id != id || first == 1; me = me->next) {
		first = 0;
		if (me->eaten == me->max_eaten)
			return 1;
	}
	pthread_barrier_wait(me->bar);
	return 0;
}

void *philosophe(void *philo)
{
	philosopher *me = (philosopher *)philo;
	 int id = me->id;

	while (!ended(me)) {
		if (me->lastact == SLEEP && me->llastact == SLEEP) {
			think(me);
		} else if (me->lastact == EAT) {
			me->act = SLEEP;
			lphilo_sleep();
		} else if (me->lastact == THINK)
			eat(me);
		me->llastact = me->lastact;
		me->lastact = me->act;
	}
	return NULL;
}

void philosopher_wait(pthread_t *threads, unsigned int nbr)
{
	for (unsigned int i = 0; i < nbr; i++) {
		pthread_join(threads[i], NULL);
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