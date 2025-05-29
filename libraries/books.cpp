#include <fstream>
#include <csignal>
#include <iostream>
#include <set>
#include <string>
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
    unsigned int id;
    unsigned long int price;

protected:

public:

    string getTitle() const {
        return title;
    }
    string getAuthorName() const {
        return authorName;
    }
    unsigned int getBookId() const {
        return id;
    }
    double getPrice() const {
        return price;
    }

    class manage  {
    public:
        manage() {
                //Empty Constructor because the previous one would call the book id and name function whenever you called the manage class
                //However the manage class should contain more than the book ID and name function 

        }

        void addBook(Book& book) {
            cin.ignore(); // flush leftover newline from previous input
        

        //Edits for bouth getline(): ensures full book titles and author names are read, even if they contain spaces

            cout << "Enter the Book Title" << "\n";
            getline(cin, book.title);
        
            cout << "Enter the Author's name" << "\n";
            getline(cin, book.authorName);

    
        //Edit
        //
            book.id = getNextAvailableId();  // Automatically assigns unique IDs to new books starting from 001, using a file scan
            cout << "Automatically assigned Book ID: " << book.id << "\n";
        
            cout << "Enter the price" << "\n";
            cin >> book.price;
        }
        
        void saveBook(Book& book) {
            ofstream outputFile("book.dat", ios::app);

            outputFile << book.getTitle() << "\n";
            outputFile << book.getAuthorName() << "\n";
            outputFile << book.getBookId() << "\n";
            outputFile << book.getPrice() << "\n";
            outputFile << "-" << "\n";

            outputFile.close();
        }

        void updateTitle(Book& book, string title) {
            book.title = title;
        }
        void updateBookId(Book& book, unsigned int id) {
            book.id = id;
        }
        unsigned int getNextAvailableId() {
            ifstream inputFile("book.dat");
            unsigned int maxId = 0;
            string title, authorName, separator;
            unsigned int id;
            unsigned long int price;
        
            while (getline(inputFile, title)) {
                getline(inputFile, authorName);
                inputFile >> id >> price;
                inputFile.ignore(); // consume newline
                getline(inputFile, separator); // consume '-'
        
                if (id > maxId) {
                    maxId = id;
                }
            }
        
            inputFile.close();
            return maxId + 1; // next ID
        }
        
        void updateAuthorName(Book& book, string authorName){
            book.authorName = authorName;
        }
        void updatePrice(Book& book, unsigned int price) {
            book.price = price;
        }

        // Adition --> Adding RemoveBookById. For the next addition of the project.
        // Efficient and safe book deletion by ID using temporary file swap
        
        void removeBookById(unsigned int idToRemove) {
            ifstream inputFile("book.dat");
            ofstream tempFile("temp.dat");
        
            string title, authorName;
            unsigned int id;
            unsigned long int price;
            string separator;
        
            bool found = false;
        
            while (getline(inputFile, title)) {
                getline(inputFile, authorName);
                inputFile >> id;
                inputFile >> price;
                inputFile.ignore();  // consume newline
                getline(inputFile, separator);  // consume '-'
        
                if (id == idToRemove) {
                    found = true;
                    cout << "Book with ID " << id << " removed.\n";
                    continue; // skip writing to temp file
                }
        
                // Write book to temp file
                tempFile << title << "\n" << authorName << "\n"
                         << id << "\n" << price << "\n" << "-\n";
            }
        
            inputFile.close();
            tempFile.close();
        
            remove("book.dat");
            rename("temp.dat", "book.dat");
        
            if (!found) {
                cout << "No book with ID " << idToRemove << " found.\n";
            }
        }
        //Edit: Search for a specific book by title, didnt use the ID because the purpose of this would be to find a book you already know the name of and are just wondering if it is available
        void searchBook(const string& titleToFind) {
            ifstream inputFile("book.dat");
            string title, authorName, separator;
            unsigned int id;
            unsigned long int price;
            bool found = false;
        
            while (getline(inputFile, title)) {
                getline(inputFile, authorName);
                inputFile >> id >> price;
                inputFile.ignore(); // consume newline
                getline(inputFile, separator); // consume '-'
        
                if (title == titleToFind) {
                    cout << "\n📚 << id << Book Found:\n";
                    cout << "Title: " << title << "\n";
                    cout << "Author: " << authorName << "\n";
                    cout << "ID: " << id << "\n";
                    cout << "Price: $" << price << "\n";
                    found = true;
                }
            }
        
            if (!found) {
                cout << "No book with the title \"" << titleToFind << "\" found.\n";
            }
        
            inputFile.close();
        }
        
        // Eddit:  Search for all books by a given author
        void searchAuthor(const string& authorToFind) {
            ifstream inputFile("book.dat");
            string title, authorName, separator;
            unsigned int id;
            unsigned long int price;
            bool found = false;
        
            while (getline(inputFile, title)) {
                getline(inputFile, authorName);
                inputFile >> id >> price;
                inputFile.ignore(); // consume newline
                getline(inputFile, separator); // consume '-'
        
                if (authorName == authorToFind) {
                    cout << "\n🖊️ Book by Author Found:\n";
                    cout << "Title: " << title << "\n";
                    cout << "Author: " << authorName << "\n";
                    cout << "ID: " << id << "\n";
                    cout << "Price: $" << price << "\n";
                    found = true;
                }
            }
        
            if (!found) {
                cout << "No books by author \"" << authorToFind << "\" found.\n";
            }
        
            inputFile.close();
        }
        
        //Edit:Lists all books in the file in a structured format
        void listAllBooks() {
            ifstream inputFile("book.dat");
            if (!inputFile) {
                cout << "No books available.\n";
                return;
            }
        
            string title, authorName, separator;
            unsigned int id;
            unsigned long int price;
            int count = 0;
        
            while (getline(inputFile, title)) {
                getline(inputFile, authorName);
                inputFile >> id >> price;
                inputFile.ignore(); // consume newline
                getline(inputFile, separator); // consume '-'
        
                cout << "\n📚 Book #" << ++count << ":\n";
                cout << "Title: " << title << "\n";
                cout << "Author: " << authorName << "\n";
                cout << "ID: " << id << "\n";
                cout << "Price: $" << price << "\n";
            }
        
            if (count == 0) {
                cout << "No books found in the database.\n";
            }
        
            inputFile.close();
        }

        //Edit: Lists all unique authors using a set to avoid duplicates
        void listAlllAuthors() {
            ifstream inputFile("book.dat");
            if (!inputFile) {
                cout << "No authors available.\n";
                return;
            }
        
            set<string> authors;
            string title, authorName, separator;
            unsigned int id;
            unsigned long int price;
        
            while (getline(inputFile, title)) {
                getline(inputFile, authorName);
                inputFile >> id >> price;
                inputFile.ignore(); // consume newline
                getline(inputFile, separator); // consume '-'
        
                if (!authorName.empty())
                    authors.insert(authorName);
            }
        
            if (authors.empty()) {
                cout << "No authors found.\n";
            } else {
                cout << "\n🖋️ All Authors:\n";
                for (const auto& name : authors) {
                    cout << "- " << name << "\n";
                }
            }
        
            inputFile.close();
        }
        
        
    private:
    };

};


/*
// feels like were going too far, feel no need for this right now
class Sale : private Book {
private:
    unsigned int id = 0;
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




