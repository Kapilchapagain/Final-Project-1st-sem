#include <stdio.h>
#include <string.h>

// Define a structure to represent a patient
struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char contact[20];
};
struct Medication {
    int id;
    char name[50];
    int quantity;
    float price;
};
struct Doctor {
    int id;
    char name[50];
    char specialization[50];
    char contact[20];
};
void addPatient() {
    struct Patient newPatient;
    FILE *file;
    file = fopen("patient_records.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter patient details:\n");
    printf("Id: ");
    scanf("%d", &newPatient.id);
    printf("Name: ");
    scanf("%s", newPatient.name);
    printf("Age: ");
    scanf("%d", &newPatient.age);
    printf("Gender: ");
    scanf("%s", newPatient.gender);
    printf("Contact: ");
    scanf("%s", newPatient.contact);
    fprintf(file, "%d %s %d %s %s\n", newPatient.id, newPatient.name, newPatient.age, newPatient.gender, newPatient.contact);
    fclose(file);
    printf("Patient added successfully!\n");
}
void displayPatients() {
    struct Patient patient;
    FILE *file;
    file = fopen("patient_records.txt", "r");
    if (file == NULL) {
        printf("No patient records found.\n");
        return;
    }
    printf("Patient Records:\n");
    printf("ID\tName\tAge\tGender\tContact\n");
    while (fscanf(file, "%d %s %d %s %s\n", &patient.id, patient.name, &patient.age, patient.gender, patient.contact) != EOF) {
        printf("%d\t%s\t%d\t%s\t%s\n", patient.id, patient.name, patient.age, patient.gender, patient.contact);
    }
    fclose(file);
}
void addMedication() {
    struct Medication newMedication;
    FILE *file;

    // Open the medication inventory file in append mode
    file = fopen("medication_inventory.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Get medication details from the user
    printf("Enter medication details:\n");
    printf("Id: ");
    scanf("%d", &newMedication.id);
    printf("Name: ");
    scanf("%s", newMedication.name);
    printf("Quantity: ");
    scanf("%d", &newMedication.quantity);
    printf("Price: ");
    scanf("%f", &newMedication.price);
    fprintf(file, "%d %s %d %.2f\n", newMedication.id, newMedication.name, newMedication.quantity, newMedication.price);
    fclose(file);

    printf("Medication added to inventory successfully!\n");
}
void displayMedications() {
    struct Medication medication;
    FILE *file;
    file = fopen("medication_inventory.txt", "r");
    if (file == NULL) {
        printf("No medications found in inventory.\n");
        return;
    }

    printf("Medication Inventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    while (fscanf(file, "%d %s %d %f\n", &medication.id, medication.name, &medication.quantity, &medication.price) != EOF) {
        printf("%d\t%s\t%d\t\t%.2f\n", medication.id, medication.name, medication.quantity, medication.price);
    }
    fclose(file);
}
void deleteMedication() {
    struct Medication medication;
	int deleted = 0;
	int medicationId;
	printf("Enter id of medication you want to delete: ");
	scanf("%d", &medicationId);
	FILE *file = fopen("medication_inventory.txt", "r");
	if (file == NULL) {
		printf("Error opening the file\n\n");
		return;
	}
	FILE *temp = fopen("temp.txt", "w");
	if (temp == NULL) {
		printf("Error opening the file\n\n");
		return;
	}
	while (fscanf(file, "%d %s %d %f\n", &medication.id, medication.name, &medication.quantity, &medication.price) != EOF) {
		if(medicationId != medication.id) {
			fprintf(temp, "%d %s %d %f\n", medication.id, medication.name, medication.quantity, medication.price);
		} else {
			deleted = 1;
		}
	}
	fclose(file);
	fclose(temp);
	remove("medication_inventory.txt");
	rename("temp.txt", "medication_inventory.txt");
	if (deleted) {
		printf("\nMedication Deleted Successfully\n\n");
	} else {
		printf("\nMedication Not Found\n\n");
	}
}
void addDoctor() {
    struct Doctor newDoctor;
    FILE *file;
    file = fopen("doctor_records.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter doctor details:\n");
    printf("Id: ");
    scanf("%d", &newDoctor.id);
    printf("Name: ");
    scanf("%s", newDoctor.name);
    printf("Specialization: ");
    scanf("%s", newDoctor.specialization);
    printf("Contact: ");
    scanf("%s", newDoctor.contact);
    fprintf(file, "%d %s %s %s\n", newDoctor.id, newDoctor.name, newDoctor.specialization, newDoctor.contact);
    fclose(file);

    printf("Doctor added successfully!\n");
}
void displayDoctors() {
    struct Doctor doctor;
    FILE *file;
    file = fopen("doctor_records.txt", "r");
    if (file == NULL) {
        printf("No doctor records found.\n");
        return;
    }

    printf("Doctor Records:\n");
    printf("ID\tName\tSpecialization\tContact\n");
    while (fscanf(file, "%d %s %s %s\n", &doctor.id, doctor.name, doctor.specialization, doctor.contact) != EOF) {
        printf("%d\t%s\t%s\t%s\n", doctor.id, doctor.name, doctor.specialization, doctor.contact);
    }
    fclose(file);
}
void deleteDoctor() {
    struct Doctor doctor;
	int deleted = 0;
	int doctorId;
	printf("Enter id of doctor you want to delete: ");
	scanf("%d", &doctorId);
	FILE *file = fopen("doctor_records.txt", "r");
	if (file == NULL) {
		printf("Error opening the file\n\n");
		return;
	}
	FILE *temp = fopen("temp.txt", "w");
	if (temp == NULL) {
		printf("Error opening the file\n\n");
		return;
	}
	while (fscanf(file, "%d %s %s %s", &doctor.id, doctor.name, doctor.specialization, doctor.contact) != EOF) {
		if(doctorId != doctor.id) {
			fprintf(temp, "%d %s %s %s\n", doctor.id, doctor.name, doctor.specialization, doctor.contact);
		} else {
			deleted = 1;
		}
	}
	fclose(file);
	fclose(temp);
	remove("doctor_records.txt");
	rename("temp.txt", "doctor_records.txt");
	if (deleted) {
		printf("\nDoctor Deleted Successfully\n\n");
	} else {
		printf("\nDoctor Not Found\n\n");
	}
}

void patientManagement() {
	int option;
	while (1) {
		printf("\nPatient Management\n");
		printf("----------------------------\n\n");
		printf("1. Add New Patient\n");
		printf("2. Display Patient\n");
		printf("3. Return to main menu\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		printf("\n");
		switch (option) {
			case 1:
				addPatient();
				break;
			case 2:
				displayPatients();
				break;
			case 3:
				printf("Returning to Main Menu...\n");
				return;
			default:
				printf("Enter valid option\n\n");
				break;
		}
	}
}
void pharmacyManagement() {
	int option;
	while (1) {
		printf("\nPharmacy Management\n");
		printf("----------------------------\n\n");
		printf("1. Add New Medication\n");
		printf("2. Display Medication Stock\n");
		printf("3. Delete Medication Information\n");
		printf("4. Return to main menu\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		printf("\n");
		switch (option) {
			case 1:
				addMedication();
				break;
			case 2:
				displayMedications();
				break;
			case 3:
				deleteMedication();
				break;
			case 4:
				printf("Returning to Main Menu...\n");
				return;
			default:
				printf("Enter valid option\n\n");
				break;
		}
	}
}
void doctorManagement() {
	int option;
	while (1) {
		printf("\nDoctor Management\n");
		printf("----------------------------\n\n");
		printf("1. Add New Doctor Informaton\n");
		printf("2. Display Doctor Information\n");
		printf("3. Delete Doctor Information\n");
		printf("4. Return to main menu\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		printf("\n");
		switch (option) {
			case 1:
				addDoctor();
				break;
			case 2:
				displayDoctors();
				break;
			case 3:
				deleteDoctor();
				break;
			case 4:
				printf("Returning to Main Menu...\n");
				return;
			default:
				printf("Enter valid option\n\n");
				break;
		}
	}
}
int main(){
	char username[50] = "admin", password[50] = "admin", get_username[50], get_password[50];
	int choice;
	int main = 1;
	printf("Enter your username: ");
	gets(get_username);
	printf("Enter your password: ");
	gets(get_password);
	if((strcmp(username, get_username) && strcmp(password, get_password)) == 0){
		while (1) {
		    printf("\nHospital Management System\n");
		    printf("---------------------------\n");
		    printf("1. Patients Management\n");
		    printf("2. Medication Management\n");
		    printf("3. Doctors Management\n");
		    printf("4. Exit\n");
		    printf("Enter your choice: ");
			scanf("%d", &choice);
			switch (choice) {
	            case 1:
	                patientManagement();
	                break;
	            case 2:
	                pharmacyManagement();
	                break;
	            case 3:
	                doctorManagement();
	                break;
	            case 4:
	                printf("Exiting...\n");
	                return 0;
	            default:
	                printf("Invalid choice. Please try again.\n");
	                break;
			}
		}
	} else {
		printf("Incorrect username or password");
	}
	return 0;
}

