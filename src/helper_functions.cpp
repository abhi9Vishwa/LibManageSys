#include"../include/helper_functions.h"

#include<iostream>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

vector<string> split_str_custom(string str, char delimiter){
    // split a string at delimiter into a vector of strings

    vector<string> splitted_str;
    string temp_str = "";
    for(int i=0; i<str.length(); i++){
        if(str[i] != delimiter){
            temp_str += str[i];
        }
        else{
            splitted_str.push_back(temp_str);
            temp_str = "";
        }
    }
    splitted_str.push_back(temp_str);
    return splitted_str;
}

bool date_valid(int date){
    int day = date/1000000;
    int month = (date/10000)%100;
    int year = date%10000;

    if (month == 1 || month==3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day > 31 || day < 1)
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30 || day < 1)
            return false;
    }
    else if (month == 2){
        if((year%4 == 0 && year%100 != 0) || year%400 == 0){
            if(day > 29 || day < 1)
                return false;
        }
        else{
            if(day > 28 || day < 1)
                return false;
        }
    }
    return true;
}


int num_days(int date1, int date2){
    // return the number of days between two dates.
    // assumes that each mont has 30 days. and a year has 365 days for now.

    int day1 = date1/1000000;
    int month1 = (date1/10000)%100;
    int year1 = date1%10000;

    int day2 = date2/1000000;
    int month2 = (date2/10000)%100;
    int year2 = date2%10000;

    int days = 0;

    if (year1 == year2){
        if (month1 == month2){
            days = day2 - day1;
        }
        else{
            days = (month2 - month1)*30 + day2 - day1;
        }
    }
    else{
        days = (year2 - year1)*365 + (month2 - month1)*30 + day2 - day1;
    }
    return days;
}

int add_days_to_date(int date, int days){
    // add days to a date to create new date.

    int day = date/1000000;
    int month = (date/10000)%100;
    int year = date%10000;

    int new_day = day + days;
    int new_date = new_day*1000000 + month*10000 + year;
    // cout<<month<<" "<<day<<endl;
    while(! date_valid(new_date)){
        if (month == 1 || month==3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            if (new_day > 31){
                new_day = new_day - 31;
                month++;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11){
            if (new_day > 30){
                new_day = new_day - 30;
                month++;
            }
        }
        else if (month == 2){
            if ((year%4 == 0 && year%100 != 0) || year%400 == 0){
                if (new_day > 29){
                    new_day = new_day - 29;
                    month++;
                }
            }
            else{
                if (new_day > 28){
                    new_day = new_day - 28;
                    month++;
                }
            }
        }

        if (month > 12){
            month = month - 12;
            year++;
        }
        new_date = new_day*1000000 + month*10000 + year;
    }
    
    return new_date;
}

// int get_todays_date(){
//     time_t t=time(0);
//     tm* now = localtime(&t);
//     int year = now->tm_year + 1900;
//     int month = now->tm_mon + 1;
//     int day = now->tm_mday;
//     int date = day*1000000 + month*10000 + year;
//     return date;
// }