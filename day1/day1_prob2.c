#include<stdio.h>
int main(){
    int units;

    //Input
    printf("Enter the units consumed: \n");
    scanf("%d",&units);


    float bill = 0.0f;
    //logic
    if (units <= 100) {
        bill = units * 2.0;
    } else if (units <= 200) {
        bill = (100 * 2.0) + ((units - 100) * 3.0);
    } else {
        bill = (100 * 2.0) + (100 * 3.0) + ((units - 200) * 5.0);
    }

     printf("Total Bill : %f\n",bill);

}