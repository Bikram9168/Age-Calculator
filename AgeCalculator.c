#include <stdio.h>

int fnIsLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int fnMonthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void fnCalculateAge(int iBirth_day, int iBirth_month, int iBirth_year,int iCurrent_day, int iCurrent_month, int iCurrent_year) 
{
    
    if (fnIsLeapYear(iCurrent_year)) 
    {
        fnMonthDays[1] = 29;
    }

    int iDay, iMonth, iYear;
    
    if (iBirth_day > iCurrent_day) 
    {
        iCurrent_day += fnMonthDays[(iCurrent_month - 2 + 12) % 12];
        iCurrent_month--;
    }

    iDay = iCurrent_day - iBirth_day;

    if (iBirth_month > iCurrent_month) 
    {
        iCurrent_year--;
        iCurrent_month += 12;
    }

    iMonth = iCurrent_month - iBirth_month;
    iYear = iCurrent_year - iBirth_year;

    printf("\nYour Age is: %d years %d months %d days\n", iYear, iMonth, iDay);
}

int main() 
{
    int iBirth_day, iBirth_month, iBirth_year;
    int iCurrent_day, iCurrent_month, iCurrent_year;

    printf("Enter your birth date (DD MM YYYY): ");
    scanf("%d %d %d", &iBirth_day, &iBirth_month, &iBirth_year);

    printf("Enter current date (DD MM YYYY): ");
    scanf("%d %d %d", &iCurrent_day, &iCurrent_month, &iCurrent_year);

    fnCalculateAge(iBirth_day, iBirth_month, iBirth_year, iCurrent_day, iCurrent_month, iCurrent_year);

    return 0;
}
