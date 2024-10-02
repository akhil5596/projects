#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    int id;
    bool isIssued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }

        cout << "Available books:\n";
        for (auto &book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author;
            if (book.isIssued) {
                cout << " [Issued]";
            }
            cout << endl;
        }
    }

    void searchBookById(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                cout << "Book found!\n";
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author;
                if (book.isIssued) {
                    cout << " [Issued]";
                }
                cout << endl;
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void issueBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    cout << "Book is already issued.\n";
                } else {
                    book.isIssued = true;
                    cout << "Book issued successfully!\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    cout << "Book is not issued.\n";
                } else {
                    book.isIssued = false;
                    cout << "Book returned successfully!\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            cout << "Enter Book ID to search: ";
            cin >> id;
            library.searchBookById(id);
            break;
        case 4:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            library.issueBook(id);
            break;
        case 5:
            cout << "Enter Book ID to return: ";
            cin >> id;
            library.returnBook(id);
            break;
        case 6:
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
