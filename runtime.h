#ifndef runtime_H
#define runtime_H

#include "array.h"
#include "ft.h"

#define MAXBUF 1024

int get_filename(int argc, char **argv, char *filename);
int read_stdin(array *arr, struct filetype *ft);

#endif