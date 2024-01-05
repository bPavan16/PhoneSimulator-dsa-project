#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void lockScreen()
{
    int k, l, z;
    int bs = 0;
    printf("Your Phone is Starting \n");

    for (z = 0; z < 30; z++)
    {
        system("cls");
        {
            char *str = "WELCOME";
            for (puts("  |\n /_\\"); *str; printf(" |%c|\n", *str++))
                ;
            puts(" |_|\n/___\\\n VvV");
            for (k = 0; k < 25000; k++)
                for (l = 0; l < 5000; l++)
                    ;
        }
    }
    for (k = 0; k < 200000; k++)
        for (l = 0; l < 10000; l++)
            ;
    int i = 5;
    while (i)
    {
        system("cls");
        int j = 5 - i;
        printf("=================================================================\n");
        printf("Enter password : ");
        while (j--)
            printf("*");
        printf("\n=================================================================\n");
        getch();
        i--;
    }
    system("cls");
    printf("=================================================================\n");
    printf("LOADING... \n");
    printf("=================================================================\n");
    for (k = 0; k < 400000; k++)
        for (l = 0; l < 10000; l++)
            ;
    // printf("press key to continue : ");
}
