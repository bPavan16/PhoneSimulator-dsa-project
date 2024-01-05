#include <stdio.h>
#include <string.h>
#include "ContactApp.h"
#include "phoneApp.h"
#include "remindersClock.h"
#include "calander.h"
#include "misc.h"

int main()
{

    HashTable hashList_1;
    initHashTable(&hashList_1);
    ImportContacts(&hashList_1);
    heap heapRoot;
    initheap(&heapRoot);
    trieNode *rootTrieNode = ImportPhone();
    int choice;

    lockScreen();
    // getch();

    while (1)
    {
        printf("Press Any Key to continue : ");

        getch();
        system("cls");
        printf("\n\n\n");
        printf("---------------------------------------");
        printf("---------------------------------------");
        CheckForRemainders(&heapRoot);
        // printf("\n");
        printf("\n\n\n");
        printf("\n\n\n");
        printf("\t(0) PRESS 0 TO SWITCH OFF \n");
        printf("\t(1) CONTACTS APP \n");
        printf("\t(2) PHONE APP \n");
        printf("\t(3) REMINDERS APP \n");
        printf("\t(4) CALENDER APP \n");

        printf("\n\n");

        printf("\tEnter what you want to do :  ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            system("cls");
            ContactsApp(&hashList_1);
            break;

        case 2:
            system("cls");
            PhoneApp(&rootTrieNode);
            break;

        case 3:
            system("cls");
            AlarmApp(&heapRoot);
            break;

        case 4:
            system("cls");
            calanderApp();
            break;

        case 0:
            system("cls");
            printf("Your Phone is Now Switching off");
            getch();
            printf(".\n.\n.\n.\n");
            getch();
            printf("BYEE TAKE CARE\n");
            getch();
            system("cls");
            exit(0);

        default:
            break;
        }
    }

    getch();
    return 0;
}