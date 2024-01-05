#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "documents.h"

/* ************************************************************************************ */
// ===========================STRUCTURE DEFINATIONS===================================//

typedef struct ContactNode
{
    Contact data;
    struct ContactNode *next;

} ContactNode;

typedef struct HashTable
{
    ContactNode **ContactNodehead;
    int TableSize;
    int NumOfKeys;

    // Seperarte Lists;
    Contact TaxiArr[200];
    int TaxiArrSize;
    Contact RestArr[200];
    int RestArrSize;
    Contact WorkerArr[200];
    int WorkerArrSize;

} HashTable;

/* ************************************************************************************* */

//--------------------------------FUNCTIONS-----------------------------------------//

/* ---------------------------------------------------------------------------------- */

// This Function Initializes the hashFunction By making a Table having Index 0 to 25 to stores names Starting from A to Z
// It makes the Head Pointer at every Index as Zero and Makes the tableSize = 26
//  It makes the num of keys stored = 0

void initHashTable(HashTable *hashRoot)
{
    hashRoot->NumOfKeys = 0;
    hashRoot->TableSize = ('Z' - 'A' + 1);
    hashRoot->ContactNodehead = (ContactNode **)malloc(sizeof(ContactNode *) * (hashRoot->TableSize));
    for (int i = 0; i < hashRoot->TableSize; i++)
    {
        hashRoot->ContactNodehead[i] = NULL;
    }
    hashRoot->RestArrSize = 0;
    hashRoot->TaxiArrSize = 0;
    hashRoot->WorkerArrSize = 0;
}

/* -------------------------------------------------------------------------------- */

// Create Node Function it takes the Contact Data as input parameter and Retuns a Node with dT contact and nextPointer as NULL

ContactNode *createContactNode(Contact newContact)
{
    ContactNode *temp = (ContactNode *)malloc(sizeof(ContactNode));
    temp->next = NULL;
    temp->data = newContact;
    return temp;
}

/* -------------------------------------------------------------------------------- */

// This is a HASH Function It maps the Names's First Letter in the hash table it returns the loction (Index )in the hashTable in which the Key is to be stored
//   Example A->0 B->1 C->2 D->3. . . . . . . . . . .

int Hashfunction(HashTable *hashRoot, char firstLetter)
{
    char Key = toupper(firstLetter);
    int index = Key - 'A';
    return index;
}

/* -------------------------------------------------------------------------------- */

// this Function Adds the Element in the Beginning of the Linked List
// It takes the double pointer To the structure head and Contact person

void AddAtHead(ContactNode **headPtr, Contact person)
{
    ContactNode *newContactCont = createContactNode(person);

    newContactCont->next = (*headPtr);
    *headPtr = newContactCont;
}

/* -------------------------------------------------------------------- */

// Function NOT WORKING PROPERLY //

void AddAtProperPosition(ContactNode **headPtr, Contact person)
{
    ContactNode *newContactCont = createContactNode(person);

    if (*headPtr == NULL)
    {
        *headPtr = newContactCont;
        newContactCont->next = NULL;
        return;
    }

    ContactNode *currPtr = *headPtr;
    ContactNode *prevPtr = NULL;
    while (currPtr && strcasecmp(person.Name, currPtr->data.Name) != 1)
    {
        prevPtr = currPtr;
        currPtr = currPtr->next;
        if (currPtr == NULL)
            break;
    }

    prevPtr->next = newContactCont;
    newContactCont->next = currPtr;
    return;
}

/* -------------------------------------------------------------------------------- */

void AddKey(HashTable *hashRoot, Contact person)
{
    int Index = Hashfunction(hashRoot, person.Name[0]);
    AddAtHead(&hashRoot->ContactNodehead[Index], person);
}

/* ------------------------------------------------------------------------------------- */

