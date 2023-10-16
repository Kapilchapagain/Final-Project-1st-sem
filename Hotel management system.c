#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct CustomerDetails {
    char roomnumber[10];
    char name[20];
    char address[25];
    char phonenumber[15];
    char nationality[15];
    char email[20];
    char period[10];
    char arrivaldate[10];
};

void add();
void list();
void deleteRecord();
void search();
void edit();

int main() {
    char choice;
    
    while (1) {
        system("cls");
        printf("******** HOTEL MANAGEMENT SYSTEM **********\n");
        printf("1. Book a room\n");
        printf("2. View Customer Record\n");
        printf("3. Delete Customer Record\n");
        printf("4. Search Customer Record\n");
        printf("5. Edit Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        choice = getch();
        
        switch (choice) {
            case '1':
                add();
                break;
            case '2':
                list();
                break;
            case '3':
                deleteRecord();
                break;
            case '4':
                search();
                break;
            case '5':
                edit();
                break;
            case '6':
                printf("\nThank you for using our service!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        
        printf("\nPress any key to continue...");
        getch();
    }
    
    return 0;
}

void add() {
    FILE* f = fopen("add.txt", "a");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct CustomerDetails s;
    printf("Enter Customer Details:\n");
    printf("Room number: ");
    scanf("%s", s.roomnumber);
    printf("Name: ");
    scanf("%s", s.name);
    printf("Address: ");
    scanf("%s", s.address);
    printf("Phone Number: ");
    scanf("%s", s.phonenumber);
    printf("Nationality: ");
    scanf("%s", s.nationality);
    printf("Email: ");
    scanf("%s", s.email);
    printf("Period: ");
    scanf("%s", s.period);
    printf("Arrival date (dd\\mm\\yyyy): ");
    scanf("%s", s.arrivaldate);

    fprintf(f, "%s %s %s %s %s %s %s %s\n", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate);
    fclose(f);
    printf("\nRoom booked successfully!\n");
}

void list() {
    FILE* f = fopen("add.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct CustomerDetails s;
    printf("\nRoom\tName\t\tAddress\t\tPhone Number\tNationality\tEmail\t\tPeriod\tArrival Date\n");
    while (fscanf(f, "%s %s %s %s %s %s %s %s", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate) != EOF) {
        printf("%s\t%s\t%s\t%s\t%s\t\t%s\t%s\t%s\n", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate);
    }

    fclose(f);
}

void deleteRecord() {
    FILE* f = fopen("add.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    FILE* t = fopen("temp.txt", "w");
    if (t == NULL) {
        printf("Error opening file.\n");
        fclose(f);
        return;
    }

    char roomnumber[10];
    int deleted = 0;
    printf("Enter Room Number to delete: ");
    scanf("%s", roomnumber);

    struct CustomerDetails s;
    while (fscanf(f, "%s %s %s %s %s %s %s %s", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate) != EOF) {
        if (strcmp(s.roomnumber, roomnumber) == 0) {
            deleted = 1;
            continue;
        }
        fprintf(t, "%s %s %s %s %s %s %s %s\n", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate);
    }

    fclose(f);
    fclose(t);

    if (deleted) {
        remove("add.txt");
        rename("temp.txt", "add.txt");
        printf("Record deleted successfully!\n");
    } else {
        printf("Record not found.\n");
        remove("temp.txt");
    }
}

void search() {
    FILE* f = fopen("add.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char roomnumber[10];
    printf("Enter Room Number to search: ");
    scanf("%s", roomnumber);

    struct CustomerDetails s;
    int found = 0;
    while (fscanf(f, "%s %s %s %s %s %s %s %s", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate) != EOF) {
        if (strcmp(s.roomnumber, roomnumber) == 0) {
            found = 1;
            printf("Record Found:\n");
            printf("Room Number: %s\n", s.roomnumber);
            printf("Name: %s\n", s.name);
            printf("Address: %s\n", s.address);
            printf("Phone Number: %s\n", s.phonenumber);
            printf("Nationality: %s\n", s.nationality);
            printf("Email: %s\n", s.email);
            printf("Period: %s\n", s.period);
            printf("Arrival Date: %s\n", s.arrivaldate);
            break;
        }
    }

    fclose(f);

    if (!found) {
        printf("Record not found.\n");
    }
}

void edit() {
    FILE* f = fopen("add.txt", "r+");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char roomnumber[10];
    printf("Enter Room Number to edit: ");
    scanf("%s", roomnumber);

    struct CustomerDetails s;
    int found = 0;
    long int pos;

    while (fscanf(f, "%s %s %s %s %s %s %s %s", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate) != EOF) {
        if (strcmp(s.roomnumber, roomnumber) == 0) {
            found = 1;
            pos = ftell(f) - sizeof(struct CustomerDetails);
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
        fclose(f);
        return;
    }

    fseek(f, pos, SEEK_SET);

    printf("Enter new data:\n");
    printf("Name: ");
    scanf("%s", s.name);
    printf("Address: ");
    scanf("%s", s.address);
    printf("Phone Number: ");
    scanf("%s", s.phonenumber);
    printf("Nationality: ");
    scanf("%s", s.nationality);
    printf("Email: ");
    scanf("%s", s.email);
    printf("Period: ");
    scanf("%s", s.period);
    printf("Arrival date (dd\\mm\\yyyy): ");
    scanf("%s", s.arrivaldate);

    fprintf(f, "%s %s %s %s %s %s %s %s", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate);

    fclose(f);
    printf("Record updated successfully!\n");
}
