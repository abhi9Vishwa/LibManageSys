#ifndef PROFESSOR_H
#define PROFESSOR_H

#include<iostream>
#include<string>
#include<vector>

#include"user.h"
#include"book.h"

using namespace std;

class prof_student: public user{
    public:
        vector<book> issued_books;
        int label;
        // int num_books_issued;
        int fine_amount;
        int max_days;
        int fine_per_day;
    
        prof_student(int user_id, string username, string password, string name, book_database &books, int max_days, int fine_per_day,int label);
        int calculate_fine(int curr_date);
        // bool issue_book(string title, string author);
        bool return_book(int book_id,int curr_date);
        bool setlle_fine(); 
        

};

#endif