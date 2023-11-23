/******************************************************************************

                    NodeOS: Create and Delete nodes!
            find out how much memory is allocated to your list!
            
            Future additions:  1. print list to a .txt file
                               2. add more data to nodes
                               3. organize nodes based on certain criteria
                               4. delete all nodes feature
                               
******************************************************************************/

#include <stdio.h>
#include "node.h"


int main() 
{
    struct list List;
    
    initList(&List);
    
    printf("Welcome to nodeOS\n");
    printf("\n't' for travelling list");
    printf("\n'h' to create head node");
    printf("\n'e' to create end node");
    printf("\n'q' to quit program");
    printf("\n'f' to free end node");
    
    char userInput;
    int value;
    
    
while(1) {
    

    scanf("%c", &userInput);
    
    if(userInput == 'f') {
        freeEndNode(&List);
    }
    if(userInput == 't') {
        travelList(&List); //reads all nodes and their values 
    }
    if(userInput == 'q') {
        return 0; //exit success
    }
    if(userInput == 'e') {
        printf("insert new data value: ");
        scanf("%d", &value);
        createEndNode(&List, value);
    }
    if(userInput == 'h') {
        printf("insert new data value: ");
        scanf("%d", &value);
        createHeadNode(&List, value);
    }
    
}

}


