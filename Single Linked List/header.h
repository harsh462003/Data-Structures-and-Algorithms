#ifndef _INCLUDED_SLIST_

#include <stdint.h>
typedef struct _node_ Node;
typedef struct _slist_ List;

struct _slist_
{
    Node *head;
    Node *tail;
    int32_t lenght;
};

struct _node_
{
    int32_t data;
    Node *next;
};



List* slist_new();
List* slist_free(List*);
int32_t slist_lenght(const List*);
List* slist_add_head(List*,int32_t data);
Node* _slist_node_new(int32_t data);
int32_t slist_lookup(const List*,int32_t key);
List* slist_add_tail(List*,int32_t data);
List* delete_head(List*);
List* delete_tail(List*);
List* delete_specific_element(List *,int32_t ele);
List* slist_add_at_position(List* list, int32_t data, int32_t position);


#endif // _INCLUDED_SLIST_
