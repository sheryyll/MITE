#include<stdio.h>
int main()
{
    int n, marks[20];

    printf("\nEnter number of students: ");
    scanf("%d",&n);
    printf("\nEnter marks:");
    for(int i=0;i<n;i++){
        scanf("%d",&marks[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(marks[i]>=90 && marks[i]<100)
            printf("Student %d : Grade A\n",i+1);
        else if (marks[i]>=80 && marks[i]<89)
        {
            printf("Student %d : Grade B\n",i+1);
        }
        else if (marks[i]>=70 && marks[i]<79)
        {
            printf("Student %d : Grade C\n",i+1);
        }
        else if (marks[i]>=60 && marks[i]<69)
        {
            printf("Student %d : Grade D\n",i+1);
        }
        else
        {
            printf("Student %d : Grade F\n",i+1);
        }    
    }
}