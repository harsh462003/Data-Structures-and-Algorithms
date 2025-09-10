    #include<stdint.h>
    #define MAX_DEPT 32
    #define RESULT_INVALID 0
    #define STACK_OK 1
    #define STACK_FULL 2
    #define STACK_EMPTY 4



    struct _stack_
    {
        uint32_t size;
        int32_t top;
        float data[MAX_DEPT];
    };
    typedef struct _stack_ stack;

    struct _stackresult_
    {
        float data;
        uint32_t status;
    };
    typedef struct _stackresult_ stackresult;



    stack stacknew(uint32_t size);
    uint32_t stack_full(const stack *stk);
    uint32_t stack_empty(const stack* stk);
    stack* stack_push(stack* stk,float data,stackresult* result);
    stack* stack_pop(stack* stk,stackresult* result);
    stack* stack_peek(const stack* stk,stackresult* result);
