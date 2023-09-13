#include <stdio.h>
#include <string.h>
struct Password {
	char websiteName[30];
	char username[50];
	char password[30];
};
void addPassword() {
	struct Password newPassword;
	printf("Enter Website Name: ");
	scanf("%s", newPassword.websiteName);
	printf("Enter Username: ");
	scanf("%s", newPassword.username);
	printf("Enter Password: ");
	scanf("%s", newPassword.password);
	FILE *fp = fopen("passwords.txt", "a");
	if (fp == NULL) {
		printf("There was error opening the file\n\n");
		return;
	}
	fprintf(fp, "%s %s %s\n", newPassword.websiteName, newPassword.username, newPassword.password);
	fclose(fp);
	printf("New Password Information Added Successfully\n\n");	
}
void displayPassword() {
	struct Password passwords;
	FILE *fp = fopen("passwords.txt", "r");
	if (fp == NULL) {
		printf("There was error opening the file\n\n");
		return;
	}
	printf("Password Entries From File:\n");
	while (fscanf(fp, "%s %s %s", passwords.websiteName, passwords.username, passwords.password) != EOF) {
		printf(" Website Name: %s\n Username: %s\n Password: %s\n\n", passwords.websiteName, passwords.username, passwords.password);
	}
	fclose(fp);	
}
void updatePasswordInfo() {
	struct Password passwordDetails;
	int updated = 0;
	char websiteName[30];
	printf("Enter name of website you want to update: ");
	scanf("%s", websiteName);
	FILE *fp = fopen("passwords.txt", "r");
	if (fp == NULL) {
		printf("There was error opening the file\n\n");
		return;
	}
	FILE *temp = fopen("temp.txt", "w");
	if (temp == NULL) {
		printf("There was error opening the file\n\n");
		return;
	}
	while (fscanf(fp, "%s %s %s", passwordDetails.websiteName, passwordDetails.username, passwordDetails.password) != EOF) {
		if(strcmp(websiteName, passwordDetails.websiteName) == 0) {
			printf("Enter new username: ");
			scanf("%s", passwordDetails.username);
			printf("Enter new password: ");
			scanf("%s", passwordDetails.password);
			updated = 1;
		}
		fprintf(temp, "%s %s %s\n", passwordDetails.websiteName, passwordDetails.username, passwordDetails.password);
	}
	fclose(fp);
	fclose(temp);
	remove("passwords.txt");
	rename("temp.txt", "passwords.txt");
	if (updated) {
		printf("\nPassword Information Updated Successfully\n\n");
	} else {
		printf("\nWebsite Not Found\n\n");
	}
}
void deletePasswordInfo() {
	struct Password passwordDetails;
	int deleted = 0;
	char websiteName[30];
	printf("Enter name of website you want to delete: ");
	scanf("%s", websiteName);
	FILE *fp = fopen("passwords.txt", "r");
	if (fp == NULL) {
		printf("There was error opening the file\n\n");
		return;
	}
	FILE *temp = fopen("temp.txt", "w");
	if (temp == NULL) {
		printf("There was error opening the file\n\n");
		return;
	}
	while (fscanf(fp, "%s %s %s", passwordDetails.websiteName, passwordDetails.username, passwordDetails.password) != EOF) {
		if(strcmp(websiteName, passwordDetails.websiteName) != 0) {
			fprintf(temp, "%s %s %s\n", passwordDetails.websiteName, passwordDetails.username, passwordDetails.password);
		} else {
			deleted = 1;
		}
	}
	fclose(fp);
	fclose(temp);
	remove("passwords.txt");
	rename("temp.txt", "passwords.txt");
	if (deleted) {
		printf("\nPassword Deleted Successfully\n\n");
	} else {
		printf("\nWebsite Not Found\n\n");
	}
}

int main() {
	int option;
	char username[50] = "admin", password[50] = "admin", get_username[50], get_password[50];
	int main = 1;
	printf("Enter your username: ");
	gets(get_username);
	printf("Enter your password: ");
	gets(get_password);
	if((strcmp(username, get_username) == 0 && strcmp(password, get_password) == 0)){
	while (1) {
		printf("Password Management System\n");
		printf("----------------------------\n\n");
		printf("1. Add New Password\n");
		printf("2. Display Passwords\n");
		printf("3. Update Password Information\n");
		printf("4. Delete Password Information\n");
		printf("5. Exit Program\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		printf("\n");
		switch (option) {
			case 1:
				addPassword();
				break;
			case 2:
				displayPassword();
				break;
			case 3:
				updatePasswordInfo();
				break;
			case 4:
				deletePasswordInfo();
				break;
			case 5:
				printf("Program Exited Successfully");
				return 0;
			default:
				printf("Enter valid option\n\n");
				break;
		}
	}
}
	return 0;
}

