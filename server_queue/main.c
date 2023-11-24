//demonstration of a queue data structure. 
//By: Jonathan Zurita

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "queue.h"
#include "node.h"


int main()
{
    struct list List;
    List.head = NULL;

    //loop goes on forever
    while(1) {
        
        //generates random person joining queue
        int playerID = ID_RNG();
        createHeadNode(&List, playerID);   
        
        //identifies user in terminal output
        printf("\nPlayerID# %06d entered queue", playerID);
        printf("\t(%d users in queue)", nodeCount(&List));
        
        //writes server capacity in output terminal
        serverCapacity(serverCheck);
        
        //delays terminal output by 1 second for readability
        sleep(1);
        
        //retrieves playerID of first person in queue
        int EndNodeID = retrieveID(&List);
        int endCondition = checkAvailability(serverCheck, Server, EndNodeID);
        
        //0 means server has space for user, 1 means full server
        //freeEndNode function call is used to remove user from queue
        if(endCondition == 0) {
            printf("\nPlayerID# %06d entered server", EndNodeID);
            freeEndNode(&List);    
        }
        if(endCondition == 1) {
            printf("Server is full, waiting for open spot\n");
        }
        
        //random number generator function call
        int random = randval();
        
        if(random >= 5) {
        leaveServer(serverCheck, Server, randval());
        } //75% chance one person leaves server
        if(random >= 10) {
            leaveServer(serverCheck, Server, randval());
            leaveServer(serverCheck, Server, randval());
        } //50% chance 2 extra people leave the server
        
        
        //file IO writes current playerID's in the server 
        FILE* fptr = fopen("server.txt", "w");
        for(int i =0; i < 20; i++) {
            fprintf(fptr, "Server[%d]\tPlayerID:%06d\n", i, Server[i]);
        }
        
        fclose(fptr);

    }
    
}