/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by martin.januario@epitech.eu,
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

	if (nbr_philosopher <= 0 || nbr_step <= 0){
		ret = 84;
		fprintf(stderr, "Argument error: Look --help\n");
	} else {
		// call the function algo
	}
	return (ret);
}