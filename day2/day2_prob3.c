//ATM Transaction System
#include<stdio.h>
int main(){
    int choice,balance = 10000, amount;


    printf("Enter your choice: \n");
    printf("1. Withdraw Money\n2. Deposit Money\n3. Check Balance\n");
    scanf("%d",&choice);

    switch (choice){
        case 1:
        //Withdraw
            printf("Enter the amount to be withdrawen\n");
            scanf("%d",&amount);
            if(amount > balance){
                printf("Insufficient Balance!");
            }
            else{
                balance -= amount;
                printf("Transaction Successful. Remaining Balance: ₹%d\n",balance);
            }
            break;
        case 2:
        //Deposit
            printf("Enter the amount to be Deposited\n");
            scanf("%d",&amount);
            balance += amount;
            printf("Transaction Successful. Remaining Balance: ₹%d\n",balance);
            break;
        
        case 3:
        //check balance
            printf("Your cureent Balance: %d\n",balance);
            break;

        default:
            printf("Invalid Choice! Please select a valid option.\n");

        }



    return 0;
}
