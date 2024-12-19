/*
Exercise 5-9. 
    Rewrite the routines day_of_year and month_day with pointers instead of indexing. 
*/
#include <stdio.h>
#include <stdlib.h>

#define MIN_DAY 1
#define MAX_DAY 31
#define MIN_MONTH 1
#define MAX_MONTH 12

static int daytab[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
};

static char *name[] = {
    "Invalid month", 
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int year, month, day, yearday, pday, pmonth;
    year = 2024;
    month = 2;
    day = 29;
    
    yearday = day_of_year(year, month, day);
    printf("Day of year: %d\n", yearday);
    
    month_day(2024, 366, &pmonth, &pday);
    char month_name[20];
    if (pmonth < MIN_MONTH || pmonth > MAX_MONTH) {
        printf("%s\n", name[0]);
        exit(1);
    }
    printf("Month: %d, Day: %d\n", pmonth, pday);

    
    return 0;
}

/*  day_of_year: set day of year from month & day   */
int day_of_year(int year, int month, int day) {
    if (month < MIN_MONTH || month > MAX_MONTH) {
        printf("%s\n", name[0]);
        exit(1);
    }
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (day < MIN_DAY || day > *(*(daytab + leap) + month)) {
        printf("Invalid day\n");
        exit(1);
    }
    for (int i = 1; i < month; i++) {
        day += *(*(daytab + leap) + i);
    }
    return day;
}

/*  month_day: set month, day from day of year  */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (yearday < MIN_DAY || yearday > (leap ? 366 : 365)) {
        printf("Invalid day of year\n");
        exit(1);
    }
    int i;
    for (i = 1; yearday > *(*(daytab + leap) + i); i++) {
        yearday -= *(*(daytab + leap) + i);
    }
    *pmonth = i;
    *pday = yearday;
}