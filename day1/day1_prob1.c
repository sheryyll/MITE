#include<stdio.h>
int main(){
    int employee, low_income = 0 ,middle_income = 0 , high_income = 0;
    int salary[40];
    
    //input data
    printf("Enter the number of Employees: \n");
    scanf("%d",&employee);

    printf("Enter salaries: \n");
    for(int i=0;i<employee;i++){
        scanf("%d",&salary[i]);
    }

    for(int i =0;i<employee;i++)
    {
        if(salary[i]<30000){
            low_income += 1 ;
        }
        else if (salary[i] >= 30000 && salary[i] < 70000)
        {
            middle_income += 1;
        }
        else if (salary[i] >= 70000)
        {
            high_income += 1;
        }
    }

    //OUTPUT DATA
    printf("\nLow Income : %d\n",low_income);
    printf("\nMiddle Income : %d\n",middle_income);
    printf("\nHigh Income : %d\n",high_income);
    return 0;
}