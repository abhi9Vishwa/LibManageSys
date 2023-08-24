#ifndef USER_DATABASE_H
#define USER_DATABASE_H

#include<iostream>
#include<string>
#include<vector>
#include"user.h"
#include"book_database.h"

using namespace std;


class user_database{
    public:
        vector<user>  users;
        int num_users;
        string file_name;

        // default constructor
        user_database();

        
        user_database(string user_txt_file);
        // ~user_database();
        
        void add_user(string name, string password, string username,int label);
        
        void delete_user(int user_id, book_database &books);

        // field = (0,1,2)=(username,password,name)
        void update_user(int user_id, int field_to_update, string new_value);
        
        // search user by name.
        vector<user> search_user_by_name(string name);
        user login_user(string username, string password);
        user search_user_by_id(int user_id);
        void save_data();
        
};

#endif