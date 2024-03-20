#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack_utils.h"

stack* stack_Ctor_func (size_t capacity,       const int   line,
                   const char*  filename, const char* function)
{
    if(capacity > Max_capacity)
    {
        return NULL;
    }

    stack* stk = (stack*) calloc (1, sizeof(*stk));
    assert (stk != NULL);

    stk->capacity = capacity;
    stk->size = 0;

    stk->data = (elem_t*) calloc (capacity, sizeof(*(stk->data)));
    assert (stk->data != NULL);

        for(size_t i = 0; i < capacity; i++)
        {
            stk->data[i] = Poison;
        }

    stk->filename = filename;
    stk->function = function;
    stk->line = line;
    stk->hash = hash_calc(stk);

    return stk;
}

void stack_Dtor (stack* stk)
{
    assert (stk       != NULL);
    assert (stk->data != NULL);

    free (stk->data);
    stk->data = NULL;

    free (stk);
    stk = NULL;

    return;
}

void push (stack* stk, elem_t element)
{
    assert (stk       != NULL);
    assert (stk->data != NULL);

    if(stk->size == stk->capacity)
    {
        stk->capacity *= 2;
        stk->data = (elem_t*) realloc(stk->data, stk->capacity * sizeof(stk->data));
        assert (stk->data != NULL);

        for(size_t i = stk->size + 1; i < stk->capacity; i++)
        {
            stk->data[i] = Poison;
        }
    }

    stk->data[stk->size] = element;
    stk->size++;

    stk->hash = hash_calc(stk);

    return;
}

elem_t pop (stack* stk)
{
    assert (stk       != NULL);
    assert (stk->data != NULL);
    assert (stk->size != 0);

    elem_t element = stk->data[stk->size - 1];
    stk->data[stk->size - 1] = Poison;
    stk->size--;

    if(stk->size <= stk->capacity / 4)
    {
        stk->capacity /= 4;
        if(stk->capacity == 0)
            stk->capacity = 1;

        stk->data = (elem_t*) realloc(stk->data, stk->capacity * sizeof(stk->data));
        assert(stk->data != NULL);
    }

    stk->hash = hash_calc(stk);

    return element;
}

void stack_dump_func (const stack* stk,     const int   line,
                      const char* filename, const char* function,
                      const char* name)
{
    printf ("\nStack name: " GREEN "%s\n" RESET, name);
    printf ("File where from dump was called: " GREEN "%s\n" RESET, filename);
    printf ("Line where from dump was called: " GREEN "%d\n" RESET, line);
    printf ("Function where from dump was called: " GREEN "%s\n" RESET, function);

    printf ("\nFile where stack was created: " GREEN "%s\n" RESET, stk->filename);
    printf ("Function where stack was created: " GREEN "%s\n" RESET, stk->function);
    printf ("Line where stack was created: " GREEN "%d\n" RESET, stk->line);

    printf ("\nSize of stack: " GREEN "%zu\n" RESET, stk->size);
    printf ("Capacity of stack: " GREEN "%zu\n" RESET, stk->capacity);
    printf ("\nHASH - " GREEN "%zu\n" RESET, stk->hash);
    printf ("\nStack data:\n");

    for (size_t i = 0; i < stk->size; i++)
    {
        printf (CYAN "[%zu]" RESET " - %d\n", i, stk->data[i]);
    }

    for (size_t i = stk->size; i < stk->capacity; i++)
    {
        printf (CYAN "[%zu]" RESET " - %X - " RED "Poison\n" RESET, i, stk->data[i]);
    }

    return;
}

size_t hash_calc (stack* stk)
{
    size_t hash = 5381;

    for (size_t idx = 1; idx <= stk->capacity; idx++)
    {
        hash+= (idx * stk->data[idx-1]);
    }

    return hash;
}

void hash_verify(stack* stk)
{
    assert(stk->hash != hash_calc(stk));
}
