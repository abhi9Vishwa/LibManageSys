#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> split_str_custom(string str, char delimiter);

int num_days(int date1, int date2);

int add_days_to_date(int date, int days);

bool date_valid(int date);

#endif