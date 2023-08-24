Implement Library Management System in C++ language using Object-oriented programming concepts. Implement the system on command line interface.


## Code Stucture
- The <a href="include/">include</a> folder contains all the header files, which contains different classes and functions.

- The <a href="src">src</a> folder contains all the source files, which contains definations of classes and functions, a header file which can be thought of as the frontend of the system,  and the <a href="src/main.cpp"> main.cpp</a> file containing the main function.

- The <a href="database" >database</a> folder contains 2 files: 
    - <a href="database/books.txt">books.txt</a>: contains the data of books, in the format: <br>
    book_id,title,author,isbn_number,publisher,currently_issued_to,last_issue_date. <br>
    - <a href="database/users.txt">users.txt</a>: contains the data of users, in the format: <br>
    user_id,username,password,name,label. <br>
    where label = 0 for librarian, 1 for student, 2 for professor.

    This data is loaded into the system at the start of the program.
- The <a href="config.yaml"> config.yaml</a> file contains some parameters such as max days for which a student/professor can issue a book, fine per day etc. .
- The <a href="CmakeLists.txt"> CmakeLists.txt</a> file contains the CMake commands to compile the code.


## Functionalities Implemented:

1. **Login** - using a username and password. The system identifies the role of user(librarian/student/admin) and redirects to the respective menu.

2. **Register** - Enter name, username, password and role. The system will add these registerations to the database only when librarian approves the user. For this librarian has to login into the system.

3. Librarian can perform the following operations:

    1. **Add Book**- add a new book to library.
    2. **Remove Book** - remove a book from library.
    3. **Update Book** - update the title/author of a book.
    4. **Add User** - add a new user to the library. 
    5. **Remove User** - remove a user from the library.
    6. **Update User** - update the name/username/password of a user.
    7. **Search Book** - search for a book in the library.
    8. **Search User** - search for a user in the library.
    9. **List Books** - list all the books in the library.
    10. **List Users** - list all the users in the library.

4. Student/Professor can perform the following operations:

    1. **Issue Book** - issue a new Book.
    2. **Return Book** - return a book to the library.
    3. **Search Book** - search for a book in the library.
    4. **Check book availability** - check the availability of a book.
    5. **List Books** - list all the books in the library.
    6. **See Total Fine** - see the total fine of the student.
    7. **List Books Issued** - list all the books issued by him/her.


## Classes Implemented:
1. **user_database** class - contains the data of users.
2. **book_database** class - contains the data of books.

3. **librarian** class - represents the librarian.
4. **prof_student** class - represents the student and the professor.
5. **user** class - represents the user, parent class of prof_student and librarian.
6. **book** class - represents the book.

I have made a single class for professor and student, because they have same functionalities only values of some parameters differs.



## Setup

```
git clone https://github.com/abhi9Vishwa/library_management_system.git
```
I have used cmake to build the code.

```
mkdir build && cd build/
```
```
cmake ..
```
This generates the makefile which can compile the code.

```
make
```

This generates the executable file "main".


## How to Run
```
./main
```
The code is run using the command line.

At any point in the program you can use the "help" command to see the list of availible commands.

The UserName, Password of librarian are "pkkl1234" and "sharma2022" respectively.
When librarian logins, the system firts display registration requests, and he/she can accept or reject them.


## Additional features:
- Case insensitive search.
- Search a book by title, author.
- Automatically generates todays date to calculate the fine.
