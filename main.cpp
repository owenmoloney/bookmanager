#include <cstdlib>
#include <iostream>
#include "libraries/books.cpp"
using namespace std;
enum options {
    error = -1,
    quit = 0,
    addBook = 1,
    removeBook,
    searchBook,
    searchAuthor,
    listAllBooks,
    listAllAuthors,
};

istream& operator>>(istream& is, options& option)
{
    int usr;
    is>>usr;
    option = static_cast<options>(usr);
    return is;
}
options askNicely(){

    options choice;
    while(true){
    cout << "choose action" << "\n";
    cout << "0 > quit" << "\n"
        << "1 > add new book" << "\n"
        << "2 > remove existing book" << "\n"
        << "3 > search for book" << "\n"
        << "4 > search author" << "\n"
        << "5 > display all books" << "\n"
        << "6 > display all authors" << "\n";
    cin >> choice;

    if (!cin) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number.\n";
        continue;
    }

    if (choice < quit || choice > listAllAuthors) {
        cout << "Invalid choice. Try again.\n";
        continue;
    }


    return choice;
    }
}

int main()
{
    bool running = true;
    while (running)
    {

        options option = askNicely();
        switch(option)
        {
            case addBook:
            {
                Book::manage manager;
                Book newBook;
                manager.addBook(newBook);
                manager.saveBook(newBook);
                break;
            }
            
            //Second Edit --> Make an effort to keep the user interaction seperate from the data handling
            case removeBook:
            {
                cout << "Enter ID of the book to remove: ";
                unsigned int bookId;
                cin >> bookId;
                Book::manage manager;
                manager.removeBookById(bookId);
                break;
            }
            

            case searchBook:
            {
                cout << "Enter title of the book to search: ";
                string title;
                cin.ignore(); // flush leftover newline
                getline(cin, title);
                Book::manage manager;
                manager.searchBook(title);
                break;
            }

            case searchAuthor:
            {
                cout << "Enter author's name to search: ";
                string author;
                cin.ignore(); // flush leftover newline
                getline(cin, author);
                Book::manage manager;
                manager.searchAuthor(author);
                break;
            }

            case listAllBooks:
            {
                cout << "Library of All Books: " << '\n';
                Book::manage manager;
                manager.listAllBooks();
                break;
            }

            case listAllAuthors:
            {
                cout << "List of Authors: " << '\n';
                Book::manage manager;
                manager.listAlllAuthors();
                break;
            }

            case quit:
            {
                cout << "quit" << '\n';
                running = false;
                    break;
            }

            // err handle, or is it
            default:
                cout << "wrong input" << "\n";
                break;
        }
    }
    cout << "\n";
    return 0;
}
