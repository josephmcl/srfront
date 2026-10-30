#pragma once

#include <stdio.h>

/* Diagnostic colored print statement.                              */
#define notice_c(...)  ( \
    fprintf(stderr, "\033[1;36m(notice)\033[0m "),  \
    fprintf(stderr, __VA_ARGS__), \
    fprintf(stderr, "\n")) /* Cyan                                  */
#define warning_c(...) ( \
    fprintf(stderr, "\033[1;33m(warning)\033[0m "), \
    fprintf(stderr, __VA_ARGS__), \
    fprintf(stderr, "\n")) /* Yellow                                */
#define error_c(...)   ( \
    fprintf(stderr, "\033[1;31m(error)\033[0m "),   \
    fprintf(stderr, __VA_ARGS__), \
    fprintf(stderr, "\n")) /* Red.                                  */
