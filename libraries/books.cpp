#include <csignal>
#include <iostream>
#include <string>
#include <thread>
using namespace std;


class Person {
protected:
    string name;
    unsigned int age;
    unsigned int id;

public:
    Person(string name="", int id=0) {

        this->name = name;
        this->id = id;
    }

    string getName(Person& person) const
    {
        if (person.name == ""){ return "person doesn't exist"; }
        else
            return person.name;
    }


    int getId(Person& person) const
    {
        if (person.id == 0) { cout << "id does not exist for this person" << "\n"; return 0; }
        else
            return person.id;
    }


    void setName(Person& person, string newName) { person.name = newName; }

    void setId(Person& person, unsigned int newId) { person.id = newId; }

};


class Author : public Person {
private:
    int numberOfBooks;

public:
    Author(string name, int id, int numberOfBooks);

    int getNumberOfBooks() const;
    void setNumberOfBooks(int count);
};


class Customer : public Person {
public:
    Customer();
    Customer(string name, int id);
};


class Book {
private:
    string title;
    int authorId;
    int id;
    double price;

public:
    Book();
    Book(string title, int bookId, int authorId, double price);

    string getTitle() const;
    int getBookId() const;
    int getAuthorId() const;
    double getPrice() const;

    void setTitle(string title);
    void setBookId(int id);
    void setAuthorId(int aid);
    void setPrice(double price);
};


class Sale {
private:
    int bookId;
    int quantity;
    int customerId;
    double price;

public:
    Sale();
    Sale(int bookId, int quantity, int customerId, double price);

    int getBookId() const;
    int getQuantity() const;
    int getCustomerId() const;
    double getPrice() const;

    void setBookId(int id);
    void setQuantity(int quantity);
    void setCustomerId(int id);
    void setPrice(double price);
};

int main()
{
    Person* ptr;
    Person homie;
    ptr = &homie;


    ptr->setId(homie, 52);
    ptr->setName(homie, "raul");
    cout << ptr->getId(homie) << "\n";

    return 0;
}
