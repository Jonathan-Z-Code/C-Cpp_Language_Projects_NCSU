#include <stdio.h>

int main() {

//Presents the User a TUI 
printf("\nPlease Select A Number 1-4\n");
printf("\n1 = Addition");
printf("\n2 = Subtraction");
printf("\n3 = Mulitplication");
printf("\n4 = Division\n\n");

//Record User Input of Any Number (1-4 will trigger case 1-4; any other number will be met with error msg)
int User_Input;
scanf("%d", &User_Input);

int First_Num;
printf("Please Choose Integer Number 1: ");
scanf("%d", &First_Num);

int Second_Num;
printf("Please Choose Integer Number 2: ");
scanf("%d", &Second_Num);

// Initialization of Variables Needed to Preform all 4 Operations
int Addition_Result;
int Multiplcation_Result;
int Subtraction_Result;
int Division_Result;

switch(User_Input){

    case 1:
      Addition_Result = First_Num + Second_Num;
      printf("%d plus %d equals %d", First_Num, Second_Num, Addition_Result);
      break;

    case 2:
      Subtraction_Result = First_Num - Second_Num;
      printf("%d minus %d equals %d", First_Num, Second_Num, Subtraction_Result);
      break;
    
    case 3:
      Multiplcation_Result = First_Num * Second_Num;
      printf("%d times %d equals %d", First_Num, Second_Num, Multiplcation_Result);
      break;

    case 4:
      Division_Result = First_Num / Second_Num;
      printf("%d divided by %d equals %d", First_Num, Second_Num, Division_Result);
      break;

    default:
        //Executes when user inputs a number other than 1,2,3, or 4
      printf("error operation selector not in input range 1-4");
}

}