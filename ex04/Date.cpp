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

const int Date::get_month() {
    return month;
}

const int Date::get_year() {
    return year;
}

const int Date::get_day() {
    return day;
}

void Date::inc_day() {
    if(this->get_month() == 1,3,5,7,8,10,12 && this -> get_day() == 31){
        this->day = 1;
    } else if(this->get_month() == 4,6,9,11 && this->get_day() == 30){
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
