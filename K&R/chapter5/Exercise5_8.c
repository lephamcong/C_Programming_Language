/*
Exercise 5-8. 
    There is no error checking in day_of_year or month_day. Remedy this defect. 
*/



#include <stdio.h>
#include <stdlib.h>

#define MIN_DAY 1
#define MAX_DAY 31
#define MIN_MONTH 1
#define MAX_MONTH 12

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int year, month, day, yearday, pday, pmonth;
    year = 2024;
    month = 1;
    day = 1;
    
    yearday = day_of_year(year, month, day);
    printf("Day of year: %d\n", yearday);
    
    month_day(2024, 366, &pmonth, &pday);
    printf("Month: %d, Day: %d\n", pmonth, pday);

    
    return 0;
}

/*  day_of_year: set day of year from month & day   */
int day_of_year(int year, int month, int day) {
    int i, leap;
    if (month < MIN_MONTH || month > MAX_MONTH) {
        printf("Invalid month\n");
        exit(1);
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (day < MIN_DAY || day > daytab[leap][month]) {
        printf("Invalid day\n");
        exit(1);
    }
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

/*  month_day: set month, day from day of year  */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (yearday < MIN_DAY || yearday > (leap ? 366 : 365)) {
        printf("Invalid day of year\n");
        exit(1);
    }
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;

}
