#ifndef DOMAIN_H
#define DOMAIN_H

#include "lib.h"

class Book {
public:
    string title;
    string author;
    string isbn;

    Book() = default;
    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << '\n';
    }
};

class Author {
public:
    string name;
    string nationality;

    Author() = default;
    Author(const string& n, const string& nat)
        : name(n), nationality(nat) {}

    void display() const {
        cout << "Name: " << name << ", Nationality: " << nationality << '\n';
    }
};

class Reader {
public:
    string name;
    int readerId;
    int borrowedBooks;

    Reader() = default;
    Reader(const string& n, int id, int b)
        : name(n), readerId(id), borrowedBooks(b) {}

    void display() const {
        cout << "Name: " << name << ", ID: " << readerId << ", Borrowed books: " << borrowedBooks << '\n';
    }
};

class Librarian {
public:
    string name;
    int librarianId;

    Librarian() = default;
    Librarian(const string& n, int id)
        : name(n), librarianId(id) {}

    void display() const {
        cout << "Librarian Name: " << name << ", ID: " << librarianId << '\n';
    }
};

class Loan {
public:
    int readerId;
    string bookIsbn;
    string dueDate;

    Loan() = default;
    Loan(int rId, const string& bIsbn, const string& dDate)
        : readerId(rId), bookIsbn(bIsbn), dueDate(dDate) {}

    void display() const {
        cout << "Reader ID: " << readerId << ", Book ISBN: " << bookIsbn << ", Due Date: " << dueDate << '\n';
    }
};

class Library {
private:
    vector<Book> books;
    vector<Reader> readers;
    vector<Loan> loans;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addReader(const Reader& reader) {
        readers.push_back(reader);
    }

    void addLoan(const Loan& loan) {
        loans.push_back(loan);
    }

    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }

    void displayReaders() const {
        for (const auto& reader : readers) {
            reader.display();
        }
    }

    void displayLoans() const {
        for (const auto& loan : loans) {
            loan.display();
        }
    }
};
#endif DOMAIN_H