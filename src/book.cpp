#include <iostream>
#include <string>
#include <vector>

#include "../include/book.h"
#include"../include/helper_functions.h"

#define PROF_MAX_DAYS 60
#define STUD_MAX_DAYS 30

using namespace std;

// default constructor
book::book(){
    book_id = 0;
    title = "";
    author = "";
    issued_to = 0;
    last_issue_date = 0;
}

book::book(int book_id, string title, string author,int isbn, string publication, int issued_to, int last_issue_date) {
    this->book_id = book_id;
    this->title = title;
    this->author = author;
    this->issued_to = issued_to;
    this->last_issue_date = last_issue_date;
    this->isbn = isbn;
    this->publication = publication;
}

int book::due_date(int label_issuer){
    int due_date;
    if(label_issuer == 2){
        due_date = add_days_to_date(last_issue_date, PROF_MAX_DAYS);
    }
    else if(label_issuer == 1){
        due_date = add_days_to_date(last_issue_date, STUD_MAX_DAYS);
    }
    else
        due_date = 0;
    
    return due_date;
}

bool book::is_available(){
    if(this->issued_to == 0)
        return true;
    else
        return false;
}

void book::print_details(){
    cout<<"Book ID: "<<this->book_id<<" "<<"Title: "<<this->title<<" "<<"Author: "<<this->author<<" "<<"Last issue date: "<<this->last_issue_date<<endl;
}