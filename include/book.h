#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;


class book{
    public:
        int book_id;
        string title;
        string author;
        // string publisher;
        int issued_to;
        int last_issue_date;
        int isbn;
        string publication;
        
        // default constructor
        book();

        book(int book_id, string title, string author,int isbn, string publication, int issued_to, int last_issue_date);
        
        int due_date(int label_issuer);
        
        bool is_available();

        void print_details();
};

#endif