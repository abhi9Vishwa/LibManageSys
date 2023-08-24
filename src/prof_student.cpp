#include"../include/prof_student.h"
#include"../include/helper_functions.h"

using namespace std;


prof_student::prof_student(int user_id, string username, string password, string name, book_database &books,int max_days, int fine_per_day,int label){
    this->user_id = user_id;
    this->username = username;
    this->password = password;
    this->name = name;
    this->label = 2;
    this->all_books = books;
    this->fine_amount = 0;
    this->max_days = max_days;
    this->fine_per_day = fine_per_day;
    this->label = label;

    // find issued books:
    for (int i = 0; i < this->all_books.books.size(); i++){
        if (this->all_books.books[i].issued_to == this->user_id){
            this->issued_books.push_back(this->all_books.books[i]);
        }
    }
}

int prof_student::calculate_fine(int curr_date){
    int fine_amount = 0;
    
    for (int i = 0; i < this->issued_books.size(); i++){
        // cout<<num_days(this->issued_books[i].last_issue_date, curr_date)<<endl;
        if(num_days(this->issued_books[i].last_issue_date, curr_date) > this->max_days){
            // cout<<num_days(this->issued_books[i].last_issue_date, curr_date) - this->max_days<<" "<<this->fine_per_day<<endl;
            fine_amount += this->fine_per_day*(num_days(this->issued_books[i].last_issue_date, curr_date) - this->max_days);
        }
    }

    this->fine_amount = fine_amount;
    return fine_amount;
}

bool prof_student::setlle_fine(){
    if (this->fine_amount == 0){
        return false;
    }
    else{
        return true;
    }
}

bool prof_student::return_book(int book_id,int curr_date){
    for (int i = 0; i < this->issued_books.size(); i++){
        if (this->issued_books[i].book_id == book_id){
            this->issued_books.erase(this->issued_books.begin() + i);
            
            // settle fine
            if(num_days(this->issued_books[i].last_issue_date, curr_date) > this->max_days){
                fine_amount -= this->fine_per_day*(num_days(this->issued_books[i].last_issue_date, curr_date) - this->max_days);
            }
            return true;

        }
    }
    return false;
}
