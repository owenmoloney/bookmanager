#include <string>
#include <iostream>

using namespace std;


class archive {
public:

    void addBook();
    void removeBook();
    void displayBooks();
    void findBook();

    void displayWriter();

private:
    string title;
    string writer;
    enum bookID {

    };
};


