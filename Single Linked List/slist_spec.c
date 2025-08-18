#include <assert.h>
#include <stddef.h>
#include <stdlib.h>     // for malloc and free
#include "header.h"


List* slist_new()
{
    List* list;
    list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    list->lenght=0;
    return list;
}



List* slist_free(List* list)
{
    Node *cur,*p;
    if(slist_lenght(list)>0)
    {
        assert(list->head && list->tail);
        cur=list->head;
        list->head=NULL;
        list->tail=NULL;
        while(cur!=NULL)
        {
            p=cur;
            cur=cur->next;
            free(p);
            --list->lenght;
        }
    }
    return list;
}



int32_t slist_lookup(const List* list,int32_t key)
{
        Node* node=list->head;
        for(node=list->head;node!=NULL;node=node->next)
        {
            if (node->data==key)
            {
                break;
            }
        }
        return (node!=NULL);

}



int32_t slist_lenght(const List* list)
{
    return list->lenght;
}


Node* _slist_node_new(int32_t data)
{
    Node* node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}



List* slist_add_head(List* list,int32_t data)
{
    Node *node=_slist_node_new(data);
    node->next=list->head;
    list->head=node;
    if(list->tail==NULL)
    {
        list->tail=node;//doubt
    }
    list->lenght++;
    return list;
}



List* slist_add_tail(List* list,int32_t data)
{
    Node* node=_slist_node_new(data);
    if(list->tail!=NULL)
    {
        list->tail->next=node;
        list->tail=node;
    }
    else
    {
        list->head=list->tail=node;
    }
    list->lenght++;
    return list;
}




List* delete_head(List* list)
{
    if (list == NULL || list->head == NULL)
    {
        return list;
    }
    Node* temp=list->head;
    list->head=list->head->next;
//    temp->next=NULL;
    free(temp);
    list->lenght--;
    return list;
}

List* delete_tail(List* list)
{
    if (list == NULL || list->head == NULL)
    {
        return list;
    }
    if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return list;
    }
    Node* temp=list->head;
    while(temp->next!=list->tail)
        temp=temp->next;
    free(list->tail);
    list->tail=temp;
    list->tail->next=NULL;
    list->lenght--;
    return list;
}


List* delete_specific_element(List* list,int32_t ele)
{
    Node* temp=list->head;
    if (temp->data == ele)
    {
        list->head = temp->next;
        free(temp);
        list->lenght--;
        return list;
    }
    Node* temp2;
    if (list == NULL || list->head == NULL)
    {
        return list;
    }
    while(temp->next != NULL && temp->next->data!=ele)
        temp=temp->next;
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    list->lenght--;
    return list;
}


List* slist_add_at_position(List* list, int32_t data, int32_t position)
{
    assert(list != NULL);
    assert(position >= 0 && position <= list->lenght);  // Valid positions: [0, length]

    if (position == 0) {
        return slist_add_head(list, data);
    } else if (position == list->lenght) {
        return slist_add_tail(list, data);
    } else {
        Node* new_node = _slist_node_new(data);
        Node* current = list->head;
        for (int i = 1; i < position; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        list->lenght++;
    }
    return list;
}

