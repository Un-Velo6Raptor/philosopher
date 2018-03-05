/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <stdlib.h>
#include <zconf.h>
#include <stdio.h>
#include "philosopher.h"
#include "extern.h"

philosopher *philosopher_initialisation(unsigned int number,
	unsigned int eaten
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
		philo[i].lastact = (i % 2) ? EAT : SLEEP;
		if (i == number - 1) {
			philo[i].next = &(philo[0]);
		} else {
			philo[i].next = &(philo[i + 1]);
		}
	}
	return philo;
}

int ended(philosopher *me)
{
	int id = me->id;
	int first = 1;

	for (; me->id != id || first == 1; me = me->next) {
		first = 0;
		if (me->eaten == me->max_eaten)
			return 1;
	}
	return 0;
}

void *philosophe(void *philo)
{
	philosopher *me = (philosopher *)philo;

	while (!ended(me)) {

		if (me->lastact == SLEEP) {
			me->act = EAT;
			printf("%i: EAT\n", me->id);
			lphilo_take_chopstick(&me->match);
			lphilo_take_chopstick(&me->next->match);
			lphilo_eat();
			me->eaten++;
			sleep(1);
			lphilo_release_chopstick(&me->match);
			lphilo_release_chopstick(&me->next->match);
		} else {
			printf("%i: SLEEP\n", me->id);
			me->act = SLEEP;
			lphilo_sleep();
		}
		me->lastact = me->act;
		pthread_barrier_wait(me->bar);
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
		usleep(100);
	}
	return thread;
}