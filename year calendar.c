#include <stdio.h>

// Function to check if the given year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Function to display the calendar for a given year
void displayCalendar(int year) {
    int day = 1;
   
    printf("Calendar for year %d\n\n", year);
   
    for (int month = 1; month <= 12; month++) {
        int days = daysInMonth(month, year);
       
        printf("Month: %d\n", month);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
       
        // Calculate the day of the week for the 1st day of the month
        int startDay = day % 7;
       
        // Print leading spaces before the 1st day of the month
        for (int i = 0; i < startDay; i++) {
            printf("    ");
        }
       
        // Print the days of the month
        for (int i = 1; i <= days; i++) {
            printf("%3d ", i);
            if ((day + i - 1) % 7 == 0 || i == days)
                printf("\n");
        }
       
        // Update the day counter for the next month
        day += days;
       
        printf("\n");
    }
}

int main() {
    int year;
   
    printf("Enter the year: ");
    scanf("%d", &year);
   
    displayCalendar(year);
   
    return 0;
}
