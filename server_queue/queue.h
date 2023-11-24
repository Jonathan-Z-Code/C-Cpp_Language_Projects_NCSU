#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

    //init arrays
    int Server[20] = {0};
    
    int serverCheck[20] = {0};
    
    //checks if server is available for a new user to enter
    int checkAvailability(int serverCheck[], int Server[], int ID) {
        
        int serverFlag = 0;
        
        for(int i = 0 ; i < 20; i++) {
            
            if(serverCheck[i] != 0) {}
            else {
                Server[i] = ID;
                serverCheck[i] = 1;
                serverFlag = 1;
                return 0;
            }
            
        }
        
        if(serverFlag == 0) {
            printf("\nServer request denied: currently full\n");
            return 1;
        }
        
    }
    
    //takes a num between 0-19 and deletes that user from the server
    void leaveServer(int serverCheck[], int Server[], int val) {
        serverCheck[val] = 0;
    }
    
    //computes the server capacity
    void serverCapacity(int Server[]) {
        int count = 0;
        for(int i = 0 ; i < 20; i++) {
            if(Server[i] == 1) count++;
        }
        printf("\nServer is %d percent full", count*5);
    }
    
    //gives random number between 0-21
    int RNG() {
        srand(time(NULL));
        int lowerLimit = 0, upperLimit = 21;
        int r =  lowerLimit + rand() % (upperLimit - lowerLimit);
        return r;
    }
    
    //gives random num from 0-999999
    int ID_RNG() {
        srand(time(NULL));
        int lowerLimit = 1, upperLimit = 999999;
        int r =  lowerLimit + rand() % (upperLimit - lowerLimit);
        return r;
    }
    
    //gives a random num 0-19 
    int randval() {
            struct timespec nanos;
            clock_gettime(CLOCK_MONOTONIC, &nanos);
            srand(nanos.tv_nsec);
            int RNG = rand() % 20;
            return RNG;
    }
    
#endif