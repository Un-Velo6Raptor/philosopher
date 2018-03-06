/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef PSU_PHILOSOPHER_2017_PHILOSOPHER_H
#define PSU_PHILOSOPHER_2017_PHILOSOPHER_H

#include <pthread.h>

typedef enum {
	EAT = 0,
	THINK = 1,
	SLEEP = 2,
	UNDEFINED = 3
} action;

typedef struct philosopher_s{
	int id;
	action act;
	action lastact;
	action llastact;
	pthread_mutex_t match;
	unsigned int eaten;
	unsigned int max_eaten;
	struct philosopher_s *next;
	pthread_barrier_t *bar;
} philosopher;

void think(philosopher *me);
void eat(philosopher *me);

philosopher *philosopher_initialisation(unsigned int, unsigned int);
void *philosophe(void *philo);
pthread_t *philosopher_thread(unsigned int number, philosopher *philos);
void philosopher_wait(pthread_t *threads, unsigned int nbr);

#endif //PSU_PHILOSOPHER_2017_PHILOSOPHER_H
