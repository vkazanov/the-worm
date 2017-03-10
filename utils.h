#pragma once

#include <stdio.h>

#define FREE(obj) fprintf(stderr, "%s:%d at %s FREE %s\n ", __FILE__,  __LINE__, __func__, #obj); free(obj)
