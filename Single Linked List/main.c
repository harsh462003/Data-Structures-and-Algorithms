#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"


void test_slist_generic()
{
    List *list=slist_new();
    assert(slist_lenght(list)==0);
    slist_add_head(list,10);//insert 1
    assert(slist_lenght(list)==1);
    slist_add_head(list,20);//insert 2
    slist_add_head(list,30);//insert 3
    assert(slist_lenght(list)==3);
    assert(slist_lookup(list,30));
    //assert(slist_lookup(list,40));
    assert(slist_add_tail(list,40));//insert 4
    assert(slist_lenght(list)==4);
    assert(slist_lookup(list,40));
    slist_add_at_position(list, 25, 2);//inserting 25 at index 2
    assert(slist_lenght(list) == 5);
    assert(slist_lookup(list, 25));



//  assert(delete_head(list));
//  assert(slist_lenght(list)==3);
//  assert(slist_lookup(list,30));

//  assert(delete_tail(list));
//  assert(slist_lenght(list)==2);
//    assert(slist_lookup(list,40));


//    assert(delete_specific_element(list,30));
//    assert(slist_lenght(list)==3);
//    assert(slist_lookup(list,30));

    slist_free(list);


}


int main()
{
    test_slist_generic();
    return 0;
}
