#ifndef FT_H
#define FT_H

#include <string.h>
#include <stdbool.h>

#define EXT_MAX 50

struct filetype {
	char *comstart;
	char *comend;
	char *extensions[EXT_MAX];
	bool use_tabs;
	int  tab_width;
};

char * ft_ext(char *filename);
int ft_parse(char *filename, struct filetype filetypes[], int len);

#endif
