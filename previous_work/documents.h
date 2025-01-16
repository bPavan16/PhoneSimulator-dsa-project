#ifndef doc_h

#define doc_h

#include <stdio.h>

typedef struct Contact
{
    char Name[20];
    char LName[20];
    char num[20];
    int Occupation;
} Contact;

/* -------------------------------------------------------------------------- */

// This function takes in pointer to structure Contact as the parameter and Displays All the contents of the structure Contact

void displayContact(Contact *cont)
{
    printf("\t");
    printf("The person Name : %s %s\n", cont->Name, cont->LName);
    printf("\t");
    printf("Number :  %s \n", cont->num);
    printf("\t");
    printf("Occupation Saved: ");

    switch (cont->Occupation)
    {
    default:
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
    }

    printf("\t Email:%s%s@gmail.com\n", cont->LName, cont->Name);
    printf("\n");
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------------- */

// This function takes in pointer to structure Contact as the parameter and Displays All the contents of the structure Contact

void readContact(Contact *cont)
{
    printf("Enter The person Fist Name : ");
    scanf("%s", cont->Name);
    printf("Enter The person Last Name : ");
    scanf("%s", cont->LName);
    printf("Enter The %s number :  ", cont->Name);
    scanf("%s", cont->num);
    printf("Occupation : \n(0)NULL\n(1)Plumber\n(2)Taxi/Cab\n(3)Restaurant\nEnter occupation :  ");
    scanf("%d", &cont->Occupation);
}

/* ------------------------------------------------------------------------ */

#endif
