#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item
typedef struct {
    char name[50];
    double price;
    int quantity;
} Item;

// Function to display the menu for admin
void adminMenu() {
    printf("Admin Menu\n");
    printf("1. Login\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

// Function to display the menu for buyer
void buyerMenu() {
    printf("Buyer Menu\n");
    printf("1. View available items\n");
    printf("2. Buy an item\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to add an item to the database
void addItem() {
    Item item;
    printf("Enter item name: ");
    scanf("%s", &item.name);
    printf("Enter item price: ");
    scanf("%lf", &item.price);
    printf("Enter item quantity: ");

    FILE *file = fopen("C:\\Users\\Abid Yafi Abiyyu\\Desktop\\projek uas\\database.txt", "a");
    if (file == NULL) {
        printf("Error opening the database file.\n");
        return;
    }

    fprintf(file, "%s %.2lf\n", item.name, item.price);
    fclose(file);
    printf("Item added to the database.\n");
}

// Function to display available items from the database
void viewItems() {
    FILE *file = fopen("C:\\Users\\Abid Yafi Abiyyu\\Desktop\\projek uas\\database.txt", "r");
    if (file == NULL) {
        printf("Error opening the database file.\n");
        return;
    }

    Item item;
    printf("Available items:\n");
    while (fscanf(file, "%s %lf", &item.name, &item.price) == 2) {
        printf("%s - $%.2lf\n", item.name, item.price);
    }

    fclose(file);
}

// Function to handle the buyer functionality
void buyer() {
    int choice;
    do {
        buyerMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewItems();
                break;
            case 2:
                // Code to handle the purchase
                break;
            case 3:
                printf("Exiting buyer menu.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);
}

// Function to handle the admin functionality
void admin() {
    char password[20];
    printf("Enter the admin password: ");
    scanf("%s", password);

    // Add your own logic to authenticate the admin
    // For simplicity, we are assuming a fixed password "admin123"
    if (strcmp(password, "admin123") != 0) {
        printf("Invalid password. Access denied.\n");
        return;
    }

    int choice;
    do {
        printf("\n");
        printf("Admin Menu\n");
        printf("1. Add item\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                printf("Exiting admin menu.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 2);
}

// Entry point of the program
int main() {
    int choice;
    do {
        adminMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                admin();
                break;
            case 2:
                buyer();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
