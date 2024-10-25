#pragma once
#include "lib.h"

class Book {
public:
	string title;
	string author;
	string ISBN;

	Book() = default;
	Book(const string& title, const string& author, const string& ISBN) : title(title), author(author), ISBN(ISBN){

	}
	void display();
};
		
