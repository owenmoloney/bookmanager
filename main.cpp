#include <cstdlib>
#include <iostream>
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
    cout << "choose action" << "\n";
    cout << "0 > quit" << "\n"
        << "1 > add new book" << "\n"
        << "2 > remove existing book" << "\n"
        << "3 > search for book" << "\n"
        << "4 > search author" << "\n"
        << "5 > display all books" << "\n"
        << "6 > display all authors" << "\n";
    cin >> choice;

    if (choice <  0 || choice > 6)
        return error;

    return choice;
}

int main()
{
    bool running = true;
    while (running)
    {
        options option = askNicely();
        switch(option)
        {
            //"1 > add new book"
            case addBook:
                cout << "addBook" << '\n';
                break;

            //"2 > remove existing book"
            case removeBook:
                cout << "removeBook" << '\n';
                break;

            // "3 > search for book"
            case searchBook:
                cout << "findBook" << '\n';
                break;

           // "4 > search author"
            case searchAuthor:
                cout << "findAuth" << '\n';
                break;

            // "5 > display all books"
            case listAllBooks:
                cout << "listBooks" << '\n';
                break;

            // "6 > display all authors"
            case listAllAuthors:
                cout << "listAuth" << '\n';
                break;

            case quit:
                cout << "quit" << '\n';
                running = false;
                break;

            // err handle, or is it
            default:
                cout << "wrong input" << "\n";
                break;
        }
    }
    cout << "\n";
    return 0;
}
