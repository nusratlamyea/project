#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct UserProfile {
    char username[50];
    char theme[10]; // light or dark
};
void saveProfile(struct UserProfile user) {
    FILE *fp = fopen("user_profile.dat", "wb");
    if (fp == NULL) {
        printf("Error saving profile!\n");
        return;
    }
    fwrite(&user, sizeof(user), 1, fp);
    fclose(fp);
}
struct UserProfile loadProfile() {
    struct UserProfile user;
    FILE *fp = fopen("user_profile.dat", "rb");

    if (fp == NULL) {
        // Default profile
        strcpy(user.username, "Guest");
        strcpy(user.theme, "Light");
        return user;
    }
    fread(&user, sizeof(user), 1, fp);
    fclose(fp);
    return user;
} void updateProfile() {
    struct UserProfile user;
    printf("\nEnter your name: ");
    scanf(" %[^\n]", user.username);

    printf("Choose Theme (Light/Dark): ");
    scanf("%s", user.theme);

    saveProfile(user);
    printf("Profile updated successfully!\n");
}

void applyTheme(struct UserProfile user) {
    if (strcmp(user.theme, "Dark") == 0 || strcmp(user.theme, "dark") == 0) {
        printf("\nDark Mode Activated\n");
    } else {
        printf("\nLight Mode Activated\n");
    }
}

void backupData() {
    FILE *source = fopen("reminders.dat", "rb");
    FILE *backup = fopen("backup.dat", "wb");

    if (!source || !backup) {
        printf("Backup failed!\n");
        return;
    } char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, backup);
    } fclose(source);
    fclose(backup);
    printf("Backup created successfully!\n");
}

void restoreData() {
    FILE *backup = fopen("backup.dat", "rb");
    FILE *restore = fopen("reminders.dat", "wb");

    if (!backup || !restore) {
        printf("Restore failed!\n");
        return;
    } char ch;
    while ((ch = fgetc(backup)) != EOF) {
        fputc(ch, restore);
    } fclose(backup);
    fclose(restore);
    printf("Data restored successfully!\n");
}

void exportData() {
    FILE *source = fopen("reminders.dat", "r");
    FILE *export = fopen("reminders_export.txt", "w");

    if (!source || !export) {
        printf("Export failed!\n");
        return;
    } char line[200];
    while (fgets(line, sizeof(line), source)) {
        fprintf(export, "%s", line);
    } fclose(source);
    fclose(export);
    printf("Data exported to reminders_export.txt\n");
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
    struct UserProfile user = loadProfile();
    applyTheme(user);
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
            case 1: updateProfile(); break;
            case 2: backupData(); break;
            case 3: restoreData(); break;
            case 4: exportData(); break;
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
