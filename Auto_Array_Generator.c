#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int Max_Val;
int i;
int Current_Value;

int Random_Var() {

            struct timespec nanos;
            clock_gettime(CLOCK_MONOTONIC, &nanos);
            srand(nanos.tv_nsec);
            return rand() % (Max_Val + 1);

}

void CheckReplica() {


}


int main() {

int TESTVAR;
int ArraySize;
printf("how many allocations do you want your array to be?");
scanf("%d", &ArraySize);
printf("what is your max_random_number?");
scanf("%d" , &Max_Val);

int Array_Pointer = 0;
int array[ArraySize];

for(i=0; i<ArraySize; i++)
    {
        array[i] = (Max_Val + 100);
    }

LOOP:

    if(Array_Pointer == ArraySize) {
        for(i=0; i<ArraySize; i++) {
            printf("ARRAY[%d]: %d  \n" , i, array[i]);
        }
        goto END_PRINT;
    
    }

    int Restart_Prompt = 0;
    

    Current_Value = Random_Var();
    printf("this is current val: %d\n", Current_Value);
    CheckReplica();
    printf("\nTEST FLAG\n");
    for (i=0; i<ArraySize; i++) {
        printf("%d", array[i]);
        if (array[i] == Current_Value) {
            printf("\nMATCH\n");
            Restart_Prompt = Restart_Prompt + 1;
        }
            if (array[i] != Current_Value) {
                printf("\nNOT MATCH\n");
            } 
        
    }
printf("RESTART_PROMPT VALUE: %d", Restart_Prompt);
    if(Restart_Prompt > 0) {
        goto LOOP;
    }
    if(Restart_Prompt == 0) {
        printf("\n this is the currentrand val: %d", Current_Value);
        array[Array_Pointer] = Current_Value ;
        printf("\n\n%d" , array[Array_Pointer]);
        Array_Pointer = Array_Pointer + 1;
        goto LOOP;
    }

END_PRINT:

    printf("\nHere is your randomly generated array, all numbers are unique");
    return 0;

}