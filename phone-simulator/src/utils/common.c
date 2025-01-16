#include "common.h"

// Function to print a message
void print_message(const char *message) {
    printf("%s\n", message);
}

// Function to check if a number is even
int is_even(int number) {
    return number % 2 == 0;
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}