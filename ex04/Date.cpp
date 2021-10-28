#include <iostream>
#include "Date.h"

void Date::set(const int m, const int d, const int y) {
    month = m;
    day = d;
    year = y;
}

void Date::print(){
    std::cout << "year: " << year << " month: " << month << " day: " << day << std::endl;
}

int Date::get_month() {
    return month;
}

int Date::get_year() {
    return year;
}

int Date::get_day() {
    return day;
}

void Date::inc_day() {
    ++day;
}

void Date::inc_month() {
    ++month;
}

void Date::inc_year() {
    ++year;
}