#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "runtime.h"

int get_filename(int argc, char **argv, char *filename)
{
	/* try to get filename from acme environment */
	char *acmename;
	acmename = getenv("samfile");
	if(acmename) {
		strcpy(filename, acmename);
		return 0;
	}

	/* get filename from flag */
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

int read_stdin(array *arr, struct filetype *ft)
{
	int in_len;
	char in[MAXBUF];
	while((in_len = read(0, in, sizeof(in))) > 0) {
		in[in_len] = '\0';
		in_len++;
		char *t = strtok(in, "\n");
		while(t != NULL) {
			if(array_push(arr, ft, t, in_len) != 0) {
				fprintf(stderr, "could not add item to array");
				exit(-1);
			}
			t = strtok(NULL, "\n");
		}
	}
	return 0;
}