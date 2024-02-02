//
//  BookType.cpp
//  PR-1
//
//  Created by Marcus Shaw on 9/16/23.
//

#include "bookType.hpp"
using namespace std;
// Default constructor
bookType::bookType (const string a,  const string b, const int c, const double d,const int e, const int f, const string g, const string h) {
    setTitle(a);
    setIsbn(b);
    setYear(c);
    setPrice(d);
    setQuantity(e);
    setNumAuthors(f);
    authors[0] = g;
    authors[1] = g;
    authors[2] = g;
    authors[3] = g;
    setPublisher(h);
}
void bookType::setTitle(const string a) {
    title = a;
}
string bookType::getTitle(){
    return title;
}

void bookType::setPublisher(const string a) {
    publisher = a;
}
string bookType::getPublisher() {
    return publisher;
}

void bookType::setIsbn(const string a) {
    isbn = a;
}
string bookType::getIsbn() {
    return isbn;
}

void bookType::setYear(const int a) {
    year = a;
}
int bookType::getYear() {
    return year;
}

void bookType::setPrice(const double a) {
    price = a;
}
double bookType::getPrice() {
    return price;
}

void bookType::setQuantity(const int a) {
    quantity = a;
}
int bookType::getQuantity() {
    return quantity;
}

void bookType::setNumAuthors(const int a) {
    numAuthors = a;
}
int bookType::getNumAuthors() {
    return numAuthors;
}

void bookType::setAuthors(const string a, const int b) {
    if(b > 4) {
        cout << "Error more authors than the max";
        throw;
    }
    authors[b] = a;
}

void bookType::print() {
    cout << "Title: " << title << '\n'
    << "ISBN: " << isbn << '\n'
    << "publisher: " << publisher << '\n'
    << "Year of publication: " << year << '\n'
    << "Number of Authors: " << numAuthors << '\n'
    << "Authors: ";
    for(int i = 0; numAuthors > i; i++) {
        if(i != numAuthors - 1) {
            cout << authors[i] << "; ";
        }
    }
    cout << authors[numAuthors - 1] << '\n'
    << "Price: " << price << '\n'
    << "Quantities in stock: " << quantity << '\n'
    <<"---------------------------" << '\n';
}
void bookType::printTitleIsbn() {
    cout << "Title: " << title << "; ISBN: " << isbn << '\n' << '\n';
}
