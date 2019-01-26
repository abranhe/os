//
// cli.c
//
// MIT licensed.
// Copyright (c) Abraham Hernandez <abraham@abranhe.com>
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "os.h"

/*
 * os version.
 */

#define VERSION "1.0.1"

/*
 * Output usage information.
 */

void
usage() {
  fprintf(stderr,
    "\n  Usage: os [options]"
    "\n"
    "\n  Options:"
    "\n"
    "\n    -h, --help      output help information"
    "\n    -v, --version   output os version"
    "\n"
    "\n  Examples:"
    "\n"
    "\n    $ os"
    "\n    macOS"
    "\n"
    "\n"
    );
  exit(1);
}

/*
 * Output os version.
 */

void
version() {
  printf("%s\n", VERSION);
  exit(0);
}

/*
 * CLI
 */

int
main(int argc, char **argv) {
  char *a = argv[1];

  if (argc == 2) {
    if (!strcmp(a, "-v") || !strcmp(a, "--version")) {
      version();
      return 0;
    }

    if (!strcmp(a, "-h") || !strcmp(a, "--help")) {
			usage();
      return 0;
    }
	}

  if (argc > 1) {
		fprintf(stderr, 
      "\033[31mSee `--help` for details.\033[0m\n");
    return 1;
  }

	printf("%s\n", operating_system());
  return 0;
}
