#include <iostream>
#include <cstring>  // for strcpy, strcat
#include <cstdlib>  // for malloc, free
#include <climits>

class RestaurantOrderManager {
public:
     
    void handleOrders() {
       
        char* orderDatabase = (char*)malloc(10);
        if (!orderDatabase) {
            std::cerr << "Memory allocation failed! Could not create order database." << std::endl;
            return;
        }

         // 输出分配的内存地址
        std::cout << "Allocated memory at: " << static_cast<void *>(orderDatabase) << std::endl;

        strcpy(orderDatabase, "Order-");  
        std::cout << "Created initial order database with content: " << orderDatabase << std::endl;

   
        const char* menuItems[] = {"Pizza", "Burger", "Pasta", "Salad", "Sushi", "Steak", "Sandwich", "Tacos"};
        char largeOrder[200] = "";  // String to build a complex order

        // Randomly add various menu items to the order
        for (int i = 0; i < 5; ++i) {
            int index = rand() % 8;  // Randomly select a menu item
            strcat(largeOrder, menuItems[index]);
            strcat(largeOrder, "-");
        }

        // Simulate overflow by appending the oversized order to the database
        strcat(orderDatabase, largeOrder);  // Heap overflow occurs
        std::cout << "Order: " << largeOrder << std::endl;
        // Check if the order still starts with "Order-"
        std::cout << "Order database content: " << orderDatabase << std::endl;

        std::cout << "Current memory at: " << static_cast<void *>(orderDatabase) << std::endl;
}
};

int main() {
    RestaurantOrderManager manager;


    // Call the order management function to simulate the restaurant order storage system
    manager.handleOrders();

    return 0;
}
