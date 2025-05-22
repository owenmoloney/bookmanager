#include <iostream>
#include "libraries/class.cpp"
using namespace std;

int main()
{
    Class name(5,"text");
    cout << name.getData() << "\n";
    cout << name.getName() << "\n";

    cout << "\n";
    return 0;
}
