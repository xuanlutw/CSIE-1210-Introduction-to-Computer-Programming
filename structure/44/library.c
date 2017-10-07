#include "book.h"
#include "date.h"

int fee(unsigned int importance){
    int a1 = -1, a2 = -1;
    for (int i = 0;i < 33;++i){
        if ((importance & 1) && (a1 == -1)) a1 = i;
        else if ((importance & 1) && (a2 == -1)){
            a2 = i;
            break;
        }
        importance /= 2;
    }
    return a2 - a1 - 1;
}

int leap (struct Date ddate){
    int ans = 0;
    ans += ddate.year / 4;
    ans -= ddate.year / 100;
    ans += ddate.year / 400;
    if (ddate.year % 400 == 0 || (ddate.year % 4 == 0 && ddate.year % 100 != 0)){
        if (ddate.month == 1) ans -= 1;
        if (ddate.month == 2 && ddate.day != 29) ans -= 1;
    }
    return ans;
}

int delta_day(struct Date date_borrowed, struct Date date_returned){
    int ans = 0, month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ans += 365 * (date_returned.year - date_borrowed.year);
    if (date_returned.month > date_borrowed.month){
        for (int i = date_borrowed.month;i < date_returned.month;++i) ans += month[i];
    }
    if (date_returned.month < date_borrowed.month){
        for (int i = date_borrowed.month;i > date_returned.month;--i) ans -= month[i - 1];
    }
    ans += date_returned.day - date_borrowed.day;
    ans -= leap(date_borrowed);
    ans += leap(date_returned);
    ans += 1;
    return ans;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    int over_day = delta_day(date_borrowed, date_returned);
    if(book.type == NOVEL) over_day -= 90;       
    if(book.type == COMICS) over_day -= 10;       
    if(book.type == MANUAL) over_day -= 100;       
    if(book.type == TEXTBOOK) over_day -= 5;
    if(over_day < 0) over_day = 0;
    return over_day * fee(book.importance);
}

           

