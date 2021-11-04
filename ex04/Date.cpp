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

int Date::get_month() const {
    return month;
}

int Date::get_year() const {
    return year;
}

int Date::get_day() const {
    return day;
}

void Date::inc_day() {
    if(((this->get_month() == 1) || (this->get_month() == 3) || (this->get_month() == 5) || (this->get_month() == 7) || (this->get_month() == 8) || (this->get_month() == 10) || (this->get_month() == 12)) && this -> get_day() == 31){
        this->day = 1;
    } else if(((this->get_month() == 4) || (this->get_month() == 6) || (this->get_month() == 9) || (this->get_month() == 11)) && this->get_day() == 30){
        this->day = 1;
    } else if(this->get_month() == 2 && (this->get_year() % 400 == 0 || (this->get_year() % 4 == 0 && this->get_year() % 100 != 0)) && this->get_day() == 29 ){
        this->day = 1;
    } else if(this->get_month() == 2 && (this->get_year() % 4 !=0 || (this->get_year() % 4 != 0 && this->get_year() % 11 != 0)) && this->get_day() == 28){
        this->day = 1;
    }
    else this->day++;
}

void Date::inc_month() {
    if(this->get_month() == 12){
        this->month = 1;
    }
    else this->month++;
}


void Date::inc_year() {
    this->year++;
}