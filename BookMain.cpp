//
//  bookMain.cpp
//  PR-1
//
//  Created by Marcus Shaw on 9/16/23.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "bookType.hpp"
#include <vector>

using namespace std;

int main() {
    vector<bookType> a; // this is th vector of the objects
    bookType b; // this is to transfer the objects into the vector more easily
    string holder; // this is to gather the string from the user input
    int x; // this is to gather int's from user input. later this is used to tell if the user inputted a 0
    double y; // this is used for user input gathering of doubles
    ifstream myFile; // this is for opening the .txt file
    myFile.open("bookdata.txt");
    if(!myFile.is_open()) { // this returns if the file is not able to open
        cout << "Error could not find bookdata.txt" << '\n';
        return 1;
    }
    getline(myFile, holder); // this is so that it gathers the first line so I can clear the buffer of the last line more easily
    while (myFile) { // this just gathers all of the variables that are in each object
        b.setTitle(holder);
        getline(myFile, holder);
        b.setIsbn(holder);
        getline(myFile, holder);
        b.setPublisher(holder);
        myFile >> x;
        b.setYear(x);
        myFile >> y;
        b.setPrice(y);
        myFile >> x;
        b.setQuantity(x);
        myFile >> x;
        b.setNumAuthors(x);
        getline(myFile, holder);
        for(int i = 0; b.getNumAuthors() > i; i++) {
            getline(myFile, holder);
            b.setAuthors(holder, i);
        }
        a.push_back(b);
        getline(myFile, holder);
    }
    myFile.close(); // closes the file after I am done using it
    x = 5;
    double dbltest; // this is used to test whether or not they have entered a fraction. as int's would round to the nearest number
    while(x != 0 ) {
        cout << "++++ Wecome to LAVC's Book Store +++++" << '\n';
        cout << "To make a selection, enter the number and press enter" << '\n' << "1: Print Information of all the books." << '\n' << "2: Print a list of the books by titles and ISBN numbers." << '\n' <<"3: search a book by ISBN." << '\n' << "0: Exit Program." << '\n' << '\n';
        cin >> dbltest;
        x = dbltest;
        if(dbltest != x ) { // this is the test of whether or not the number entered was a fraction
            x = 5;
        }
        if(x == 1) { // this is the first option choice of output which is of all the books
            for(int i = 0; a.size() > i; i++) {
                a[i].print();
            }
            cout << "Unique book title counted: " << a.size() << '\n' << '\n';
        }
        else if( x == 2) { // this is the second option for output which is the titles and isbn
            for(int i = 0; a.size() > i; i++) {
                a[i].printTitleIsbn();
                cout << '\n';
            }
        }
        else if (x == 3) {
            cout << "Enter book ISBN: "; // this is to search for the book based off of isbn
            getline(cin, holder); // this is to clear the user input
            getline(cin, holder);
            for(int i = 0; a.size() > i; i++) {
                if(a[i].getIsbn() == holder) {
                    cout << "Book found +++++++++" << '\n';
                    a[i].print();
                    break;
                }
                else if(i == a.size()- 1) {
                    cout << "Sorry, this book is not on the list." << '\n';
                }
            }
        }
        else if(x != 0 ) { // this is used to tell the used that they have inputted an invalid option 
            cout << "Invalid input" << '\n';
        }
        
    }
    cout << "Thank you for visting the Book Store!" << '\n';
    return 0;
}
