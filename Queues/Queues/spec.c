#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include "header.h"

queue* queue_new(uint32_t size)
{
    size = (size > 0 && size < MAX_QUEUE_LEN) ? size : MAX_QUEUE_LEN;
    queue* q = (queue*)malloc(sizeof(queue));
    if (q != NULL) {
        q->size = size;
        q->count = 0;
        q->head = 0;
        q->tail = 0;
    }
    return q;
}

queue* queue_add(queue* q, int32_t data, queueresult* result)
{
    assert(q != NULL && q->count <= q->size);
    if (q->count < q->size)
    {
        q->q[q->tail] = data;
        q->tail = (q->tail + 1) % q->size;
        ++q->count;
        result->status = QUEUE_OK;
    }
    else
    {
        result->status = QUEUE_FULL;
    }
    return q;
}

queue* queue_remove(queue* q, queueresult* result)
{
    assert(q != NULL && q->count <= q->size);
    if (q->count > 0)
    {
        result->data = q->q[q->head];
        q->head = (q->head + 1) % q->size;
        --q->count;
        result->status = QUEUE_OK;
    }
    else
    {
        result->status = QUEUE_EMPTY;
    }
    return q;
}


uint32_t queue_full(queue* q)
{
    assert(q != NULL);
    return (q->count == q->size);
}

uint32_t queue_empty(queue* q)
{
    assert(q != NULL);
    return (q->count == 0);
}
