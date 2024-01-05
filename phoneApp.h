#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "documents.h"

/* ----------------------------------------------------------------------------------------- */

typedef struct trieNode
{
    Contact data;
    int isEnd;
    struct trieNode *childern[10];
} trieNode;

/* ------------------------------------------------------------------------------------------ */

void deleteTrie(trieNode **rootTrieNode);
trieNode *getTrieNode();
void Addword(trieNode **rootTrieNode, char *word, Contact ContactInfo);
void displayContact(Contact *cont);
void readContact(Contact *cont);
int SearchTrie(trieNode *rootTrieNode, char *word);
void displayTrie(trieNode *rootTrieNode);
trieNode *ImportPhone();
void _deleteTrie(trieNode *rootTrieNode);
void deleteTrie(trieNode **rootTrieNode);
int SearchTrieAndDisplay(trieNode *rootTrieNode, char *word);
void PhoneApp();
void callPerson(Contact *c);

/* ------------------------------------------------------------------------------------------ */

void callPerson(Contact *contactPassed)
{

    printf("---------------------------------------\n");
    printf("|                                     |\n");
    printf("|             Calling [ . . .         |\n");
    printf("|             _________               |\n");
    printf("|             |       |               |\n");
    printf("|             |       |               |\n");
    printf("|             |       |               |\n");
    printf("|             |_______|               |\n");
    printf("|                                     |\n");
    printf("|                                     |\n");
    printf("|                                     |\n");
    printf("|                                     |\n");
    printf("\t name:%s %s\n", contactPassed->Name, contactPassed->LName);
    printf("\tPhone Number : %s\n", contactPassed->num);
    printf("\tOccupation : ");
    switch (contactPassed->Occupation)
    {
    case 0:
        printf("NULL\n");
        break;
    case 1:
        printf("Plumber\n");
        break;
    case 2:
        printf("Taxi/Cab\n");
        break;
    case 3:
        printf("Restaurant\n");
        break;

    default:
        break;
    }

    printf("|                                     |\n");
    printf("|                                     |\n");
    printf("\t Email:%s%s@gmail.com\n", contactPassed->LName, contactPassed->Name);
    printf("|                                     |\n");
    printf("|                                     |\n");
    printf("|                                     |\n");
    printf("|                                     |\n");
    printf("|                                     |\n");
    printf("|            End Call ( [ )           |\n");
    printf("|                                     |\n");
    printf("---------------------------------------\n");
}

/* ------------------------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------------------------ */

trieNode *getTrieNode()
{
    trieNode *newContactNode = (trieNode *)malloc(sizeof(trieNode));
    newContactNode->isEnd = 0;
    for (int i = 0; i < 10; i++)
    {
        newContactNode->childern[i] = NULL;
    }
    return newContactNode;
}

/* ------------------------------------------------------------------------------------------ */

void Addword(trieNode **rootTrieNode, char *word, Contact ContactInfo)
{
    if (*rootTrieNode == NULL)
        *rootTrieNode = getTrieNode();

    trieNode *p = *rootTrieNode;
    char ch;
    int index;

    for (int i = 0; word[i]; i++)
    {
        index = word[i] - '0';

        if (p->childern[index] == NULL)
            p->childern[index] = getTrieNode();

        p = p->childern[index];
    }

    p->isEnd = 1;
    p->data = ContactInfo;
}

int SearchTrie(trieNode *rootTrieNode, char *word)
{

    if (rootTrieNode == NULL)
        return 0;

    int index;

    trieNode *temp = rootTrieNode;

    for (int i = 0; word[i]; i++)
    {

        index = word[i] - '0';

        if (temp->childern[index] == NULL)
        {
            printf("The Number not in the Contacts \n\n");
            return 0;
        }

        temp = temp->childern[index];
    }

    if (temp->isEnd == 1)
        displayContact(&temp->data);
    return temp->isEnd;
}

//* ----------------------------------------------------------------------------------- */

int SearchTrieandCall(trieNode *rootTrieNode, char *word)
{

    if (rootTrieNode == NULL)
        return 0;

    int index;

    trieNode *temp = rootTrieNode;

    for (int i = 0; word[i]; i++)
    {

        index = word[i] - '0';

        if (temp->childern[index] == NULL)
        {
            printf("The Number not in the Contacts \n\n");
            return 0;
        }

        temp = temp->childern[index];
    }

    if (temp->isEnd == 1)
        callPerson(&temp->data);
    return temp->isEnd;
}

