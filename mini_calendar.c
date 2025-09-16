#include <stdio.h>
#include <stdbool.h>

// Function to check if a year is a leap year
bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false; // not divisible by 4 → not a leap year
    } else if (year % 100 != 0) {
        return true; // divisible by 4 but not by 100 → leap year
    } else if (year % 400 != 0) {
        return false; // divisible by 100 but not by 400 → not a leap year
    } else {
        return true; // divisible by 400 → leap year
    }
}

int main() {
    int year;

    // Ask the user for input
    printf("Enter a year between 1800 and 10000: ");
    scanf("%d", &year);

    // Call the function and print result
    if (is_leap_year(year)) {
        printf("Leap Year\n");
    } else {
        printf("Not Leap Year\n");
    }

    return 0;
}
