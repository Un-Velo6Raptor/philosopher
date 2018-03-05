/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef PSU_PHILOSOPHER_2017_PHILOSOPHER_H
#define PSU_PHILOSOPHER_2017_PHILOSOPHER_H

#include <pthread.h>

typedef struct philosopher_s{
	pthread_mutex_t match;
	unsigned int eaten;
	unsigned int max_eaten;
	struct philosopher_s *next;

} philosopher;

#endif //PSU_PHILOSOPHER_2017_PHILOSOPHER_H
