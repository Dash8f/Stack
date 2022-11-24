#ifndef STACK_UTILS_H
#define STACK_UTILS_H

#include "config.h"
#include "Colors.h"

// stack* stack_Ctor (size_t capacity);
void   stack_Dtor (stack* stk);

void   push (stack* stk, elem_t element);
elem_t pop (stack* stk);

size_t hash_calc (stack* stk);
void hash_verify(stack* stk);

#define stack_Ctor(capacity) \
    stack_Ctor_func(capacity, __LINE__, __FILE__, __PRETTY_FUNCTION__)

stack* stack_Ctor_func (size_t  capacity,      const int   line,
                        const char*  filename, const char* function);


#define stack_dump(stk) \
    stack_dump_func(stk, __LINE__, __FILE__, __PRETTY_FUNCTION__, #stk)

void stack_dump_func (const stack* stk,      const int   line,
                      const char*  filename, const char* function,
                      const char*  name);

#endif
