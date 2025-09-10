#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"


void testing()
{
    stack stk_instance = stacknew(1);
    stack* stk = &stk_instance;
    stackresult result;

    assert(stack_empty(stk));

    stack_peek(stk, &result);
    assert(result.status == STACK_EMPTY);

    stack_pop(stk, &result);
    assert(result.status == STACK_EMPTY);

    stack_push(stk, 99, &result);
    assert(result.status == STACK_OK);

    assert(stack_full(stk));

    stack_push(stk, 100, &result);
    assert(result.status == STACK_FULL);

    stack_peek(stk, &result);
    assert(result.data == 99 && result.status == STACK_OK);

    stack_pop(stk, &result);
    assert(result.status == STACK_OK && result.data == 99);

    assert(stack_empty(stk));
}



int main()
{
    testing();


}
