//*****************************************************************************
// Student Name: Jerry Tian, Neha Javed
// Student Number: 20894361, 20899460
//
// SYDE 121 Assignment: Assignment #5
// Filename: a5_library.hpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Library
// Purpose: Simulate a library using Object Oriented Programming
// Due Date: Friday, November 20, 2020
//**************************************************************

#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <string>
#include <vector>

#include "a5_book.hpp"

using namespace std;

class Library {
    vector<Book> books;

public:
    Library(); // default constructor

    Library(vector<Book> new_books); // take input new_books and store it in books 

    void print(); // access Book::print() to output books 

    // insert a new book into the library where title, author and dop are provided
    bool insert(string title, string author, string dop); 
    
    bool insert(Book book); // insert a new book into the library with a given book object

    // removing selected book from library where title, author and dop are provided
    bool remove(string title, string author, string dop);

    // removes book from the library with given book objcet
    bool remove (Book book);
};

#endif