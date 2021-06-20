#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "array.h"
#include "line.h"
#include "config.h"
#include "ft.h"
#include "runtime.h"

int main(int argc, char **argv)
{
	array arr;
	struct filetype *ft;
	bool touch;
	enum line_action act;
	char in[MAXBUF];
	char *filename;
	int ft_len;
	int ft_idx;
	int lines;
	ssize_t in_len;

	ft = NULL;
	filename = (char*)malloc(MAXBUF*sizeof(char));
	ft_len = sizeof(filetypes)/sizeof(struct filetype);
	touch = false;

	if(get_filename(argc, argv, filename) < 0 || filename == NULL) {
		fprintf(stderr, "filename must be provided with -f flag");
		exit(-1);
	}
	if(array_create(&arr) != 0) {
		fprintf(stderr, "could not allocate array");
		exit(-1);
	}
	if((ft_idx = ft_parse(filename, filetypes, ft_len)) >= 0) {
		touch = true;
		ft = &filetypes[ft_idx];
	}
	if (read_stdin(&arr, ft) != 0) {
		fprintf(stderr, "could not read stdin");
		exit(-1);
	}
	for(int i = 0; i < arr.index; i++) {
		line *l = (line*)malloc(sizeof(line));
		if(array_at(&arr, l, i) != 0) {
			fprintf(stderr, "could not retreive item from array");
			exit(-1);
		}

		if(l == NULL) {
			fprintf(stderr, "item not popped from array");
			exit(-1);
		}
		if(touch) {
			line_unindent(l, ft);
		}
		if(arr.index > 1 && i == arr.index-1)
			printf("%s", l->content);
		else
			printf("%s\n", l->content);
		free(l);
	}
	array_destroy(&arr);
	exit(0);
}
