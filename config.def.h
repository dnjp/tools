#include "ft.h"

static struct filetype filetypes[] = {
	{ "// ", NULL, {".go", NULL}, true, 8 },              /* Go */
	{ "// ", NULL, {".java", NULL}, false, 2 },           /* Java */
	{ "// ", NULL, {".js", ".ts", NULL}, false, 2 },      /* Javascript */
	{ "# ", NULL, {".yaml", ".yml", NULL}, false, 2 },    /* Yaml */
	{ "# ", NULL, {".tf", NULL}, false, 2 },              /* Terraform */
	{ "/* ", " */", {".c", ".h", NULL}, true, 8 },        /* C */
};
