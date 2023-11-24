#ifndef NODE_H
#define NODE_H

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

//initializes linked list with one node with data val 0
void initList(struct list* theList) {
    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    theList->head = new;
    new->data = 0;
    new->next = NULL;
    
}

//creates a node at the end of a linked list
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

//creates a node at the beginning of a linked list
void createHeadNode(struct list* theList, int val) {
    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    
    new->data = val;
    new->next = theList->head;
    theList->head = new;
    
}

//traverses the entire list and prints every node's data value
void travelList(struct list* theList) {
    
    struct node* p = theList->head;
    int count = 0;
    while(p != NULL) {
        printf("\nnode %d contains value %06d", count, p->data);
        count++;
        p = p->next;
    }
    
    printf("\nTotal memory allocation of linked list is %ld bytes\n", (sizeof(struct node)*count + sizeof(struct list)));
    
}

//frees the node at the end of the list
int freeEndNode(struct list* theList) {
    
    if(theList->head == NULL) {
        printf("\nerror list is empty, cannot remove end node");
        return -1;
    } //checks if list is empty first
    
    struct node* p = theList->head;
    struct node* prev = NULL;
    
    while(p->next != NULL) {
        prev = p;
        p = p->next;
    }
    
    if(p == theList->head) {
        free(p);
        theList->head = NULL;
        printf("\nSuccessfully deleted queue node\n");
        return 1;
    }   //ensures emptying list is done correctly
    else {
        prev->next = NULL;
        free(p);
        if(prev->next == NULL) printf("\nSuccessfully deleted queue node\n");
        return 0;
    }
    
}


//counts the amount of nodes in a linked list
int nodeCount(struct list* theList) {
    
    struct node* p = theList->head;
    int count = 0;
    
    while(p != NULL) {
        count++;
        p = p->next;
    }
    
    return count;
}

//retrieves data of the last node in a linked list
int retrieveID(struct list* theList) {
    
    struct node* p = theList->head;
    
    while(p->next != NULL) {
        p = p->next;
    }
    
    return p->data;
    
}

#endif