#include <csignal>
#include <iostream>
#include <string>
#include <thread>
using namespace std;

/*
class Person {
protected:
    string name;
    unsigned int age;
    unsigned int id;

public:
    Person(string name="", unsigned int id=0) {

        this->name = name;
        this->id = id;
    }

    string getName(Person& person) const
    {
        if (person.name == ""){ return "person doesn't exist"; }
        else
            return person.name;
    }


    unsigned int getId(Person& person) const
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
    unsigned int numberOfBooks;

public:
    Author(string name, unsigned int id, unsigned int numberOfBooks);

    unsigned int getNumberOfBooks() const;
    void setNumberOfBooks(unsigned int count);
};


class Customer : public Person {
public:
    Customer(string name, unsigned int id);
};
*/

class Book {
private:
    string title;
    string authorName;
    unsigned int authorId;
    unsigned int bookId;

protected:
    unsigned long int price;

public:

    string getTitle() const {
        return title;
    }
    string getAuthorName() const {
        return authorName;
    }
    unsigned int getBookId() const {
        return bookId;
    }
    double getPrice() const {
        return price;
    }

    class manage  {
    public:
        manage(string title="", string authorName="", unsigned int bookId=0, unsigned long int price=0) {
            Book* book;
            book->title = title;
            book->authorName = authorName;
            book->bookId = bookId;
            book->price = price;

        }

        bool addBook() {
            cout << "add book yippie" << "\n";
            return 1;
        }

        void updateTitle(Book& book, string title) {
            book.title = title;
        }
        void updateBookId(Book& book, unsigned int bookId) {
            book.bookId = bookId;
        }
        void updateAuthorName(Book& book, string authorName){
            book.authorName = authorName;
        }
        void updatePrice(Book& book, unsigned int price) {
            book.price = price;
        }
    private:
    };

};


/*
// feels like were going too far, feel no need for this right now
class Sale : private Book {
private:
    unsigned int bookId = 0;
    unsigned int customerId = 0;
    unsigned int saleId = 0;
    unsigned int quantity = 0;
    unsigned long int price = 0;

public:

    unsigned int getBookId() const;
    unsigned int getQuantity() const;
    unsigned int getCustomerId() const;
    double getPrice() const;

    void setBookId(unsigned int id);
    void setQuantity(unsigned int quantity);
    void setCustomerId(unsigned int id);
    void setPrice(double price);
};
*/
