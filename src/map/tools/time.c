/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

float time_as_seconds(sfClock *clock)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    return (seconds);
}
