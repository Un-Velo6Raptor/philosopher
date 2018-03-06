/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <unistd.h>
#include "extern.h"
#include "philosopher.h"

void think(philosopher *me) {
	me->act = THINK;
	lphilo_take_chopstick(&me->match);
	lphilo_think();
	usleep(1000);
	lphilo_release_chopstick(&me->match);
}