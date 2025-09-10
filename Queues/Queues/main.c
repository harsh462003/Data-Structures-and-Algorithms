#include <stdio.h>
#include <assert.h>
#include "header.h"
void testing_queue() {
    queueresult result;
    queue* q = queue_new(5);
    assert(q != NULL);
    assert(queue_empty(q) == 1);
    assert(queue_full(q) == 0);
    for (int i = 1; i <= 5; ++i) {
        q = queue_add(q, i * 10, &result);
        assert(result.status == QUEUE_OK);
    }
    assert(queue_full(q) == 1);
    assert(queue_empty(q) == 0);
    q = queue_add(q, 60, &result);
    assert(result.status == QUEUE_FULL);
    for (int i = 1; i <= 3; ++i) {
        q = queue_remove(q, &result);
        assert(result.status == QUEUE_OK);
        printf("Popped: %d\n", result.data);
    }
    assert(queue_empty(q) == 0);
    assert(queue_full(q) == 0);
    q = queue_add(q, 70, &result);
    assert(result.status == QUEUE_OK);
    q = queue_add(q, 80, &result);
    assert(result.status == QUEUE_OK);
    while (!queue_empty(q)) {
         queue_remove(q, &result);
        (result.status == QUEUE_OK);
        printf("Popped: %d\n", result.data);
    }
    assert(queue_empty(q) == 1);
    q = queue_remove(q, &result);
    assert(result.status == QUEUE_EMPTY);
}

int main() {
    testing_queue();
    printf("All assertions passed.\n");
    return 0;
}
