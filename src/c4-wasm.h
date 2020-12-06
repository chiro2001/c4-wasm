// c4.c - C in four functions

// char, int, and pointer types
// if, while, return, and expression statements
// just enough features to allow self-compilation and a bit more

// Written by Robert Swierczek
#include <emscripten/emscripten.h>

#include "efiles/efiles.h"
// void next();
// void expr(int lev);
// void stmt();
// int process(int argc, char **argv);

extern EFILE *_out_;
#define printf(str, ...)                                   \
  do {                                                     \
    sprintf(_efiles_buf_, str, __VA_ARGS__);               \
    if (!_out_) break;                                     \
    efwrite(_efiles_buf_, strlen(_efiles_buf_), 1, _out_); \
  } while (0)

#define putstring(str) printf("%s", str)