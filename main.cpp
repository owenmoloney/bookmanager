#include <cstdlib>
#include <iostream>
using namespace std;
//raul
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
            case addBook:
                cout << "addBook" << '\n';
                break;

            case removeBook:
                cout << "removeBook" << '\n';
                break;

            case searchBook:
                cout << "findBook" << '\n';
                break;

            case searchAuthor:
                cout << "findAuth" << '\n';
                break;

            case listAllBooks:
                cout << "listBooks" << '\n';
                break;

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
