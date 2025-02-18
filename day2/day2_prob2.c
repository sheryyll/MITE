//Toll Tax Calculation Using Switch Case
#include<stdio.h>
#include<string.h>
int main(){
    int vechiles, plaza_charges=0;
    char  vehicle_type[10];

    printf("Enter the number of vechiles: ");
    scanf("%d", &vechiles);
    for(int i=0;i<vechiles;i++){
        printf("Enter  the Vechile type (Car/Truck/Bike/Bus): ");
        scanf("%s",vehicle_type);
    
   
        switch (0)
        {
            default:
                if (strcmp(vehicle_type, "Car") == 0) {
                    plaza_charges += 50;
                    break;
                }
                if (strcmp(vehicle_type, "Truck") == 0) {
                    plaza_charges += 100;
                break;
                }
                if (strcmp(vehicle_type, "Bike") == 0) {
                    plaza_charges += 20;
                    break;
                }
                if (strcmp(vehicle_type, "Bus") == 0) {
                    plaza_charges += 80;
                    break;
                }
                printf("Invalid vehicle type entered!\n");
                break;
        }
    }
    
    printf("\nTotal Toll Tax: %d\n", plaza_charges);

    return 0;
}