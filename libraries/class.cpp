#include <string>
using namespace std;

class Class{

public:
    Class(int data, string name) : data(data), name(name){}

    int getData(){
        return data;
    }
    string getName(){
        return name;
    }
private:
    int data{0};
    string name = "";

};
