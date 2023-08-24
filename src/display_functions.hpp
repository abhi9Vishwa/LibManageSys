#ifndef DISPLAY_H
#define DISPLAY_H

#include<bits/stdc++.h>
#include<book_database.h>
#include<book.h>
#include<user.h>
#include<user_database.h>
#include<librarian.h>
#include<prof_student.h>
#include<student.h>


using namespace std;

void display_date(int date){
    cout<<date/1000000<<"/"<<(date/10000)%100<<"/"<<date%10000;
}

void invalid_dtype(){
    
    cout << "ERROR -- You entered an invalid data type."<<endl;
    cin.clear(); 
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



void book_availiabilty(string username,book_database &all_books, user_database &all_users){
    cout<<username<<"/ >";
    cout<<"Book ID: ";
    int book_id;
    cin>>book_id;
    if(cin.fail()){
        invalid_dtype();
        return;
    }
    book book_avail = all_books.search_book_by_id(book_id);
    if(book_avail.book_id==0){
        cout<<username<<"/ >";
        cout<<"Book not found.\n";
    }
    else{
        int user_id_issuer = book_avail.issued_to;
        user issuer = all_users.search_user_by_id(user_id_issuer);
        if(book_avail.is_available()){
            cout<<username<<"/ >";
            cout<<"Book is available.\n";
        }
        else{
            cout<<username<<"/ >";
            cout<<"Book is not available.\n";
            cout<<"Due Date: ";
            display_date(book_avail.due_date(issuer.label));
            cout<<endl;
        }
    }
}


void issue_book(string username,int user_id,book_database &all_books, user_database &all_users,int curr_date, prof_student &user_ps){
    cout<<username<<"/ >";
    cout<<"Book ID: ";
    int book_id;
    cin>>book_id;
    if(cin.fail()){
        invalid_dtype();
    }
    book book_avail = all_books.search_book_by_id(book_id);
    if(book_avail.book_id==0){
        cout<<username<<"/ >";
        cout<<"Book not found.\n";
    }
    else{
        int user_id_issuer = book_avail.issued_to;
        user issuer = all_users.search_user_by_id(user_id_issuer);
        if(book_avail.is_available()){
            cout<<username<<"/ >";
            all_books.issue_book(book_id,user_id,curr_date);
            cout<<"Book issued.\n";
            user_ps.issued_books.push_back(all_books.search_book_by_id(book_id));
        }
        else{
            cout<<username<<"/ >";
            cout<<"Book is not available.\n";
            cout<<"Due Date: ";
            display_date(book_avail.due_date(issuer.label));
            cout<<endl;
        }
    }
}


void display_books(vector<book> books){
    cout<<books.size()<<" books found"<<endl;
    string status;
    int date;
    for(int i=0;i<books.size();i++){
        if(books[i].is_available()){
            status = "Available";
        }
        else{
            status = "Issued";
        }
        cout<<"BOOK ID: "<<books[i].book_id<<", TITLE: "<<books[i].title<<", AUTHOR: "<<books[i].author<<", STATUS: "<<status<<", ISSUED ON: ";
        date = books[i].last_issue_date;
        display_date(date);
        cout<<endl;
    }
}

void display_users(vector<user> users){
    cout<<users.size()<<"users found"<<endl;
    for(int i=0;i<users.size();i++){
        cout<<"USER ID: "<<users[i].user_id<<", NAME: "<<users[i].name<<", USERNAME: "<<users[i].username<<endl;
    }
}


void book_by_title(string username, book_database &all_books){
    cout<<username<<"/ >";
    cout<<"Title of the book: ";
    string title;
    cin.ignore();
    getline(cin,title);
    vector<book> books = all_books.search_book_by_title(title);
    display_books(books);
}

void book_by_author(string username, book_database &all_books){
    cout<<username<<"/ >";
    cout<<"Author of the book: ";
    string author;
    cin.ignore();
    getline(cin,author);
    vector<book> books = all_books.search_book_by_author(author);
    display_books(books);
}

void print_help_non_lib(){
    cout<<"help- show this help message"<<endl;
    cout<<"logout- exit the program"<<endl;
    cout<<"list_issued_books- list all the books issued by the you"<<endl;
    cout<<"list_books- list all the books in the library"<<endl;
    cout<<"search_book_title- search for a book by title"<<endl;
    cout<<"search_book_author- search for a book by author"<<endl;
    cout<<"show_total_fine- show the total fine of the user"<<endl;
    cout<<"check_book_avail- check if a book is available"<<endl;
    cout<<"issue_book- issue a book"<<endl;
    cout<<"return_book- return a book"<<endl;
}

#endif