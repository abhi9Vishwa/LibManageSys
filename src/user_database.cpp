#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cassert>
#include<bits/stdc++.h>

#include"../include/user_database.h"
#include"../include/helper_functions.h"

using namespace std;

// default constructor
user_database::user_database(){
    this->num_users = 0;
}

user_database::user_database(string user_txt_file){
    file_name = user_txt_file;
    ifstream user_file(user_txt_file);
    string line;
    int user_id;
    string name;
    string password;
    string username;
    int label;

    while(getline(user_file, line)){
        vector<string> user_info = split_str_custom(line, ',');
        user_id = stoi(user_info[0]);
        username = user_info[1];
        password = user_info[2];
        name = user_info[3];
        label = stoi(user_info[4]);

        user new_user;
        
        new_user.user_id = user_id;
        new_user.name = name;
        new_user.password = password;
        new_user.username = username;
        new_user.label = label;

        users.push_back(new_user);

    }
    num_users = users.size();
    user_file.close();
}

void user_database::add_user(string name, string password, string username,int label){
    int user_id = users.back().user_id+1;
    user new_user;
    new_user.user_id = user_id;
    new_user.name = name;
    new_user.password = password;
    new_user.username = username;
    new_user.label = label;
    num_users++;
    users.push_back(new_user);
}

void user_database::delete_user(int user_id, book_database &books){
    for(int i=0;i<num_users;i++){
        if(users[i].user_id == user_id){
            users.erase(users.begin()+i);
            num_users--;
            for(int j=0;j<books.num_books;j++){
                if(books.books[j].issued_to == user_id){
                    books.books[j].issued_to = 0;
                    books.books[j].last_issue_date = 0;
                }
            }
            break;
        }
    }
}

void user_database::update_user(int user_id, int field_to_update, string new_value){
    for(int i=0;i<num_users;i++){
        if(users[i].user_id == user_id){
            if(field_to_update == 0){
                users[i].username = new_value;
            }
            else if(field_to_update == 1){
                users[i].password = new_value;
            }
            else if(field_to_update == 2){
                users[i].name = new_value;
            }
            break;
        }
    }
}

vector<user> user_database::search_user_by_name(string name){
    transform(name.begin(),name.end(),name.begin(),::tolower);
    string temp;
    vector<user> found_users;
    for(int i=0; i<users.size(); i++){
        temp = users[i].name;
        transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        // cout<<temp<<", "<<name<<endl;
        if(temp==name){
            found_users.push_back(users[i]);
        }
    }
    return found_users;
}

user user_database::login_user(string username, string password){
    for(int i=0; i<users.size(); i++){
        if(users[i].username==username && users[i].password==password){
            return users[i];
        }
    }
    user dummy_user;
    return dummy_user;
}

user user_database::search_user_by_id(int user_id){
    for(int i=0; i<users.size(); i++){
        if(users[i].user_id==user_id){
            return users[i];
        }
    }
    user dummy_user;
    return dummy_user;
}

void user_database::save_data(){
    ofstream user_file(file_name);
    for(int i=0; i<users.size(); i++){
        user_file << users[i].user_id << "," << users[i].username << "," << users[i].password << "," << users[i].name << "," << users[i].label << endl;
    }
    user_file.close();
}