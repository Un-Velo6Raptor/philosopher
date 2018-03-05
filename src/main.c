/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by martin.januario@epitech.eu,
*/

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include "extern.h"
#include "philosopher.h"

static void prompt_help(void)
{
	printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\n");
	printf("DESCRIPTION\n\t-p nbr_p  number of philosophers");
	printf("           \n\t-e nbr_e  maximum number times a philosopher "
		"eats before exiting the program\n");
}

static int help_check(int argc, char **argv)
{
	if (argc == 1)
		prompt_help();
	for (int idx = 1; idx < argc; ++idx) {
		if (!strcmp(argv[idx], "--help") || !strcmp(argv[idx], "-h")) {
			prompt_help();
			break;
		}
	}
	return (0);
}

void philosophe() {

}

int main(int argc, char **argv)
{
	if (help_check(argc, argv))
		return (0);
	RCFStartup(argc, argv);
	return (0);
}