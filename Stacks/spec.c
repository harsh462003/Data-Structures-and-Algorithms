#include <stdint.h>
#include "header.h"
#include <assert.h>
#include <stddef.h>


stack stacknew(uint32_t size)
 {
    size = (size > 0 && size < MAX_DEPT) ? size : MAX_DEPT;
    stack s = { size, -1, {0} };
    return s;
}

uint32_t stack_full(const stack* stk)
{
    assert(stk!=NULL);
    return ((stk->top+1)==stk->size);
}

uint32_t stack_empty(const stack* stk)
{
    assert(stk != NULL);
    return (stk->top == -1);
}


stack* stack_push(stack* stk, float data, stackresult* result)
{
    assert(stk!=NULL);
    if(stk->top+1<stk->size)
    {
        stk->data[++stk->top]=data;
        result->data=data;
        result->status=STACK_OK;
    }
    else
    {
        result->data=data;
        result->status=STACK_FULL;
    }
    return stk;
}

stack* stack_pop(stack* stk,stackresult* result)
{
    assert(stk!=NULL);
    if(stk->top>-1)
    {
        result->data=stk->data[stk->top];
        result->status=STACK_OK;
        --stk->top;
    }
    else
    {
        result->status=STACK_EMPTY;
    }
    return stk;
}

stack* stack_peek(const stack* stk,stackresult* result)
{
    assert(stk!=NULL);
    if(stk->top>-1)
    {
        result->data=stk->data[stk->top];
        result->status=STACK_OK;
    }
    else
    {
        result->status=STACK_EMPTY;
    }
    return stk;
}

