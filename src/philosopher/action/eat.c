/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <unistd.h>
#include "extern.h"
#include "philosopher.h"

void eat(philosopher *me) {
	me->act = EAT;
	lphilo_take_chopstick(&me->match);
	lphilo_take_chopstick(&me->next->match);
	lphilo_eat();
	usleep(1000);
	me->eaten++;
	lphilo_release_chopstick(&me->match);
	lphilo_release_chopstick(&me->next->match);
}