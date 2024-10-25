#include "domain.h"
#include "lib.h"

int main() {
    Library library;

    vector<Book> books = loadBooks("data/books.csv");
    for (const auto& book : books) {
        library.addBook(book);
    }

    vector<Reader> readers = loadReaders("data/readers.csv");
    for (const auto& reader : readers) {
        library.addReader(reader);
    }

    vector<Loan> loans = loadLoans("data/loans.csv");
    for (const auto& loan : loans) {
        library.addLoan(loan);
    }

    cout << "Books in library:\n";
    library.displayBooks();

    cout << "\nReaders in library:\n";
    library.displayReaders();

    cout << "\nLoans:\n";
    library.displayLoans();

    return 0;
}
