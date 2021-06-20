#include "ft.h"

static struct filetype filetypes[] = {
	{ "// ", NULL, {".go", NULL} },              /* Go */
	{ "// ", NULL, {".java", NULL} },            /* Java */
	{ "// ", NULL, {".js", ".ts", NULL} },       /* Javascript */
	{ "/* ", " */", {".c", ".h", NULL} },        /* C */
};
