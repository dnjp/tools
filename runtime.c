#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "runtime.h"

int get_filename(int argc, char **argv, char *filename)
{
	int opt;
	while((opt = getopt(argc, argv, ":f:")) != -1) {
		switch(opt) {
			case 'f':
				strcpy(filename, optarg);
				return 0;
		}
	}
	return -1;
}