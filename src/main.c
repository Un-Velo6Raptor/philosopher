/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by martin.januario@epitech.eu,
*/

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include "parsing.h"
#include <stdlib.h>
#include "extern.h"
#include "philosopher.h"

static int prompt_help(void)
{
	printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\n");
	printf("DESCRIPTION\n\t-p nbr_p  number of philosophers");
	printf("           \n\t-e nbr_e  maximum number times a philosopher "
		"eats before exiting the program\n");
	return (1);
}

static int help_check(int argc, char **argv)
{
	int ret = 0;

	if (argc == 1 || argc > 5)
		ret = prompt_help();
	for (int idx = 1; idx < argc && argc > 5; ++idx) {
		if (!strcmp(argv[idx], "--help") || !strcmp(argv[idx], "-h")) {
			ret = prompt_help();
			break;
		}
	}
	return (ret);
}

int main(int argc, char **argv)
{
	int ret = 0;

	if (help_check(argc, argv))
		return (0);
	ret = parsing(argc, argv);
	if (ret != 84)
		RCFCleanup();
	return (ret);
}