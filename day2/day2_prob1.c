//Medical Insurance Eligibility Checker
#include<stdio.h>
#include<string.h>
void inputdata(int age, float salary, char pre_condition[]){
    printf("Enter the Age: ");
    scanf("%d",&age);
    printf("\nAny Pre-existing condition? (yes/no): ");
    scanf("%s",pre_condition);
    printf("\nEnter Monthly Salary: ");
    scanf("%f",&salary);
}
void eligiblity(int age,char pre_condition[],float salaray){
    if( (age > 18 && age < 60) && (strcmp(pre_condition, "no")== 0 ) && (salaray >= 25000 )){
        printf("\nEligible for Medical Insurance !!");
    }
    else{
        printf("\nNot eligible for Medical Insurance !!");
    }

}

int main(){
    int age;
    float salary;
    char pre_condition[10];
    inputdata(age,salary, pre_condition);
    eligiblity(age, pre_condition,salary);;
    
    return 0;
}