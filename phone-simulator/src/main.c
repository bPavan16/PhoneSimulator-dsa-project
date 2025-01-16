#include "simulator/phone.h"
#include <stdio.h>

int main()
{
    int choice;
    char name[MAX_NAME];
    char number[MAX_NUMBER];
    char time[10];
    char title[50];
    char datetime[20];

    initializePhone();

    while (1)
    {
        printf("\nPhone Simulator Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Update Contact\n");
        printf("4. Make Call\n");
        printf("5. View Call History\n");
        printf("6. Set Alarm\n");
        printf("7. Add Reminder\n");
        printf("8. View Reminders\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            addContact(name, number);
            break;

        case 2:
            printf("Enter name to delete: ");
            scanf("%s", name);
            deleteContact(name);
            break;

        case 3:
            printf("Enter name to update: ");
            scanf("%s", name);
            printf("Enter new number: ");
            scanf("%s", number);
            updateContact(name, number);
            break;

        case 4:
            printf("Enter number to call: ");
            scanf("%s", number);
            makeCall(number);
            break;

        case 5:
            viewCallHistory();
            break;

        case 6:
            printf("Enter alarm time (HH:MM): ");
            scanf("%s", time);
            setAlarm(time);
            break;

        case 7:
            printf("Enter reminder title: ");
            scanf("%s", title);
            printf("Enter datetime (DD/MM/YYYY HH:MM): ");
            scanf("%s", datetime);
            addReminder(title, datetime);
            break;

        case 8:
            displayReminders();
            break;

        case 9:
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}