#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include<iostream>
#include<string>
#include<vector>

#include"user.h"
#include"book.h"
#include"user_database.h"
#include"book_database.h"

using namespace std;

class librarian:public user{
    public:
        user_database all_users;

        librarian();

        librarian(user_database &users, book_database &books, int user_id);
        
        void add_user(string name, string password, string username,int label);
        
        void delete_user(int user_id);
        
        // field = (0,1,2)=(username,password,name
        void update_user(int id, int field_to_update, string new_value);
        
        vector<user> list_users();

        void add_book(string title, string author,int isbn,string pub);

        void delete_book(int book_id);

        // field = (0,1)=(title, author)
        void update_book(int book_id, int field_to_update, string new_value);

        void issue_book(vector<int> book_ids, vector<int> student_ids, vector<int> dates);

};


#endif