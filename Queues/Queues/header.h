
#include <stdint.h>
#define MAX_QUEUE_LEN 32

struct _queue_
{
    uint32_t size;
    uint32_t count;
    uint32_t head;
    uint32_t tail;
    int32_t q[MAX_QUEUE_LEN]
};
typedef struct _queue_ queue;

struct _queue_result_
{
    uint32_t data;
    uint32_t status;
};
typedef struct _queue_result_ queueresult;

#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 4


queue* queue_new(uint32_t size);
queue* queue_add(queue* q, int32_t data, queueresult* result);
queue* queue_remove(queue* q, queueresult* result);
uint32_t queue_full(queue* q);
uint32_t queue_empty(queue* q);