int DeleteKeyinLL(ContactNode **headPtr, char name[])
{

    if (strcasecmp((*headPtr)->data.Name, name) == 0)
    {
        *headPtr = (*headPtr)->next;
        return 1;
    }

    else
    {
        ContactNode *currPtr = *headPtr;
        ContactNode *prevPtr = NULL;
        while (currPtr && strcasecmp(currPtr->data.Name, name) != 0)
        {
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        if (currPtr == NULL)
            return 0;

        else
        {
            prevPtr->next = currPtr->next;
            return 1;
        }
    }
}

void DeleteKey(HashTable *hT, char name[])
{
    int Index = Hashfunction(hT, name[0]);
    int ans = DeleteKeyinLL(&hT->ContactNodehead[Index], name);
    if (ans == 1)
        printf("The Contact with the Entered name is deleted Successfully \n\n ");
    else
        printf("The Contact with the Entered name is not found \n\n ");
}

/* ------------------------------------------------------------------------------------- */

// Search Funtion to search the perticular named contact from the HashTables Linked list
// Interates through The LinkedList and Finds The contact and Displays it
// IF Not Found it prints Contact Not found

void SearchInLL(ContactNode *headPtr, char name[])
{

    ContactNode *currPtr = headPtr;

    while (currPtr)
    {
        if (strcasecmp(name, currPtr->data.Name) == 0)
        {
            displayContact(&currPtr->data);
            return;
        }
        currPtr = currPtr->next;
    }

    printf("SORRY\nYOUR CONTACT NOT FOUND \n\n");
}

void SearchKey(HashTable *hashRoot, char name[])
{
    int Index = Hashfunction(hashRoot, name[0]);
    SearchInLL(hashRoot->ContactNodehead[Index], name);
}

/* ------------------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------------------- */

//  This Table Displays All the Keys in The Hash Table
// It Iterates through The array of Head pointers and Displays All the Conatacts from the Linked List in the head

void DisplayTable(HashTable *hashRoot)
{
    for (int i = 0; i < hashRoot->TableSize; i++)
    {
        ContactNode *currPtr = hashRoot->ContactNodehead[i];

        if (currPtr)
            printf("%c  | -----------------------------------------------------------\n", i + 'A');

        while (currPtr)
        {
            displayContact(&currPtr->data);
            printf("\n");
            currPtr = currPtr->next;
        }
    }
    printf("\n\n");
}

/* -------------------------------------------------------------------------------------- */

void ImportContacts(HashTable *hashRoot)
{
    Contact a;
    FILE *filePtr;
    filePtr = fopen("ContactFile.txt", "r");
    int i = 1;
    while (fscanf(filePtr, "%s%s%s%d", a.Name, a.LName, a.num, &a.Occupation) == 4)
    {
        // printf("%s %s\n",a.Name,a.num);
        AddKey(hashRoot, a);

        if (a.Occupation == 1)
        {
            hashRoot->WorkerArr[hashRoot->WorkerArrSize] = a;
            hashRoot->WorkerArrSize++;
        }
        else if (a.Occupation == 2)
        {
            hashRoot->TaxiArr[hashRoot->TaxiArrSize] = a;
            hashRoot->TaxiArrSize++;
        }
        else if (a.Occupation == 3)
        {
            hashRoot->RestArr[hashRoot->RestArrSize] = a;
            hashRoot->RestArrSize++;
        }
    }
    // printf("File read and closed\n");
    fclose(filePtr);
}

/* -------------------------------------------------------------------------------------- */

// This Function reades the values from the HashTable and Adds Them into the textFile
// This Function is Called After the newContact Key is added in the Table and is also During the Contact App is Closed (May Not be req)
// This Function Keeps the Contact List UPDATED

void ExportContacts(HashTable *hashRoot)
{
    Contact a;
    FILE *filePtr;
    filePtr = fopen("ContactFile.txt", "w");

    for (int i = 0; i < hashRoot->TableSize; i++)
    {
        ContactNode *currPtr = hashRoot->ContactNodehead[i];

        while (currPtr)
        {
            fprintf(filePtr, "%s\n%s\n%s\n%d", currPtr->data.Name, currPtr->data.LName, currPtr->data.num, currPtr->data.Occupation);
            currPtr = currPtr->next;
        }
    }

    // printf("File closed\n");
    fclose(filePtr);
}

/* ------------------------------------------------------------------------------------ */

void DisplayTableLetter(HashTable *hashRoot, char Alphabet)
{

    Alphabet = toupper(Alphabet);
    int idx = Alphabet - 'A';

    ContactNode *currPtr = hashRoot->ContactNodehead[idx];

    if (currPtr)
    {
        printf("%c  | -----------------------------------------------------------\n", Alphabet);
        while (currPtr)
        {
            displayContact(&currPtr->data);
            printf("\n");
            currPtr = currPtr->next;
        }

        printf("--------------------------------------------------------------\n");
    }
    else
    {
        printf(" No contact starting from this Letter \n");
    }

    printf("\n\n");
}

/* -------------------------------------------------------- */

void DisplayMiniLists(HashTable *hashList)
{

    printf("\t Worker List \n\n");
    for (int i = 0; i < hashList->WorkerArrSize; i++)
    {
        displayContact(&hashList->WorkerArr[i]);
    }

    printf("\n\n");
    printf("\t Restaurant List \n\n");
    for (int i = 0; i < hashList->RestArrSize; i++)
    {
        displayContact(&hashList->RestArr[i]);
    }

    printf("\n\n");

    printf("\t Taxt/Cab List \n\n");
    for (int i = 0; i < hashList->TaxiArrSize; i++)
    {
        displayContact(&hashList->TaxiArr[i]);
    }

    printf("\n\n");
}

/* -------------------------------------- */

// Launching The Contact Application with all the basic Functionalities of the Contact Book
// This is The final Function To be Implemented in The main of the PhoneSystem Program

void ContactsApp(HashTable *hashList_1)
{
    // passed the HashTable the reference

    Contact newContact;
    int choice;
    char name[20];
    char alphabet;

    ImportContacts(hashList_1);

    while (1)
    {
        // printf("Contact App started Press Enter key to continue\n");
        // getch();

        system("cls");
        printf("WELCOME TO CONTACTS APP\n\n\n");
        printf("(1) Insert newContact Contact\n");
        printf("(2) Display All contacts \n");
        printf("(3) Display contacts from Letter \n");
        printf("(4) Delete Contact \n");
        printf("(5) Search Contact\n");
        printf("(6) Total Number of Contacts\n");
        printf("(7) Close Contact\n");
        printf("(8) seperate List Display\n");
        printf("(0) Exit Application\n");

        printf("\n\n");
        printf("Enter what you want to do :  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            readContact(&newContact);
            AddKey(hashList_1, newContact);
            printf("The contact is successfully Added\n\n");
            ExportContacts(hashList_1);
            getch();
            break;

        case 2:
            // Display All the Contacts
            system("cls");
            DisplayTable(hashList_1);
            // printf("All the contacts are :");
            getch();
            break;

        case 3:
            // Display All the Contacts
            system("cls");
            printf("Enter The Starting Letter :  ");
            scanf("%*c%c", &alphabet);
            printf("\n\n\n");
            DisplayTableLetter(hashList_1, alphabet);
            printf("All the contacts are :\n\n");
            getch();
            break;

        case 4:
            // Delete Contact With perticular Name
            printf("Enter the Person Whose conatact you want to Delete :  ");
            scanf("%s", name);
            DeleteKey(hashList_1, name);
            getch();
            break;

        case 5:
            // Search the Contact
            printf("Enter the Person Whose conatact you want to Search :  ");
            scanf("%s", name);
            SearchKey(hashList_1, name);
            getch();
            break;

        case 8:
            printf("Displaying all The individual List\n");
            DisplayMiniLists(hashList_1);
            getch();
            break;

        case 0:
            // Close The Application
            // ExportContacts(hashList_1);
            return;
            break;

        default:
            // Any random Key Pressed apart from Functional Keys
            printf("\n");
            printf("SORRY INVALID CHOICE\n");
            printf("Enter a Valid choice\n");
            break;
        }
    }
}

/* -------------------------------------------------------------------------------- */
