//
//  bookType.hpp
//  PR-1
//
//  Created by Marcus Shaw on 9/16/23.
//

#ifndef bookType_hpp
#define bookType_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class bookType {
private:
    //These are all the variables that are a part of the object.
    string title;
    string publisher;
    string isbn;
    int year;
    double price;
    int quantity;
    int numAuthors;
    string authors[4]; // I declare this array as 4 as the max authors can be 4. A dynamic array seems a little much for 4 max.
    
public:
    bookType (const string a = "0", const string b = "0", const int c = 0, const double d = 0,
              const int e = 0, const int f = 0, const string g = "0", const string h = "0"); // this is the default constructor
    void setTitle(const string a); // these two are to set and get the string stored in title
    string getTitle();
    
    void setPublisher(const string a); // these two are to set and get the string stored in publisher
    string getPublisher();
    
    void setIsbn(const string a); // these two are to set and get the string stored in isbn
    string getIsbn();
    
    void setYear(const int a); // these two are to set and get the int that is stored in year
    int getYear();
    
    void setPrice(const double a); // these two are to set and get the double that is stored in price
    double getPrice();
    
    void setQuantity(const int a); // these two are to set and get the int that is stored in quantity
    int getQuantity();
    
    void setNumAuthors(const int a); // these two are to set and get the int that is stored in numAuthors
    int getNumAuthors();
    
    void setAuthors(const string a, const int b); // these two are to set and get the array of strings stored in authors
    void print(); // this is to print out the whole object
    void printTitleIsbn(); // this is to print out only the title and isbn of the object
    
    
    
};

#endif /* bookType_hpp */
