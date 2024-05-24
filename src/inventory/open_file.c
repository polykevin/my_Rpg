/*
** EPITECH PROJECT, 2024
** main
** File description:
** open file function
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include "snow_header.h"

static int file_size(char const *filepath)
{
    struct stat st;
    int size = 0;

    if (stat(filepath, &st) == ERROR_INT)
        return ERROR_INT;
    size = st.st_size;
    return size;
}

static bool init_error(int fd, int filesize)
{
    if (fd == ERROR_INT) {
        return true;
    }
    if (filesize == ERROR_INT) {
        return true;
    }
    if (filesize == 0) {
        return true;
    }
    return false;
}

char *open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    size_t line_size = 0;
    int filesize = file_size(filepath);
    char *buffer = NULL;

    if (init_error(fd, filesize)) {
        return NULL;
    }
    buffer = calloc(filesize + 1, sizeof(char));
    if (buffer == NULL) {
        dprintf(2, "[ERROR] Unable to allocate memory\n");
        return NULL;
    }
    line_size = read(fd, buffer, filesize);
    if (line_size == (size_t)ERROR_INT) {
        dprintf(2, "[ERROR] Unable to read file\n");
        return NULL;
    }
    close(fd);
    return buffer;
}
