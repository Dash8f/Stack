#include "stack_utils.h"

int main()
{
    stack* stk1 = stack_Ctor (4);

    // stk1->data = (elem_t *) 1; // Encapsulation bug.
    // // TODO Fix that.

    push(stk1, 1);
    push(stk1, 96);
    push(stk1, 45);
    push(stk1, 1);
    push(stk1, 28);

    stack_dump (stk1);

    push(stk1, 17);

    stack_dump (stk1);

    int popa = pop(stk1);
    popa = pop(stk1);

    pop(stk1);
    pop(stk1);
    pop(stk1);
    pop(stk1);

    stack_dump (stk1);

    stack_Dtor (stk1);

    return 0;
}
