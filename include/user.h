#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>

#include"book_database.h"

using namespace std;


typedef struct Book_Detail{
    int book_id;
    string title;
    string author;
}book_detail;

class user{
    public:
        int user_id;
        string name;
        string password;
        string username;
        int label;

        int _get_book_id(string title, string author);
        book_database all_books;
        // user(int user_id, string username, string password, string name,int label, book_database &books);

        // default constructor
        user();
        // copy constructor
        user(const user &user);

        vector<book> search_book_by_title(string title);
        vector<book> search_book_by_author(string author);
        
        // list book
        vector<book_detail> list_all_books();
        bool is_available(string title, string author);
        int due_date(string title, string author);
        void print_details();
    
};

#endif