/* ------------------------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------------------------ */

int SearchTrieAndDisplay(trieNode *rootTrieNode, char *word)
{
    if (rootTrieNode == NULL)
        return 0;

    int index;

    trieNode *temp = rootTrieNode;

    for (int i = 0; word[i]; i++)
    {
        index = word[i] - '0';

        if (temp->childern[index] == NULL)
        {
            printf("The Number not in the Contacts \n\n");
            return 0;
        }
        temp = temp->childern[index];
    }

    if (temp->isEnd == 1)
        displayContact(&temp->data);

    displayTrie(temp);
}

/* ------------------------------------------------------------------------------------------ */

void displayTrie(trieNode *rootTrieNode)
{
    trieNode *Iterator;

    if (rootTrieNode == NULL)
        return;

    else
    {
        for (int i = 0; i < 10; i++)
        {
            Iterator = rootTrieNode->childern[i];

            if (Iterator != NULL)
            {
                if (Iterator->isEnd == 1)
                {
                    printf("\t");
                    printf("%s %s : ", Iterator->data.Name, Iterator->data.LName);
                    printf("%s", Iterator->data.num);
                    printf("\n");
                }
                displayTrie(Iterator);
            }
        }
    }
}

/* ------------------------------------------------------------------------------------------ */

trieNode *ImportPhone()
{
    trieNode *rootTrieNode = NULL;
    Contact tempStorage;
    FILE *filePtr;
    filePtr = fopen("ContactFile.txt", "r");
    int i = 1;

    while (fscanf(filePtr, "%s%s%s%d", tempStorage.Name, tempStorage.LName, tempStorage.num, &tempStorage.Occupation) == 4)
    {
        // printf("%s %s\n",a.Name,a.num);
        // displayContact(&a);
        Addword(&rootTrieNode, tempStorage.num, tempStorage);
    }

    // printf("File closed\n");
    fclose(filePtr);
    return rootTrieNode;
}

/* ------------------------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------------------------ */

void _deleteTrie(trieNode *rootTrieNode)
{
    if (rootTrieNode = NULL)
    {
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (rootTrieNode->childern[i])
        {
            _deleteTrie(rootTrieNode->childern[i]);
        }

        free(rootTrieNode->childern[i]);
    }
}

/* ------------------------------------------------------------------------------------------ */

void deleteTrie(trieNode **rootTrieNode)
{
    _deleteTrie(*rootTrieNode);
    *rootTrieNode = NULL;
    printf("Trie Successfully Deleted\n\n");
}

/* ------------------------------------------------------------------------------------------ */

void PhoneApp(trieNode **rootTrieNode)
{
    // trieNode *rootTrieNode = ImportPhone();
    Contact newContact;
    int choice;
    char number[20];

    while (1)
    {
        // system("cls");

        printf("\n\n\nWELCOME TO PHONE APP\n\n\n");
        printf("(0) Press 0 to exit App");
        printf("(1) Add A new Phone Number\n");
        printf("(2) Display All Phone Numbers \n");
        printf("(3) Find A Number\n");
        printf("(4) Call A Person with Number\n");
        printf("(5) Close the Phone App\n");

        printf("\n\n");
        printf("Enter what you want to do :  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            printf("\n\n\n");
            system("cls");
            readContact(&newContact);
            Addword(rootTrieNode, newContact.num, newContact);
            getch();
            system("cls");
            break;

        case 2:
            printf("\n\n\n");
            system("cls");
            displayTrie(*rootTrieNode);
            break;

        case 3:
            printf("\n\n\n");
            printf("Enter the number you want to search  : ");
            scanf("%s", number);
            SearchTrieAndDisplay(*rootTrieNode, number);
            getch();
            system("cls");
            break;

        case 4:
            printf("\n\n\n");
            printf("Enter the number you want to search  : ");
            scanf("%s", number);
            SearchTrieandCall(*rootTrieNode, number);
            getch();
            system("cls");
            break;

        case 5:
            printf("\n\n\n");
            // deleteTrie(&rootTrieNode);
            printf("The Phone App successfully Closed");
            getch();
            system("cls");
            return;
            break;

        default:
            break;
        }
    }
}

///* -------------------------------------------------------------------------------- */
