#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct UserProfile {
    char username[50];
};

void backupData() {
    
}
void restoreData() {
    
}
void exportData() {
    
}
void showHelp() {
    printf("\n===== HELP SECTION =====\n");
    printf("1. Add reminders with date and time\n");
    printf("2. Use backup to save data safely\n");
    printf("3. Restore data using backup\n");
    printf("4. Extract data for external use\n");
}

void showAbout() {
    printf("\n===== ABOUT =====\n");
    printf("Smart Reminder Pro\n");
    printf("Developed using C Language\n");
    printf("Module by: Nusrat Jahan\n");
}

void Menu() {
    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Update Profile\n");
        printf("2. Backup Data\n");
        printf("3. Restore Data\n");
        printf("4. Export Data\n");
        printf("5. Help\n");
        printf("6. About\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // case 1: updateProfile(); break;
            // case 2: backupData(); break;
            // case 3: restoreData(); break;
            // case 4: exportData(); break;
            case 5: showHelp(); break;
            case 6: showAbout(); break;
            case 0: printf("Exiting module...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
}


int main() {
    Menu();
    return 0;
}
