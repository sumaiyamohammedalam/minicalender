#include <stdio.h>
#include <stdbool.h>

// Leap year check function
bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false; // Not divisible by 4 → Not a leap year
    } else if (year % 100 != 0) {
        return true; // Divisible by 4 but not 100 → Leap year
    } else if (year % 400 != 0) {
        return false; // Divisible by 100 but not 400 → Not a leap year
    } else {
        return true; // Divisible by 400 → Leap year
    }
}

// Days in each month (index 0 unused for convenience)
int days_in_month[] = { 
    0,  // dummy
    31, // Jan
    28, // Feb (29 if leap year)
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    30, // Nov
    31  // Dec
};

// Add days to a given date
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    while (days_left_to_add > 0) {
        int days_left_in_month = days_in_month[*mm] - *dd;

        // February leap year adjustment
        if (*mm == 2 && is_leap_year(*yy)) {
            days_left_in_month++;
        }

        if (days_left_to_add > days_left_in_month) {
            // Move to the first day of the next month
            days_left_to_add -= (days_left_in_month + 1);
            *dd = 1;

            if (*mm == 12) {
                *mm = 1;  // wrap to January
                (*yy)++;  // increment year
            } else {
                (*mm)++;
            }
        } else {
            // All remaining days fit in this month
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

int main() {
    int mm, dd, yy, days_to_add;

    printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add:\n");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_to_add);

    add_days_to_date(&mm, &dd, &yy, days_to_add);

    printf("New date: %d %d %d\n", mm, dd, yy);

    return 0;
}
