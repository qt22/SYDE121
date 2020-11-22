//*****************************************************************************
// Student Name: Jerry Tian, Neha Javed
// Student Number: 20894361, 20899460
//
// SYDE 121 Assignment: Assignment #5
// Filename: a5_main.cpp
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

/* 
    Test cases: 
    
    create book objects with different constructors

    print the book object details with print() function and getters

    set the book properties of an existing book object with setters

    create library objects with different constructors

    insert new books into the library by passing books
    
    insert new books into the library by passing book properties (title, author, dop)

    insert duplicate books into the library to check how the program handles it 

    print out both types of insertion by calling print() function in the Library class

    remove books from the library by passing books 

    remove books from the library by passing book properties (title, author, dop)

    remove a book that is never inserted to check how the program handles it
    
    Limitations: 

    n/a
*/

#include <iostream>
#include <vector>

#include "a5_book.hpp"
#include "a5_library.hpp"

using namespace std;


// Default Constructor: title, author, dop n/a
Book::Book () {
    title = "n/a";
    author = "n/a";
    dop = "n/a";
}
// title, author, dop are given
Book::Book (string new_title, string new_author, string new_date_of_publication)
{
    title = new_title;
    author = new_author;
    dop = new_date_of_publication;
}
// dop n/a
Book::Book (string new_title, string new_author)
{
    title = new_title;
    author = new_author;
    dop = "n/a";
}
// author, dop n/a
Book::Book (string new_title)
{
    title = new_title;
    author = "n/a";
    dop = "n/a";
}

// print function for Book
void Book::print() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Date: " << dop << endl;
    
}

// setters 

void Book::set_title(string new_title){
    title = new_title;
}

void Book::set_author(string new_author){
    author = new_author;
}

void Book::set_dop(string new_dop){
    dop = new_dop;
}

// getters

string Book::get_title(){
    return title;
}

string Book::get_author(){
    return author;
}

string Book::get_dop(){
    return dop;
}

// default constructor for library
Library::Library () {
    const int MAX = 1000;
    books.reserve(MAX); // reserve 1000 book slots in the library
}

Library::Library (vector<Book> new_books) {
    // add new books to the end of the book array
    for(int i = 0; i < new_books.size(); i++){
        books.push_back(new_books[i]);
    }
}

void Library::print() {
    //cout << books.size();
    for(int i = 0; i < books.size(); i++){
        books[i].print(); // use the print() function in Book object to print out details
        cout.put('\n'); // add '\n' to leave a blank line
    }
}

bool Library::insert(string title, string author, string dop){
    Book book(title, author, dop); // create a new book object
    bool compare = false;

    // compare title, author and dop with every book in the library
    for (int i = 0; i < books.size(); i++)
    {
        compare = title == books[i].get_title() &&
                  author == books[i].get_author() &&
                  dop == books[i].get_dop();
        if(compare){
            return false;
        }
    }
    
    books.push_back(book); // add the book into the library
    return true;
}

bool Library::insert(Book book){
    bool compare = false;

    // compare title, author and dop with every book in the library
    for (int i = 0; i < books.size(); i++)
    {
        compare = book.get_title() == books[i].get_title() &&
                  book.get_author() == books[i].get_author() &&
                  book.get_dop() == books[i].get_dop();
        if(compare){
            return false;
        }
    }

    books.push_back(book); // add the book into the library
    return true;
}

bool Library::remove (string title, string author, string dop)
{
    Book book(title, author, dop);
    vector<Book>::iterator itr = books.begin(); // iterator set to the beginning of the vector
    bool check_library = false;

    // compare title, author and dop with every book in the library
    for (int i = 0; i < books.size(); ++i) 
    {
        check_library = title == books[i].get_title() &&
                        author == books[i].get_author() &&
                        dop == books[i].get_dop();
        if (check_library) 
        {
            books.erase(itr); // removes selected book from the library
            return true;
        }

        itr++;
    }
    
    return false;
}

bool Library::remove (Book book) 
{   
    bool check_library = false;
    vector<Book>::iterator itr = books.begin(); // iterator set to the beginning of the vector
    
    // compare title, author and dop with every book in the library
    for (int i = 0; i < books.size(); ++i) 
    {
        check_library = book.get_title() == books[i].get_title() &&
                        book.get_author() == books[i].get_author() &&
                        book.get_dop() == books[i].get_dop();
        if (check_library) 
        {
            books.erase(itr); // removes selected book from the library
            return true;
        }
        itr++;
    }
    
    return false;
}

Library test_book_insertion(){
    // test case: default Library constructor
    Library empty_lib;

    Book instruction; // test case: Book default constructor
    cout << instruction.get_title() << " " << instruction.get_author() << " " << instruction.get_dop() << endl;

    Book textbook1("igor"); // test case: title only
    textbook1.print();

    Book manga("haikyuu", "jt"); // test case: title and author, no dop
    manga.print();

    Book scifi_novel("foundation", "issac asimov", "1942"); // test case: title, author and dop
    cout << scifi_novel.get_title() << " " << scifi_novel.get_author() << " " << scifi_novel.get_dop() << endl;

    cout.put('\n');

    // test case: insertion with given book object
    empty_lib.insert(instruction);
    empty_lib.insert(manga);
    empty_lib.insert(textbook1);
    empty_lib.insert(scifi_novel);
    empty_lib.insert(manga); // duplicate insertion

    empty_lib.print();

    cout.put('\n');





    
    // test case: setters
    Book movie("Inception");
    movie.set_title("StarWars");
    movie.set_author("george lucas");
    movie.set_dop("1976");

    // test case: Library with given vector of books
    vector<Book> books;
    books.push_back(movie);
    books.push_back(instruction);
    books.push_back(textbook1);
    books.push_back(manga);
    books.push_back(scifi_novel);
    Library rich_lib(books);

    // test case: insertion with given title, author, dop
    rich_lib.insert("1984", "go", "1984");
    rich_lib.insert("foundation", "issac asimov", "1942"); // duplicate insertion
    
    rich_lib.print();
    
    return empty_lib; // pass the library to the test_book_removal() function
}


void test_book_removal() {
    Library rich_lib = test_book_insertion();
    
    Book instruction; // test case: default constructor
    cout << instruction.get_title() << " " << instruction.get_author() <<  " " << instruction.get_dop() << endl;
    
    Book textbook1("igor"); // test case: title only
    textbook1.print();

    Book textbook2("spiderman"); // test case: invalid entry (book does not exist in the library)
    textbook2.print();

    Book manga("haikyuu", "jt"); // test case: title and auhor are given (no dop)
    manga.print();

    Book scifi_novel("foundation", "issac asimov", "1942"); // // test case: title, auhor and dop are given
    cout << scifi_novel.get_title() << " " << scifi_novel.get_author() << " " << scifi_novel.get_dop() << endl;

    cout.put('\n');
    
    // test case: removal with given book object
    cout << rich_lib.remove(instruction);
    cout << rich_lib.remove(textbook1);
    cout << rich_lib.remove(textbook2); // removal of bool that does not exist in library
    cout << rich_lib.remove(manga);
    cout << rich_lib.remove(scifi_novel);

    rich_lib.print();
    
    cout.put('\n');

}

int main () {
    test_book_removal(); // test_book_insertion is called at the top of test_book_removal
}