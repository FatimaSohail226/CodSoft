#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), isAvailable(true) {}
};

class Library {
private:
    vector<Book> books;
    map<string, time_t> borrowedBooks; 

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void searchBook(const string& query) {
        for (const auto& book : books) {
            if (book.title.find(query) != string::npos || book.author.find(query) != string::npos || book.ISBN == query) {
                cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
            }
        }
    }

    void checkOutBook(const string& ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN && book.isAvailable) {
                book.isAvailable = false;
                borrowedBooks[ISBN] = time(nullptr); 
                cout << "Book checked out successfully." << endl;
                return;
            }
        }
        cout << "Book not available." << endl;
    }

    void returnBook(const string& ISBN) {
        if (borrowedBooks.find(ISBN) == borrowedBooks.end()) {
            cout << "This book was not borrowed." << endl;
            return;
        }

        for (auto& book : books) {
            if (book.ISBN == ISBN) {
                book.isAvailable = true;
                time_t now = time(nullptr);
                double days = difftime(now, borrowedBooks[ISBN]) / (60 * 60 * 24);
                borrowedBooks.erase(ISBN);
                cout << "Book returned. ";

                if (days > 30) { 
                    double fine = (days - 30) * 0.5;
                    cout << "Fine for overdue: $" << fixed << setprecision(2) << fine;
                }
                cout << endl;
                return;
            }
        }
    }

    void run() {
        while (true) {
            int choice;
            cout << "\nLibrary Management System\n";
            cout << "1. Add Book\n";
            cout << "2. Search Book\n";
            cout << "3. Check Out Book\n";
            cout << "4. Return Book\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 5) break;

            string title, author, ISBN, query;
            switch (choice) {
                case 1:
                    cout << "Enter title: "; getline(cin, title);
                    cout << "Enter author: "; getline(cin, author);
                    cout << "Enter ISBN: "; getline(cin, ISBN);
                    addBook(Book(title, author, ISBN));
                    break;
                case 2:
                    cout << "Enter title, author, or ISBN to search: "; getline(cin, query);
                    searchBook(query);
                    break;
                case 3:
                    cout << "Enter ISBN to check out: "; getline(cin, ISBN);
                    checkOutBook(ISBN);
                    break;
                case 4:
                    cout << "Enter ISBN to return: "; getline(cin, ISBN);
                    returnBook(ISBN);
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    Library library;
    library.run();
    return 0;
}
