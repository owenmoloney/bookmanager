#include <iostream>
using namespace std;

int askNicely(){
    unsigned int choice{0};
    cout << "choose action" << "\n";
    cout << "1 > add new book" << "\n"
        << "2 > remove existing book" << "\n"
        << "3 > search for book" << "\n"
        << "4 > search author" << "\n"
        << "5 > display all books" << "\n"
        << "6 > display all authors" << "\n";
    cin >> choice;
    if (choice <=  0 || choice > 6)
        return -1;

    return choice;
}

int main()
{
    bool running = true;
    while (running)
    {
        int option = askNicely();
        switch(option)
        {
            //"1 > add new book"
            case 1:
                break;

            //"2 > remove existing book"
            case 2:
                break;

            // "3 > search for book"
            case 3:
                break;

           // "4 > search author"
            case 4:
                break;

            // "5 > display all books"
            case 5:
                break;

            // "6 > display all authors"
            case 6:
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
