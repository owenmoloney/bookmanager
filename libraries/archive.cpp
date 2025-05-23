#include <string>
#include <iostream>

using namespace std;


class archive {
public:
    string title;
    string writer;
    unsigned int id;

private:

};

class manager: public archive  {
public:
    void addBook();
    void displayBook();

private:

};

class writers : public archive {
public:

private:

};
