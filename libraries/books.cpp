#include <iostream>
#include <string>
using namespace std;


class Person {
protected:
    string name;
    int id;

public:
    Person();
    Person(string name, int id);

    string getName() const;
    int getId() const;

    void setName(string newName);
    void setId(int newId);
};


class Author : public Person {
private:
    int numberOfBooks;

public:
    Author();
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

