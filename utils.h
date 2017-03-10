#pragma once

#include <stdlib.h>
#include <stdio.h>

#define MALLOC(size) malloc(size); fprintf(stderr, "%s:%d (%s) MALLOC %ld\n ", __FILE__,  __LINE__, __func__, (size))
#define FREE(obj) free(obj); fprintf(stderr, "%s:%d (%s) FREE %s\n ", __FILE__,  __LINE__, __func__, #obj)
