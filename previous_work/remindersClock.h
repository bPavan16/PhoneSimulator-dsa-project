#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#include <time.h>
// #include<string.h>
#define dt reminder

typedef struct reminder
{
    int hr;
    int min;
    int sec;
    int approx;
    char msg[50];
} reminder;

typedef struct heap
{
    int heapSize;
    dt arr[100];

} heap;

/* ---------------------------------------------------------------- */

void readReminder(reminder *r)
{
    printf("Enter Time in  HR:MIN:SEC format [Enter the valid time] : ");
    scanf("%d%*c%d%*c%d", &r->hr, &r->min, &r->sec);
    scanf("%*c");
    printf("Enter the reminder message : ");
    gets(r->msg);
    r->approx = r->hr * 3600 + r->min * 60 + r->sec;
}

void displayReminder(reminder *r)
{
    printf("\tTime = %d : %d : %d\n", r->hr, r->min, r->sec);
    printf("\tMessage : %s\n", r->msg);
    printf("\n");
}

/* ---------------------------------------------------------------- */

int parent(int i)
{
    // Returns the index of the Parent.
    return (i - 1) / 2;
}

int lChild(int i)
{
    // Returns the index of the left child.
    return (2 * i + 1);
}

int rChild(int i)
{
    // Returns the index of the right child.
    return (2 * i + 2);
}

/* ---------------------------------------------------------------- */

void swap(reminder *a, reminder *b)
{
    reminder c;
    c = *a;
    *a = *b;
    *b = c;
}

/* ---------------------------------------------------------------- */

void MinHeapify(heap *heapRoot, int i)
{
    int l = lChild(i);
    int r = rChild(i);
    int smallest = i;
    if (l < heapRoot->heapSize && heapRoot->arr[l].approx < heapRoot->arr[i].approx)
        smallest = l;
    if (r < heapRoot->heapSize && heapRoot->arr[r].approx < heapRoot->arr[smallest].approx)
        smallest = r;
    if (smallest != i)
    {
        swap(&heapRoot->arr[i], &heapRoot->arr[smallest]);
        MinHeapify(heapRoot, smallest);
    }
}

/* ---------------------------------------------------------------- */

void initheap(heap *h)
{
    h->heapSize = 0;
}

/* ---------------------------------------------------------------- */

// Add Key in the Heap
void insertReminder(heap *heapRoot, dt x)
{
    // The new key is initially inserted at the end.
    heapRoot->heapSize++;
    int i = heapRoot->heapSize - 1;
    heapRoot->arr[i] = x;

    //   The min heap property is checked if violation occurs, it is restored.
    while (i != 0 && heapRoot->arr[parent(i)].approx > heapRoot->arr[i].approx)
    {
        swap(&heapRoot->arr[i], &heapRoot->arr[parent(i)]);
        i = parent(i);
    }
}

/* ---------------------------------------------------------------- */

// get the node with minimum time (approx time calculated)
reminder getMinTime(heap *h)
{
    return h->arr[0];
}

/* ---------------------------------------------------------------- */

void decreaseKey(heap *heapRoot, int i, reminder new_val)
{
    heapRoot->arr[i] = new_val;
    while (i != 0 && heapRoot->arr[parent(i)].approx > heapRoot->arr[i].approx)
    {
        swap(&heapRoot->arr[i], &heapRoot->arr[parent(i)]);
        i = parent(i);
    }
}

/* ---------------------------------------------------------------- */

reminder extractMin(heap *heapRoot)
{
    // Store the minimum value, and remove it from heap
    reminder root = heapRoot->arr[0];
    heapRoot->arr[0] = heapRoot->arr[heapRoot->heapSize - 1];
    heapRoot->heapSize--;
    MinHeapify(heapRoot, 0);
    return root;
}

/* ---------------------------------------------------------------- */

void displayAllreminders(heap *heapRoot)
{

    printf("Displaying all Reminders \n");

    for (int i = 0; i < heapRoot->heapSize; i++)
    {

        printf("Reminder : %d\n", i + 1);
        displayReminder(&heapRoot->arr[i]);
    }

    printf("\n\n\n");
}

/* ---------------------------------------------------------------- */

void CheckForRemainders(heap *heapRoot)
{
    time_t currTime;
    time(&currTime);
    printf("\n\t%s\n\n", ctime(&currTime));
    struct tm now_t = *localtime(&currTime);
    int Currapprox = now_t.tm_hour * 3600 + now_t.tm_min * 60 + now_t.tm_sec;
    // printf("curr appox = %d \n\n", Currapprox);

    reminder upperMostRem = getMinTime(heapRoot);
    reminder temp;
    temp.approx = INT_MIN;

    while (heapRoot->heapSize > 0 && upperMostRem.approx < Currapprox)
    {
        displayReminder(&upperMostRem);
        extractMin(heapRoot);
        upperMostRem = getMinTime(heapRoot);
    }
}

/* ---------------------------------------------------------------- */

void AlarmApp(heap *heapRoot)
{

    int choice;
    // initheap(heapRoot);
    reminder newReminder;
    int index;

    while (1)
    {
        printf("");
        printf("\n");

        CheckForRemainders(heapRoot);

        printf("\n\n");
        printf("(0) Press 0 to exit App");
        printf("(1) Enter a new reminder\n");
        printf("(2) Delete a reminder\n");
        printf("(3) Display All the reminders \n");
        printf("(4) Display The upcoming Reminder\n");
        printf("(5) Delete The upcoming Reminder\n");

        printf("Enter the Choice :  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return;

        case 1:
            printf("\tEnter The reminder : \n");
            readReminder(&newReminder);
            insertReminder(heapRoot, newReminder);
            break;

        case 3:
            displayAllreminders(heapRoot);
            break;

        case 2:
            displayAllreminders(heapRoot);
            printf("Enter the reminder number that you want to delete : ");
            scanf("%d", &index);
            newReminder.approx = INT_MIN;
            decreaseKey(heapRoot, index - 1, newReminder);
            newReminder = extractMin(heapRoot);
            printf("The deleted reminder is : \n");
            displayReminder(&newReminder);
            printf("\n\n");
            break;

        case 4:
            newReminder = getMinTime(heapRoot);
            displayReminder(&newReminder);
            printf("\n\n");

        case 5:
            newReminder = extractMin(heapRoot);
            displayReminder(&newReminder);
            printf("\n\n");

        default:
            break;
        }
    }
}
