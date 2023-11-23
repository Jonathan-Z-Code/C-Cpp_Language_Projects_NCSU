#ifndef NODE_C 
#define NODE_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node* next;
};

struct list {
  struct node* head;  
};

void initList(struct list* theList) {
    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    theList->head = new;
    new->data = 0;
    new->next = NULL;
    
}

void createEndNode(struct list* theList, int val) {
    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* p = theList->head;
    
    while(p->next != NULL) {
        p = p->next;
    }
    
    p->next = new; 
    new->next = NULL;
    new->data = val;
    
}

void createHeadNode(struct list* theList, int val) {
    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    
    new->data = val;
    new->next = theList->head;
    theList->head = new;
    
}

void travelList(struct list* theList) {
    
    struct node* p = theList->head;
    int count = 0;
    while(p != NULL) {
        printf("\nnode %d contains value %d", count, p->data);
        count++;
        p = p->next;
    }
    
    printf("\nTotal memory allocation of linked list is %ld bytes\n", (sizeof(struct node)*count + sizeof(struct list)));
    
}

int freeEndNode(struct list* theList) {
    
    struct node* p = theList->head;
    struct node* prev = NULL;
    while(p->next != NULL) {
        prev = p;
        p = p->next;
    }
    
    if(p == theList->head) {
        printf("\nCould not delete node (must be 1 node in list)");
        return -1;
    }   
    
    prev->next = NULL;
    free(p);
    if(prev->next == NULL) printf("\nSuccessfully deleted last node\n");
    
    return 0;
    
}


#endif