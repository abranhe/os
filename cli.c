//
// cli.c
//
// MIT licensed.
// Copyright (c) Abraham Hernandez <abraham@abranhe.com>
//

#include <stdio.h>
#include <string.h>
#include "os.h"

const char*
show_help() {
 return "\n\
 Wanna know your operating system? - I know right :)\n\n\
 Usage:\n\n\
   $ os <flag> \n\n\
 Options:\n\n\
   -v,  --version     output version number\n\
   -h,  --help        output usage information\n\n\
 Example:\n\n\
   $ os\n\
   macOS\n\n";
}

/* CLI. */
int
main(int argc, char **argv) {
  char *a = argv[1];

  if (argc == 2) {
    if (!strcmp(a, "-v") || !strcmp(a, "--version")) {
      printf("%s", "1.0.0\n");
      return 0;
    }

    if (!strcmp(a, "-h") || !strcmp(a, "--help")) {
			printf("%s", show_help());
      return 0;
    }
	}

  if (argc > 1) {
		fprintf(stderr, "\033[31mSee `--help` for details.\033[0m\n");
    return 1;
  }

	printf("%s\n", operating_system());
  return 0;
}
