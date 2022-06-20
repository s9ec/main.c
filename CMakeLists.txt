cmake_minimum_required(VERSION 3.20)
project(library02 C)

set(CMAKE_C_STANDARD 11)

add_executable(library02
        book_management.h
        book_management.c
        first.c
        users.h
        users.c
        check.c
        check.h
        borrow_return.c
        borrow_return.h
        first.h
        enroll_login.c
        enroll_login.h
        )
