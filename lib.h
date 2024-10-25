#ifndef LIB_H 
#define LIB_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "domain.h"

using namespace std;

vector<Book> loadBooks(const string& filename) {
    vector<Book> books;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << '\n';
        return books;
    }
    string line, title, author, isbn;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, isbn, ',');
        books.emplace_back(title, author, isbn);
    }
    return books;
}

vector<Reader> loadReaders(const string& filename) {
    vector<Reader> readers;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << '\n';
        return readers;
    }
    string line, name;
    int readerId, borrowedBooks;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        ss >> readerId;
        ss.ignore(); 
        ss >> borrowedBooks;
        readers.emplace_back(name, readerId, borrowedBooks);
    }
    return readers;
}

vector<Loan> loadLoans(const string& filename) {
    vector<Loan> loans;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << '\n';
        return loans;
    }
    string line, bookIsbn, dueDate;
    int readerId;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> readerId;
        ss.ignore();  
        getline(ss, bookIsbn, ',');
        getline(ss, dueDate, ',');
        loans.emplace_back(readerId, bookIsbn, dueDate);
    }
    return loans;
}
#endif LIB_H