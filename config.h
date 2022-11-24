#include <stddef.h>

typedef int elem_t;

static const elem_t Poison = 0xBADDED;

static const size_t Max_capacity = 99999999;

typedef struct stack
{
    elem_t* data;

    size_t size;
    size_t capacity;

    size_t hash;

    const char* filename;
    const char* function;
    int line;
} stack;
