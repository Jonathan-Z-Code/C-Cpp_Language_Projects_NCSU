#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {

CODE:   

    //initalizes all global variables
    int Opening_Card_Sum = 0;
    int i;
    int Player_Input_1;
    int Player_Input_2;
    int randomnumber_value;
    int Player_Card_Sum = 0 ;

    //opening statement
    printf("\nWelcome to the Blackjack Table, select your option (1 or 2): ");
     sleep(0.75);
     printf("\n2 = Play Blackjack");
     sleep(0.75);
     printf("\n1 = Learn the Rules of Blackjack\n");
    scanf("%d", &Player_Input_1);

    //Chooses either BlackJackEngine or RuleBook
    switch (Player_Input_1)
    {
    case 1:
        
        printf("HOW TO PLAY \nValues: 2-10 is face value, Face Cards are worth 10, and Ace is either 1 or 11 (Player Choice) \nObjective: Try to get 21 or as close to 21 as possible \nGameplay: User must decide to hit (draw one card) or stand (end your turn). Remember to add up all your card values to determine if you are at 21 or under, as going over 21 will result in you automatically losing\n");
        goto CODE;
        break;

    case 2:
        
        //Draws two cards for the player

        for(i=0; i<2; i++) {
            struct timespec nanos;
            clock_gettime(CLOCK_MONOTONIC, &nanos);
            srand(nanos.tv_nsec);
            randomnumber_value = rand() % 13;

            randomnumber_value = randomnumber_value + 1;
                if(randomnumber_value == 13) {
                 printf("The card you draw is a King\n");
                }
                    else if(randomnumber_value == 12) {
                        printf("The card you draw is a Queen\n");
                    }
                        else if(randomnumber_value == 11) {
                            printf("The card you draw is a Jack\n");
                        }
                            else {
                                printf("The card you draw is a %d\n", randomnumber_value);
                            }

        if(randomnumber_value>10) {
            randomnumber_value = 10;
        }
        else {
            printf("");
        }
        
        Opening_Card_Sum = Opening_Card_Sum + randomnumber_value;
        sleep(1);

        }

        sleep(1);
        printf("The value of the opening draw is %d\n", Opening_Card_Sum);
        //ends the two card draw code
    

        /*
        The following for() loop starts the infinite loop of drawing cards (until you go over 21) 
        Player can decide to stand (by entering 2) and it will activate the Dealer's Turn
        Choosing stand will end player's turn!
        */

        Player_Card_Sum = Opening_Card_Sum;  


        for(;;) {
            sleep(1);
            printf("\nWhat is your next move: ");
            printf("\n1 - Hit");
            printf("\n2 - Stand");
            scanf("%d" , &Player_Input_2);

            switch (Player_Input_2)
            {
            case 1: 
            
             sleep(1);

             //this will retrieve another card from the random card generator 
                    
                    int randomnumber_value_1;           
                    struct timespec nanos_1;
                    clock_gettime(CLOCK_MONOTONIC, &nanos_1);
                    srand(nanos_1.tv_nsec);
                    randomnumber_value_1 = rand() % 13;

                    //adds one to the random number bc it is impossible to draw a 0 value card
                    randomnumber_value_1 = randomnumber_value_1 + 1;

                        if(randomnumber_value_1 == 13) {
                        printf("The card you draw is a King\n");
                        }
                            else if(randomnumber_value_1 == 12) {
                                printf("The card you draw is a Queen\n");
                                }
                                else if(randomnumber_value_1 == 11) {
                                    printf("The card you draw is a Jack\n");
                                    }
                                    else {
                                    printf("The card you draw is a %d\n", randomnumber_value_1);
                                    }

                    if(randomnumber_value_1>10) {
                        randomnumber_value_1 = 10;
                    }
                    else {
                    printf("");
                    }    
                        //Adds the current card value to the total sum
                        Player_Card_Sum = Player_Card_Sum + randomnumber_value_1 ;
                        
                        printf("\nThe total value of all cards for player is %d", Player_Card_Sum);

                        if(Player_Card_Sum>21) {
                             sleep(1);
                            printf("\n\nSorry you went over! You Lose\n\n");
                            
                            //restarts program back to beginning to play again
                            goto CODE;
                        }

            break;

            case 2: 

             sleep(1);

                //Runs the program DealerTurn which randomly generates the dealers turn
                    int Dealer_Card_Sum = 0;

                LOOP: 

                 sleep(1);

                int randomnumber_value_2;           
                struct timespec nanos;   
                clock_gettime(CLOCK_MONOTONIC, &nanos);
                srand(nanos.tv_nsec);
                randomnumber_value_2 = rand() % 13;

                randomnumber_value_2 = randomnumber_value_2 + 1;

                if(randomnumber_value_2 == 13) {
                    printf("The card the dealer draws is a King\n");
                }
                else if(randomnumber_value_2 == 12) {
                    printf("The card the dealer draws is a Queen\n");
                }
                else if(randomnumber_value_2 == 11) {
                    printf("The card the dealer draws is a Jack\n");
                }
                else {
                    printf("The card the dealer draws is a %d\n", randomnumber_value_2);
                }

                if(randomnumber_value_2>10) {                       
                    randomnumber_value_2 = 10;
                } 
                else {
                    printf("");
                }    

                //Adds the current card value to the total sum
                Dealer_Card_Sum = Dealer_Card_Sum + randomnumber_value_2 ;

                 sleep(1);
                printf("The total value of all cards for the dealer is %d\n", Dealer_Card_Sum);
                if(Dealer_Card_Sum>21) {
                 sleep(1);
                printf("\n\nThe Dealer has gone over 21! You automatically win!\n\n");
                goto CODE;
                }
                if(Dealer_Card_Sum<17) {
                goto LOOP;
                }   
                if(Dealer_Card_Sum <= 21 && Dealer_Card_Sum >= 17) {
                     sleep(1);
                    //Compares Player and Dealer Values
                    if(Dealer_Card_Sum>Player_Card_Sum) {
                        printf("The dealer has the higher total, dealer wins!");
                        goto CODE;
                    }
                    else if(Dealer_Card_Sum<Player_Card_Sum) {
                        printf("Player has the higher total, you win!");
                        goto CODE;
                    }
                    else{
                        printf("Both parties have the same amount! It is a tie.");
                        goto CODE;
                    }
                }
            break;
            
            default: 
                sleep(0.5);
                //any number other than 1 or 2 will be met with a invalid input prompt
                printf("Invalid Input, Try Again");
                
            }
        }
   
    }

    
}





