#include "lib.h"

class Book {
public:
	string title;
	string author;
	string isbn;

	Book() = default;
	Book(const string& title, const string& author, const string& isbn) : title(title), author(author), isbn(isbn){

	}
	void display() {
		cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << '\n';
	}
};
		
