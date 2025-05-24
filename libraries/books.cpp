#include <iostream>
#include <string>
using namespace std;


<<<<<<< HEAD
class person{
protected:
   string name;
   int id;
public:
   person(string name, int id);
   string const Get_Name();
   int const get_Id();
   void set_Name(string newname);
   void set_wId(int newid);
};


class author : public person{
private:
    int numberofbooks;
public:
    author();
    author(string name,int id,int numberofbooks);
    int const getnumberofbooks();
    void setnumberofbooks(int count);
};


class customer : public person{
public:
    customer(string name, int Id);
};


class books{
private:
=======
class Person {
protected:
>>>>>>> a7d4aa6064a228ac272c2281c1b8bfd8c6d56cf7
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
<<<<<<< HEAD
public:
    books(string title, int bookid,int authorid, double price);
    string const get_title();
    int const get_book_id();
    int const get_author_id();
    double const get_price();
    void set_title(string title);
    void set_book_id(int id);
    void set_author_id(int aid);
    void set_price(double price);
};


class sale : public books{
public:
    sale();
    sale( int bookid,int quantity,int cutomerid,double price);
    int const get_book_id();
    int const get_quantity();
    int const get_customerid();
    double const get_price();
    void set_book_id(int id);
    void set_quantity(int quantity);
    void set_customerid(int id);
    void set_price(double price);
=======

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
>>>>>>> a7d4aa6064a228ac272c2281c1b8bfd8c6d56cf7
};
