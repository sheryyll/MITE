/*2. Inventory Management System 
`Scenario:`  
A `retail store` manages products in stock using sorting techniques. The system should:  
- Sort `items based on quantity available` (ascending)  
- Search `for an item by name` using `binary search`  
- Display `items running low on stock (< 5 units)`  

`Operations Example:`  
Inventory: 
[{"Item": "Sugar", "Quantity": 50}, 
 {"Item": "Salt", "Quantity": 3}, 
 {"Item": "Oil", "Quantity": 10}]

Sorted by Quantity: Salt (3), Oil (10), Sugar (50)
Search 'Oil': Found (Quantity: 10)
Low Stock Items: Salt (3)
*/

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100


typedef struct {
    char item[50];
    int quantity;
} Inventory;


void swap(Inventory *a, Inventory *b) {
    Inventory temp = *a;
    *a = *b;
    *b = temp;
}


void sortInventory(Inventory inv[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (inv[j].quantity > inv[j + 1].quantity) {
                swap(&inv[j], &inv[j + 1]);
            }
        }
    }
}


int binarySearch(Inventory inv[], int size, char key[]) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(inv[mid].item, key);
        
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


void displayLowStock(Inventory inv[], int size) {
    printf("Low Stock Items (< 5 units):\n");
    for (int i = 0; i < size; i++) {
        if (inv[i].quantity < 5) {
            printf("%s (%d)\n", inv[i].item, inv[i].quantity);
        }
    }
}

int main() {
    Inventory inventory[] = {
        {"Sugar", 50},
        {"Salt", 3},
        {"Oil", 10}
    };
    int size = sizeof(inventory) / sizeof(inventory[0]);

    
    sortInventory(inventory, size);
    printf("Sorted Inventory by Quantity:\n");
    for (int i = 0; i < size; i++) {
        printf("%s (%d)\n", inventory[i].item, inventory[i].quantity);
    }
    
    
    char searchItem[50] = "Oil";
    int index = binarySearch(inventory, size, searchItem);
    if (index != -1) {
        printf("\nSearch '%s': Found (Quantity: %d)\n", searchItem, inventory[index].quantity);
    } else {
        printf("\nSearch '%s': Not Found\n", searchItem);
    }
    
    
    printf("\n");
    displayLowStock(inventory, size);
    
    return 0;
}