#include <stdio.h>

int main() {

int Students;
printf("Enter number of students: ");
scanf("%d" , &Students);

int array[Students];

for (int i=0 ; i<Students ; i++) {

    printf("Enter Grade for Student %d: ", i);
    scanf("%d" , &array[i]);

}

printf("\n\nHere is the Gradebook:\n");

// second loop to print total array[]

for (int i=0 ; i<Students ; i++) {
    printf("%d\n", array[i]);

}

printf("\nHere is the average test score for all %d students: " , Students);
int sum = 0;

for (int i=0 ; i<Students ; i++) {
    sum = array[i] + sum;

}

// converts integers values into double in order to calculate an accurate Test_Avg.
double Students_Num = Students;
double Sum_Number = sum;

//does the math to calculate the test average (Sum of Tests divded by # of students).
double Test_Avg = Sum_Number / Students_Num;
printf("%lf", Test_Avg);

//end of script
}
