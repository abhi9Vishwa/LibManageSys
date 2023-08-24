cmake_minimum_required( VERSION 3.0)
project(LMS)

include_directories(./include)

add_executable(main ./src/main.cpp ./src/helper_functions.cpp ./src/user.cpp ./src/user_database.cpp ./src/book.cpp ./src/book_database.cpp ./src/librarian.cpp ./src/prof_student.cpp . ./src/display_functions.hpp)