#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item
typedef struct {
    char name[100];
    double price;
} Item;

typedef struct {
	char name[100];
	char barang[100];
	int angka;
} Pembeli;

// Function for startup program

void mainMenu(){
	printf("Masuk sebagai:\n");
	printf("1. Admin\n");
	printf("2. Pembeli\n");
	printf("3. Exit\n");
	printf("Masukkan pilihanmu: ");
}

// Function to add an item to the database
void tambahItem() {
    Item item;
    int jumlah;
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", &item.name);
    printf("Enter item price: ");
    scanf("%lf", &item.price);

    FILE *file = fopen("C:\\Users\\Abid Yafi Abiyyu\\Desktop\\projek uas\\database.txt", "a");
    if (file == NULL) {
        printf("Error opening the database file.\n");
        return;
    }
	
	fprintf(file, "%s   %.2lf\n", item.name, item.price);
	

    fclose(file);
    printf("Data item berhasil dimasukkan\n");
}

// Function to display available items from the database
void lihatItems() {
    FILE *file = fopen("C:\\Users\\Abid Yafi Abiyyu\\Desktop\\projek uas\\database.txt", "r");
    if (file == NULL) {
        printf("Error opening the database file.\n");
        return;
    }

    Item item;
    printf("Available items:\n");
    while (fscanf(file, "%s   %lf", &item.name, &item.price) == 2) {
        printf("%s - Rp%.2lf\n", item.name, item.price);
    }
    fclose(file);
}

void dataPembeli(){
	Pembeli pembeli;
	int jumlah;
	char 
	printf("Masukkan nama: ");
	scanf(" %[^\n]%*c", &pembeli.name);
	printf("Masukkan item yang dibeli: ");
	scanf(" %[^\n]%*c", &pembeli.barang); //
	printf("Jumlah item: ");
	scanf("%d", &pembeli.angka); // 2//

	/*
		Tambahin logic untuk pengecekan item yang akan dibeli mengacu pada file database.
		
		Item item;
		FILE *file = fopen("C:\\Users\\Abid Yafi Abiyyu\\Desktop\\projek uas\\pembeli.txt","r");
		 while (fscanf(file, "%s   %lf", &item.name, &item.price) == 2) {
        	if(strcmp(pembeli.brang == item.name)){
        		found =1
			}
			if(strcmp(pembeli.barang != item.name)
    	}
    	
	*/
	FILE *file = fopen("C:\\Users\\Abid Yafi Abiyyu\\Desktop\\projek uas\\pembeli.txt","a");
	if (file == NULL) {
        printf("Error opening the database file.\n");
        return;
    }
    
    fprintf(file, "%s   %s   %d\n", pembeli.name, pembeli.barang, pembeli.angka);
    fclose(file);
    printf("Data pembeli berhasil dimasukkan\n");
}

void lihatPembeli(){
	FILE *file = fopen("C:\\Users\\Abid Yafi Abiyyu\\Desktop\\projek uas\\pembeli.txt", "r");
    if (file == NULL) {
        printf("Error opening the database file.\n");
        return;
    }

    Pembeli pembeli;
    printf("Available items:\n");
    while (fscanf(file, "%s   %s   %d", &pembeli.name, &pembeli.barang, &pembeli.angka) == 3) {
        printf("%s - $%.2lf - %d item\n", pembeli.name, pembeli.barang, pembeli.angka);
    }
    fclose(file);
}

//Function to handle the buyer 
void pembeli(){
	int choice;
	
	do{
		printf("Menu pembeli:\n");
		printf("1. Lihat list item\n");
		printf("2. Isi data pembeli dan Beli item\n");
		printf("3. Cetak Resi\n");
		printf("4. Exit\n");
		printf("Masukkan pilihanmu: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				lihatItems();
				break;
			case 2:
				dataPembeli();
				break;
			case 3:
//				cetakResi();
				break;
			case 4:
				printf("Exiting the program.\n");
				break;
			default:
				printf("Pilihanmu gagal, silahkan coba lagi");
				break;
		}
	}while(choice != 4);
}


// Function to handle the admin functionality
void admin() {
    char password[20];
    printf("Enter the admin password: ");
    scanf("%s", password);

    if (strcmp(password, "admin123") != 0) {
        printf("Invalid password. Access denied.\n");
        return;
    }
    
    int choice;
    
    do{
    	printf("Menu admin:\n");
    	printf("1. Tambah item\n");
    	printf("2. Data Pembeli\n");
    	printf("3. Exit\n");
    	printf("Masukkan pilihanmu: ");
    	scanf("%d", &choice);
    	
    	switch (choice){
    		case 1:
    			tambahItem();
    			break;
    		case 2:
    			lihatPembeli();
    			break;
    		case 3:
    			printf("Exit Program.\n");
    			break;
    		default:
    			printf("Masukkan anda salah");
    			return;
		}
	}while(choice != 3);
}

// Entry point of the program
int main() {
    int choice;
    do {
        mainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                admin();
                break;
            case 2:
                pembeli();
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
