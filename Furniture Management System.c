#include<stdio.h>
#include<stdlib.h>

struct Person {
	int id;
	char name[30];
	char address[60];
};

struct InventoryItem {
	int id;
	char name[30];
	int quantity;
	float price;
};

void addCustomer() {
	struct Person newCustomer;
    printf("Enter customer ID: ");
    scanf("%d", &newCustomer.id);
    printf("Enter customer name: ");
    scanf(" %s", newCustomer.name);
    printf("Enter customer address: ");
    scanf(" %s", newCustomer.address);
	FILE *fp = fopen("customers.txt", "a");
	if (fp == NULL) {
		printf("Error opening the file \n");
		return;
	}
	fprintf(fp,"%d %s %s\n", newCustomer.id, newCustomer.name, newCustomer.address);
	fclose(fp);
	printf("Customer added successfully...\n\n");
}
void displayCustomers() {
	struct Person customers;
	FILE *fp = fopen("customers.txt", "r");
	if(fp == NULL) {
		printf("Error opening the file\n");
		return;
	}
	printf("\nCustomers: \n\n");
	while(fscanf(fp, "%d %s %s", &customers.id, customers.name, customers.address) != EOF) {
		printf(" ID: %d \n Name: %s \n Address: %s \n\n", customers.id, customers.name, customers.address);
	}
	fclose(fp);
}
void updateCustomer() {
	struct Person customer;
	int customerId, updated = 0;
	printf("Enter Customer ID: ");
	scanf("%d", &customerId);
	FILE *fp = fopen("customers.txt", "r");
	if(fp == NULL) {
		printf("Error opening the file...\n");
		return;
	}
	FILE *tempFile = fopen("tempFile.txt", "w");
	if(tempFile == NULL) {
		printf("Error opening the file...\n");
		return;
	}
	while (fscanf(fp, "%d %s %s", &customer.id, customer.name, customer.address) != EOF) {
		if (customer.id == customerId){
			printf("Enter new name: ");
			scanf("%s", customer.name);
			printf("Enter new address: ");
			scanf("%s", customer.address);
			updated = 1;
		}
		fprintf(tempFile, "%d %s %s\n", customer.id, customer.name, customer.address);
	}
	fclose(fp);
	fclose(tempFile);
	remove("customers.txt");
	rename("tempFile.txt", "customers.txt");
	if(updated) {
		printf("Customer Information Updated Successfully...\n\n");
	} else {
		printf("Customer Not Found...\n\n");
	}
}
void deleteCustomer() {
	struct Person customer;
	int customerId, deleted = 0;
	printf("Enter Customer ID: ");
	scanf("%d", &customerId);	
	FILE *fp = fopen("customers.txt", "r");
	if(fp == NULL) {
		printf("Error opening the file...\n");
		return;
	}
	FILE *tempFile = fopen("tempFile.txt", "w");
	if(tempFile == NULL) {
		printf("Error opening the file...\n");
		return;
	}
	
	while (fscanf(fp, "%d %s %s", &customer.id, customer.name, customer.address) != EOF) {
		if (customer.id != customerId) {
			fprintf(tempFile, "%d %s %s\n", customer.id, customer.name, customer.address);
		} else {
			deleted = 1;
		}
	}
	fclose(fp);
	fclose(tempFile);
	remove("customers.txt");
	rename("tempFile.txt", "customers.txt");
	if(deleted) {
		printf("Customer Deleted Successfully...\n\n");
	} else {
		printf("Customer Not Found...\n\n");
	}
}
void addSupplier() {
	struct Person newSupplier;
    printf("Enter supplier ID: ");
    scanf("%d", &newSupplier.id);
    printf("Enter supplier name: ");
    scanf("%s", newSupplier.name);
    printf("Enter supplier address: ");
    scanf("%s", newSupplier.address);
	FILE *fp = fopen("suppliers.txt", "a");
	if (fp == NULL) {
		printf("Error opening the file \n");
		return;
	}
	fprintf(fp,"%d %s %s\n", newSupplier.id, newSupplier.name, newSupplier.address);
	fclose(fp);
	printf("Supplier added successfully...\n\n");
}
void displaySuppliers() {
	struct Person suppliers;
	FILE *fp = fopen("suppliers.txt", "r");
	if(fp == NULL) {
		printf("Error opening the file\n");
		return;
	}
	printf("\nSuppliers: \n\n");
	while(fscanf(fp, "%d %s %s", &suppliers.id, suppliers.name, suppliers.address) != EOF) {
		printf(" ID: %d \n Name: %s \n Address: %s \n\n", suppliers.id, suppliers.name, suppliers.address);
	}
	fclose(fp);
}
void updateSupplier() {
	struct Person supplier;
	int supplierId, updated = 0;
	printf("Enter Supplier ID: ");
	scanf("%d", &supplierId);
	FILE *fp = fopen("suppliers.txt", "r");
	if(fp == NULL) {
		printf("Error opening the file...\n");
		return;
	}
	FILE *tempFile = fopen("tempFile.txt", "w");
	if(tempFile == NULL) {
		printf("Error opening the file...\n");
		return;
	}
	while (fscanf(fp, "%d %s %s", &supplier.id, supplier.name, supplier.address) != EOF) {
		if (supplier.id == supplierId){
			printf("Enter new name: ");
			scanf("%s", supplier.name);
			printf("Enter new address: ");
			scanf("%s", supplier.address);
			updated = 1;
		}
		fprintf(tempFile, "%d %s %s\n", supplier.id, supplier.name, supplier.address);
	}
	fclose(fp);
	fclose(tempFile);
	remove("suppliers.txt");
	rename("tempFile.txt", "suppliers.txt");
	if(updated) {
		printf("Supplier Information Updated Successfully...\n\n");
	} else {
		printf("Supplier Not Found...\n\n");
	}
}
void deleteSupplier() {
	struct Person supplier;
	int supplierId, deleted = 0;
	printf("Enter Supplier ID: ");
	scanf("%d", &supplierId);	
	FILE *fp = fopen("suppliers.txt", "r");
	if(fp == NULL) {
		printf("Error opening the file...\n");
		return;
	}
	FILE *tempFile = fopen("tempFile.txt", "w");
	if(tempFile == NULL) {
		printf("Error opening the file...\n");
		return;
	}
	
	while (fscanf(fp, "%d %s %s", &supplier.id, supplier.name, supplier.address) != EOF) {
		if (supplier.id != supplierId) {
			fprintf(tempFile, "%d %s %s\n", supplier.id, supplier.name, supplier.address);
		} else {
			deleted = 1;
		}
	}
	fclose(fp);
	fclose(tempFile);
	remove("suppliers.txt");
	rename("tempFile.txt", "suppliers.txt");
	if(deleted) {
		printf("Supplier Deleted Successfully...\n\n");
	} else {
		printf("Supplier Not Found...\n\n");
	}
}
void addInventoryItem() {
	struct InventoryItem item;
	printf("Enter item ID: ");
	scanf("%d", &item.id);
	printf("Enter item name: ");
	scanf("%s", item.name);
	printf("Enter item price: ");
	scanf("%f", &item.price);
	printf("Enter item's stock quantity: ");
	scanf("%d", &item.quantity);
	FILE *fp = fopen("inventory.txt", "a");
	if(fp == NULL) {
		printf("Error opening file...\n");
		return;
	}
	fprintf(fp, "%d %s %.2f %d\n", item.id, item.name, item.price, item.quantity);
	fclose(fp);
	printf("Inventory item added successfully...\n\n");	
}
void displayInventoryItems() {
	struct InventoryItem items;
	FILE *fp = fopen("inventory.txt", "r");
	if(fp == NULL) {
		printf("Error opening file...\n");
		return;
	}
	printf("\nInventory Items:\n\n");
	while (fscanf(fp, "%d %s %f %d", &items.id, items.name, &items.price, &items.quantity) != EOF) {
		printf(" ID: %d\n Name: %s\n Price: %.2f\n Quantity: %d\n\n", items.id, items.name, items.price, items.quantity);
	}
	fclose(fp);
}
void updateInventoryItem() {
	struct InventoryItem item;
	int itemId, updated = 0;
	printf("Enter ID of item to update: ");
	scanf("%d", &itemId);
	FILE *fp = fopen("inventory.txt", "r");
	if(fp == NULL) {
		printf("Error opening file...\n");
		return;
	}
	FILE *tempFile = fopen("tempFile.txt", "w");
	if(tempFile == NULL) {
		printf("Error opening file...\n");
		return;
	}
	while (fscanf(fp, "%d %s %f %d", &item.id, item.name, &item.price, &item.quantity) != EOF) {
		if (itemId == item.id){
			printf("Enter new item name: ");
			scanf("%s", item.name);
			printf("Enter item price: ");
			scanf("%f", &item.price);
			printf("Enter item's stock quantity: ");
			scanf("%d", &item.quantity);
			updated = 1;
		}
		fprintf(tempFile, "%d %s %.2f %d\n", item.id, item.name, item.price, item.quantity);
	}
	fclose(fp);
	fclose(tempFile);
	remove("inventory.txt");
	rename("tempFile.txt", "inventory.txt");
	if(updated){
		printf("Inventory Item Updated Successfully...\n\n");
	} else {
		printf("Item not found...\n\n");
	}	
}
void deleteInventoryItem() {
	struct InventoryItem item;
	int itemId, deleted = 0;
	printf("Enter ID of item to delete: ");
	scanf("%d", &itemId);
	FILE *fp = fopen("inventory.txt", "r");
	if(fp == NULL) {
		printf("Error opening file...\n");
		return;
	}
	FILE *tempFile = fopen("tempFile.txt", "w");
	if(tempFile == NULL) {
		printf("Error opening file...\n");
		return;
	}
	while(fscanf(fp, "%d %s %f %d", item.id, item.name, item.price, item.quantity) != EOF) {
		if (itemId != item.id) {
			fprintf(tempFile, "%d %s %f %d\n", item.id, item.name, item.price, item.quantity);
		} else {
			deleted = 1;
		}
	}
	fclose(fp);
	fclose(tempFile);
	remove("inventory.txt");
	rename("tempFile.txt", "inventory.txt");
	if(deleted){
		printf("Inventory Item Deleted Successfully...\n\n");
	} else {
		printf("Item not found...\n\n");
	}	
}
void manageCustomers() {
	int choice;
	while (1) {
        printf("\nCustomer Management\n");
        printf("-------------------\n");
        printf("1. Add Customer\n");
        printf("2. Display Customers\n");
        printf("3. Update Customer\n");
        printf("4. Delete Customer\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		switch(choice){
			case 1:
				addCustomer();	
				break;
			case 2:
				displayCustomers();
				break;
			case 3:
				updateCustomer();
				break;
			case 4:
				deleteCustomer();
				break;
			case 5:
                printf("Returning to Main Menu...\n");
                return;
			default:
                printf("Invalid choice. Please try again.\n");
                break;
		}		
	}
}
void manageSuppliers() {
	int choice;
	while (1) {
        printf("\nSupplier Management\n");
        printf("-------------------\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Update Supplier\n");
        printf("4. Delete Supplier\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		switch(choice){
			case 1:
				addSupplier();	
				break;
			case 2:
				displaySuppliers();
				break;
			case 3:
				updateSupplier();
				break;
			case 4:
				deleteSupplier();
				break;
			case 5:
                printf("\nReturning to Main Menu...\n\n");
                return;
			default:
                printf("Invalid choice. Please try again.\n");
                break;
		}		
	}
}
void manageInventory () {
	int choice;
	while (1) {
        printf("\nInventory Management\n");
        printf("-------------------\n");
        printf("1. Add Inventory Item\n");
        printf("2. Display Inventory Items\n");
        printf("3. Update Inventory Item\n");
        printf("4. Delete Inventory Item\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		switch(choice){
			case 1:
				addInventoryItem();	
				break;
			case 2:
				displayInventoryItems();
				break;
			case 3:
				updateInventoryItem();
				break;
			case 4:
				deleteInventoryItem();
				break;
			case 5:
                printf("Returning to Main Menu...\n");
                return;
			default:
                printf("Invalid choice. Please try again.\n");
                break;
		}		
	}	
}
void displayMenu() {
    printf("\nFurniture Management System\n");
    printf("---------------------------\n");
    printf("1. Manage Customers\n");
    printf("2. Manage Suppliers\n");
    printf("3. Manage Inventory\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}
int choice=0;
int main(){
	int choice;
	char username[50] = "username", password[50] = "password", get_username[50], get_password[50];
	int main = 1;
	printf("Enter your username: ");
	gets(get_username);
	printf("Enter your password: ");
	gets(get_password);
	if((strcmp(username, get_username) == 0 && strcmp(password, get_password) == 0)){
	while (1) {
		displayMenu();
		scanf("%d", &choice);
		switch (choice) {
            case 1:
                manageCustomers();
                break;
            case 2:
                manageSuppliers();
                break;
            case 3:
                manageInventory();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
		}
	}
	}else {
		count++;
		printf("Incorrect username or password\n\n");
		if(count >= 3) {
			printf("Maximum Try Limit Reached...");
			return 0;
		}
		main();
	}
	return 0;
}
