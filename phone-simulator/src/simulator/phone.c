#include "phone.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

HashTable *contacts;
Stack *callHistory;
BSTree *reminders;
MinHeap *alarms;

void initializePhone()
{
    contacts = createHashTable(100);
    callHistory = createStack(50);
    reminders = createBSTree();
    alarms = createMinHeap(20);
}

void addContact(char *name, char *number)
{
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    hashTableInsert(contacts, name, newContact);
    printf("Contact added successfully!\n");
}

void deleteContact(char *name)
{
    if (hashTableDelete(contacts, name))
    {
        printf("Contact deleted successfully!\n");
    }
    else
    {
        printf("Contact not found!\n");
    }
}

void updateContact(char *name, char *newNumber)
{
    Contact *contact = (Contact *)hashTableGet(contacts, name);
    if (contact)
    {
        strcpy(contact->number, newNumber);
        printf("Contact updated successfully!\n");
    }
    else
    {
        printf("Contact not found!\n");
    }
}

void makeCall(char *number)
{
    stackPush(callHistory, number);
    printf("Calling %s...\n", number);
    // Simulate call duration
    sleep(2);
    printf("Call ended\n");
}

void viewCallHistory()
{
    printf("Recent Calls:\n");
    stackDisplay(callHistory);
}

void setAlarm(char *time)
{
    Alarm *newAlarm = (Alarm *)malloc(sizeof(Alarm));
    strcpy(newAlarm->time, time);
    newAlarm->isActive = 1;
    minHeapInsert(alarms, newAlarm);
    printf("Alarm set for %s\n", time);
}

void addReminder(char *title, char *datetime)
{
    Reminder *newReminder = (Reminder *)malloc(sizeof(Reminder));
    strcpy(newReminder->title, title);
    strcpy(newReminder->datetime, datetime);
    bsTreeInsert(reminders, datetime, newReminder);
    printf("Reminder added successfully!\n");
}

void displayReminders()
{
    printf("Your Reminders:\n");
    bsTreeInorderTraversal(reminders);
}