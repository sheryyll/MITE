/*`2. Online Shopping Order Processing`  
`Scenario:`  
An `online shopping system` records orders with `Order ID, Customer Name, Product, and Amount`. The system should:  
- Store and update orders using `structures`  
- Write order details to a `file`  
- Allow `retrieval of order details`  

`Input Example:`  
    Enter number of orders: 2
    Order 1: 301, Alice, Laptop, ₹60000
    Order 2: 302, Bob, Mobile, ₹25000
    Enter Order ID to search: 301
`Output Example:`  
    Order Found: Alice - Laptop - ₹60000
    Record saved in "orders.txt"*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define MAX_ORDERS 100
    #define FILENAME "orders.txt"
    
    struct Order_t {
        int order_id;
        char customer_name[50];
        char product[50];
        float amount;
    };
    
    typedef struct Order_t Order;
    
    void readOrders(Order orders[], int n);
    void saveOrders(Order orders[], int count);
    Order findOrderById(Order orders[], int count, int order_id);
    
    int main() {
        int orderCount;
        printf("Enter number of orders: ");
        scanf("%d", &orderCount);
    
        Order orders[MAX_ORDERS];
        readOrders(orders, orderCount);
        saveOrders(orders, orderCount);
        
        int order_id_to_search;
        printf("Enter Order ID to search: ");
        scanf("%d", &order_id_to_search);
        
        Order found_order = findOrderById(orders, orderCount, order_id_to_search);
        
        if (found_order.order_id != -1) {
            printf("Order Found: %s - %s - ₹%.2f\n", 
                   found_order.customer_name, 
                   found_order.product, 
                   found_order.amount);
        } else {
            printf("Order not found.\n");
        }
    
        return 0;
    }
    
    void readOrders(Order orders[], int n) {
        printf("Enter order details (Order ID, Customer Name, Product, Amount):\n");
        for (int i = 0; i < n; i++) {
            printf("Order %d: ", i + 1);
            scanf("%d, %s, %s, %f", 
                  &orders[i].order_id, 
                  orders[i].customer_name, 
                  orders[i].product, 
                  &orders[i].amount);
        }
    }
    
    void saveOrders(Order orders[], int count) {
        FILE *file = fopen(FILENAME, "w");
        if (file == NULL) {
            printf("Error opening file for writing.\n");
            return;
        }
        
        for (int i = 0; i < count; i++) {
            fprintf(file, "%d, %s, %s, %.2f\n", 
                    orders[i].order_id, 
                    orders[i].customer_name, 
                    orders[i].product, 
                    orders[i].amount);
        }
        
        fclose(file);
        printf("Record saved in \"%s\"\n", FILENAME);
    }
    
    Order findOrderById(Order orders[], int count, int order_id) {
        for (int i = 0; i < count; i++) {
            if (orders[i].order_id == order_id) {
                return orders[i];
            }
        }
        Order not_found = {-1, "", "", -1.0};
        return not_found;
    }