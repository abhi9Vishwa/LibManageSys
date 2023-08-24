#ifndef BOOK_DATABASE_H
#define BOOK_DATABASE_H

#include<iostream>
#include<string>
#include<vector>

#include"book.h"

using namespace std;

class book_database{
    public:
        vector<book> books;
        int num_books;
        string file_name;

        // default constructor
        book_database();
        // copy constructor
        book_database(book_database &books);

        book_database(string book_txt_file);
        // ~book_database();

        void add_book(string title, string author, int isbn, string pub);
        void delete_book(int book_id);

        // field = (0,1,2)=(title, author, publication)
        void update_book(int book_id, int field_to_update, string new_value);

        void issue_book(int book_id, int student_id, int date);

        vector<book> search_book_by_title(string title);
        vector<book> search_book_by_author(string author);
        book search_book(string title, string author);
        book search_book_by_id(int book_id);

        void save_data();

};

#endif