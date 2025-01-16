#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int isleap(int s)
{
    if (s % 400 == 0)
        return 1;
    else if (s % 100 == 0)
        return 0;
    else if (s % 4 == 0)
        return 1;
    else
        return 0;
}

void getStartingWeekOfGivenYear(int year, int month, unsigned int *s, unsigned int *d)
{
    int i1800 = 3;
    int leap = 0;
    for (int i = 1800; i < year; i++)
    {
        int e = isleap(i);
        if (e)
            leap++;
    }

    *s = i1800 + 365 * (year - 1800) + leap;
    *s = *s % 7;

    int currentmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isleap(year))
        currentmonth[1] = 29;
    *d = currentmonth[month - 1];
    for (int i = 0; i < month - 1; i++)
    {
        *s = ((*s) + currentmonth[i]) % 7;
    }
}

int calender1(int year)
{
    unsigned int i = 0, j = 0;
    int month;

    char month_name[12][5] = {{"Jan"}, {"Feb"}, {"Mar"}, {"Apr"}, {"May"}, {"Jun"}, {"Jul"}, {"Aug"}, {"Sept"}, {"Oct"}, {"Nov"}, {"Dec"}};

    system("cls");
    printf("%d\n\n\n", year);
    for (month = 1; month <= 12; month++)
    {
        getStartingWeekOfGivenYear(year, month, &i, &j);

        printf("\n\n");
        printf("\t\tyear --%d Month -- %s\n", year, month_name[month - 1]);
        printf("        Sun    Mon     Tue     Wed     Thu     Fri     Sat\n\n");
        for (int n = 0; n <= i; n++)
            printf("\t");
        printf("%d", 1);
        int nextrow = 7 - i;
        for (int n = 2; n <= nextrow; n++)
        {
            printf("\t%d", n);
        }
        printf("\n");
        int currentrow = 0;
        for (int n = nextrow + 1; n <= j; n++)
        {
            if (currentrow == 7)
            {
                printf("\n");
                currentrow = 0;
            }
            printf("\t%d", n);
            currentrow++;
        }
    }
}

int calender2(int year, int month)
{
    unsigned int i = 0, j = 0;

    char month_name[12][5] = {{"Jan"}, {"Feb"}, {"Mar"}, {"Apr"}, {"May"}, {"Jun"}, {"Jul"}, {"Aug"}, {"Sept"}, {"Oct"}, {"Nov"}, {"Dec"}};

    system("cls");
    printf("%d\n\n\n", year);
    getStartingWeekOfGivenYear(year, month, &i, &j);
    printf("\n\n");
    printf("\t\tyear --%d Month -- %s\n", year, month_name[month - 1]);
    printf("        Sun    Mon     Tue     Wed     Thu     Fri     Sat\n\n");
    for (int n = 0; n <= i; n++)
        printf("\t");
    printf("%d", 1);
    int nextrow = 7 - i;
    for (int n = 2; n <= nextrow; n++)
    {
        printf("\t%d", n);
    }
    printf("\n");
    int currentrow = 0;
    for (int n = nextrow + 1; n <= j; n++)
    {
        if (currentrow == 7)
        {
            printf("\n");
            currentrow = 0;
        }
        printf("\t%d", n);
        currentrow++;
    }
}

void calanderApp()
{
    int choice, year, month;
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("Enter 0 to exit the application \n");
        printf("Enter 1 to display all the month in a calender year  \n");
        printf("Enter 2 to display particular month in a calender year \n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 0:
            printf("Closing the Calender App \n.\n.\n.\n");
            return;
        case 1:
            printf("Enter year(above 1800) : ");
            scanf("%d", &year);
            calender1(year);
            break;
        case 2:
            printf("Enter year(above 1800) : ");
            scanf("%d", &year);
            printf("Enter month (1-12)");
            scanf("%d", &month);
            calender2(year, month);
            break;

        default:
            printf("Enter valid choice \n");
            break;
        }
        getch();
    }
}