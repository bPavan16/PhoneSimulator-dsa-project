#ifndef PHONE_H
#define PHONE_H

#include "../data_structures/hashtable.h"
#include "../data_structures/stack.h"
#include "../data_structures/queue.h"
#include "../data_structures/heap.h"
#include "../data_structures/tree.h"

#define MAX_NAME 50
#define MAX_NUMBER 15

typedef struct
{
    char name[MAX_NAME];
    char number[MAX_NUMBER];
} Contact;

typedef struct
{
    char title[50];
    char datetime[20];
} Reminder;

typedef struct
{
    char time[10];
    int isActive;
} Alarm;

// Phone functions declarations
void initializePhone(void);
void addContact(char *name, char *number);
void deleteContact(char *name);
void updateContact(char *name, char *newNumber);
void displayContacts(void);
void makeCall(char *number);
void viewCallHistory(void);
void setAlarm(char *time);
void addReminder(char *title, char *datetime);
void displayReminders(void);

#endif