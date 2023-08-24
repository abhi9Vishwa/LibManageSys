#include"../include/student.h"
#include"../include/helper_functions.h"

using namespace std;

#define FINE_PER_DAY 5
#define MAX_DAYS 30


student::student(int user_id, string username, string password, string name, book_database &books){
    this->user_id = user_id;
    this->username = username;
    this->password = password;
    this->name = name;
    this->label = 1;
    this->all_books = books;
    this->fine_amount = 0;

    // find issued books:
    for (int i = 0; i < this->all_books.books.size(); i++){
        if (this->all_books.books[i].issued_to == this->user_id){
            this->issued_books.push_back(this->all_books.books[i]);
        }
    }
}

int student::calculate_fine(int curr_date){
    int fine_amount = 0;
    
    for (int i = 0; i < this->issued_books.size(); i++){
        if(num_days(this->issued_books[i].last_issue_date, curr_date) > MAX_DAYS){
            fine_amount += FINE_PER_DAY*(num_days(this->issued_books[i].last_issue_date, curr_date) - MAX_DAYS);
        }
    }

    this->fine_amount = fine_amount;
    return fine_amount;
}

bool student::return_book(string title, string author,int curr_date){
    for (int i = 0; i < this->issued_books.size(); i++){
        if (this->issued_books[i].title == title && this->issued_books[i].author == author){
            this->issued_books.erase(this->issued_books.begin() + i);
            
            if(num_days(this->issued_books[i].last_issue_date, curr_date) > MAX_DAYS){
                fine_amount -= FINE_PER_DAY*(num_days(this->issued_books[i].last_issue_date, curr_date) - MAX_DAYS);
            }

            return true;
        }
        
    }
    return false;
}

bool student::setlle_fine(){
    if (this->fine_amount == 0){
        return false;
    }
    else{
        return true;
    }
}