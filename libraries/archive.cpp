#include <string>
#include <iostream>

using namespace std;


class archive {
public:
    string title;
    string writer;
    unsigned int id;

    void displayBooks();
    void findBook();

private:

};

class manager: public archive  {
public:

private:
    void addBook();
    void removeBook();
};


class writerDetails : public archive {
public:

private:
    void displayWriters();
    // read details from file by finding their writername in the file head
};
