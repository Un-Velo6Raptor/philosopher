/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by martin.januario@epitech.eu,
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <asm/errno.h>
#include "philosopher.h"
#include "extern.h"

static int get_nbr_option(char *str)
{
	int result = 0;
	int idx = 0;

	if (!str || !strlen(str))
		result = -1;
	for (; str && str[idx] != '\0' && str[idx] >= '0' &&
		str[idx] <= '9'; ++idx);
	return ((idx == 0 || result == -1) ? -1 : atoi(str));
}

static int get_opt_by_string(int argc, char **argv, char *opt)
{
	int result = -1;

	for (int idx = 0; idx < argc; ++idx) {
		if (!strcmp(argv[idx], opt)) {
			result = get_nbr_option(argv[idx + 1]);
			break;
		}
	}
	return (result);
}

int parsing(int argc, char **argv)
{
	int ret = 0;
	int nbr_philosopher = get_opt_by_string(argc, argv, "-p");
	int nbr_step = get_opt_by_string(argc, argv, "-e");
	void *philo;
	pthread_t *threads;

	if (nbr_philosopher <= 1 || nbr_step <= 0) {
		ret = 84;
		fprintf(stderr, "Argument error: Look --help\n");
	} else {
		RCFStartup(argc, argv);
		philo = philosopher_initialisation(
			(unsigned int)nbr_philosopher, (unsigned int)nbr_step);
		threads = philosopher_thread((unsigned int)nbr_philosopher,
			philo);
		philosopher_wait(threads, (unsigned int)nbr_philosopher);
	}
	return (ret);
}