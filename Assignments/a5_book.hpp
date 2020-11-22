//*****************************************************************************
// Student Name: Jerry Tian, Neha Javed
// Student Number: 20894361, 20899460
//
// SYDE 121 Assignment: Assignment #5
// Filename: a5_book.hpp
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

#ifndef BOOK
#define BOOK

#include <iostream>
using namespace std;    

class Book {
    string title, author, dop;

public: 
    Book(); // default constructor, sets all attributes to n

    Book(string new_title, string new_author, string new_date_of_publication); // all three attributes

    Book(string new_title, string new_author); // only title and author, dop is set to n/a

    Book(string new_title); // only title, author and dop is set to n/a

    void print(); // output all values

    // setters

    void set_title (string new_title);

    void set_author (string new_author);
    
    void set_dop (string new_dop);

    // getters

    string get_title ();

    string get_author ();

    string get_dop ();
};

#endif