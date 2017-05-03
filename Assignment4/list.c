#include <stdio.h>
#include <stdlib.h>
#include "list.h"


/*
 * List implementation
 */

typedef struct listnode listnode_t;
struct listnode {
    listnode_t  *next;
    void        *item;
};

struct list {
    listnode_t *head;
    int numitems;
};


// Create new list
list_t *list_create(void)
{
    // Implement me
    list_t * head = NULL;
    head = malloc(sizeof(list_t));
    if (head == NULL)
        exit (0);

    head->numitems = 0;
    head->head = NULL;
    return head;
}


// Free list. items not freed.
void list_destroy(list_t *list)
{
    // Implement me
    free(list);
}


// Insert item first in list
int list_addfirst(list_t *list, void *item)
{
    // Implement me
    listnode_t *first =(listnode_t*)malloc(sizeof(listnode_t));
    if(first == NULL){
        printf("You have failed me for the last time.\n");
        exit(0);
    }
    first->next = list->head;
    list->head = first;
    first->item = item;
    list->numitems++;
    return 1;

}

// Insert item last in list.
int list_addlast(list_t *list, void *item)
{
    listnode_t *node;
    listnode_t *last;

  
    node = (listnode_t*)malloc(sizeof(node));

    last = list->head;

    if (list->head == NULL){
        list->head = node;
        node->next = NULL;
        list->numitems ++;
        node->item = item;
        return 1;
    }

   else if(list->head->next == NULL){
        list->head->next = node;
        node->next = NULL;
       list->numitems ++;
       node->item = item;
        return 1;

    }
    else{
    while(last->next->next != NULL){
        last->next = last->next->next;
    }
    last->next->next = node;
    node->next = NULL;
    list->numitems ++;
    node->item = item;
    return 1;
    }

    return 0;



}
// Remove item from list
void list_remove(list_t *list, void *item)
{
    // Implement me
    listnode_t *node;
    listnode_t *delete;
    node = list->head;
    if(node->item == item)
    {
        list->head = node->next;
        free(node);
        list->numitems --;
        return;

    }
    while(node->next != NULL)
    {
        if(node->next->item == item)
        {
            delete = node->next;
            node->next = node->next->next;
            free(delete);
            list->numitems -=1;
            break;
        }
        node = node->next;
    }
}

// Return # of items in list
int list_size(list_t *list)
{
    // Implement me
    return list->numitems;
}




 //* Iterator implementation



struct list_iterator {
    listnode_t *next;
    list_t *list;
};

// Create new list iterator
list_iterator_t *list_createiterator(list_t *list)
{
    // Implement me
    list_iterator_t * iterator =(list_iterator_t*)malloc(sizeof(list_iterator_t));
    iterator->list = list;
    iterator->next = list->head;
    return iterator;
}

// Free iterator
void list_destroyiterator(list_iterator_t *iter)
{
    // Implement me
    free(iter);
}

// Move iterator to next item in list and return current.
void *list_next(list_iterator_t *iter)
{
    // Implement me
    void *item;
    if (iter->next == NULL)
    {
        return NULL;
    }
    item = iter->next->item;
    iter->next = iter->next->next;
    return item;
}

// Let iterator point to first item in list again
void list_resetiterator(list_iterator_t *iter)
{
    // Implement me
    iter->next = iter->list->head;
}
